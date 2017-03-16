import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
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
	String[] s = new String[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

	public String solve(String s) {

		dfs("", new ArrayList<Integer>(), s);

		Collections.sort(ans);
		StringBuilder sb = new StringBuilder();
		for (int i : ans) {
			sb.append(i);
		}
		return sb.toString();
	}

	private void dfs(String state, ArrayList<Integer> list, String target) {
		if (!ans.isEmpty())
			return;
		if (state.length() > target.length()) {
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
				return;
			}
		}
		for (int i = 0; i < 10; i++) {
			list.add(i);
			dfs(state + s[i], list, target);
			if (!ans.isEmpty())
				return;
			list.remove(list.size() - 1);
		}

	}

}
