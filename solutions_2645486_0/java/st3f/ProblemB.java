import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemB {
	
	static void nextCase(Scanner sc, PrintStream ps) {
		int E = sc.nextInt();
		int r = sc.nextInt();
		int n = sc.nextInt();
		int[] v = new int[n];
		for (int i = 0; i < n; i++)
			v[i] = sc.nextInt();
		
		if (r >= E) {
			long s = 0;
			for (int i = 0; i < n; i++)
				s += v[i];
			ps.println(E * s);
			return;
		}
		
		long[] dpOld = new long[E + 1];
		long[] dpNew = new long[E + 1];
		long[] tmp;
		
		for (int k = r; k <= E; k++)
			dpNew[E - k + r] = k * v[0];
		
		for (int i = 1; i < n; i++) {
			tmp = dpNew;
			dpNew = dpOld;
			dpOld = tmp;
			Arrays.fill(dpNew, 0);
			for (int e = r; e <= E; e++)
				for (int k = 0; k <= e; k++) {
					int eNew = Math.min(E, e - k + r);
					dpNew[eNew] = Math.max(dpNew[eNew], dpOld[e] + k * v[i]);
				}
		}
		long m = 0;
		for (int e = r; e <= E; e++)
			m = Math.max(m, dpNew[e]);
		ps.println(m);
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File(args[0] + ".in"));
		PrintStream ps = new PrintStream(args[0] + ".out");
		int t = sc.nextInt();
		sc.nextLine();

		for (int c = 1; c <= t; c++) {
			System.out.printf("Case #%d:%n", c);
			ps.printf("Case #%d: ", c);
			nextCase(sc, ps);
		}
	}
}
