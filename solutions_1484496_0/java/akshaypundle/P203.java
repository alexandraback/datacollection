import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

import javax.print.attribute.standard.Finishings;

public class P203 {
	static String test = "2 20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600";

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
		int[] sums = new int[100000*20];
		for (int i = 0; i < 1 << 19; i++) {
			int s1 = 0;
			for (int j = 0; j < 20; j++) {
				if ((i & (1 << j)) != 0) {
					s1 += d.get(j);
				}
			}
			if (sums[s1] != 0) {

				int a1 = i;
				int a2 = sums[s1];
				String ret = "\n";
				for (int j = 0; j < 20; j++) {
					if ((a1 & (1 << j)) != 0) {
						ret += d.get(j) + " ";
					}
				}
				ret += "\n";
				for (int j = 0; j < 20; j++) {
					if ((a2 & (1 << j)) != 0) {
						ret += d.get(j) + " ";
					}
				}
				return ret;
			} else {
				sums[s1] = i;
			}
		}
		return "Impossible";
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
