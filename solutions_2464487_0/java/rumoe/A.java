package j2013.round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

@SuppressWarnings("all")
public class A {

	private static final boolean LOG = true;
	private static final String FILE_NAME = "A-small-attempt0";	
	
	private final String relativePath;
	{
		String p = getClass().getPackage().getName();
		p = p.replace('.', '\\');
		relativePath = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private final Scanner sc;
	private PrintWriter pw;
	
	public A () throws FileNotFoundException {
		sc = new Scanner(new File(relativePath + ".in"));	
		pw = new PrintWriter(relativePath + ".out"); 
			
		int cases = sc.nextInt();	
		for (int i = 1; i <= cases; i++) {
			write("Case #" + i + ": ");
			solve();
			writeln();
		}	

		pw.close();
		System.out.println("\nDONE!");
	}
	
	private void solve() {
		long r = sc.nextLong();
		long t = sc.nextLong();

		long n = 1;
		while (n*2*r+n*n*2-1*n <= t) {
			n++;
		}
		
		write(n-1);
	}
	
	private void write(long i) {
		write(Long.toString(i));
	}
	private void write(int i) {
		write(Integer.toString(i));
	}
	
	private void write(String s) {
		pw.write(s);
		if(LOG) System.out.print(s);
	}
	
	private void writeln() {
		write("\n");
	}
	
	public static void main(String[] args) {
		try {
			new A();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}






















