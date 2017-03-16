package r1a2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class ManageYourEnergy2 {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		ManageYourEnergy2 obj = new ManageYourEnergy2();
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
			int[] v = new int[N];
			int[] max = new int[100];
			for (int i = 0; i < N; i++) {
				v[i] = Integer.parseInt(token.nextToken());
				max[i / 100] = Math.max(v[i], max[i / 100]);
			}

			int g = solve(E, R, v, E, 0, 0);

			bw.write("Case #" + (t + 1) + ": " + g);
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}

	public int solve(int E,int R,int[] v,int now,int pos,int nowG) {
		now = Math.min(E, now + R);
		if (pos == v.length - 1) {
			return nowG + now * v[pos];
		}
		int max = 0;
		for (int i = 0; i <= now; i++) {
			int ret = solve(E, R, v, now - i, pos + 1, nowG + i * v[pos]);
			max = Math.max(max, ret);
		}
		return max;
	}
}
