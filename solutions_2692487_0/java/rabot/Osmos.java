package r1b2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Osmos {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		Osmos obj = new Osmos();
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
			int A = Integer.parseInt(token.nextToken());
			int N = Integer.parseInt(token.nextToken());

			str = br.readLine();
			token = new StringTokenizer(str);
			long[] m = new long[N];
			for (int n = 0 ; n < N ; n++ ) {
				m[n] = Long.parseLong(token.nextToken());
			}
			Arrays.sort(m);

			int cur = 0;
			long size = A;
			int[] add = new int[N];
			int ans = N;
			if ( size > 1 ) {
				while (cur < N) {
					if ( cur == 0 ) {
						add[0] = 0;
					} else {
						add[cur] = add[cur - 1];
					}
					if (m[cur] < size) {
						size += m[cur];
						cur++;
						continue;
					} else {
						while (size <= m[cur]) {
							size += size - 1;
							add[cur]++;
						}
						size += m[cur];
						cur++;
						continue;
					}
				}
				for (int n = 0 ; n < N ; n++) {
					ans = Math.min(ans, add[n] + N - n - 1);
				}
			}

			bw.write("Case #" + (t + 1) + ": " + ans);
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}

}
