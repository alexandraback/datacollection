package j2016.r1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;

@SuppressWarnings("all")
public class A {

	private static final String FILE_NAME = "A-large";	
	
	private static final String RELATIVE_PATH;
	static {
		String p = A.class.getPackage().getName();
		p = p.replace('.', '\\');
		RELATIVE_PATH = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private Scanner in;
	private PrintStream out;
	
	public A () throws FileNotFoundException {
		in = new Scanner(new File(RELATIVE_PATH + ".in"));	
		out = new PrintStream(RELATIVE_PATH + ".out"); 
			
		int cases = nextInt();	
		for (int i = 1; i <= cases; i++) {
			print("Case #" + i + ": ");
			solve();
			println();
		}	

		out.close();
		System.out.println("\nDONE!");
	}
	
	String[] ss = {
			"ZERO",
			"ONE",
			"TWO",
			"THREE",
			"FOUR",
			"FIVE",
			"SIX",
			"SEVEN",
			"EIGHT",
			"NINE",
	};
	
	int[] xx = {0,2,8,3,4,5,6,1,9,7};
	
	private void solve() {
		char[] X = next().toCharArray();
		
		int[] h = new int[256];
		for (char x : X) {
			h[x]++;
		}
		
		int[] digits = new int[10];
		
		char[] m = "ZWGHUFXOIS".toCharArray();
		for (int i = 0; i < 10; i++) {
			int c = h[m[i]];
			digits[xx[i]] = c;
			h = sub(h, ss[xx[i]], c);
		}
		
		String s = "";
		for (int i = 0; i < digits.length; i++) {
			for (int v = 0; v < digits[i]; v++) {
				s += Integer.toString(i);
			}
		}
		print(s);
	}
	
	int[] sub(int[] hist, String s, int c) {
		for (char t : s.toCharArray()) {
			hist[t] -= c;
		}
		return hist;
	}
	
	
	
	/*
	 * Manage input
	 */
	private String next() {
		return in.next();
	}
	private int nextInt() {
		return in.nextInt();
	}
	private long nextLong() {
		return in.nextLong();
	}

	/*
	 * Manage output
	 */
	private void print(String s) { 
		System.out.print(s);
		out.print(s); 
	}	
	private void print(int i) { 
		System.out.print(i);
		out.print(i); 
	}	
	private void print(Object o) {
		System.out.print(o);
		print(o);
	}
	private void println() { 
		System.out.println();
		out.println(); 
	}
	
	public static void main(String[] args) {
		try {
			new A();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
