package gcj2012R1C;

import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run(new Scanner(System.in));
	}

	void run(Scanner sc) {
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}

	void setInput(Scanner sc, int n, ArrayList<long[]> ns) {
		for(int i = 0; i < n; i++) {
			long a = sc.nextLong();
			long A = sc.nextLong();
			if(i != 0) {
				if(ns.get(ns.size() - 1)[0] == A) {
					ns.get(ns.size() - 1)[1] += a;
					continue;
				}
			}
			ns.add(new long[]{A, a});
		}
	}

	long solve2(ArrayList<long[]> ns, ArrayList<long[]> ms) {
		long[][] dp = new long[ns.size() + 1][ms.size() + 1];
		long res = 0;
		for(int i = 0; i < ns.size(); i++) {
			long[] n_val = ns.get(i);
			for(int j = 0; j < ms.size(); j++) {
				dp[i + 1][j + 1] = Math.max(dp[i + 1][j], dp[i][j + 1]);
				res = Math.max(res, dp[i + 1][j + 1]);
				long sum = 0;
				for(int l = i; l >= 0; l--) {
					long[] n2_val = ns.get(l);
					if(n2_val[0] == n_val[0]) sum += n2_val[1];
					long total = 0;
					for(int k = j; k >= 0; k--) {
						long[] m_val = ms.get(k);
						if(m_val[0] == n_val[0]) total += m_val[1];
						dp[i + 1][j + 1] = Math.max(
								dp[i + 1][j + 1], dp[l][k] + Math.min(total, sum));
						res = Math.max(dp[i + 1][j + 1], res);
//						System.out.println(i+" "+j+" "+k+":" + dp[i + 1][j + 1]);
					}
				}
			}
		}
		return res;
	}

	void solve(Scanner sc, int case_num) {
		int n = sc.nextInt();
		int m = sc.nextInt();
		ArrayList<long[]> ns = new ArrayList<long[]>();
		ArrayList<long[]> ms = new ArrayList<long[]>();
		
		setInput(sc, n, ns);
		setInput(sc, m, ms);
		
		long res = solve2(ns, ms);
		
		System.out.printf("Case #%d: ", case_num);
		System.out.println(res);
	}
}
