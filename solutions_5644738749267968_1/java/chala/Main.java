/*
	read data

	guest1 map1
	guest2 map2

	compare 2 maps

	output
*/

import java.io.*;
import java.util.*;
import java.text.*;

public class Main {

	public static void main(String[] args) throws Exception {

		Scanner scan = new Scanner(System.in);
		int i0 = scan.nextInt();
		PrintStream out = new PrintStream("04out.txt");

		for (int i = 0; i < i0; i++) {
			Q q = new Q();
			q.n = scan.nextInt();
			for (int j = 0; j < q.n; j++) {
				q.u1.add(scan.nextDouble());
			}
			for (int j = 0; j < q.n; j++) {
				q.u2.add(scan.nextDouble());
			};
			out.println("Case #" + (i+1) + ": " + q.ans1() + " " + q.ans2());
		}
		out.close();

	}

	static class Q implements Comparator<Double> {

		public int compare(Double o1, Double o2) {
			return (Double) o1 > (Double) o2 ? 1 : -1;
		}

		int n;
		List<Double> u1 = new ArrayList<Double>();
		List<Double> u2 = new ArrayList<Double>();

		int ans1() {
			Collections.sort(u1, this);
			Collections.sort(u2, this);

			int p1 = 0;
			int p2 = 0;

			while (true) {
				double b1 = u1.get(p1);
				double b2 = u2.get(p2);

				p1++;
				if (b1 > b2) {
					p2++;
				}

				if (p1 == u1.size()) {
					break;
				}
			}

			return p2;
		}

		int ans2() {

			//System.out.println(u1);
			//System.out.println(u2);
			int p1 = n - 1;
			int p2 = n - 1;
			int count = 0;

			while (true) {
				double b1 = u1.get(p1);
				double b2 = u2.get(p2);

				if (b1 > b2) {
					b2 = u2.get(count);
					if (b1 > b2) {
						count++;
						//System.out.println(b1 + "," + b2 + ", " + count);
					}
				} else {
					p2--;
				}

				p1--;
				if (p1 == -1) {
					break;
				}
			}
			return count;
		}

	}

}
