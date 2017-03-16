package googleCodeJam_5_15_1B;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
	static String probName = "A";
	static boolean small = true;
	static Scanner in ;
		
	public static void main(String[] args) throws FileNotFoundException {
		System.err.println(Long.parseLong("000100"));
		System.setIn(new FileInputStream(new File(probName + "-" + ((small)? "small" : "large") + ".in")));
		System.setOut(new PrintStream(new File(probName + "-" + ((small)? "small" : "large") + ".out")));
		in = new Scanner(System.in);
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			long N = in.nextLong();
			System.out.printf("Case #%d: %d", t, getCount(N));
			System.out.println();
		}
	}
	
	static long[] tens = new long[20];
	
	static long getTens(int digs) {
		tens[1] = 1;
		tens[2] = 10;
		if (tens[digs] != 0) {
			return tens[digs];
		}
		long x = getCount((long)Math.pow(10, (digs-1)));
		tens[digs] = x;
		return x;
	}
	
	static long getCount(long N) {
		
		if (N <= 19) {
			return N;
		}
		
		int numDigs = ("" + N).length();
		String S = ("" + N);
		if (reverse(N) == 1){
			return getCount(N-1) + 1;			
		}
		if (S.charAt(S.length()-1) == '0') {
			return getCount(N-1) + 1;
		}

		long tot = getTens(numDigs);
		// not at 10^x + 1
		
		String front = S.substring(0, S.length() /2);
		String back = S.substring(S.length() / 2);
		if (!(reverse(getInt(front)) == 1)) {
			tot += getInt(reverse(front));	
			tot++;
		} else {
			tot++;
		}
		tot += getInt(back) - 1;
		return tot;
	}
	
	static long getInt(String s) {
		return Long.parseLong(s);
	}
	
	static String reverse(String s) {
		StringBuilder q = new StringBuilder();
		for (int i = 0; i < s.length(); i++) {
			q.append(s.charAt(s.length()-1-i));
		}
		return q.toString();		
	}
	
	static long reverse(long x) {
		String s = "" + x;
		StringBuilder q = new StringBuilder();
		for (int i = 0; i < s.length(); i++) {
			q.append(s.charAt(s.length()-1-i));
		}
		return getInt(q.toString());		
	}
}
