package j2015.round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;

@SuppressWarnings("all")
public class A {

	private static final String FILE_NAME = "A-small-attempt5";	
	
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
	
	private void solve() {
		long N = nextLong();


		print(getTo(N));
	}
	
	private long getTo(long N) {
		if (N % 10 == 0) {
			return getTo(N-1) + 1;
		}
		if (N < 20) { 
			return N;
		}
		
		String number = Long.toString(N);
		int half = number.length() / 2;
		String first = number.substring(0, half);
		boolean needFlip = true;
		if (Integer.parseInt(first) == Math.pow(10, half-1)) {
			needFlip = false;
		}
		
		char[] digits = number.toCharArray();
		
		long base = 1 + getTo((long) (Math.pow(10, digits.length-1)-1));
		

		long numbers = 0;
		for (int i = 0; i < half; i++) {
			numbers += Character.getNumericValue(digits[i])*Math.pow(10, i);
		}

		for (int i = digits.length-1; i >= half; i--) {
			numbers += Character.getNumericValue(digits[i])*Math.pow(10, digits.length-1-i);
		}
		
		if (needFlip == false) numbers--;
		
		return numbers + base;
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
	private void print(long i) { 
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
