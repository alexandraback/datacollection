package Quali;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;


public class ProblemA {
	
	public static void solve(Scanner sc) {
		int sMax = sc.nextInt();
		String levels = sc.next();
		char[] arr = levels.toCharArray();
		int[] sums = new int[sMax + 1];
		int invite = 0;
		for (int i = 0; i <= sMax; i++) {
			sums[i] = arr[i] - '0';
			if (i > 0) {
				sums[i] += sums[i-1];
			}
			if (sums[i] <= i) {
				invite++;
				sums[i]++;
			}
		}
		System.out.format("%d%n", invite);
	}
	
	
	
	
	public static void main(String[] args) throws FileNotFoundException {
//		 Scanner sc = new Scanner(new File("A-practice.in"));
//		 Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		Scanner sc = new Scanner(new File("A-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
