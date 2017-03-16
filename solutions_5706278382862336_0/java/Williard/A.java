package codejam2014round1c;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {
	static long gcf(long a, long b) {
		return (b == 0 ? a : gcf(b, a % b));
	}
	static boolean poweroftwo(long a) {
		return ((a & (a -1)) == 0);
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder out = new StringBuilder();
		StringTokenizer st;
		int numcases = Integer.parseInt(br.readLine().trim());
		long p, q, gcd, limit = (1 << 20);
		limit = limit * limit;
		for (int casenum = 1; casenum <= numcases; casenum++) {
			st = new StringTokenizer(br.readLine());
			p = Long.parseLong(st.nextToken("/"));
			q = Long.parseLong(st.nextToken("/"));
			gcd = gcf(p,q);
			p = p / gcd;
			q = q / gcd;
			out.append(String.format("Case #%d: ", casenum));
			if (poweroftwo(q) && (q <= limit)) {
				int ans = 0;
				while (q > p) {
					ans++;
					q = (q / 2);
				}
				if (ans == 0)
					ans = 1;
				out.append(ans);
			}
			else {
				out.append("impossible");
			}
			out.append('\n');
		}
		System.out.print(out);
	}
}
