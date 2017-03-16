package r1a2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CruiseControl {
	static final String L = "L";
	static final String R = "R";

	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		CruiseControl obj = new CruiseControl();
		obj.solve(fileName);
	}

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String str = br.readLine();
			StringTokenizer token = new StringTokenizer(str, " ");
			int N = Integer.parseInt(token.nextToken());

			String[] C = new String[N];
			int[] S = new int[N];
			double[] P = new double[N];
			for (int j = 0; j < N; j++) {
				str = br.readLine();
				token = new StringTokenizer(str, " ");

				C[j] = token.nextToken();
				S[j] = Integer.parseInt(token.nextToken());
				P[j] = Integer.parseInt(token.nextToken());
			}

			double t = solve(C, S, P, N);

			String ans = null;
			if (t == Double.MAX_VALUE) {
				ans = "Possible";
			} else {
				DecimalFormat ft = new DecimalFormat("0.######");
				ans = ft.format(t);
			}

			bw.write("Case #" + (i + 1) + ": " + ans);
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}

	private double solve(String[] ic, int[] s, double[] ip, int n) {
		double[] p = new double[n];
		String[] c = new String[n];

		double t = Double.MAX_VALUE;
		int I = -1;
		int J = -1;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i; j < n; j++) {
				double tmp = 0;
				if (s[i] < s[j]) {
					if (ip[i] - 5 > ip[j]) {
						tmp = (ip[i] - 5 - ip[j]) / (s[j] - s[i]);
					}
				} else if (s[i] > s[j]) {
					if (ip[j] - 5 > ip[i]) {
						tmp = (ip[j] - 5 - ip[i]) / (s[i] - s[j]);
					}

				}
				if (tmp != 0 && t > tmp) {
					t = tmp;
					I = i;
					J = j;
				}
			}
		}
		if (I == -1) {
			return Double.MAX_VALUE;
		}

		for (int i = 0; i < n; i++) {
			p[i] = ip[i] + s[i] * t;
			c[i] = ic[i];
		}

		double tL = 0;
		double tR = 0;
		// LR
		boolean flg = true;
		if (R.equals(ic[I])) {
			for (int i = 0; i < n; i++) {
				if (i == I || i == J) {
					continue;
				}
				if (p[I] > p[i] - 5 && p[I] < p[i] + 5) {
					flg = false;
					break;
				}
				if (p[I] == p[i] - 5 && s[I] > s[i]) {
					flg = false;
					break;
				}
				if (p[I] == p[i] + 5 && s[I] < s[i]) {
					flg = false;
					break;
				}
			}
		}
		if (flg && L.equals(ic[J])) {
			for (int i = 0; i < n; i++) {
				if (i == I || i == J) {
					continue;
				}
				if (p[J] > p[i] - 5 && p[J] < p[i] + 5) {
					flg = false;
					break;
				}
				if (p[J] == p[i] - 5 && s[J] > s[i]) {
					flg = false;
					break;
				}
				if (p[J] == p[i] + 5 && s[J] < s[i]) {
					flg = false;
					break;
				}
			}
		}
		if (flg) {
			c[I] = L;
			c[J] = R;
			tL = solve(c, s, p, n);
			if (tL == Double.MAX_VALUE) {
				return Double.MAX_VALUE;
			}
		}

		// RL
		flg = true;
		if (L.equals(ic[I])) {
			for (int i = 0; i < n; i++) {
				if (i == I || i == J) {
					continue;
				}
				if (p[I] > p[i] - 5 && p[I] < p[i] + 5) {
					flg = false;
					break;
				}
				if (p[I] == p[i] - 5 && s[I] > s[i]) {
					flg = false;
					break;
				}
				if (p[I] == p[i] + 5 && s[I] < s[i]) {
					flg = false;
					break;
				}
			}
		}
		if (flg && R.equals(ic[J])) {
			for (int i = 0; i < n; i++) {
				if (i == I || i == J) {
					continue;
				}
				if (p[J] > p[i] - 5 && p[J] < p[i] + 5) {
					flg = false;
					break;
				}
				if (p[J] == p[i] - 5 && s[J] > s[i]) {
					flg = false;
					break;
				}
				if (p[J] == p[i] + 5 && s[J] < s[i]) {
					flg = false;
					break;
				}
			}
		}
		if (flg) {
			c[I] = R;
			c[J] = L;
			tR = solve(c, s, p, n);
			if (tR == Double.MAX_VALUE) {
				return Double.MAX_VALUE;
			}
		}

		return t + Math.max(tL, tR);
	}
}
