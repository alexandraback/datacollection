package problemB;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ProblemB {
	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("B-practice.in"));
//		Scanner sc = new Scanner(new File("B-small.in"));
		Scanner sc = new Scanner(new File("B-large.in"));
		int cases = sc.nextInt();
		for (int i = 1; i <= cases; i++) {
			// do case things here
			int n = sc.nextInt();
			int s = sc.nextInt();
			int p = sc.nextInt();
			int count = 0;
			for (int j = 0; j < n; j++) {
				int t = sc.nextInt();
				if (p == 0) {
					count++;
					continue;
				}
				if (t == 0) {
					continue;
				}
				if (t == 1) {
					if (p == 1) {
						count++;
					}
					continue;
				}
				if (t == 2) {
					if (p == 1) {
						count++;
					}
					if (p == 2) {
						if (s > 0) {
							s--;
							count++;
						}
					}
					continue;
				}
				if (t/3 >= p) {
					count++;
					continue;
				}
				if (t/3 == p - 1 && t % 3 != 0) {
					count++;
					continue;
				}
				if (s > 0) {
					if (t/3 == p-1) {
						count++;
						s--;
						continue;
					}
					if (t/3 == p-2 && t%3 == 2) {
						count++;
						s--;
						continue;						
					}
				}
			}
			System.out.format("Case #%d: %d\n", i, count);
		}
	}
}
