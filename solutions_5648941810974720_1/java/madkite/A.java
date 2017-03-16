package gcj2016r1b;

import java.util.*;

import com.google.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public class A extends SingleThreadSolution<Object> {
	public static void main(String[] args) throws Exception {
		solve(br -> {
			return new A(br.readLine());
		}, "google/src/" + A.class.getPackage().getName() + "/" + "A-large.in");
	}

	private final String number;
	private A(String number) {
		this.number = number;
	}

	public String call() throws Exception {
		return solve(number);
	}

	private static String solve(String number) {
		Map<Character, Integer> map = new HashMap<>();
		for(int i = 0; i < number.length(); i++) {
			char ch = number.charAt(i);
			int count = map.getOrDefault(ch, 0);
			map.put(ch, count + 1);
		}
		StringBuilder result = new StringBuilder();
		String[] digits = new String[]{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
		int[] order = new int[]{0, 2, 4, 6, 8, 1, 3, 7, 5, 9};
		for(int i : order) {
			for(;;) {
				boolean o = true;
				for(char ch : digits[i].toCharArray()) {
					o &= map.getOrDefault(ch, 0) > ((i == 3 || i == 7) && ch == 'E' || (i == 9 && ch == 'N') ? 1 : 0);
					if(!o)
						break;
				}
				if(o) {
					for(char ch : digits[i].toCharArray())
						map.put(ch, map.get(ch) - 1);
					result.append(i);
				} else
					break;
			}
		}
		for(char ch : map.keySet()) {
			if(map.get(ch) != 0) {
				System.err.println(number + " " + result);
				System.err.println(ch + " " + map.get(ch));
			}
		}
		char[] chars = result.toString().toCharArray();
		Arrays.sort(chars);
		return new String(chars);
	}
}
