import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class ProblemA {
	
	static void nextCase(Scanner sc, PrintStream ps) {
		long r = sc.nextLong();
		long t = sc.nextLong();
		
		long k = 1;
		while (k * (2 * r + 2 * k - 1) <= t) k *= 2;
		
		long kMax = k;
		long kMin = k / 2;
		while (kMax - kMin > 1) {
			long kMid = (kMin + kMax) / 2;
			if (kMid * (2 * r + 2 * kMid - 1) <= t)
				kMin = kMid;
			else
				kMax = kMid;
		}
		ps.println(kMin);
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
