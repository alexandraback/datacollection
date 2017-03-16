package bullseye;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Bullseye {
	
	final static BigInteger TWO = new BigInteger("2");
	final static BigInteger THREE = new BigInteger("3");

	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("A-large.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream("large.out"));
		
		int T = Integer.parseInt(in.readLine());
		for (int CASE = 1; CASE <= T;CASE ++) {
			long r, t;
			StringTokenizer st = new StringTokenizer(in.readLine());
			r = Long.parseLong(st.nextToken());
			t = Long.parseLong(st.nextToken());
			
			
			BigInteger bt = new BigInteger(String.valueOf(t));
			BigInteger marked = new BigInteger("-1");
			StringBuilder sb = new StringBuilder("1");
			for (int i = 0;i < 62; i++)
				sb.append("0");
			BigInteger end = new BigInteger(sb.toString());
			BigInteger start = new BigInteger("1");
			
			boolean even = r % 2 == 1;
//			long rr = even ? (r / 2 ): (r / 2 - 1);
			BigInteger rrr = even ? new BigInteger(String.valueOf(r/2)) : new BigInteger(String.valueOf(r/2-1));
			BigInteger rr = even ? evenSum(rrr) : oddSum(rrr);
			
//			long end = 1 << 62;
//			long start = 1;
			
			while (true) {
				if (end.compareTo(start) == 0)
					break;
//				long init = (end + start) / 2;
				BigInteger init = end.add(start).divide(TWO);
				BigInteger x = even ? evenSum(init) : oddSum(init);
				x = x.subtract(rr);
				if (x.equals(bt)) {
					marked = init;
					break;
				}
				if (x.compareTo(bt) < 0) {
					marked = init;
					start = init.add(BigInteger.ONE);
					continue;
				}
				if (x.compareTo(bt) > 0) {
					end = init;
					continue;
				}
			}
			
			System.out.println();
			out.println("Case #"+CASE+": " + marked.subtract(rrr).longValue() );
		}
		
		
		out.close();
		in.close();
	}
	
	public static long evenSum(long i ) {
		return 2 * i * i + i;
	}
	
	public static long oddSum(long i ) {
		return 2 * i * i + 3 * i;
	}
	
	public static BigInteger evenSum(BigInteger i ) {
		return i.multiply(i).multiply(TWO).add(i);
	}
	
	public static BigInteger oddSum(BigInteger i ) {
		return i.multiply(i).multiply(TWO).add(i.multiply(THREE));
	}
	
	
}
