import java.util.*;

public class _GettingDigits {
	
	static ArrayList<HashMap<Character, Integer>> numbers = new ArrayList<HashMap<Character, Integer>>();
	static {
		String[] letters = {
				"ZERO",
				"ONE",
				"TWO",
				"THREE",
				"FOUR",
				"FIVE",
				"SIX",
				"SEVEN",
				"EIGHT",
				"NINE"
			};
		for (String s : letters) {
			HashMap<Character, Integer> count = new HashMap<>();
			for (int i = 0; i < s.length(); i++) {
				if (count.containsKey(s.charAt(i))) {
					count.put(s.charAt(i), count.get(s.charAt(i)) + 1);
				} else {
					count.put(s.charAt(i), 1);
				}
			}
			numbers.add(count);
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			System.out.printf("Case #%d: ", t);
			String num = in.next();
			
			HashMap<Character, Integer> count = new HashMap<>();
			for (int i = 0; i < num.length(); i++) {
				if (count.containsKey(num.charAt(i))) {
					count.put(num.charAt(i), count.get(num.charAt(i)) + 1);
				} else {
					count.put(num.charAt(i), 1);
				}
			}
			
			ArrayList<Integer> list = solve(count, new ArrayList<Integer>(), 0);
			Collections.sort(list);
			
			for (int i : list) {
				System.out.print(i);
			}
			System.out.println();
		}
	}
	
	public static ArrayList<Integer> solve(HashMap<Character, Integer> map, ArrayList<Integer> list, int pos) {
		if (map.isEmpty())
			return list;
		
		for (int i = pos; i < numbers.size(); i++) {
			if (remove(map, numbers.get(i))) {
				list.add(i);
				ArrayList<Integer> tmp = solve(map, list, i);
				if (tmp != null)
					return tmp;
				list.remove(list.size()-1);
				add(map, numbers.get(i));
			}
		}
		
		return null;
	}
	
	public static boolean remove(HashMap<Character, Integer> map1, HashMap<Character, Integer> map2) {
		for (Map.Entry<Character, Integer> e : map2.entrySet()) {
			if (!map1.containsKey(e.getKey())) {
				return false;
			} else if (map1.get(e.getKey()).compareTo(e.getValue()) < 0) {
				return false;
			}
		}
		for (Map.Entry<Character, Integer> e : map2.entrySet()) {
			if (map1.get(e.getKey()).compareTo((Integer) e.getValue()) == 0) {
				map1.remove(e.getKey());
			} else {
				map1.put(e.getKey(), map1.get(e.getKey()) - e.getValue());
			}
		}
		return true;
	}
	
	public static void add(HashMap<Character, Integer> map1, HashMap<Character, Integer> map2) {
		for (Map.Entry<Character, Integer> e : map2.entrySet()) {
			if (!map1.containsKey(e.getKey())) {
				map1.put(e.getKey(), e.getValue());
			} else {
				map1.put(e.getKey(), map1.get(e.getKey()) + e.getValue());
			}
		}
	}
}
