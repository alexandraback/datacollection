import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

import com.google.common.base.Charsets;
import com.google.common.base.Function;
import com.google.common.base.Joiner;
import com.google.common.collect.HashMultimap;
import com.google.common.collect.HashMultiset;
import com.google.common.collect.Iterables;
import com.google.common.collect.Lists;
import com.google.common.collect.Maps;
import com.google.common.collect.Multimap;
import com.google.common.collect.Multiset;
import com.google.common.collect.Multiset.Entry;
import com.google.common.collect.Sets;
import com.google.common.io.Files;

/*
 * using Google Guava (http://code.google.com/p/guava-libraries/)
 */

public class Treasure {
	public static void main(String[] args) throws IOException {
		String content = Files.toString(new File(args[0]), Charsets.UTF_8);
		Scanner scanner = new Scanner(content);
		
		StringBuilder output = new StringBuilder();
		int testCases = scanner.nextInt();
		for(int i=1; i<=testCases; i++) {
			String solution = "Case #"+i+": "+solve(scanner)+"\n";
			System.err.print(solution);
			output.append(solution);
		}
		Files.write(output.toString(), new File("out.out"), Charsets.UTF_8);
	}

	private static class Chest {
		int id;
		int keyType;
		Multiset<Integer> containedKeys = HashMultiset.create();
		boolean visited = false;
		public String toString() {
			return "["+id+": "+keyType+" => "+containedKeys+"]";
		}
	}
	
	private static String solve(Scanner scanner) {
		int keysIHave = scanner.nextInt();
		int chestsNum = scanner.nextInt();
		
		Multiset<Integer> keys = HashMultiset.create();
		for (int i=0; i<keysIHave; i++) keys.add(scanner.nextInt());

		List<Chest> chests = Lists.newArrayList();
		for (int i=1; i<=chestsNum; i++) {
			Chest chest = new Chest();
			chest.id = i;
			chest.keyType = scanner.nextInt();
			int keysInChest = scanner.nextInt();
			for (int j=0; j<keysInChest; j++) chest.containedKeys.add(scanner.nextInt());
			chests.add(chest);
		}
		Treasure treasure = new Treasure();
		treasure.chests = chests;
		
		if (impossibleByMissingKeys(chests, keys) || impossibleBySCC(chests, keys)) {
			return "IMPOSSIBLE";
		}
		
		List<Integer> solution = treasure.solveState(keys, Lists.<Integer>newArrayList());
		if (solution == null) {
			return "IMPOSSIBLE";
		}
		return Joiner.on(" ").join(solution);
	}

	private static boolean impossibleByMissingKeys(List<Chest> chests, Multiset<Integer> keys) {
		Multiset<Integer> neededKeys = HashMultiset.create();
		Multiset<Integer> totalKeys = HashMultiset.create();
		for(Chest chest:chests) {
			neededKeys.add(chest.keyType);
			addAll(totalKeys, chest.containedKeys);
		}
		addAll(totalKeys, keys);
		for(int key: neededKeys.elementSet()) {
			if (neededKeys.count(key) > totalKeys.count(key)) return true;
		}
		return false;
	}

	private static boolean impossibleBySCC(List<Chest> chests, Multiset<Integer> keys) {
		Multimap<Integer, Chest> chestsByNeededKey = HashMultimap.create();
		for(Chest chest: chests) chestsByNeededKey.put(chest.id, chest);
		
		Set<Integer> visitedIds = Sets.newHashSet();
		
		for(int key:keys) {
			for(Chest chest:chestsByNeededKey.get(key)) {
				visitNode(chest, chestsByNeededKey, visitedIds);
			}
		}
		
		return visitedIds.size() == chests.size();
	}
	private static void visitNode(Chest chest, Multimap<Integer, Chest> chestsByNeededKeys, Set<Integer> visited) {
		chest.visited = true;
		visited.add(chest.id);
		for(int key:chest.containedKeys.elementSet()) {
			for(Chest newchest:chestsByNeededKeys.get(key)) {
				if (!newchest.visited) {
					visitNode(newchest, chestsByNeededKeys, visited);
				}
			}
		}
	}
	
	
	private List<Chest> chests;
	private Map<Set<Integer>, Multiset<Integer>> memoize = Maps.newHashMap();
	
	private Multiset<Integer> getState(Multiset<Integer> keys, List<Integer> opened, Chest chest) {
		Set<Integer> keySet = Sets.newHashSet(opened);
		if(memoize.containsKey(keySet)) return memoize.get(keySet);
		
		Multiset<Integer> stateKeys = cloneMultiset(keys);
		stateKeys.remove(chest.keyType, 1);
		addAll(stateKeys, chest.containedKeys);
		
		memoize.put(keySet, stateKeys);
		return stateKeys;
	}
	
	private List<Integer> solveState(Multiset<Integer> keys, List<Integer> opened) {
		if (opened.size() == chests.size()) return opened;
		for(Chest openingChest : chests) {
			if (!opened.contains(openingChest.id) && keys.contains(openingChest.keyType)) {
				List<Integer> stateOpened=Lists.newLinkedList(opened);
				stateOpened.add(openingChest.id);
				
				Multiset<Integer> stateKeys = getState(keys, stateOpened, openingChest);
				
				List<Integer> result = null;
				if (!stateClearlyInconsistent(stateKeys, stateOpened)) {
					result = solveState(stateKeys, stateOpened);
				}
				if (result != null) return result;
			}
		}
		
		return null;
	}
	
	private boolean stateClearlyInconsistent(Multiset<Integer> stateKeys, List<Integer> stateOpened) {
		for (Chest chest:chests) {
			// still closed and I have no key!
			if (!stateOpened.contains(chest.id) && !stateKeys.contains(chest.keyType)) {
				for (Chest otherChest:chests) {
					if (!stateOpened.contains(otherChest.id) 
							&& otherChest.keyType != chest.keyType 
							&& otherChest.containedKeys.contains(chest.keyType)) return false;
				}
				return true;
			}
		}
		return false;
	}

	private static <T> Multiset<T> cloneMultiset(Multiset<T> set) {
		Multiset<T> newset = HashMultiset.create();
		for(Entry<T> entry:set.entrySet()) newset.setCount(entry.getElement(), entry.getCount());
		return newset;
	}
	private static <T> void addAll(Multiset<T> target, Multiset<T> toadd) {
		for(Entry<T> entry:toadd.entrySet()) {
			target.add(entry.getElement(), entry.getCount());
		}
	}
}
