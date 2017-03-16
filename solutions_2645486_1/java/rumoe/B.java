package j2013.round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

@SuppressWarnings("all")
public class B {

	private static final boolean LOG = true;
	private static final String FILE_NAME = "B-large";	
	
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
	}
	
	private void solve() {
		long E = sc.nextInt();
		long R = sc.nextInt();
		int N = sc.nextInt();
		
		long[] v = new long[N];
		for (int i = 0; i < N; i++) {
			v[i] = sc.nextInt();
		}
		
		long total = 0;
		long currentE = E;
		outer:
		for (int i = 0; i < N; i++) {
			currentE = Math.min(E, currentE + R);
			
			long tmpE = currentE;
			for (int j = i + 1; j < N; j++) {
				tmpE = tmpE + R;
				
				if (v[j] > v[i] && tmpE <= E) {
					continue outer;
				} else if (v[j] > v[i] && tmpE > E) {
					total += v[i] * (tmpE - E);
					currentE -= Math.min(currentE, tmpE - E);
					if (currentE < 0) System.err.println("fsf");
					continue outer;
				} else if (tmpE - E > currentE) {
					total += v[i] * currentE;
					currentE = 0;
					continue outer;
				}	
			}
			
			total += v[i] * currentE;
			currentE = 0;
		}
		
		write(total);
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
			new B();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}