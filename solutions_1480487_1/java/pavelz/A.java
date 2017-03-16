package oneb;

import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=0;i<t;i++) {
			int n = sc.nextInt();
			int [] s = new int[n];
			int sm = 0;
			int total = 0;
			for( int j=0;j<n;j++) {
				s[j] = sc.nextInt();
				if (s[j] > sm) sm = s[j];
				total += s[j];
			}
			boolean ok [] = new boolean[n];
			for (int j=0;j<n;j++) ok[j] = false;
			int remain = total;
			int remainCount = n;
			boolean change = true;
			while (change) {
				change = false;
				for (int j=0;j<n;j++) {
					if (!ok[j] && s[j] * remainCount >= total + remain) {
						ok[j] = true;
						change = true;
					}
				}
				remain = 0;
				remainCount = 0;
				for (int j=0;j<n;j++) {
					if (!ok[j]) { remain += s[j]; remainCount++;}
				}
			}
			double unit = ((double)(total + remain)) / remainCount;
			System.out.print("Case #" + (i + 1) + ":");
			for (int j=0;j<n;j++) {
				double add = 0;
				if (!ok[j]) {
					add = (unit - s[j]) / total * 100;
				}
				if (add < 0) {
					System.err.println("\nAAAAA");
					return;
				}
				System.out.print(" " + add);
			}
			System.out.println("");
		}
	}
}
