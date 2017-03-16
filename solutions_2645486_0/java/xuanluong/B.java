

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class B {

	static final String filein = "B-in.txt";
	static final String fileout = "B-out.txt";
	static int ntest, E, R, N, maxreg;
	static int[] V;
	
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File(filein));
		PrintStream ps = new PrintStream(new File(fileout));
		PrintStream stdout = System.out;
		System.setOut(ps);
		ntest = scanner.nextInt();
		for (int test=1;test<=ntest;++test) {
			E = scanner.nextInt();
			R = scanner.nextInt();
			N = scanner.nextInt();
			V = new int[N];
			maxreg = 0;
			for (int i=0;i<N;++i) {
				V[i] = scanner.nextInt();
			}
			for (int i=0;i<=E;++i) {
				dfs(1,i*V[0],E-i+R);
			}
			System.out.println("Case #" + test + ": " + maxreg);
		}

	}

	private static void dfs(int idx, int reg, int ene) {
		if (ene > E) {
			ene = E;
		}
		if (idx == N) {
			if (reg > maxreg) {
				maxreg = reg;
			}
			return;
		}
		for (int i=0;i<=ene;++i) {
			dfs(idx+1,reg + i*V[idx],ene-i+R);
		}
		
	}

}
