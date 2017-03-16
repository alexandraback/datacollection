package r1c2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws Exception {
//		 String input = "in";
//		 String output = "out";
		String input = "C-small-attempt3.in";
		String output = "C-small-attempt3.out";
		// String input = "C-large.in";
		// String output = "C-large.out";

		Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(
				output)));

		int T = Integer.parseInt(scan.nextLine());
		for (int t = 1; t <= T; t++) {
			String[] info = scan.nextLine().split(" ");
			int N = Integer.parseInt(info[0]);
			int M = Integer.parseInt(info[1]);
			long[] a = new long[N], b = new long[M];
			int[] A = new int[N], B = new int[M];
			info = scan.nextLine().split(" ");
			for (int i = 0; i < N; i++) {
				a[i] = Long.parseLong(info[i * 2]);
				A[i] = Integer.parseInt(info[i * 2 + 1]);
			}
			info = scan.nextLine().split(" ");
			for (int i = 0; i < M; i++) {
				b[i] = Long.parseLong(info[i * 2]);
				B[i] = Integer.parseInt(info[i * 2 + 1]);
			}

			long[][] dp = new long[N + 1][M + 1];
			for (int i = N - 1; i >= 0; i--)
				for (int j = M - 1; j >= 0; j--) {
					long v = Math.max(dp[i + 1][j], dp[i][j + 1]);
					dp[i][j] = Math.max(dp[i][j], v);
					if (A[i] == B[j]) {
						dp[i][j] = Math.max(dp[i][j], Math.min(a[i], b[j])
								+ dp[i + 1][j + 1]);
						// long counta = 0, countb = 0;
						// for (int k = 0; k <= i; k++)
						// counta += (A[k] == A[i]) ? a[k] : 0;
						// for (int k = 0; k <= j; k++)
						// countb += (B[k] == B[i]) ? b[k] : 0;
						// // System.out.println("[" + i + "][" + j +
						// "] counta:"
						// // + counta + " countb:" + countb);
						// dp[0][0] = Math.max(dp[0][0], Math.min(counta,
						// countb)
						// + dp[i + 1][j + 1]);
						long counta = 0, countb = 0;
						for (int n = i; n < N; n++)
							if (A[n] == A[i]) {
								counta += a[n];
								countb = 0;
								for (int m = j; m < M; m++)
									if (B[m] == B[j]) {
										countb += b[m];
										dp[i][j] = Math.max(dp[i][j],
												Math.min(counta, countb)
														+ dp[n + 1][m + 1]);
									}
							}
					}
					// System.out.println("dp[" + i + "][" + j + "]:" +
					// dp[i][j]);
				}
			System.out.println("Case #" + t + ": " + dp[0][0]);
			pw.println("Case #" + t + ": " + dp[0][0]);
		}

		scan.close();
		pw.close();
	}
}
