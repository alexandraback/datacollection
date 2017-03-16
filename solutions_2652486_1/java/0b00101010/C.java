import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	private static int r, n, m, k, count;
	private static int[] res, factors;
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(System.in);
		PrintStream outfile = new PrintStream("C-small-2.out.txt");
		int cases = scan.nextInt();
		long lcmAll, next, temp;
		double r4, r6, r8;
		for (int c = 1; c <= cases; c++) {
			r = scan.nextInt();
			n = scan.nextInt();
			m = scan.nextInt();
			k = scan.nextInt();
			res = new int[m+1];
			factors = new int[m+1];
			outfile.println("Case #" + c + ": ");
			for (int i = 0; i < r; i++)
			{
				Arrays.fill(res, 0);
				lcmAll = 1;
				for (int j = 0; j < k; j++) {
					next = scan.nextLong();
					lcmAll = lcm(lcmAll, next);
					for (int x = m; x >= 2; x--) {
						temp = next;
						while ((temp % x) == 0) {
							temp /= x;
							factors[x]++;
						}
					}
				}
				count = 0;
				for (int j = m; j >= 2; j--) {
					while (count < n && (lcmAll % j) == 0) {
						lcmAll /= j;
						res[j]++;
						count++;
					}
				}
				res[1] = n - count;
				while (res[1] > 0 && (res[8] > 0 || res[6] > 0 || res[4] > 0)) {
					r4 = calcRatio(4);
					r6 = calcRatio(6);
					r8 = calcRatio(8);
					if (res[1] > 0 && res[8] > 0 && r8 >= r6 && r8 >= r4) {
						res[8]--;
						res[1]--;
						res[4]++;
						res[2]++;
					}
					if (res[1] > 0 && res[6] > 0 && r6 >= r4 && r6 >= r8) {
						res[6]--;
						res[1]--;
						res[3]++;
						res[2]++;
					}
					if (res[1] > 0 && res[4] > 0 && r4 >= r6 && r4 >= r8) {
						res[4]--;
						res[1]--;
						res[2] += 2;
					}
				}
				while (res[1] > 0) {
					res[1]--;
					res[findMaxRatio().maxFactor]++;
				}
				for (int j = m; j >= 2; j--)
					for (int x = 0; x < res[j]; x++)
						outfile.print(j);
				//if (res[1] > 0) outfile.print('!');
				outfile.println();
			}
		}
	}
	private static long gcd(long a, long b)
	{
		if (b == 0)
			return a;
		return gcd(b, a%b);
	}
	private static long lcm(long a, long b) {
		return a / gcd(a, b) * b;
	}
	private static double calcRatio(int j) {
		if (res[j] > 0)
			return factors[j] / (double) res[j];
		else
			return -1.0;
	}
	private static int findMinCount() {
		int minCount = Integer.MAX_VALUE;
		int minFactor = 2;
		for (int j = m; j >= 2; j--) {
			if (res[j] < minCount) {
				minCount = res[j];
				minFactor = j;
			}
		}
		return minFactor;
	}
	private static MaxResult findMaxRatio() {
		double maxRatio = 0.0;
		double ratio;
		int maxFactor = 2;
		for (int j = m; j >= 2; j--) {
			if (res[j] > 0) {
				ratio = calcRatio(j);
				if (ratio > maxRatio) {
					maxFactor = j;
					maxRatio = ratio;
				}
			}
		}
		return new MaxResult(maxFactor, maxRatio);
	}
	private static class MaxResult {
		public final int maxFactor;
		public final double maxRatio;
		public MaxResult(int maxFactor, double maxRatio) {
			super();
			this.maxFactor = maxFactor;
			this.maxRatio = maxRatio;
		}
	}
}
