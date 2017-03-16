package Quali;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;


public class ProblemB {
	
	public static void solve(Scanner sc) {
		double C = sc.nextDouble();
		double F = sc.nextDouble();
		double X = sc.nextDouble();
		double time = 0;
		double prod = 2;
		if (X <= C) {
			System.out.println(X / prod);
			return;
		}
		while (true) {
			// is buying another useful?
			double time1 = X / prod;
			double time2 = C / prod + X / (prod + F);
			if (time2 <= time1) {
				//if so, buy another
				time += C / prod;
				prod += F;
			} else {
				time += time1;
				System.out.println(time);
				return;
			}
		}
	}
	
	
	
	
	public static void main(String[] args) throws FileNotFoundException {
//		 Scanner sc = new Scanner(new File("B-practice.in"));
//		 Scanner sc = new Scanner(new File("B-small-attempt0.in"));
		Scanner sc = new Scanner(new File("B-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
