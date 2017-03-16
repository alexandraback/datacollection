package round1a;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class KingdomRush {
	public static void main(String[] args) {
		new KingdomRush().run();
	}

	private void run() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			int N = sc.nextInt();
			int[] a = new int[N];
			int[] b = new int[N];
			for (int i = 0; i < N; i++) {
				a[i] = sc.nextInt();
				b[i] = sc.nextInt();
			}
			int result = solve(N, a, b);
			if (result < 0) {
				System.out.printf("Case #%d: Too Bad\n", t + 1);
			} else {
				System.out.printf("Case #%d: %d\n", t + 1, result);
			}
		}
	}

	class Level {
		int a;
		int b;
		int c;
		Level(int a, int b) {
			this.a = a;
			this.b = b;
			this.c = 0;
		}
	}

	public int solve(int n, int[] a, int[] b) {
		Level[] levels = new Level[n];
		for (int i = 0; i < n; i++) {
			levels[i] = new Level(a[i], b[i]);
		}
		Arrays.sort(levels, new Comparator<Level>() {
			@Override
			public int compare(Level arg0, Level arg1) {
				return arg1.b - arg0.b;
			}
		});
//		for (int i = 0; i < n; i++) {
//			System.err.printf("levels[%d]: (%d, %d)\n", i, levels[i].a, levels[i].b); 
//		}

		int stars = 0;
		int count = 0;
		int comp = 0;

		while (comp < n) {
			boolean found = false;
			count++;

			// level 2
			for (int cc = 0; cc <= 1; cc++) {
				for (int i = 0; i < n; i++) {
					if (levels[i].b <= stars && levels[i].c == cc) {
						found = true;
						stars += (2 - levels[i].c);
						levels[i].c += 2;
						comp++;
//						System.err.printf("# [%d] %d-L2: a=%d, b=%d, c=%d, stars=%d\n",
//								count, i, levels[i].a, levels[i].b, levels[i].c, stars);
						break;
					}
				}
				if (found) break;
			}
			if (found) continue;
	
			// level 1
			for (int cc = 0; cc <= 2; cc += 2) {
				for (int i = 0; i < n; i++) {
					if (levels[i].a <= stars && levels[i].c == cc) {
						found = true;
						stars += (1 - levels[i].c / 2);
						levels[i].c += 1;
//						System.err.printf("# [%d] %d-L2: a=%d, b=%d, c=%d, stars=%d\n",
//								count, i, levels[i].a, levels[i].b, levels[i].c, stars);
						break;
					}
				}
				if (found) break;
			}
			if (found) continue;

//			System.err.printf("NG\n");
			return -1;
		}
		
//		System.err.printf("Result = %d\n", count);
		return count;
	}


}
