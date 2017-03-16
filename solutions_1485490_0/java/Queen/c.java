package r1_20122506;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class PC {

	static Scanner sc = new Scanner(new BufferedInputStream(System.in));
	static PrintWriter pw = new PrintWriter(
			new BufferedOutputStream(System.out));

	static long[][] box, toy;
	static int n, m;

	public static void main(String[] args) {
		int test = sc.nextInt();
		for (int ti = 1; ti <= test; ti++) {
			n = sc.nextInt();
			m = sc.nextInt();
			box = new long[n][2];
			toy = new long[m][2];

			for (int i = 0; i < n; i++) {
				box[i][0] = sc.nextLong();
				box[i][1] = sc.nextLong();
			}
			for (int j = 0; j < m; j++) {
				toy[j][0] = sc.nextLong();
				toy[j][1] = sc.nextLong();
			}

			pw.println("Case #" + ti + ": " + _try(0, 0));
		}
		pw.flush();
	}

	static long _try(int i, int j) {
		if (i == n || j == m)
			return 0;

		if (box[i][1] == toy[j][1]) {
			
			if (box[i][0] == toy[j][0])
				return _try(i + 1, j + 1) + box[i][0];
			else if (box[i][0] < toy[j][0]) {
				toy[j][0] -= box[i][0];
				long res = _try(i + 1, j);
				toy[j][0] += box[i][0];
				return res + box[i][0];
			} else {				
				box[i][0] -= toy[j][0];
				long res = _try(i, j + 1);
				box[i][0] += toy[j][0];
				return res + toy[j][0];
			}
			
		} else {
			long tmp1 = 0, tmp2 = 0;
			tmp1 = _try(i + 1, j);
			tmp2 = _try(i, j + 1);

			return Math.max(tmp1, tmp2);
		}
	}
}
