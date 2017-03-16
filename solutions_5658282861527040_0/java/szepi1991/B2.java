package QB;

import java.io.BufferedInputStream;
import java.util.Scanner;

public class B2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		int T =	sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			System.out.println("Case #" + t + ": " + solve(sc.nextInt(), sc.nextInt(), sc.nextInt()));
		}

	}
	
	private static long solve(int A, int B, int K) {
		long ways = 0;
		for (int a = 0; a < A; a++) {
			for (int b = 0; b < B; b++) {
				if ((a & b) < K) ways++;
			}
		}
		
		return ways;
	}

}
