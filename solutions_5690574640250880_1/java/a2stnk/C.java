package cj2014.q;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc;
	PrintWriter pw;
	int R, C, M;
	
	public class Pair implements Comparable<Pair>{
		int i, v;
		public Pair(int i, int v) {
			this.i = i;
			this.v = v;
		}
		public int compareTo(Pair p) {
			return this.i - p.i;
		}
	}
	
	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"C-large";

		try {
			new C().run(filePrefix);
		} catch(Exception e) {
			System.err.println("file read error");
		}
	}
	
	public void run(String filePrefix) throws Exception {
		sc = new Scanner(new FileReader(filePrefix + ".in"));
		pw = new PrintWriter(new FileWriter(filePrefix + ".out"));
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			read(sc);
			pw.print("Case #" + test + ": ");
			System.out.print("Case #" + test + ": ");
			solve();
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
		
	}
	
	void read(Scanner sc) {
		R = sc.nextInt();
		C = sc.nextInt();
		M = sc.nextInt();
	}
	
	void print(Object s) {
		pw.print(s);
		System.out.print(s);
	}
	
	void println(Object s) {
		pw.println(s);
		System.out.println(s);
	}	
	
	public void solve() {
		boolean conv=false;
		if(C<R) {
			int temp = C;
			C = R;
			R = temp;
			conv = true;
		}
		boolean[][] mine = new boolean[R][C];
		
		if(R==1) {
			for(int i=0; i<M; i++)
				mine[0][i]=true;
		} else if(R==2) {
			if(M<=2*(C-2) && M%2==0) {
				for(int i=0; i<M/2; i++) {
					mine[0][i] = true;
					mine[1][i] = true;
				}
			} else if(M==R*C-1) {
				for(int i=0; i<C-1; i++) {
					mine[0][i] = true;
					mine[1][i] = true;
				}
				mine[0][C-1] = true;
			} else {
				println("\nImpossible");
				return;
			}
		} else {
			for(int i=0; i<R-2; i++)
				for(int j=0; j<C-2; j++)
					if(M>0) {
						mine[i][j] = true;
						M--;
					}

			for(int i=0; i<R-3; i++) {
				if(M>0) {
					mine[i][C-2] = mine[i][C-1] = true;
					M-=2;
				}
			}
			for(int i=0; i<C-3; i++) {
				if(M>0) {
					mine[R-2][i] = mine[R-1][i] = true;
					M-=2;
				}
			}
			if(M==-1) {
				mine[R-3][C-3] = false;
				M++;
			}
			if(M>=2) {
				mine[R-3][C-2] = mine[R-3][C-1] = true;
				M-=2;
			}
			if(M>=2) {
				mine[R-2][C-3] = mine[R-1][C-3] = true;
				M-=2;
			}
			if(M==3) {
				mine[R-2][C-2] = mine[R-2][C-1] = mine[R-1][C-2] = true;
				M-=3;
			}
			if(M!=0) {
				println("\nImpossible");
				return;
			}
		}
		
		if(conv) {
			int temp = C;
			C = R;
			R = temp;
			boolean[][] mine2 = new boolean[R][C];
			for(int i=0; i<R; i++)
				for(int j=0; j<C; j++)
					mine2[i][j] = mine[j][i];
			mine = mine2;
		}
		
		println("");
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++)
				print((i==R-1&&j==C-1)?"c":mine[i][j]?"*":".");
			println("");
		}
	}
}
