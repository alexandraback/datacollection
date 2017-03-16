import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class ProblemB {
	public static void main(String[] args) throws Throwable {
		Scanner in = new Scanner(new File("b.in"));
		PrintWriter out = new PrintWriter("b.out");
		int testCount = Integer.parseInt(in.nextLine().trim());
		for (int i = 0; i < testCount; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve(in, out);
		}
		out.close();
	}

	static void solve(Scanner in, PrintWriter out) {
		int n = in.nextInt();
		int m = in.nextInt();
		int p = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		sort(a);
		int ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			int z = (a[i] + 2) / 3;
			if (z >= p) {
				++ans;
				continue;
			}
			if (p >= 2 && z == p - 1 && a[i] % 3 != 1 && m > 0) {
				--m;
				++ans;
			} else {
				break;
			}
		}
		out.println(ans);
	}
}
