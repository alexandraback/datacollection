import java.io.*;
import java.util.*;

public class C_RecycledNumbers {
	static String name = "C-large";
	static boolean been[];

	static int f(int a, int b) {
		//System.out.println(a + " " + b);
		been[a] = true;
		int c = a;
		int num = 1, k = -1, ans = 1;
		while (c != 0) {
			c /= 10;
			num *= 10;
			k++;
		}
		num /= 10;
		c = a;
		for (int i = 0; i < k; i++) {
			int rem = a % 10;
			a /= 10;
			a += rem * num;
			if (a <= b && a >= c) {
				if (been[a])
					continue;
//				System.out.println(a+" "+c);
				been[a] = true;
				ans++;
			}
		}
		return ans * (ans - 1) / 2;

	}

	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(name + ".in"));
		PrintWriter out = new PrintWriter(name + ".out");
		int t = Integer.parseInt(in.readLine()), caseN = 1;
		been = new boolean[10000000];
		while (caseN <= t) {
			long ans = 0;
			StringTokenizer tok = new StringTokenizer(in.readLine());

			int a = Integer.parseInt(tok.nextToken()), b = Integer.parseInt(tok
					.nextToken());
			for (int i = a; i <= b; i++) {
				ans += f(i, b);
			}
			Arrays.fill(been, a, b + 10, false);

			out.print("Case #");
			out.print(caseN++);
			out.print(": ");
			out.println(ans);
		}
		out.flush();
	}
}
