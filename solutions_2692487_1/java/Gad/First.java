import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class First {
	static int all[];
	static int res = 1 << 30;

	static int maxSize = 1000000;

	static void solve(int size, int i, int op) {

		if (op >= res)
			return;
		if (size > maxSize) {
			res = Math.min(res, op);
			return;
		}
		if (i == all.length) {
			res = Math.min(res, op);
			return;
		}
		if (size > all[i])
			solve(size + all[i], i + 1, op);
		else {
			if (size > 1)
				solve(size + size - 1, i, op + 1);
			solve(size, i + 1, op + 1);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader buff = new BufferedReader(new FileReader("test"));
		int t = new Integer(buff.readLine().trim());
		for (int I = 1; I <= t; I++) {
			StringTokenizer tok = new StringTokenizer(buff.readLine());
			int size = new Integer(tok.nextToken()), n = new Integer(
					tok.nextToken());
			all = new int[n];
			tok = new StringTokenizer(buff.readLine());
			for (int i = 0; i < all.length; i++)
				all[i] = new Integer(tok.nextToken());

			Arrays.sort(all);
			res = 1 << 30;
			if (size == 1 && all[0] > 1)
				System.out.println("Case #" + I + ": " + n);
			else {
				solve(size, 0, 0);
				System.out.println("Case #" + I + ": " + res);
			}
		}
	}
}
