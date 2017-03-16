package r1a2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.StringTokenizer;

public class KingdomRush {

	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		KingdomRush obj = new KingdomRush();
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

			int[] a = new int[N];
			int[] b = new int[N];
			for (int j = 0; j < N; j++) {
				str = br.readLine();
				token = new StringTokenizer(str, " ");

				a[j] = Integer.parseInt(token.nextToken());
				b[j] = Integer.parseInt(token.nextToken());
			}

			int[] check = new int[N];
			int cnt = 0;
			int star = 0;

			boolean flg = true;
			while (flg) {
				flg = false;
				// 2-star
				for (int j = 0; j < N; j++) {
					if (check[j] == 2) {
						continue;
					}
					if (b[j] <= star) {
						star += 2 - check[j];
						check[j] = 2;
						cnt += 1;
						flg = true;
					}
				}
				if (flg) {
					continue;
				}
				// 1-star
				int idx = -1;
				int max = -1;
				for (int j = 0; j < N; j++) {
					if (check[j] >= 1) {
						continue;
					}
					if (a[j] <= star) {
						if (b[j] > max) {
							max = b[j];
							idx = j;
						}
					}
				}
				if (idx >= 0) {
					star += 1;
					check[idx] = 1;
					cnt += 1;
					flg = true;
				}
				if (flg) {
					continue;
				} else {
					break;
				}
			}

			String ans = Integer.toString(cnt);
			for (int j = 0; j < N; j++) {
				if (check[j] != 2) {
					ans = "Too Bad";
					break;
				}
			}

			bw.write("Case #" + (i + 1) + ": " + ans);
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}
}
