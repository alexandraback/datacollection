package at.jaki.round1.c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

	public static void main(String... args) throws FileNotFoundException {
		String name = "C-small-1-attempt0";
		Scanner sc = new Scanner(new File(name + ".in"));
		PrintWriter pw = new PrintWriter(new File(name + ".out"));
		int nnn = sc.nextInt();
		for (int iii = 1; iii <= nnn; iii++) {
			String msg = null;

			int r = sc.nextInt();
			int n = sc.nextInt();
			int m = sc.nextInt();
			int k = sc.nextInt();

			String s = "Case #" + iii + ":";
			System.out.println(s);
			pw.println(s);

			for (int i = 0; i < r; i++) {
				int[] t = new int[k];
				for (int j = 0; j < k; j++) {
					t[j] = sc.nextInt();
				}
				int three = 0;
				int four = 0;
				int five = 0;
				boolean sawFour = false;

				for (int j = 0; j < k; j++) {
					if (t[j] % 4 == 0) {
						sawFour = true;
					}

					if (t[j] % Math.pow(5, 3) == 0) {
						five = 3;
					}
					if (t[j] % Math.pow(5, 2) == 0) {
						five = Math.max(five, 2);
					}
					if (t[j] % 5 == 0) {
						five = Math.max(five, 1);
					}

					if (t[j] % Math.pow(3, 3) == 0) {
						three = 3;
					}
					if (t[j] % Math.pow(3, 2) == 0) {
						three = Math.max(three, 2);
					}
					if (t[j] % 3 == 0) {
						three = Math.max(three, 1);
					}

					if (t[j] % Math.pow(4, 3) == 0) {
						four = 3;
					}
					if (t[j] % Math.pow(4, 2) == 0) {
						four = Math.max(four, 1);
					}
				}

				StringBuilder sb = new StringBuilder();
				for (int q = 0; q < three; q++) {
					sb.append('3');
				}
				for (int q = 0; q < four; q++) {
					sb.append('4');
				}
				for (int q = 0; q < five; q++) {
					sb.append('5');
				}

				if (sb.length() > n) {
					System.out.println("wtf????");
				}
				if (sb.length() == 2 && sawFour && four == 0) {
					sb.append('4');
				}
				while (sb.length() < n) {
					sb.append('2');
				}
				System.out.println(sb);
				pw.println(sb);

			}
			pw.flush();
			pw.close();

		}
	}
}