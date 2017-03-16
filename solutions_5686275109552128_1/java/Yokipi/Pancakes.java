package codejam2015;

import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;


public class Pancakes {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st = null;
	
	static Integer nextInt() throws Exception {
		if (st == null || !st.hasMoreElements()) {
			String s = in.readLine();
			if (s == null) return null;
			st = new StringTokenizer(s);
		}
		return parseInt(st.nextToken());
	}
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader(new File("src/codejam2015/b.in")));
		out = new PrintWriter(new FileWriter(new File("src/codejam2015/b.out")));
		
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			
			int D = nextInt();
			int[] P = new int[D];
			for (int i = 0; i < D; i++) {
				P[i] = nextInt();
			}
			
			Arrays.sort(P);
			int i = 0;
			int ans = 9999999;
			for (int min = 1; min < 1001; min++) {
				if (i >= D) break;
				while (i < D && P[i] <= min) i++;
				
				int res = min;
				for (int j = i; j < D; j++) {
					int x = P[j];
					int y = x/min;
					if (x%min == 0) y--;
					res += y;
				}
				
				ans = Math.min(ans, res);
			}
			
			
			out.printf("Case #%d: %d\n", t+1, ans);
		}
		
		in.close();
		out.close();
	}
}
