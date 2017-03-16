import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemA {
		
	static void nextCase(Scanner sc, PrintStream ps) {
		long a = sc.nextLong();
		int n = sc.nextInt();
		int[] s = new int[n];
		for (int i = 0; i < n; i++)
			s[i] = sc.nextInt();
		Arrays.sort(s);
		
		if (a == 1) {
			ps.println(n);
			return;
		}
		
		int i;
		int op = 0;
		int minOp = n;
		for (i = 0; i < n; i++) {
			if (a <= s[i]) {
				minOp = Math.min(op + n - i, minOp);
			}
			while (a <= s[i]) {
				a += a - 1;
				op++;
			}
			a += s[i];
		}
		minOp = Math.min(op, minOp);
		
		ps.println(minOp);
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
