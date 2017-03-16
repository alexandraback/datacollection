package at.jaki.round1.b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class B {

	private static final Map<String, Integer> map = new HashMap<String, Integer>();

	public static void main(String... args) throws FileNotFoundException {
		String name = "B-small-attempt0";
		Scanner sc = new Scanner(new File(name + ".in"));
		PrintWriter pw = new PrintWriter(new File(name + ".out"));
		int nnn = sc.nextInt();
		for (int iii = 1; iii <= nnn; iii++) {
			map.clear();
			String msg = null;

			int e = sc.nextInt();
			int r = sc.nextInt();
			int n = sc.nextInt();

			int[] t = new int[n];
			for (int i = 0; i < n; i++) {
				t[i] = sc.nextInt();
			}

			int total = solve(e, r, t, 0, e);


			String s = "Case #" + iii + ": " + total;
			System.out.println(s);
			pw.println(s);
		}
		pw.flush();
		pw.close();

	}

	private static int solve(int e, int r, int[] t, int k, int curr) {
		String x = curr + " " + k;
		if (map.containsKey(x)) {
			return map.get(x);
		}
		if (k == t.length) {
			return 0;
		}
		int max = 0;

		for (int i = 0; i <= curr; i++) {
			int rez = t[k] * i + solve(e, r, t, k + 1, Math.min(curr - i + r, e));
			max = Math.max(rez, max);
		}
		//System.out.println(curr + " " + k + " " + max);
		map.put(x, max);
		return max;
	}
}
