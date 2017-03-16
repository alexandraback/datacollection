import java.io.*;
import java.math.*;
import java.util.*;

public class Bullseye {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;
	
	static String nextToken() throws IOException {
		while (st==null || !st.hasMoreElements())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	static String NAME = "bullseye";
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader(NAME+".in"));
		out = new PrintWriter(new FileWriter(NAME+".out"));
		
		int tt = nextInt();
		for (int t=1; t<=tt; t++) {
			out.printf("Case #%d: ", t);
			
			long rad = nextLong(), paint = nextLong();
			long min = 1, max = paint;
			while (min+1<max) {
				long mid = (max+min)/2;
				BigInteger poss = calc(mid, rad);
				if (poss.compareTo(toBig(Long.MAX_VALUE)) > 0) {
					max = mid;
					continue;
				}
				if (poss.longValue() <= paint)
					min = mid;
				if (poss.longValue() >= paint)
					max = mid;
			}
			out.println(min);
		}
		
		in.close();
		out.close();
	}

	private static BigInteger calc(long mid, long rad) {
		BigInteger result = toBig(mid).add(toBig(rad));
		result = result.multiply(toBig(2));
		result = result.subtract(toBig(1));
		result = result.multiply(toBig(mid));
		return result;
	}
	
	private static BigInteger toBig(long x) {
		return new BigInteger(String.valueOf(x));
	}
}
