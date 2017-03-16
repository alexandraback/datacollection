import java.util.*;

public class a {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int T = stdin.nextInt();

		for (int loop=1; loop<=T; loop++) {

			int A = stdin.nextInt();
			int B = stdin.nextInt();
			double[] prob = new double[A];

			for (int i=0; i<A; i++)
				prob[i] = stdin.nextDouble();

			double ans = solve(A, B, prob);

			System.out.println("Case #"+loop+": "+ans);
		}
	}

	public static double solve(int A, int B, double[] p) {

		double[] allcorrect = new double[A];
		allcorrect[0] = p[0];
		for (int i=1; i<A; i++)
			allcorrect[i] = allcorrect[i-1]*p[i];

		double keep = allcorrect[A-1]*(B-A+1) +
					  (1 - allcorrect[A-1])*(B-A+1+B+1);

		double enter = B + 2;

		double best = keep;
		if (enter < best)
			best = enter;

		// Try all now.
		for (int i=1; i<A; i++) {

			int orig = 2*i + B - A + 1;
			double prob = allcorrect[A-1-i]*orig +
				          (1 - allcorrect[A-1-i])*(orig+B+1);

			if (prob < best)
				best = prob;

		}

		return best;
	}


}