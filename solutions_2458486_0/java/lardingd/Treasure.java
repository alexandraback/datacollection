package qualifierFun;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.TreeSet;

public class Treasure {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			PrintWriter out = new PrintWriter(new FileWriter("outputTreasure.txt")); 
			BufferedReader in  = new BufferedReader(new FileReader("input.txt"));
			int answer =1;
			String strLine = in.readLine();
			int totalCases = Integer.parseInt(strLine);
			Map<Integer, List<Integer>> boxToKeys = new HashMap<Integer, List<Integer>>();
			Map<Integer, Integer> boxToLock = new HashMap<Integer, Integer>();
			Set<Integer> boxes = new TreeSet<Integer>();
			Map<Integer, Integer> keys = new HashMap<Integer, Integer>();
			for(int i = 0; i < totalCases; i++) {
				boxToKeys.clear();
				boxToLock.clear();
				boxes.clear();
				keys.clear();
				strLine = in.readLine();
				String inputs[] = strLine.split(" ");
				int numKeys = Integer.parseInt(inputs[0]);
				int numBoxes = Integer.parseInt(inputs[1]);
				strLine = in.readLine();
				inputs = strLine.split(" ");
				for(String input : inputs) {
					int key = Integer.parseInt(input);
					Integer current = keys.get(key);
					keys.put(key, current == null ? 1 : current + 1);
				}
				for(int j= 0; j < numBoxes; j++) {
					strLine = in.readLine();
					boxes.add(j+1);
					inputs = strLine.split(" ");
					int lock = Integer.parseInt(inputs[0]);
					boxToLock.put(j+1, lock);
					List<Integer> boxKeys = new ArrayList<Integer>();
					int numBoxKeys = Integer.parseInt(inputs[1]);
					for(int k = 0; k < numBoxKeys; k++) {
						boxKeys.add(Integer.parseInt(inputs[2+k]));
					}
					boxToKeys.put(j+1, boxKeys);
				}
				boolean sane = simpleSanity(boxToLock, boxToKeys, keys);
				List<Integer> order = null;
				if(sane) {
					order = getCases(boxToKeys, boxToLock, boxes, keys);
				}
				String theOrder = order(order);
				System.out.print(String.format("Case #%s: %s\n", answer, theOrder));
				out.write(String.format("Case #%s: %s\n", answer, theOrder));
				answer++;
			}
			out.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("I'd want to know");
		} catch (IOException e) {
			System.out.println("I'd want to know io");
		}
		System.out.println("done");

	}
	
	private static boolean simpleSanity(Map<Integer, Integer> boxToLock,
			Map<Integer, List<Integer>> boxToKeys,
			Map<Integer, Integer> keys) {
		Map<Integer, Integer> totalKeys = new HashMap<Integer, Integer>(keys);
		for(List<Integer> keySet : boxToKeys.values()) {
			for(Integer key : keySet) {
				Integer current = totalKeys.get(key);
				totalKeys.put(key, current == null ? 1 : current + 1);
			}
		}
		for(Integer lock : boxToLock.values()) {
			Integer current = totalKeys.get(lock);
			if(current == null || current < 1) {
				return false;
			} else {
				totalKeys.put(lock, current -1);
			}
		}
		return true;
	}
	
	private static String order(List<Integer> order) {
		if(order == null || order.isEmpty()) {
			return "IMPOSSIBLE";
		}
		StringBuilder builder = new StringBuilder();
		for(Integer box : order) {
			builder.append(box).append(" ");
		}
		builder.deleteCharAt(builder.length()-1);
		return builder.toString();
	}

	private static List<Integer> getCases(
			Map<Integer, List<Integer>> boxToKeys,
			Map<Integer, Integer> boxToLock,
			Set<Integer> boxes,
			Map<Integer, Integer> keys) {
		
		if (boxes.isEmpty()) {
			return new ArrayList<Integer>();
		}
		
		int next = 0;
		Set<Integer> copyBoxes = new TreeSet<Integer>(boxes);
		for(Integer box : boxes) {
			Integer lock = boxToLock.get(box);
			Integer integer = keys.get(lock);
			if(integer == null || integer == 0) {
				continue;
			} else {
				next = box;
				keys.put(lock, integer -1);
				addKeys(keys, boxToKeys.get(box));
				copyBoxes.remove(box);
				if(integer != 1 || keyNoLongerNeeded(keys, next, copyBoxes, boxToLock, boxToKeys)) {
					List<Integer> follow = getCases(boxToKeys, boxToLock, copyBoxes, keys);
					if(follow != null) {
						follow.add(0, next);
						return follow;
					}
				}
				removeKeys(keys, boxToKeys.get(box));
				keys.put(lock, integer);
				copyBoxes.add(box);
			}
		}
		return null;
	}

	private static boolean keyNoLongerNeeded(Map<Integer, Integer> keys,
			int next,
			Set<Integer> copyBoxes,
			Map<Integer, Integer> boxToLock, 
			Map<Integer, List<Integer>> boxToKeys) {
		Set<Integer> keyTypes = new HashSet<Integer>();
		for(Entry<Integer, Integer> keyEntry : keys.entrySet()) {
			if(keyEntry.getValue() > 0) {
				keyTypes.add(keyEntry.getKey());
			}
		}
		boolean moreNeeded = false;
		for(Integer box : copyBoxes) {
			if(keyTypes.contains(boxToLock.get(box))) {
				for(Integer lock : boxToKeys.get(box)) {
					if (!keyTypes.contains(lock)) {
						return true;
					}
				}
			} else {
				moreNeeded = true;
			}
		}
		return !moreNeeded;
	}

	private static void addKeys(Map<Integer, Integer> keys, List<Integer> list) {
		for(Integer key : list) {
			Integer current = keys.get(key);
			keys.put(key, current == null ? 1 : current + 1);
		}
	}
	
	private static void removeKeys(Map<Integer, Integer> keys, List<Integer> list) {
		for(Integer key : list) {
			Integer current = keys.get(key);
			keys.put(key, current - 1);
		}
	}

	public Treasure() {
		
	}

}
