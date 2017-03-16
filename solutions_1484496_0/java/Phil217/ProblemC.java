package problemC;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;

public class ProblemC {
	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("C-practice.in"));
		 Scanner sc = new Scanner(new File("C-small.in"));
		// Scanner sc = new Scanner(new File("C-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			int N = sc.nextInt();
			int[] s = new int[N];
			int sum = 0;
			for (int j = 0; j < s.length; j++) {
				s[j] = sc.nextInt();
				sum += s[j];
			}
			
			int found = find(N, s, sum);
			if (found == -1) {
				System.out.format(Locale.US, "Case #%d: Impossible\n", i);
			} else {
				System.out.format(Locale.US, "Case #%d:\n", i);
				findAgain(N, s, found);
			}
//				System.out.format(Locale.US, "Case #%d:\n", i);
//				for (int j = 0; j < taken.length; j++) {
//					if (taken[j]) {
//						System.out.print(s[j] + " ");
//					}
//				}
//				System.out.println("");
//				for (int j = 0; j < taken2.length; j++) {
//					if (taken2[j]) {
//						System.out.print(notTaken[j] + " ");
//					}
//				}
//				System.out.println("");
//			} else {
//			}

			// do case things here
		}
	}
	
	private static void findAgain(int N, int[] s, int sum) {
		boolean[] taken = new boolean[N];
		int count = 0;
		for (int j = 1; j < pow2(N); j++) {
			if (taken[0]) {
				int temp = 0;
				while(taken[temp]) {
					taken[temp] = false;
					temp++;
					if (temp >= N) {
						break;
					}
				}
				if (temp < N) {
					taken[temp] = true;
				} else {
					break;
				}
			} else {
				taken[0] = true;
			}
			int tempSum = 0;
			for (int k = 0; k < taken.length; k++) {
				if (taken[k]) {
					tempSum += s[k];
				}
			}
			if (tempSum == sum) {
				for (int i = 0; i < taken.length; i++) {
					if (taken[i]) {
						System.out.print(s[i] + " ");
					}
				}
				System.out.println("");
				count++;
				if(count==2) {
					return;
				}
			}
		}
	}
	
	private static int find(int N, int[] s, int sum) {
		boolean[] taken = new boolean[N];
		HashSet<Integer> found = new HashSet<Integer>();
		for (int j = 1; j < pow2(N); j++) {
			if (taken[0]) {
				int temp = 0;
				while(taken[temp]) {
					taken[temp] = false;
					temp++;
					if (temp >= N) {
						break;
					}
				}
				if (temp < N) {
					taken[temp] = true;
				} else {
					break;
				}
			} else {
				taken[0] = true;
			}
			int tempSum = 0;
			for (int k = 0; k < taken.length; k++) {
				if (taken[k]) {
					tempSum += s[k];
				}
			}
			if (tempSum*2>sum) {
				continue;
			}
			if (found.contains(tempSum)) {
				return tempSum;
			} else {
				found.add(tempSum);
			}
		}
		return -1;
	}
	
	private static int pow2(int n) {
		if (n == 1) {
			return 2;
		}
		return n*pow2(n-1);
	}
}