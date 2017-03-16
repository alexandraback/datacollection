import java.util.List;
import java.util.Scanner;
import java.math.BigInteger;

public class Enclosure { 
	public static void main(String[] arguments) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();

		for (int i = 0; i < t; i++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int k = sc.nextInt();

			if (n == 1 || n == 2 || m == 1 || m == 2) {
				System.out.printf("Case #%d: %d\n", i + 1, k);
				continue;
			}

			int count = 0;

			if (n == 3 && m == 3) {
				if (k > 4) {
					count = k - 1;
				} else {
					count = k;
				}
			} else if ((n == 3 && m == 4) || (n == 4 && m == 3)) {
				if (k > 4 && k < 8) {
					count = k - 1;
				} else if (k >= 8) {
					count = k - 2;
				} else {
					count = k;
				}
			} else if ((n == 3 && m == 5) || (n == 5 && m == 3)) {
				if (k > 4 && k < 8) {
					count = k - 1;
				} else if (k >= 8 && k < 11) {
					count = k - 2;
				} else if (k >= 11) {
					count = k - 3;
				} else {
					count = k;
				}
			} else if ((n == 3 && m == 6) || (n == 6 && m == 3)) {
				if (k > 4 && k < 8) {
					count = k - 1;
				} else if (k >= 8 && k < 11) {
					count = k - 2;
				} else if (k >= 11 && k < 14) {
					count = k - 3;
				} else if (k > 14) {
					count = k - 4;
				} else {
					count = k;
				}
			} else if (n == 4 && m == 4) {
				if (k < 5) {
					count = k;
				} else if (k < 8) {
					count = k - 1;
				} else if (k < 11) {
					count = k - 2;
				} else if (k < 13) {
					count = k - 3;
				} else {
					count = k - 4;
				}
			} else if ((n == 4 && m == 5) || (n == 5 && m == 4)) {
				if (k < 5) {
					count = k;
				} else if (k < 8) {
					count = k - 1;
				} else if (k < 11) {
					count = k - 2;
				} else if (k < 13) {
					count = k - 3;
				} else if (k < 15) {
					count = k - 4;
				} else if (k == 15) {
					count = 10;
				} else {
					count = k - 6;
				}
			}
			

			System.out.printf("Case #%d: %d\n", i + 1, count);
		}		
	}
}
