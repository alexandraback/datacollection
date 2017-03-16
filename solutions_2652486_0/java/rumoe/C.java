package j2013.round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

@SuppressWarnings("all")
public class C {

	private static final boolean LOG = true;
	private static final String FILE_NAME = "C-small-1-attempt6";	
	
	private final String relativePath;
	{
		String p = getClass().getPackage().getName();
		p = p.replace('.', '\\');
		relativePath = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private final Scanner sc;
	private PrintWriter pw;
	
	public C () throws FileNotFoundException {
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
		int R = sc.nextInt();
		int N = sc.nextInt();
		int M = sc.nextInt();
		int K = sc.nextInt();
		writeln();
		outer:
		for (int i = 0; i < R; i++) {
			
			int[] p = new int[K];
			for (int j = 0; j < K; j++) {
				p[j] = sc.nextInt();
				if (p[j] > 25) {
					String s = tryloockup(p[j]);
					if (s != null) {
						write(s);
						writeln();
						continue outer;
					}
				}
			}
			
			int dig = 0;
			for(int q = 5; q >= 2 && q != 4; q--)
			for (int j = 0; j < K; j++) {
				if (p[j] == q) {
					dig++;
					write((int) q);
					for (int k = 0; k < K; k++) {
						double x = p[k] / q;
						if (x == (int)x)
						p[k] = (int) x;
					}
					continue;
				}
			}
			while (dig < N) {
				write(2 + (int) (Math.random() * 3));
				dig++;
			}
			writeln();
		}
	}
	
	private String tryloockup(int i) {
		String s = null;
		int res = 0;
		for (int a = 2; a <= 5; a++) {
			for (int b = a; b <= 5; b++) {
				for (int c = b; c <= 5; c++) {
					if (a*b*c == i) {
						s = ""+a+b+c;
						res++;
					}
				}
			}
		}
		
		if (res != 1) return null;
		return s;
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
			new C();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}