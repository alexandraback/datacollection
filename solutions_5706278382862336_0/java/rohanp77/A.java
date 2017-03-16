import java.io.*;
import java.util.*;

public class A {
	static StringTokenizer st;
	static BufferedReader in;
	static PrintWriter out;
	
	static String nextToken() throws IOException {
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader("A.in"));
		out = new PrintWriter(new FileWriter("A.out"));
		
		long[] powersOf2 = new long[41];
		powersOf2[0] = 1;
		for (int i=1; i<powersOf2.length; i++)
			powersOf2[i] = powersOf2[i-1]*2;
		
		int ttt = nextInt();
		outer: for (int tt=1; tt<=ttt; tt++) {
			out.printf("Case #%d: ", tt);
			
			st = new StringTokenizer(in.readLine(), "/");
			
			long numer = nextLong();
			long denom = nextLong();
			long d = gcd(numer, denom);
			numer /= d; denom /= d;
			
			if (Arrays.binarySearch(powersOf2, denom) < 0) {
				out.println("impossible");
				continue;
			}
			
			for (int i=1; i<powersOf2.length; i++)
				if (denom <= numer * powersOf2[i]) {
					out.println(i);
					continue outer;
				}
			
			out.println("impossible");
		}
		
		out.close();
	}

	private static long gcd(long a, long b) {
		if (a > b) return gcd(b,a);
		if (a==0) return b;
		return gcd(b%a, a);
	}
}
