package problemC;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemC {
	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("C-practice.in"));
		 Scanner sc = new Scanner(new File("C-small-attempt0.in"));
		// Scanner sc = new Scanner(new File("C-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int tcase = 1; tcase <= cases; tcase++) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			long[][] boxes = new long[N][2];
			long[][] toys = new long[M][2];
			for (int i = 0; i < boxes.length; i++) {
				boxes[i][0] = sc.nextLong();
				boxes[i][1] = sc.nextInt();
			}
			for (int i = 0; i < toys.length; i++) {
				toys[i][0] = sc.nextLong();
				toys[i][1] = sc.nextInt();
			}

			long count = max(boxes, toys, 0, 0, 0, 0);

			// do case things here
			System.out.format(Locale.US, "Case #%d: %d\n", tcase, count);
		}
	}

	private static long max(long[][] boxes, long[][] toys, int b, long b2,
			int t, long t2) {
		if (b >= boxes.length || t >= toys.length) {
			return 0;
		}
		long take = 0;
		if (boxes[b][1] == toys[t][1]) {
			if (boxes[b][0] - b2 > toys[t][0] - t2) {
				take = toys[t][0] - t2;
				t++;
				t2 = 0;
				b2 += take;
			} else if (boxes[b][0] - b2 < toys[t][0] - t2) {
				take = boxes[b][0] - b2;
				b++;
				b2 = 0;
				t2 += take;
			} else {
				take = boxes[b][0] - b2;
				b++;
				t++;
				b2 = 0;
				t2 = 0;
			}
			return take + max(boxes, toys, b, b2, t, t2);
		}
		long max1 = max(boxes, toys, b + 1, 0, t, t2);
		long max2 = max(boxes, toys, b, b2, t + 1, 0);

		return take + Math.max(max1, max2);
	}
}