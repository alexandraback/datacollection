import java.io.File;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input.in"));
		int t, n, s, p, ans;
		int scores[];
		t = in.nextInt();
		for (int tc = 1; tc <= t; tc++) {
			n = in.nextInt();
			s = in.nextInt();
			p = in.nextInt();
			ans = 0;
			scores = new int[n];
			for (int i = 0; i < scores.length; i++) {
				scores[i] = in.nextInt();
			}

			for (int i = 0; i < scores.length; i++) {
				if (scores[i] == 0 && p != 0)
					continue;
				if (scores[i] / 3 >= p) {
					ans++;
					continue;
				}
				if ((double) scores[i] / 3 == scores[i] / 3) {
					if (p - scores[i] / 3 == 1 && s > 0) {
						ans++;
						s--;
						continue;
					}
				} else {
					double temp = (double) scores[i] / 3;
					if (scores[i] - 3 * Math.floor(temp) < 2
							&& scores[i] - 2 * Math.floor(temp) >= p)
						ans++;
					else if (scores[i] - 3 * Math.ceil(temp) < 2
							&& (scores[i] - 2 * Math.ceil(temp) >= p || Math
									.ceil(temp) >= p))
						ans++;
					else if (scores[i] - 3 * Math.floor(temp) == 2 && s != 0
							&& scores[i] - 2 * Math.floor(temp) >= p) {
						ans++;
						s--;
					} else if (scores[i] - 3 * Math.ceil(temp) == 2 && s != 0
							&& scores[i] - 2 * Math.ceil(temp) >= p) {
						ans++;
						s--;
					}
				}

			}
			System.out.println("Case #" + tc + ": " + ans);

		}
	}
}
