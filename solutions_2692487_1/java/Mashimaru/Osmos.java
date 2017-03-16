import java.util.*;
import java.io.*;

public class Osmos {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-large.out")));
		
		int numTests = sc.nextInt();
		for (int numCases = 1; numCases <= numTests; numCases++) {
			long A = sc.nextLong();
			int n = sc.nextInt();
			int[] a = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				a[i] = sc.nextInt();
			}
			Arrays.sort(a, 1, n + 1);
			
			int[] dp = new int[n + 1];
			dp[0] = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] < A) {
					dp[i] = dp[i - 1];
					A += a[i];
				} else if (A > 1) {
					int numSteps = 0;
					while (A <= a[i]) {
						A = 2 * A - 1;
						numSteps++;
					}
					dp[i] = dp[i - 1] + numSteps;
					A += a[i];
				} else {
					dp[i] = Integer.MAX_VALUE;
				}
			}
			
			int ans = n;
			for (int i = 1; i <= n; i++) {
				if (dp[i] < Integer.MAX_VALUE) {
					ans = Math.min(ans, dp[i] + n - i);
				} else {
					break;
				}
			}
			
			out.println("Case #" + numCases + ": " + ans);
		}
		
		out.flush();
		out.close();
	}
}
