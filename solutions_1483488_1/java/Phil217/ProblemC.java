package problemC;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ProblemC {
	public static void main(String[] args) throws FileNotFoundException {
		// Scanner sc = new Scanner(new File("C-practice.in"));
		// Scanner sc = new Scanner(new File("C-small.in"));
		Scanner sc = new Scanner(new File("C-large.in"));
		int cases = sc.nextInt();
		for (int i = 1; i <= cases; i++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			long count = 0;
			for (int j = A; j <= B; j++) {
				int number = recycle(j);
				while (number != j) {
					if (number > j && number <= B) {
						count++;
					}
					number = recycle(number);
				}
			}
			// do case things here
			System.out.format("Case #%d: %d\n", i, count);
		}
	}

	private static int recycle(int n) {
		int temp = n;
		int max = 1;
		while (temp >= 10) {
			max *= 10;
			temp /= 10;
		}
		int m = n / 10 + (max * (n % 10));
		temp = n;
		while (temp % 10 == 0) {
			temp = m;
			m = m / 10 + (max * (m % 10));
		}
		return m;
	}
}
