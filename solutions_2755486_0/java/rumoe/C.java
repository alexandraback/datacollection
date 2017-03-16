package j2013.r1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

@SuppressWarnings("all")
public class C {

	private static final boolean LOG = true;
	private static final String FILE_NAME = "C-small-attempt2";	
	
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
		int N = sc.nextInt();
		Tribe[] t = new Tribe[N];
		int[] tmpWall = new int[1000];
		int[] wall = new int[1000]; // 500 = 0
		for (int i = 0; i < N; i++) {
			Tribe tmp = new Tribe(sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt());
			t[i] = tmp;
		}
		
		int success = 0;
		boolean b;	
		boolean tsa = false;
		do {
			b = false;
			for (Tribe x : t) {
				int[] a = x.attackToday();
				
				if (a != null) {
					a[0] = a[0]* 2 + 500;
					a[1] = a[1]* 2 + 500;
					
					boolean sa = false;
					for (int p = a[0]; p <= a[1]; p++) {
						tmpWall[p] = Math.max(tmpWall[p], a[2]);
						if (tmpWall[p] > wall[p]) {
							sa = true;
							tsa = true;
						}
					}
					if (sa) success++;
				}
				
				if (x.attacksLeft()) {
					b  = true;
				}
			}
			
			//rebuild!
			if (tsa) {
				for (int i = 0; i < wall.length; i++) {
					wall[i] = Math.max(wall[i], tmpWall[i]);
				}
				tsa = false;
			}
			
		} while (b);
		write(success);
	}
	
	
	class Tribe {
		int dI;
		int pI;
		int sI;
		
		int w;
		int e;
		int d;
		int n;
		int s;
		
		Tribe (int d, int n, int w, int e, int s, int dd, int dp, int ds) {
			dI = dd;
			pI = dp;
			sI = ds;
			this.d = d;
			this.n = n;
			this.w = w;
			this.e = e;
			this.s = s;
		}
		
		public int[] attackToday() {
			int[] x  = null;
			if (n <= 0) return x;
			if (d-- <= 0) {
				x = new int[]{w,e,s};
				s += sI;
				w += pI;
				e += pI;
				d = dI - 1;
				n--;
			}
			
			return x;
		}
		public boolean attacksLeft(){return n >0; };
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
			new C();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}






















