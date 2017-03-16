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

		PrintStream out = new PrintStream("02out.txt");

		DecimalFormat ff = new DecimalFormat("#.#######");

		Q q = new Q();
		for (int i = 0; i < i0; i++) {
			q.c = scan.nextDouble();
			q.f = scan.nextDouble();
			q.x = scan.nextDouble();
			out.println("Case #" + (i+1) + ": " + ff.format(q.ans()));
		}
		out.close();

	}

	static class Q {
		double c, f, x;
		List<Double> ls = new ArrayList<Double>();
		double ans() {
			int count = 0;

			ls.add(x / 2);

			while (true) {
				count++;
				double newd = fac(count);
				double old = ls.get(ls.size() - 1);
				if (newd < old) {
					ls.add(newd);
				} else {
					break;
				}
			}
		//	System.out.println(ls);
			return ls.get(ls.size() - 1);

		}

		double fac(int val) {

			int count = 1;
			double total = 0.0f;
			double speed = 2;
			total += c / 2;
			speed += f;

			while (count < val) {
		//		System.out.println(total);
				total += (c / speed);
				speed += f;
		//		System.out.println(total);
				count++;
			}
			total += (x / speed);

		//	System.out.println(val + "," + total);
			return total;
		}



	}

	static	double m(double f) {
				return ((int) Math.round(f * 10000000)) / 10000000.0;
		}

}