package Quali;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class ProblemD {

	public static void solve(Scanner sc) {
		int N = sc.nextInt();
		double[] weightsNaomi = new double[N];
		double[] weightsKen = new double[N];

		for (int i = 0; i < N; i++) {
			weightsNaomi[i] = sc.nextDouble();
		}

		for (int i = 0; i < N; i++) {
			weightsKen[i] = sc.nextDouble();
		}

		Arrays.sort(weightsNaomi);
		Arrays.sort(weightsKen);
		// compute scores
		int origScore = 0;
		int kenPos = N - 1;
		int naomiPos = N - 1;

		for (int i = 0; i < N; i++) {
			if (weightsKen[kenPos] > weightsNaomi[naomiPos]) {
				kenPos--;
				naomiPos--;
			} else {
				naomiPos--;
				origScore++;
			}
		}

		kenPos = 0;
		naomiPos = 0;
		int newScore = 0;
		
		for (int i = 0; i < N; i++) {
			if (weightsKen[kenPos] > weightsNaomi[naomiPos]) {
				naomiPos++;
			} else {
				naomiPos++;
				kenPos++;
				newScore++;
			}
		}

		System.out.format("%d %d\n", newScore, origScore);
	}

	public static void main(String[] args) throws FileNotFoundException {
//		 Scanner sc = new Scanner(new File("D-practice.in"));
		Scanner sc = new Scanner(new File("D-small-attempt0.in"));
//		 Scanner sc = new Scanner(new File("A-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
