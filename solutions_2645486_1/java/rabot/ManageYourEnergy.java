package r1a2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class ManageYourEnergy {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		ManageYourEnergy obj = new ManageYourEnergy();
		obj.solve(fileName);
	}

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			String str = br.readLine();
			StringTokenizer token = new StringTokenizer(str);
			int E = Integer.parseInt(token.nextToken());
			int R = Integer.parseInt(token.nextToken());
			int N = Integer.parseInt(token.nextToken());

			str = br.readLine();
			token = new StringTokenizer(str);
			long[] v = new long[N];
			long[] max = new long[100];
			for (int i = 0; i < N; i++) {
				v[i] = Integer.parseInt(token.nextToken());
				max[i / 100] = Math.max(v[i], max[i / 100]);
			}

			long g = 0;
			long now = E;
			for (int i = 0; i < N; i++) {
				now = Math.min(E, now + R);
				//int use = Math.min(now, R);
				long use = 0;
				boolean flg = false;
				for (int j = i + 1; j < N; j++) {
					if (use >= now) {
						flg = true;
						break;
					}
					if (j % 100 == 0 && j + 100 < N) {
						if (v[i] > max[j / 100]) {
							use = Math.min(use + R * 100, now);
							j += 99;
							continue;
						}
					}
					if (v[i] > v[j]) {
						use = Math.min(use + R, now);
						continue;
					} else {
						if (E - (j - i) * R <= now) {
							use = Math.min(now, now - E + (j - i) * R);
						}
						flg = true;
						break;
					}
				}
				if (flg == false) {
					use = now;
				}
				//System.out.println(use);
				g += use * v[i];
				now -= use;
			}

			bw.write("Case #" + (t + 1) + ": " + g);
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}
}
