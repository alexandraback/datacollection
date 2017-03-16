import java.lang.*;
import java.util.*;
import java.io.*;

public class Solution {
	public static long solve(long n) {
		if (n == 0) { return 0; }

		int digits = 0;
		int[] set = new int[10];
		long next = n;

		while (true) {
			long curr = next;

			while (curr > 0) {
				int digit = (int) curr % 10;
				if (set[digit] == 0) {
					set[digit] = 1;
					digits++;
				}
				if (digits == 10) {
					return next;
				}
				curr /= 10;
			}

			next += n;
		}
	}

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
			int t = scanner.nextInt();
			for (int i = 1; i <= t; i++) {
				long n = scanner.nextInt();
				long ans = solve(n);
				if (ans == 0) {
					System.out.println("case #" + i + ": INSOMNIA");
				} else {
					System.out.println("case #" + i + ": " + ans);
				}
			}
		}
	}
}
