import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws Exception {
		String path = "D:\\B-small-attempt0";
		Scanner sc = new Scanner(new File(path + ".in"));
		PrintWriter pw = new PrintWriter(path + ".out");
		int testCases = sc.nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			int E = sc.nextInt();
			int R = sc.nextInt();
			int n = sc.nextInt();
			int[] v = new int[n];
			for (int i = 0; i < n; i++) {
				v[i] = sc.nextInt();
			}
			int res = 0;

			int[] a = new int[n + 1];
			while (a[n] == 0) {
				int cur = 0;

				int energy = E;
				for (int i = 0; i < n; i++) {
					energy -= a[i];
					if (energy < 0) {
						cur = 0;
						break;
					}
					cur += a[i] * v[i];
					energy = Math.min(energy + R, E);
				}

				res = Math.max(res, cur);
				++a[0];
				for (int i = 0; i < n; i++) {
					if (a[i] > E) {
						a[i] = 0;
						++a[i + 1];
					}
				}
			}

			pw.println("Case #" + testCase + ": " + res);
			pw.flush();
		}
		pw.close();
	}
}
