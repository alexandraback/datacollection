package round1c_14;

import java.io.*;
import java.util.*;


public class Enclosure {
	static BufferedReader in;
	static StringTokenizer st;
	static FileWriter out;
	
	static int getint() throws Exception {
		if (!st.hasMoreElements()) st = new StringTokenizer(in.readLine());
		return Integer.parseInt(st.nextToken());
	}
	
	static int N, M, K;
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader("src/round1c_14/C.in"));
		st = new StringTokenizer(in.readLine());
		out = new FileWriter("src/round1c_14/C.out");
		//out2 = new FileWriter("src/round1c_14/B2.out");
		
		int T = getint();
		for (int t = 1; t <= T; t++) {
			N = getint(); M = getint(); K = getint();
			if (M < N) {int temp = N; N = M; M = temp;}
			int X = N*M;
			
			int ans = bs(0, X+1);
			
			out.write(String.format("Case #%d: %s\n", t, Integer.toString(ans)));
		}
		
		in.close();
		out.close();
	}
	
	public static int bs(int s, int e) {
		if (e <= s) return -1;
		int m = (s+e)/2;
		if (help(m)) {
			int ans = bs(s, m);
			if (ans == -1) return m;
			else return ans;
		} else {
			return bs(m+1, e);
		}
	}
	
	public static boolean help(int k) {
		if (k >= K) return true;
		for (int a = 1; a < N-1; a++) {
			for (int b = 1; b < M-1; b++) {
				if (stones(a,b) <= k && (k + a*b) >= K) return true; 
			}
		}
		return false;
	}
	
	public static int stones(int x, int y) {
		return 2*x + 2*y;
	}
}
