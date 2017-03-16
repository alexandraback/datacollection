package r1b2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.StringTokenizer;

public class FallingDiamonds {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		FallingDiamonds obj = new FallingDiamonds();
		obj.solve(fileName);
	}

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int[] NUM = new int[1000];
		for ( int i = 0 ; i < 1000 ; i++ ) {
			NUM[i] = 2 * i * i  + 3 * i + 1;
		}
		DecimalFormat fmt = new DecimalFormat("0.0#######");

		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			String str = br.readLine();
			StringTokenizer token = new StringTokenizer(str);
			int N = Integer.parseInt(token.nextToken());
			int X = Integer.parseInt(token.nextToken());
			int Y = Integer.parseInt(token.nextToken());

			int num = (Math.abs(X) + Math.abs(Y)) / 2;
			double ans = 0;
			if (num >= 1000) {
				ans = 0;
			} else if (NUM[num] <= N) {
				ans = 1;
			} else if (NUM[num] - 4 * num - 1 >= N) {
				ans = 0;
			} else {
				int k = N - NUM[num] + 4 * num + 1;
				if (k >= 2 * num + Y + 1) {
					ans = 1;
				} else if ( Y == 2 * num ) {
					ans = 0;
				} else if ( Y >= k ) {
					ans = 0;
				} else {
					for (int a = 0 ; a <= Y ; a++ ) {
						double tmp = 1;
						for (int b = 0; b < k; b++) {
							if (b < k - a) {
								tmp = tmp * (k - b) / (k - a - b) / 2;
							} else {
								tmp = tmp * (k - b) / (a - (b - (k - a))) / 2;
							}
						}
						ans += tmp;
					}
					ans = 1 - ans;
				}
			}

			bw.write("Case #" + (t + 1) + ": " + fmt.format(ans));
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}

}
