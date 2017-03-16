package j2013.round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

@SuppressWarnings("all")
public class B {

	private static final boolean LOG = true;
	private static final String FILE_NAME = "B-small-attempt0";	
	
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
		int E = sc.nextInt();
		int R = sc.nextInt();
		int N = sc.nextInt();
		
		int[] v = new int[N];
		for (int i = 0; i < N; i++) {
			v[i] = sc.nextInt();
		}
		
		write(energy(0,E,E,R,v));
	}
	
	private int energy(int i, int e, int E, int R, int[] N) {
		if (i >= N.length) return 0;
		int max = 0;
		
		for (int x = 0; x <= e; x++) {
			int tmp = N[i]*x + energy(i+1, Math.min(e - x + R, E), E,  R, N); 
			max = Math.max(tmp, max);
		}
		return max;
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