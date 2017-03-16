package googlejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class DancingWithGooglers {

	private static int N;
	private static int S;
	private static int p;
	private static int[] ts;
	private static int[][] memo;
	private static int[] maxSupr;
	private static int[] maxNotSupr;

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("inputB.txt"));
		PrintWriter pw = new PrintWriter("outputB.txt");
		int T = sc.nextInt();

		maxSupr = new int[31];
		Arrays.fill(maxSupr, -1);
		maxNotSupr = new int[31];
		Arrays.fill(maxNotSupr, -1);

		for (int a = 0; a <= 10; a++) {
			for (int b = 0; b <= 10; b++) {
				for (int c = 0; c <= 10; c++) {
					int s = a + b + c;
					if (Math.abs(a - b) <= 2 && Math.abs(b - c) <= 2 && Math.abs(c - a) <= 2) {
						int max = Math.max(a, Math.max(b, c));
						if (Math.abs(a - b) == 2 || Math.abs(b - c) == 2 || Math.abs(c - a) == 2) {
							maxSupr[s] = Math.max(maxSupr[s], max);
						} else {
							maxNotSupr[s] = Math.max(maxNotSupr[s], max);
						}
					}
				}
			}
		}

		for (int t = 1; t <= T; t++) {
			N = sc.nextInt();
			S = sc.nextInt();
			p = sc.nextInt();
			ts = new int[N];
			for (int i = 0; i < ts.length; i++) {
				ts[i] = sc.nextInt();
			}

			memo = new int[N + 1][S + 1];
			for (int[] m : memo) {
				Arrays.fill(m, -1);
			}

			int max = getMax(0, S);
			pw.println("Case #" + t + ": " + max);
		}
		pw.flush();
		pw.close();
	}

	public static int getMax(int index, int surpr) {
		int res = memo[index][surpr];
		if (res == -1) {
			if (index == N) {
				if (surpr == 0) {
					res = 0;
				} else {
					res = -1000;
				}
			} else {
				// not suprised
				res = (maxNotSupr[ts[index]] >= p ? 1 : 0) + getMax(index + 1, surpr);

				if (surpr > 0 && maxSupr[ts[index]] != -1) {
					// suprised
					res = Math.max(res, (maxSupr[ts[index]] >= p ? 1 : 0) + getMax(index + 1, surpr - 1));
				}

			}
			memo[index][surpr] = res;
		}
		return res;
	}
}
