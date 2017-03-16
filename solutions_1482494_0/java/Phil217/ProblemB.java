package problemB;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ProblemB {
	public static void main(String[] args) throws FileNotFoundException {
		// Scanner sc = new Scanner(new File("B-practice.in"));
		Scanner sc = new Scanner(new File("B-small.in"));
		// Scanner sc = new Scanner(new File("B-large.in"));
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			int T = sc.nextInt();
			int[][] stars = new int[T][2];
			for (int j = 0; j < stars.length; j++) {
				for (int k = 0; k < 2; k++) {
					stars[j][k] = sc.nextInt();
				}
			}
			int[] starsGotten = new int[T];
			int solved = 0;
			int hasStars = 0;
			int trys = solve(T, stars, starsGotten, solved, hasStars);
			if (trys == -1) {
				System.out.format("Case #%d: Too Bad\n", i);
			} else {
				System.out.format("Case #%d: %d\n", i, trys);
			}
		}
	}

	private static int solve(int T, int[][] stars, int[] starsGotten, int solved, int hasStars) {

		boolean change = false;

		int trys = 0;

		do {
			if (solved == T) {
				break;
			}
			trys++;
			change = false;
			// solve
			for (int j = 0; j < starsGotten.length; j++) {
				if (starsGotten[j] == 0) {
					if (stars[j][1] <= hasStars) {
						solved++;
						hasStars += 2;
						starsGotten[j] = 2;
						change = true;
						break;
					}
				}
			}
			// 1->2
			if (!change) {
				for (int j = 0; j < starsGotten.length; j++) {
					if (starsGotten[j] == 1) {
						if (stars[j][1] <= hasStars) {
							solved++;
							hasStars += 1;
							starsGotten[j] = 2;
							change = true;
							break;
						}
					}
				}
			}
			// 0->1
			if (!change) {
				int min = -1;
				for (int j = 0; j < starsGotten.length; j++) {
					if (starsGotten[j] == 0) {
						if (stars[j][0] <= hasStars) {
							int[] cl = starsGotten.clone();
							cl[j] = 1;
							int test = solve(T, stars, cl, solved, hasStars + 1);
							if (min == -1 || test < min) {
								min = test;
							}
						}
					}
				}
				if (min == -1) {
					return min;
				}
				return min + trys;
			}
		} while (change);
		if (solved < T) {
			return -1;
		}
		return trys;

	}
}
