import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class Bullseye {
	public static BufferedReader BR;
	
	public static String readLine() {
		try {
			return BR.readLine();
		} catch(Exception E) {
			System.err.println(E.toString());
			return null;
		}
	}
	
	
	// ****** MAIN ******
	
	public static void main(String [] args) throws Exception {
		BR = new BufferedReader(new InputStreamReader(System.in));
	
		int testcases = Integer.parseInt(readLine());
		for (int t = 1; t <= testcases; t++) {
			Bullseye instance = new Bullseye();
			instance.solve(t);
		}
	
	}
	
	// ****** GLOBAL VARIABLES ******
	
	
	
	public Bullseye() {
	}
	
	public boolean canPaint(long r, long t, long n) {
		BigInteger two = BigInteger.valueOf(2);
		BigInteger rr = BigInteger.valueOf(r);
		BigInteger tt = BigInteger.valueOf(t);
		BigInteger nn = BigInteger.valueOf(n);
		BigInteger volume = nn.multiply(nn.multiply(two).add(rr.multiply(two)).subtract(BigInteger.ONE));
		return volume.compareTo(tt) <= 0;
	}
	
	public boolean solve(int caseNumber) {
		StringTokenizer st = new StringTokenizer(readLine());
		long r = Long.parseLong(st.nextToken());
		long t = Long.parseLong(st.nextToken());
		long lo = 1, hi = t+1;
		while (lo < hi) {
			long mid = lo + (hi-lo)/2;
			if (canPaint(r, t, mid)) {
				lo = mid+1;
			} else {
				hi = mid;
			}
		}
		lo = Math.max(1, lo-10);
		while (canPaint(r, t, lo)) ++lo;
		System.out.println("Case #" + caseNumber + ": " + (lo-1));
		return false;
	}


}
