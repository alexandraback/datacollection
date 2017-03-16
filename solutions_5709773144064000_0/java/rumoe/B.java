package j2014.qual;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

@SuppressWarnings("all")
public class B {

	private static final String FILE_NAME = "B-small-attempt0";	
	
	private static final String RELATIVE_PATH;
	static {
		String p = B.class.getPackage().getName();
		p = p.replace('.', '\\');
		RELATIVE_PATH = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private Scanner in;
	private PrintStream out;
	
	public B () throws FileNotFoundException {
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
		double C = nextDouble();
		double F = nextDouble();
		double X = nextDouble();
		
		int farmCount = 0;
		
		double elapsedTime = 0;
		double prevTime = X / 2;
		double nextTime;
		while (true) {
			elapsedTime += C / (farmCount * F + 2);
			farmCount++;
			
			nextTime = elapsedTime + X / (farmCount * F + 2);
			
			if (nextTime >= prevTime) {
				break;
			} else {
				prevTime = nextTime;
			}
		}
		
		print(prevTime, 7);
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
	private double nextDouble() {
		return Double.parseDouble(in.next());
	}
	
	/*
	 * Manage output
	 */	
	private void print(double d, int precision) {
		String formatString = "%1$." + precision + "f";
		print(String.format(Locale.ENGLISH, formatString, d));
	}
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
			new B();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
