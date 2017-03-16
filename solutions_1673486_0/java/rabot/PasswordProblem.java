package r1a2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.StringTokenizer;

public class PasswordProblem {

	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		PasswordProblem obj = new PasswordProblem();
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
			int A = Integer.parseInt(token.nextToken());
			int B = Integer.parseInt(token.nextToken());

			str = br.readLine();
			token = new StringTokenizer(str, " ");

			double[] p = new double[A];
			double[] c = new double[A];
			for (int j = 0; j < A; j++) {
				p[j] = Double.parseDouble(token.nextToken());
				if (j == 0) {
					c[0] = p[0];
				} else {
					c[j] = c[j - 1] * p[j];
				}
			}

			double ans = B + 2;
			for (int j = 0; j < A; j++) {
				double tmp = (B - A + 1 + 2 * j) * c[A - j - 1]
						+ (B - A + 1 + 2 * j + B + 1) * (1 - c[A - j - 1]);
				if (tmp < ans) {
					ans = tmp;
				}
			}

			DecimalFormat ft = new DecimalFormat("0.0000000");
			bw.write("Case #" + (i + 1) + ": " + ft.format(ans));
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}
}
