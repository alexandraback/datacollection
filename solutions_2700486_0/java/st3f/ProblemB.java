import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class ProblemB {
	static long[] count = new long[20001];
	static double[] coef = new double[1000001];
	
	static void precalc() {
		count[0] = 1;
		int k = 1;
		for (int i = 1; i <= 20000; i++) {
			k += 4;
			count[i] = count[i - 1] + k;
		}
	}
	
	static void nextCase(Scanner sc, PrintStream ps) {
		int n = sc.nextInt();
		int x = Math.abs(sc.nextInt());
		int y = sc.nextInt();
		
		int c = (x + y) / 2;
		if (n >= count[c]) {
			ps.println(1.0);
			return;
		}
		if (n <= count[c - 1]) {
			System.out.println("euh?");
			ps.println(0.0);
			return;
		}
		
		if (x == 0) {
			ps.println(0.0);
			return;
		}
		
		long rest = n - count[c - 1];
		
		
		coef[0] = 0.5; coef[1] = 0;
		for (int i = 2; i <= rest; i++) {
			coef[i] = 0;
			for (int j = i; j > 0; j--)
				coef[j] = (coef[j] + coef[j - 1]) / 2;
			coef[0] = (coef[0] + 1) / 2;
		}
		ps.println(coef[y]);
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File(args[0] + ".in"));
		PrintStream ps = new PrintStream(args[0] + ".out");
		precalc();
		
		
		int t = sc.nextInt();
		sc.nextLine();

		for (int c = 1; c <= t; c++) {
			System.out.printf("Case #%d:%n", c);
			ps.printf("Case #%d: ", c);
			nextCase(sc, ps);
		}
	}
}
