import java.math.*;
import java.util.*;

class ProblemD {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();

		for (int t = 1; t <= T; t++) {
			int K = s.nextInt(), C = s.nextInt(), S = s.nextInt();
			int minCount = (K - 1) / C + 1;
			if (S >= minCount) {
				System.out.print("Case #" + t + ":");

				BigInteger result = BigInteger.ZERO;
				BigInteger bigK = BigInteger.valueOf(K);
				for (int current = 0; current < K; current++) {
					result = result.multiply(bigK).add(BigInteger.valueOf(current));
					if ((current + 1) % C == 0) {
						System.out.print(" " + result.add(BigInteger.ONE));
						result = BigInteger.ZERO;
					}
				}
				if (K % C != 0)
					System.out.print(" " + result.add(BigInteger.ONE));
				System.out.println();
			} else {
				System.out.println("Case #" + t + ": IMPOSSIBLE");
			}
		}
	}

}