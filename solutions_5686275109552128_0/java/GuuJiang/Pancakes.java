package codejam2015;

import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Pancakes {	
	Scanner cin;

	public void solveAll() {
		cin = new Scanner(System.in);
		int t = cin.nextInt();
		for (int i = 1; i <= t; ++i) {
			System.out.printf("Case #%d: %d\n", i, solve());
		}
	}

	private int solve() {
		int d = cin.nextInt();
		int[] np = new int[d];
		int max = 0;
		for (int i = 0; i < d; ++i) {
			np[i] = cin.nextInt();
			if (np[i] > max) {
				max = np[i];
			}
		}
		int min = max;
		for (int i = 1; i <= max; ++i) {
			int n = i;
			for (int j = 0; j < d; ++j) {
				if (np[j] > i) {
					if (np[j] % i == 0) {
						n += np[j] / i - 1;
					} else {
						n += np[j] / i;
					}
				}
			}
			if (n < min) {
				min = n;
			}
		}
		
		return min;
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("B-small-attempt1.in"));
		System.setOut(new PrintStream("B-small.out"));
		new Pancakes().solveAll();
	}
}
