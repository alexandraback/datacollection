package r1b2016;

import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("C.out"));
		
		for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int n = in.nextInt();
			String[][] s = new String[n][2];
			for (int i = 0; i < n; i++) {
				s[i][0] = in.next();
				s[i][1] = in.next();
			}
			
			int ans = 0;
			for (int mask = 0; mask < (1 << n); mask++) {
				Set<String> o1 = new HashSet<>();
				Set<String> o2 = new HashSet<>();
				for (int i = 0; i < n; i++) {
					if (((mask >> i)&1) != 0) {
						o1.add(s[i][0]);
						o2.add(s[i][1]);
					}
				}
				boolean possible = true;
				for (int i = 0; i < n && possible; i++) {
					if (((mask >> i)&1) == 0) {
						if (!o1.contains(s[i][0])) {
							possible = false;
						}
						if (!o2.contains(s[i][1])) {
							possible = false;
						}
					}
				}
				if (possible) {
					ans = Math.max(ans, n - Integer.bitCount(mask));
				}
			}
			
			out.println(ans);
		}

		out.flush();
	}

}
