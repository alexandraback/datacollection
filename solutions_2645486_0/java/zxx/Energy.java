import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Energy {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = parseInt(br.readLine());
		for (int i = 1; i <= T; i++) {
			String[] s = br.readLine().split(" ");
			int e = parseInt(s[0]), r = parseInt(s[1]), n = parseInt(s[2]);
			int[] v = new int[n];
			s = br.readLine().split(" ");
			for (int j = 0; j < n; j++) {
				v[j] = parseInt(s[j]);
			}
			int[][] mem = new int[n][e + 1];
			for (int j = 0; j <= e; j++) {
				int newE = Math.min(e, e - j + r);
				mem[0][newE] = j * v[0];
			}
			for (int k = 1; k < n; k++) {
				for (int j = 0; j <= e; j++) {
					for (int p = 0; p <= j; p++) {
						int newE = Math.min(e, j - p + r);
						mem[k][newE] = Math.max(mem[k][newE], mem[k - 1][j] + p * v[k]);
					}
				}
			}
			int res = mem[n - 1][0];
			for (int j = 0; j < mem[n - 1].length; j++) {
				res = Math.max(res, mem[n - 1][j]);
			}
			System.out.println("Case #" + i + ": " + res);
		}
	}
}
