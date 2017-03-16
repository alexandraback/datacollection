package Quali;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemC {

	public static void solve(Scanner sc) {
		int R = sc.nextInt();
		int C = sc.nextInt();
		int M = sc.nextInt();
		boolean mirror = false;
		if (R > C) {
			int temp = R;
			R = C;
			C = temp;
			mirror = true;
		}
		int free = R * C - M;
		int[][] arr = new int[R][C];
		if (free == 1) {
			// possible
			arr[0][0] = 1;
			output(arr, mirror);
			return;
		}
		if (R == 1) {
			// possible
			arr[0][0] = 1;
			for (int i = 1; i < free; i++) {
				arr[0][i] = 2;
			}
			output(arr, mirror);
			return;
		}
		if (R == 2) {
			// possible if free >2 even
			if (free == 2 || free % 2 == 1) {
				System.out.println("Impossible");
				return;
			} else {
				arr[0][0] = 1;
				arr[1][0] = 2;
				for (int i = 1; i < free / 2; i++) {
					arr[0][i] = 2;
					arr[1][i] = 2;
				}
				output(arr, mirror);
				return;
			}
		}
		// impossible for 2, 3, 5, 7
		if (free == 2 || free == 3 || free == 5 || free == 7) {
			System.out.println("Impossible");
			return;
		}
		// special case 4
		if (free == 4) {
			arr[0][0] = 1;
			arr[0][1] = 2;
			arr[1][0] = 2;
			arr[1][1] = 2;
			output(arr, mirror);
			return;
		}
		int rest = free % R;
		int rows = free / R;
		// fill rows
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < rows; j++) {
				arr[i][j] = 2;
			}
		}
		// check special cases for rest
		if (rows == 1 && rest != 0) {
			int curr = R;
			while (curr > rest + 1) {
				curr--;
				arr[curr][0] = 0;
				rest++;
			}
			if (rest != curr) {
				rest--;
				curr--;
				arr[curr][0] = 0;
				curr--;
				arr[curr][0] = 0;
				arr[0][2] = arr[1][2] = arr[2][2] = 2;
			}
		}

		if (rest == 1) {
			if (rows == 2) {
				arr[R - 1][0] = arr[R - 1][1] = 0;
				rest = 3;
			} else {
				arr[R - 1][rows - 1] = 0;
				rest = 2;
			}
		}

		// fill rest
		for (int i = 0; i < rest; i++) {
			arr[i][rows] = 2;
		}
		arr[0][0] = 1;
		output(arr, mirror);
		return;
	}

	public static void output(int[][] arr, boolean mirror) {
		if (mirror) {
			for (int i = 0; i < arr[0].length; i++) {
				for (int j = 0; j < arr.length; j++) {
					if (arr[j][i] == 1) {
						System.out.print("c");
					} else if (arr[j][i] == 2) {
						System.out.print(".");
					} else {
						System.out.print("*");
					}
				}
				System.out.println();
			}
		} else {
			for (int i = 0; i < arr.length; i++) {
				for (int j = 0; j < arr[i].length; j++) {
					if (arr[i][j] == 1) {
						System.out.print("c");
					} else if (arr[i][j] == 2) {
						System.out.print(".");
					} else {
						System.out.print("*");
					}
				}
				System.out.println();
			}
		}

	}

	public static void main(String[] args) throws FileNotFoundException {
		// Scanner sc = new Scanner(new File("C-practice.in"));
		// Scanner sc = new Scanner(new File("C-small-attempt0.in"));
		Scanner sc = new Scanner(new File("C-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d:\n", i);
			solve(sc);
		}
		sc.close();
	}
}
