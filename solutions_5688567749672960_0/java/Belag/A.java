package b1;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small.in"));
		PrintWriter out = new PrintWriter(new FileWriter(
				new File("a-small.out")));
		int n = sc.nextInt();

		for (int T = 1; n-- > 0; T++) {
			int N = sc.nextInt();
			long total = 0;
			if (N > 10) {
				total += 10;
			}
			if (N >= 100) {
				total += 10 - 1 + 10;
				if (N == 100) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 1000) {
				total += 100 - 1 + 10;
				if (N == 1000) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 10000) {
				total += 100 - 1 + 100;
				if (N == 10000) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 100000) {
				total += 1000 - 1 + 100;
				if (N == 100000) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}

			String s = Integer.toString(N);
			if (N <= 10) {
				total = N;
			} else if (s.endsWith("0")) {
				s = Integer.toString(N-1);
				int mid = s.length() / 2;
				String firstMid = s.substring(0, mid);
				firstMid = new StringBuilder(firstMid).reverse().toString();
				int firstIntReverse = Integer.parseInt(firstMid);

				String secondMid = s.substring(mid, s.length());
				int secondInt = Integer.parseInt(secondMid);
				if (N - Math.pow(10, s.length() - 1) <= firstIntReverse
						+ secondInt) {
					total += N - Math.pow(10, s.length() - 1);
				} else {
					total += firstIntReverse + secondInt + 1;
				}
			} else {
				int mid = s.length() / 2;
				String firstMid = s.substring(0, mid);
				firstMid = new StringBuilder(firstMid).reverse().toString();
				int firstIntReverse = Integer.parseInt(firstMid);

				String secondMid = s.substring(mid, s.length());
				int secondInt = Integer.parseInt(secondMid);
				if (N - Math.pow(10, s.length() - 1) < firstIntReverse
						+ secondInt) {
					total += N - Math.pow(10, s.length() - 1);
				} else {
					total += firstIntReverse + secondInt;
				}
			}

			out.println("Case #" + T + ": " + total);
			System.out.println("Case #" + T + ": " + total);
		}
		out.flush();
	}
}