package gcj2012R1C;

import java.io.*;
import java.util.*;

public class CSmall {
	public static void main(String[] args) {
		new CSmall().run(new Scanner(System.in));
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
	
	long solve1(ArrayList<long[]> ns, ArrayList<long[]> ms) {
		long[] n_val = ns.get(0);
		long res = 0;
		for(long[] m_val : ms) if(m_val[0] == n_val[0]) res += m_val[1];
		res = Math.min(res, n_val[1]);
		return res;
	}

	long solve2(ArrayList<long[]> ns, ArrayList<long[]> ms) {
		long[][] dp = new long[ns.size() + 1][ms.size() + 1];
		long res = 0;
		for(int i = 0; i < ns.size(); i++) {
			long[] n_val = ns.get(i);
			for(int j = 0; j < ms.size(); j++) {
				long total = 0;
				dp[i + 1][j + 1] = Math.max(dp[i + 1][j], dp[i][j + 1]);
				res = Math.max(res, dp[i + 1][j + 1]);
				for(int k = j; k >= 0; k--) {
					long[] m_val = ms.get(k);
					if(m_val[0] == n_val[0]) total += m_val[1];
					dp[i + 1][j + 1] = Math.max(
							dp[i + 1][j + 1], dp[i][k] + Math.min(total, n_val[1]));
					res = Math.max(dp[i + 1][j + 1], res);
//					System.out.println(i+" "+j+" "+k+":" + dp[i + 1][j + 1]);
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
		
		long res = 0;
		if(ns.size() == 1) {
			res = solve1(ns, ms);
		} else if(ns.size() == 2) {
			res = solve2(ns, ms);
		} else {
			if(ns.get(0)[0] == ns.get(2)[0]) {
				ArrayList<long[]> ns2 = new ArrayList<long[]>();
				ns2.add(new long[]{ns.get(0)[0], ns.get(0)[1] + ns.get(2)[1]});
				res = solve1(ns2, ms);

//				ArrayList<long[]> ns3 = new ArrayList<long[]>();
//				ns3.add(ns.get(1));
//				res = Math.max(res, solve1(ns3, ms));
//				System.out.println("#"+res+" "+(ns.get(0)[1] + ns.get(2)[1]));
			}
			res = Math.max(res, solve2(ns, ms));
		}
		
		System.out.printf("Case #%d: ", case_num);
		System.out.println(res);
	}
}
