package j2013.r1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

@SuppressWarnings("all")
public class B {

	private static final boolean LOG = true;
	private static final String FILE_NAME = "B-small-attempt2";	
	
	private final String relativePath;
	{
		String p = getClass().getPackage().getName();
		p = p.replace('.', '\\');
		relativePath = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private final Scanner sc;
	private PrintWriter pw;
	
	public B () throws FileNotFoundException {
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
		System.out.println(fac(4));
	}
	
	private void solve() {
		int N = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		
		int t = Math.abs(X) + Math.abs(Y);
		
		if (t >= 8){
			write(0.0);
			return;
		}
		if (t == 0) {
			write(1.0); return;
		}
		
		if (t == 2) {
			if (N >= 6) {
				write(1.0); return;
			} else if (N <= 1) {
				write(0.0); return;
			} else if (X == 0){
				write(0.0); return;
			}
			N -= 1;
		}
		
		if (t == 4) {
			if (N >= 15) {
				write(1.0); return;
			} else if (N <= 6) {
				write(0.0); return;
			} else if (X == 0){
				write(0.0); return;
			}
			N -= 6;
		}
		
		if (t == 6) {
			if (N <= 15) {
				write(0.0); return;
			} else if (X == 0){
				write(0.0); return;
			}
			N -= 15;
		}
		if (N == 0) {
			write(0.0);
			return;
		}
		
		
		double pob = 0;
		for (int q = Y + 1 ; q <= N; q++) {
			pob += comb(N, q)* Math.pow(0.5, N-q)* Math.pow(0.5, q);
		}
		
		write(pob);
	}
	
	private long comb(int n, int k) {
		if (n == k) return 1;
		return fac(n) /(fac(n-k)*fac(k));
	}
	
	public long fac(int n){
		if( n == 0) return 1;
	  long x = n;
	  for (int i = n - 1; i >= 1; i--) {
		  x *= i;
	  }
	  return x;
	}
	
	private void write(double d) {
		write(Double.toString(d));
	}
	
	private void write(long l) {
		write(Long.toString(l));
	}
	private void write(int i) {
		write(Integer.toString(i));
	}
	
	private void write(char c) {
		write(Character.toString(c));
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
			new B();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}






















