import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class Digits {
	
	public static void take(String take, HashMap<Character, Integer> chars) {
		for (char c : take.toCharArray()) {
			int amount = chars.getOrDefault(c, 0);
			
			if (amount - 1 > 0) {
				chars.put(c, amount - 1);
			} else {
				chars.remove(c);
			}
		}
	}
	public static void put(String take, HashMap<Character, Integer> chars) {
		for (char c : take.toCharArray()) {
			int amount = chars.getOrDefault(c, 0);
			chars.put(c, amount + 1);
		}
	}
	
	public static boolean contains(char c, int num, HashMap<Character, Integer> chars) {
		return chars.getOrDefault(c, 0) >= num;
	}
	
	public static boolean check(int num, HashMap<Character, Integer> chars) {
		boolean result = true;
		if (num == 1) {
			result = result && contains('o', 1, chars);
			result = result && contains('n', 1, chars);
			result = result && contains('e', 1, chars);
		} else if (num == 3) {
			result = result && contains('t', 1, chars);
			result = result && contains('h', 1, chars);
			result = result && contains('r', 1, chars);
			result = result && contains('e', 2, chars);
		} else if (num == 5) {
			result = result && contains('f', 1, chars);
			result = result && contains('i', 1, chars);
			result = result && contains('v', 1, chars);
			result = result && contains('e', 1, chars);
		} else if (num == 9) {
			result = result && contains('n', 2, chars);
			result = result && contains('i', 1, chars);
			result = result && contains('e', 1, chars);
		}
		return result;
	}		
	
	public static int reduce(HashMap<Character, Integer> chars, ArrayList<Integer> numbers) {
		boolean changed = true;
		int taken = 0;
		while (changed) {
			if (chars.getOrDefault('z', 0) > 0) {
				take("zero", chars);
				numbers.add(0);
				taken += 4;
			} else if (chars.getOrDefault('x', 0) > 0) {
				take("six", chars);
				numbers.add(6);
				taken += 3;
			} else if (chars.getOrDefault('w', 0) > 0) {
				take("two", chars);
				numbers.add(2);
				taken += 3;
			} else if (chars.getOrDefault('u', 0) > 0) {
				take("four", chars);
				numbers.add(4);
				taken += 4;
			} else if (chars.getOrDefault('g', 0) > 0) {
				take("eight", chars);
				numbers.add(8);
				taken += 5;
			} else if (chars.getOrDefault('s', 0) > 0) {
				take("seven", chars);
				numbers.add(7);
				taken += 5;
			} else {
				changed = false;
			}
		}
		return taken;
	}
	
	public static ArrayList<Integer> checkerino(int num, String nums, int left, HashMap<Character, Integer> chars, ArrayList<Integer> numbers) {
		if (check(num, chars)) {
			ArrayList<Integer> clone = (ArrayList<Integer>) numbers.clone();
			take(nums, chars);
			clone.add(num);
			ArrayList<Integer> result = guess(chars, left - nums.length(), clone);
			put(nums, chars);
			return result;
		}
		return null;
	}
	
	public static ArrayList<Integer> guess(HashMap<Character, Integer> chars, int left, ArrayList<Integer> numbers) {
	
		int taken = reduce(chars, numbers);
		left -= taken;
		
		if (left == 0) {
			return numbers;
		}
		
		ArrayList<Integer> r = checkerino(1, "one", left, chars, numbers);
		if (r != null)  { return r; }
		r = checkerino(3, "three", left, chars, numbers);
		if (r != null)  { return r; }
		r = checkerino(5, "five", left, chars, numbers);
		if (r != null)  { return r; }
		r = checkerino(9, "nine", left, chars, numbers);
		if (r != null)  { return r; }

		return null;
	}
	
public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	
	
	int t = sc.nextInt();
	
	for (int c = 1; c <= t; c++) {
		
		HashMap<Character, Integer> chars = new HashMap<>();
		String s = sc.next().toLowerCase();
		
		int left = s.length();

		
		for (char ch : s.toCharArray()) {
			chars.put(ch, chars.getOrDefault(ch, 0) + 1);
		}
		
		ArrayList<Integer> result = guess(chars, left, new ArrayList<Integer>());
		Collections.sort(result);
		
		System.out.print("Case #" + c + ": ");
		for (int i : result) {
			System.out.print(i);
		}
		System.out.println();
	}
}
}
