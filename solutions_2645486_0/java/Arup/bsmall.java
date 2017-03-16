import java.util.*;

public class bsmall {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			int e = stdin.nextInt();
			int boost = stdin.nextInt();
			int n = stdin.nextInt();
			int[] gain = new int[n];
			for (int i=0; i<n; i++)
				gain[i] = stdin.nextInt();


			Integer[][] dp = new Integer[n+1][e+1];

			dp[0][e] = 0;
			for (int i=0; i<e; i++) dp[0][i] = null;

			// Go through each item.
			for (int i=1; i<=n; i++) {

				// Fill in best answer for item i at energy level j.
				for (int j=0; j<=e; j++) {

					int best = 0;

					// k is the energy level from which we build.
					for (int k=0; k<=e; k++) {

						if (dp[i-1][k] != null) {

							int value = Math.min(k+boost, e);

							if (value >= j) {

								int temp = (value-j)*gain[i-1] + dp[i-1][k];
								if (temp > best)
									best = temp;
							}
						}
					}
					dp[i][j] = best;
				}
			}

			int ans = dp[n][0];
			for (int i=1; i<=e; i++)
				if (dp[n][i] > ans)
					ans = dp[n][i];

			System.out.println("Case #"+loop+": "+ans);

		}
	}


}

