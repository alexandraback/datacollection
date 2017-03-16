import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemC {
	private enum RunType {
		DEBUG, TEST, SMALL, LARGE
	}

	private static RunType runType = RunType.SMALL;

	private static int caseCount;

	public static void main(String[] args) throws Throwable {
		switch (runType) {
		case TEST:
			System.setIn(new FileInputStream("c-test.in"));
			break;
		case SMALL:
			System.setIn(new FileInputStream("c-small.in"));
			System.setOut(new PrintStream(new FileOutputStream("c-small.out")));
			break;
		case LARGE:
			System.setIn(new FileInputStream("c-large.in"));
			System.setOut(new PrintStream(new FileOutputStream("c-large.out")));
			break;
		}

		Scanner in = new Scanner(System.in);

		caseCount = in.nextInt();
		in.nextLine();

		for (int n = 1; n <= caseCount; n++) {
			int N = in.nextInt();
			in.nextLine();

			boolean[] lanes = new boolean[N];
			double[] positions = new double[N];
			int[] speeds = new int[N];
			for (int i = 0; i < N; i++) {
				lanes[i] = in.next().equals("R");
				speeds[i] = in.nextInt();
				positions[i] = in.nextInt();
				in.nextLine();
			}

			double res = solve(N, lanes, positions, speeds);
			String output = "";

			if (res < 0)
				output = "Possible";
			else
				output = res + "";

			System.out.println("Case #" + n + ": " + output);
		}

		System.in.close();
		System.out.close();
	}

	private static double solve(int N, boolean[] lanes, double[] positions,
			int[] speeds) {
		double time = 0;
		int count0 = 0;
		do {
			sort(N, lanes, positions, speeds);
			//System.out.println("BEFORE: " + time);
			/*for (int i = 0; i < N; i++) {
				System.out.println(lanes[i] + " " + positions[i] + " " + speeds[i]);
			}*/
			if (possible(N, lanes, positions, speeds))
				return -1;
//			System.exit(0);
			double dt = nextCollision(N, lanes, positions, speeds);
			if (dt == 0) {
				count0++;
				if (count0 > N)
					break;
			} else {
				count0 = 0;
			}
			//System.out.println(dt);
			sim(N, lanes, positions, speeds, dt);
			sort(N, lanes, positions, speeds);
			time += dt;
			/*System.out.println("AFTER: " + time);
			for (int i = 0; i < N; i++) {
				System.out.println(lanes[i] + " " + positions[i] + " " + speeds[i]);
			}*/
			//System.out.println();
		} while (tryswitch(N, lanes, positions, speeds));
		return time;
	}

	private static double nextCollision(int N, boolean[] lanes,
			double[] positions, int[] speeds) {
		double min = Double.MAX_VALUE;
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (lanes[j] != lanes[i])
					continue;
				if (speeds[j] >= speeds[i])
					continue;
				int sdif = speeds[i] - speeds[j];
				double ddif = positions[j] - positions[i] - 5;
				double dt = ddif / sdif;
				if (dt < min)
					min = dt;
			}
		}
		if (min == Double.MAX_VALUE)
			System.exit(0);
		return min;
	}

	private static boolean tryswitch(int N, boolean[] lanes,
			double[] positions, int[] speeds) {
		for (int i = 0; i < N - 1; i++) {
			boolean blocked = false;
			for (int j = i + 1; j < N; j++) {
				if (lanes[j] != lanes[i])
					continue;
				if (speeds[j] >= speeds[i])
					continue;
				if (Math.abs(positions[j] - positions[i] - 5.) < .00001) {
					blocked = true;
					break;
				}
			}
			if (!blocked)
				continue;
			for (int j = 0; j < N; j++) {
				if (lanes[j] == lanes[i]) continue;
				if (Math.abs(positions[i] - positions[j]) < 5)
					return false;
			}
			lanes[i] = !lanes[i];
		}
		return true;
	}

	private static void sim(int N, boolean[] lanes, double[] positions,
			int[] speeds, double dt) {
		for (int i = 0; i < N; i++) {
			positions[i] += speeds[i] * dt;
		}
	}

	private static void sort(int N, boolean[] lanes, double[] positions,
			int[] speeds) {
		boolean btemp;
		double dtemp;
		int itemp;
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (positions[j] >= positions[i])
					continue;
				btemp = lanes[i];
				lanes[i] = lanes[j];
				lanes[j] = btemp;
				dtemp = positions[i];
				positions[i] = positions[j];
				positions[j] = dtemp;
				itemp = speeds[i];
				speeds[i] = speeds[j];
				speeds[j] = itemp;
			}
		}
	}

	private static boolean possible(int N, boolean[] lanes, double[] positions,
			int[] speeds) {
		int[] curspeeds = new int[2];
		for (int i = 0; i < N; i++) {
			int x = lanes[i] ? 1 : 0;
			if (speeds[i] < curspeeds[x])
				return false;
			curspeeds[x] = speeds[i];
		}
		return true;
	}

}
