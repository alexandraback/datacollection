import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for (int i = 1; i <= T; i++) {
			String S = scanner.next();
			System.out.print("Case #" + i + ": ");
			System.out.println(new Solver().solve(S));
		}
	}
}

class Solver {

	ArrayList<Integer> ans = new ArrayList<>();
	String[] ref = new String[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
	HashMap<Character, Integer> cut = new HashMap<>();

	public String solve(String s) {

		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (!cut.containsKey(c)) {
				cut.put(c, 1);
			} else {
				cut.put(c, cut.get(c) + 1);
			}
		}

		StringBuilder state = new StringBuilder();
		ArrayList<Integer> list = new ArrayList<>();
		preProcess('G', 8, state, list);
		preProcess('U', 4, state, list);
		preProcess('X', 6, state, list);
		preProcess('W', 2, state, list);

		if (cut.containsKey('H')) {
			int g = !cut.containsKey('G') ? 0 : cut.get('G');
			for (int i = 0; i < cut.get('H') - g; i++) {
				state.append(ref[3]);
				list.add(3);
			}
		}

		dfs(state.toString(), new ArrayList<Integer>(), s);

		ans.addAll(list);
		Collections.sort(ans);
		StringBuilder sb = new StringBuilder();
		for (int i : ans) {
			sb.append(i);
		}
		return sb.toString();
	}

	private void preProcess(char c, int n, StringBuilder state, ArrayList<Integer> list) {
		if (!cut.containsKey(c))
			return;
		for (int i = 0; i < cut.get(c); i++) {
			state.append(ref[n]);
			list.add(n);
		}
	}

	private void dfs(String state, ArrayList<Integer> list, String target) {
		if (state.length() > target.length()) {
			return;
		}
		HashMap<Character, Integer> map = new HashMap<>();
		for (int i = 0; i < state.length(); i++) {
			char c = state.charAt(i);
			if (!map.containsKey(c)) {
				map.put(c, 1);
			} else {
				map.put(c, map.get(c) + 1);
			}
		}

		for (Entry<Character, Integer> e : map.entrySet()) {
			char c = e.getKey();
			if (!cut.containsKey(c))
				return;
			if (cut.get(c) < e.getValue())
				return;
		}

		if (state.length() == target.length()) {
			char[] c0 = state.toCharArray();
			char[] c1 = target.toCharArray();
			Arrays.sort(c0);
			Arrays.sort(c1);
			boolean same = true;
			for (int i = 0; i < c0.length; i++) {
				if (c0[i] != c1[i]) {
					same = false;
					break;
				}
			}
			if (same) {
				ans = new ArrayList<>(list);
			}
			return;
		}
		int index = list.isEmpty() ? 0 : list.get(list.size() - 1);
		for (int i = index; i < 10; i++) {
			if (i == 2 || i == 3 || i == 8 || i == 4 || i == 6)
				continue;
			list.add(i);
			dfs(state + ref[i], list, target);
			if (!ans.isEmpty())
				return;
			list.remove(list.size() - 1);
		}

	}

}
