import java.util.*;

public class A {
	private static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int T = s.nextInt();

		for (int t = 0; t < T; t++) {
			int A = s.nextInt();
			int B = s.nextInt();

			double correct = 1;
			double[] a = new double[A];
			for (int i = 0; i < A; i++) {
				correct *= s.nextDouble();
				a[i] = correct;
			}

			double incorrect = 1 - correct;
			double score1 = correct * (B - A + 1) + incorrect * (2 * B - A + 2);

			double best = Math.min(2 + B, score1);

			for (int i = 0; i < A - 1; i++) {
				int strokes_incorrect = (i + 1) * 2 + 2 * B - A + 2;
				int strokes_correct = (i + 1) * 2 + B - A + 1;
				double score2 = a[A - i - 2] * strokes_correct + (1 - a[A - i - 2]) * strokes_incorrect;
				best = Math.min(best, score2);
			}

			System.out.printf("Case #%d: %f\n", t + 1, best);
		}
	}
}
