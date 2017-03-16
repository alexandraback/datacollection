package qual2012;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("B.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			int n = in.nextInt(), s = in.nextInt(), p = in.nextInt();
			int ans = 0;
			for (int i = 0; i < n; i++) {
				int x = in.nextInt();
				if ((x+2)/3 >= p) {
					ans++;
				}
				else if (s > 0 && can(x, p)) {
					s--;
					ans++;
				}
			}
			out.println("Case #" + cs + ": " + ans);
		}
		
		out.flush();
	}

	static boolean can(int x, int y) {
		if (x == 0) return y == 0;
		int max = (x+2)/3;
		if (x%3 != 1) {
			max++;
		}
		return max <= 10 && max >= y;
	}
}
