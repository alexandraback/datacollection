package Quali;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;


public class ProblemB {
	
	public static void solve(Scanner sc) {
		int D = sc.nextInt();
		int[] plates = new int[D];
		for (int i = 0; i < plates.length; i++) {
			plates[i] = sc.nextInt();
		}
		int minTime = Integer.MAX_VALUE;
		for (int target = 1; target <= 1000; target++) {
			int time = target;
			for (int i = 0; i < plates.length; i++) {
				time += (plates[i] - 1) / target;
			}
			minTime = Math.min(minTime, time);
		}
		System.out.println(minTime);
	}
	
	
	
	
	public static void main(String[] args) throws FileNotFoundException {
//		 Scanner sc = new Scanner(new File("B-practice.in"));
		 Scanner sc = new Scanner(new File("B-small-attempt0.in"));
//		Scanner sc = new Scanner(new File("B-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
