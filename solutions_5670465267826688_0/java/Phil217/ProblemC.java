package Quali;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemC {

	public static void solve(Scanner sc) {
		int L = sc.nextInt();
		long X = sc.nextInt();
		String s = sc.next();
		int[] arr = new int[L];
		
		int totalProd = 1;
		for (int i = 0; i < arr.length; i++) {
			arr[i] = 2 + (s.charAt(i) - 'i');
			totalProd = multiply(totalProd,arr[i]);
		}
		
		int prod = 1;
		// find greedy
		int search = 2;
		for (int pos = 0; pos < 10*L; pos++) {
			if (pos == X * L) {
				if (search == 4 && prod == 4) {
					System.out.println("YES");
				} else {
					System.out.println("NO");
				}
				return;
			}
			prod = multiply(prod, arr[pos % L]);
			if (search == 2 && prod == 2) {
				// i found, now search for j
				search = 3;
				prod = 1;
			}
			if (search == 3 && prod == 3) {
				prod = 1;
				search = 4;
			}
		}
		if (search != 4) {
			System.out.println("NO");
			return;
		}
		long remaining = (X - 10) % 4;
		for (int i = 0; i < remaining; i++) {
			prod=multiply(prod,totalProd);
		}
		if (prod != 4) {
			System.out.println("NO");
			return;
		}
		System.out.println("YES");
	}
	
	// 1,2,3,4=1,i,j,k
	private static int multiply(int i, int j) {
		if (i < 0) {
			return -multiply(-i,j);
		}
		if (j < 0) {
			return -multiply(i,-j);
		}
		if (i == 1) {
			return j;
		}
		if (j == 1) {
			return i;
		}
		if (i == j) {
			return -1;
		}
		if (i == 2) {
			if (j == 3) {
				return 4;
			} else {
				return -3;
			}
		}
		if (i == 3) {
			if (j == 2) {
				return -4;
			} else {
				return 2;
			}
		}
		if (i == 4) {
			if (j == 2) {
				return 3;
			} else {
				return -2;
			}
		}
		System.out.println("ERROR");
		return -1;
	}

	public static void main(String[] args) throws FileNotFoundException {
//		 Scanner sc = new Scanner(new File("C-practice.in"));
		 Scanner sc = new Scanner(new File("C-small-attempt0.in"));
//		Scanner sc = new Scanner(new File("C-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
