import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;


public class C {
	
	int[] p;
	int[] f;
	ArrayList<Integer> al;
	int[] dd;
	
	private int solve(int C, int[] D, int V) {
		dd = D;
		int c = 0;
		if (dd[0] != 1) {
			int[] d = new int[dd.length + 1];
			for (int i = 1; i < d.length; i++) {
				d[i] = dd[i-1];
			}
			d[0] = 1;
			dd = d;
			c++;
		}
		f = new int[V + 1];
		p = new int[dd.length];
		// vyplni f
		generuj(0);
		
		al = new ArrayList<Integer>();
		for (int i = 1; i < f.length; i++) {
			if (f[i] == 0) {
				al.add(i);
			}
		}
		
		while(!al.isEmpty()) {
			
			TreeSet<Integer> ts = new TreeSet<Integer>();
			
			for (int i = 0; i < dd.length; i++) {
				ts.add(dd[i]);
			}
			
			for (int i = 0; i < dd.length; i++) {
				System.out.print(dd[i]);
			}
			System.out.println();
			
			for (int i = 0; i < f.length; i++) {
				System.out.print(f[i]);
			}
			System.out.println();
			
			pridajD(al, ts);
						
			c++;
			f = new int[V + 1];
			p = new int[dd.length];
			generuj(0);
			
			al = new ArrayList<Integer>();
			for (int i = 1; i < f.length; i++) {
				if (f[i] == 0) {
					al.add(i);
				}
			}
		}		
		return c;
	}
	
	private void pridajD(ArrayList<Integer> al, TreeSet<Integer> ts) {
		int m = Integer.MIN_VALUE;
		int index = 0;
		for (int j = 1; j < 31; j++) {
			if (!ts.contains(j)) {
				int staci = 0;
				for (int i = 0; i < al.size(); i++) {
					int x = al.get(i);
					if (x-j >= 0) {
						if (f[x-j] == 1) {
							staci++;
						}
					}
				}
				if (staci > m) {
					m = staci;
					index = j;
				}
			}
		}
		
		ArrayList<Integer> D = new ArrayList<Integer>();
		for (int i = 0; i < dd.length; i++) {
			D.add(dd[i]);
		}
		D.add(index);
		dd = new int[D.size()];
		for (int i = 0; i < dd.length; i++) {
			dd[i] = D.get(i);
		}
		
		Arrays.sort(dd);
	}

	private void can(int[] d, int c) {
		/*for (int j = d.length - 1; j >= 0; j++) {
			for (int k = 0; k < c; k++) {
				if (i - d[j] >= 0) {
					i = i - d[j];
				}
			}
		}
		return 0;*/
		
	}
	
	private void generuj(int odIndexu) {
		if (p.length == odIndexu) {
			int c = 0;
			for (int i = 0; i < p.length; i++) {
				if (p[i] == 1) {
					c += dd[i];
				}
			}
			if (0 < c && c < f.length) {
				f[c] = 1;
			}
			return;
		}
		for (int i = 0; i < 2; i++) {
			p[odIndexu] = i;
			generuj(odIndexu + 1);
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		C cc = new C();
		Scanner s = new Scanner(new File("inC.in"));
		PrintWriter pw = new PrintWriter(new File("outC.out"));
		int c = s.nextInt();
		for (int i = 0; i < c; i++) {
			int C = s.nextInt();
			int D = s.nextInt();
			int V = s.nextInt();
			int[] d = new int[D];
			for (int j = 0; j < D; j++) {
				d[j] = s.nextInt();
			}
			pw.println("Case #" + (i + 1) + ": " + cc.solve(C, d, V));
		}
		pw.close();
	}	
}
