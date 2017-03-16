import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import javax.print.attribute.standard.Finishings;

public class P201 {
	static String test = "5 2 20 10 2 10 0 4 25 25 25 25 3 24 30 21 6 0 0 0 0 0 100";

	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		int t = inp.nextInt();
		int i = 1;
		while (t > 0) {
			int n = inp.nextInt();
			List<Integer> d = new ArrayList<Integer>();
			for (int c = 0; c < n; c++) {
				d.add(inp.nextInt());
			}
			System.out.println("Case #" + i + ": " + calc(n, d));
			--t;
			++i;
		}

	}

	private static String calc(int n, List<Integer> d) {
		List<Double> ret = new ArrayList<Double>();
		int sum = 0;
		for (int i = 0; i < d.size(); i++) {
			sum += d.get(i);
		}
		for (int i = 0; i < d.size(); i++) {
			double minp = 0;
			double maxp = 1;
			List<Integer> copyOfd = new ArrayList<Integer>(d);
			copyOfd.remove(i);
			while (Math.abs(maxp - minp) > 0.0000000001) {
				double mid = (minp + maxp) / 2;
				double pmid = minOf(copyOfd, sum * (1 - mid));
				if (pmid > d.get(i) + mid * sum) {
					minp = mid;
				} else {
					maxp = mid;
				}
			}
			ret.add(minp);
		}
		String r = "";
		for (int i = 0; i < d.size(); i++) {
			r += String.format("%8.6f", ret.get(i) * 100) + " ";
		}
		return r.trim();
	}

	private static double minOf(List<Integer> d1, double points) {
		ArrayList<Integer> d = new ArrayList<Integer>(d1);
		if (d.size() == 1) {
			return d.get(0) + points;
		}
		int sum = 0;
		int l = 0;
		int lar = d.get(0);
		for (int i = 0; i < d.size(); i++) {
			sum += d.get(i);
			if (d.get(i) > lar) {
				lar = d.get(i);
				l = i;
			}
		}
		double e = (sum + points) / d.size();
		if (e >= lar) {
			return e;
		} else {
			d.remove(l);
			return minOf(d, points);
		}
	}
}
