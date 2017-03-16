package j2013.r1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

@SuppressWarnings("all")
public class A {

	private static final boolean LOG = true;
	private static final String FILE_NAME = "A-large";	
	
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
		long A = sc.nextInt();
		int N = sc.nextInt();
		long[] m = new long[N];
		for (int i = 0; i < m.length; i++) {
			m[i] = sc.nextInt();
		}
		
		int o = 0;
		Arrays.sort(m);
		
		if (A == 1) {
			write(m.length);
			return;
		}
		
		for (int i = 0; i < m.length; i++) {
			
			if (m[i] < A) {
				A+=m[i];
				continue;
			}
			
			if (A + A-1 > m[i]) {
				A += A-1;
				A += m[i];
				o++;
				continue;
			}
			
			int min = Integer.MAX_VALUE;
			for (int k = 0; i <= m.length - k ; k++) {
				long t = A;
				int x = 0;
				for (int j = i; j < m.length - k; j++) {
					while (t <= m[j]) {
						t += t-1; 
						x++;
					}
					t += m[j];
				}
				x += k;
				min = Math.min(x, min);
			}
			o += min;
			break;
		}
		
		write(o);
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
			new A();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}






















