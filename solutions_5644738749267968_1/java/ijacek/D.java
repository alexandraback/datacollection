package R0;

// Deceitful War
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class D {

	private static Scanner sc;
	private static PrintStream out;

	private static void solve(int TC) {
		int N = ni();
		double[] a = new double[N];
		double[] b = new double[N];
		for (int i = 0; i < N; i++)
			a[i] = sc.nextDouble();
		for (int i = 0; i < N; i++)
			b[i] = sc.nextDouble();

		Arrays.sort(a);
		Arrays.sort(b);

		int X = 0;
		for (int i = 0; i < N; i++) {
			if ( a[i] > b[X] )
				X++;
		}

		int Y = N;
		for (int i = N - 1; i >= 0; i--) {
			if ( a[i] < b[Y - 1] )
				Y--;
		}

		out.println(String.format("Case #%d: %d %d", TC, X, Y));
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ENGLISH);

		String file = "tst/R0/D.ex";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		int TC = ni();
		for (int i = 1; i <= TC; i++)
			solve(i);
	}

	private static int ni() {
		return sc.nextInt();
	}
}
