import java.util.Scanner;

/*
 2
 2
 180 1 100000
 180 1 1
 1
 180 2 1
 */
public class deertiny {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int cases = in.nextInt();
		int cn = 0;

		while (cn++ < cases) {
			int groups = in.nextInt();

			int idx = 0;
			int[] start = new int[2];
			int[] time = new int[2];
			for (int i = 0; i < groups; i++) {
				int startPos = in.nextInt();
				int hikers = in.nextInt();
				int timeToCircle = in.nextInt();

				for (int j = 0; j < hikers; j++) {
					start[idx] = startPos;
					time[idx] = timeToCircle + j;
					idx++;
				}
			}

			int ret;
			if (idx <2) {
				ret = 0;
			} else if (time[0] == time[1]) {
				ret = 0;
			} else {
				// gaurentees: 2 hikers of differant speed
				// fastest in 0
				if (time[0] > time[1]) {
					int tmp = time[0];
					time[0] = time[1];
					time[1] = tmp;
					tmp = start[0];
					start[0] = start[1];
					start[1] = tmp;
				}

				double[] finishLap = new double[2];
				for (int i = 0; i < finishLap.length; i++) {
					finishLap[i] = time[i] * ((360-start[i]) / 360d);
				}

				double fastFinish = finishLap[0];
				double slowFinish = finishLap[1];
				// if fast finishes 2 laps, we should have passed slow
				if (fastFinish + time[0] <= slowFinish) {
					ret = 1;
				} else {
					ret = 0;
				}
			}

			System.out.printf("Case #%d: %d\n", cn, ret);
		}
	}
}
