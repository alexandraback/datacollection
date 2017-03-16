package round1c_14;

import java.io.*;
import java.util.*;


public class PartElf {
	static BufferedReader in;
	static StringTokenizer st;
	static FileWriter out;
	
	static int getint() throws Exception {
		if (!st.hasMoreElements()) st = new StringTokenizer(in.readLine(), " \t\n\r\f/");
		return Integer.parseInt(st.nextToken());
	}
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader("src/round1c_14/A.in"));
		st = new StringTokenizer(in.readLine());
		out = new FileWriter("src/round1c_14/A.out");
		
		int T = getint();
		for (int t = 1; t <= T; t++) {
			long P = getint();
			long Q = getint();
			long g = gcd(P,Q);
			P/=g;
			Q/=g;
			
			int ans = 0;
			if (((~Q+1)&Q)==Q) {
				P = Long.highestOneBit(P);
				while (Q != P) {
					Q/=2;
					ans++;
				}
			}
			
			out.write(String.format("Case #%d: %s\n", t, ans == 0 ? "impossible" : Integer.toString(ans)));
		}
		
		in.close();
		out.close();
	}
	
	public static long gcd(long a, long b) {
		if (b < a) {long temp = a; a = b; b = temp;}
		if (a == 0) return b;
		b = b%a;
		return gcd(b, a);
	}
}
