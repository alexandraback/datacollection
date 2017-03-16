package gcj2016r1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ProblemC {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		ProblemC obj = new ProblemC();
		obj.solve(fileName);
	}

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			int N = Integer.parseInt(br.readLine());
			ArrayList<String> list = new ArrayList<>();
			int[][] topics = new int[N][2];
			for (int j = 0; j < N; j++) {
				String str = br.readLine();
				StringTokenizer token = new StringTokenizer(str, " ");
				String a = token.nextToken();
				String b = token.nextToken();
				if (!list.contains(a)) {
					topics[j][0] = list.size();
					list.add(a);
				} else {
					for (int k = 0; k < list.size(); k++) {
						if (a.equals(list.get(k))) {
							topics[j][0] = k;
						}
					}
				}
				if (!list.contains(b)) {
					topics[j][1] = list.size();
					list.add(b);
				} else {
					for (int k = 0; k < list.size(); k++) {
						if (b.equals(list.get(k))) {
							topics[j][1] = k;
						}
					}
				}
			}

			boolean[][] chk = new boolean[2][list.size()];
			int max = 0;
			for (int j = 0; j < (1L << N); j++) {
				Arrays.fill(chk[0], false);
				Arrays.fill(chk[1], false);
				int cnt = 0;
				for (int k = 0; k < N; k++) {
					if (((j >> k) & 1L) == 1L) {
						cnt++;
					} else {
						chk[0][topics[k][0]] = true;
						chk[1][topics[k][1]] = true;
					}
				}
				if (cnt <= max) {
					continue;
				}
				boolean flg = true;
				for (int k = 0; k < N; k++) {
					if (((j >> k) & 1L) == 1L) {
						if (!chk[0][topics[k][0]] || !chk[1][topics[k][1]]) {
							flg = false;
							break;
						}
					}
				}
				if (flg && cnt >= max) {
					max = cnt;
				}
			}

			bw.write("Case #" + (i + 1) + ": " + max);
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}
}
