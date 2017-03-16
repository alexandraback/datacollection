import java.util.*;

public class c {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int dummy = stdin.nextInt();

		int trials = stdin.nextInt();
		int size = stdin.nextInt();
		int max = stdin.nextInt();
		int numSubsets = stdin.nextInt();


		/*** Do this here ***/
		int[][] freq = new int[1000][126];

		for (int i=2; i<=5; i++) {
			for (int j=i; j<=5; j++) {
				for (int k=j; k<=5; k++) {
					// Fill freq i,j,k
					int n = 100*i+10*j+k;
					freq[n][1]++;
					freq[n][i]++;
					freq[n][j]++;
					freq[n][k]++;
					freq[n][i*j]++;
					freq[n][i*k]++;
					freq[n][j*k]++;
					freq[n][i*j*k]++;
				}
			}
		}

		System.out.println("Case #1:");
		for (int loop=0; loop<trials; loop++) {

			int[] subsets = new int[numSubsets];
			for (int i=0; i<numSubsets; i++)
				subsets[i] = stdin.nextInt();

			System.out.println(solve(subsets,freq));
		}
	}

	public static int solve(int[] subsets, int[][] freq) {

		// Score each possible subset...
		int max = 0, ans = 222;


		int[] matches = new int[126];
		for (int i=0; i<subsets.length; i++)
			matches[subsets[i]]++;

		for (int i=0; i<1000; i++) {
			if (freq[i][1] == 0) continue;

			int temp = 0;
			boolean possible = true;
			for (int j=0; j<subsets.length; j++) {
				if (freq[i][subsets[j]] == 0)
					possible = false;
			}
			for (int j=0; j<matches.length; j++) {
				temp += matches[j]*freq[i][j];
			}

			if (temp > max && possible) {
				max = temp;
				ans = i;
			}
		}

		return ans;
	}
}