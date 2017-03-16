package yulong.codejam;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();

		for (int t = 1; t <= T; t++) {
			int E = s.nextInt();
			int R = s.nextInt();
			int N = s.nextInt();

			final int[] values = new int[N];
			Integer[] order = new Integer[N];
			for (int n = 0; n < N; n++) {
				values[n] = s.nextInt();
				order[n] = n;
			}
			Arrays.sort(order, new Comparator<Integer>() {
				@Override
				public int compare(Integer o1, Integer o2) {
					return values[o2] - values[o1];
				}
			});

			int energy = E;
			int must_remain = 0;
			int gain = 0;
			for (int i = 0; i < order.length; i++) {
				/* value */
				int value = values[order[i]];

				/* spend on this */
//				int can_spend = energy + R - must_remain;
//				int spend = Math.min(energy, can_spend); 
				int spend = energy;
//				System.out.println("case " + t+ ": e=" + energy+ ", " + order[i] + " " + spend);
				
//				must_remain = spend;
				gain += spend * value;
				energy = energy - spend + R;
				if (energy > E) {
					energy = E;
				} 
			}

			System.out.println("Case #" + t + ": " + gain);
//			System.out.println();
		}
		s.close();
	}
}
