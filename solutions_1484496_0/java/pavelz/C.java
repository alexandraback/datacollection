package oneb;

import java.util.Scanner;

public class C {
	
	private static void printSet(int [] set, int content) {
		boolean first = true;
		for (int pos = 0; content > 0; pos++) {
			if ((content & 1) == 1) {
				if (first) {
					first = false;
				} else {
					System.out.print(" ");
				}
				System.out.print("" + set[pos]);
			}
			content >>= 1;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=0;i<t;i++) {
			int n = sc.nextInt();
			int ints [] = new int[n];
			for (int j=0;j<n;j++) ints[j] = sc.nextInt();
			
			int totals[] = new int[2000000];
			for (int j=0;j<totals.length;j++) totals[j] = 0;
			
			System.out.println("Case #" + (i + 1) + ":");
			
			boolean found = false;
			for (int j=1;j<(1<<n);j++) {
				int jt = j;
				int total = 0;
				for (int pos = 0;pos<n;pos++) {
					if ((jt & 1) == 1) {
						total += ints[pos];
					}
					jt >>= 1;
				}
				if (totals[total] != 0) {
					printSet(ints, totals[total]);
					System.out.println("");
					printSet(ints, j);
					System.out.println("");
					found = true;
					break;
				}
				totals[total] = j;
			}
			
			if (!found) {
				System.out.println("Impossible");
			}
		}
	}
}
