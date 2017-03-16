import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	private static double C, F, X;

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("B-large.in"));
		System.setOut(new PrintStream("B-large.out"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			C = sc.nextDouble();
			F = sc.nextDouble();
			X = sc.nextDouble();
			double k = (F * X - 2 * C) / (C * F);
			System.out.printf("Case #%d: %.7f\n", i,
					Math.min(get((int) k), get((int) k + 1)));
		}
		sc.close();
	}

	private static double get(int k) {
		double sum = X / (2 + k * F);
		for (int i = 0; i < k; i++) {
			sum += C / (2 + i * F);
		}
		return sum;
	}
}