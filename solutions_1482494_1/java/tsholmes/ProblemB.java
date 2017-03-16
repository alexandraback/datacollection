import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemB {
	private enum RunType {
		DEBUG, TEST, SMALL, LARGE
	}

	private static RunType runType = RunType.LARGE;

	private static int caseCount;

	public static void main(String[] args) throws Throwable {
		switch (runType) {
		case TEST:
			System.setIn(new FileInputStream("b-test.in"));
			break;
		case SMALL:
			System.setIn(new FileInputStream("b-small.in"));
			System.setOut(new PrintStream(new FileOutputStream("b-small.out")));
			break;
		case LARGE:
			System.setIn(new FileInputStream("b-large.in"));
			System.setOut(new PrintStream(new FileOutputStream("b-large.out")));
			break;
		}

		Scanner in = new Scanner(System.in);

		caseCount = in.nextInt();
		in.nextLine();

		for (int n = 1; n <= caseCount; n++) {
			int N = in.nextInt();
			int[] as = new int[N];
			int[] bs = new int[N];

			for (int i = 0; i < N; i++) {
				as[i] = in.nextInt();
				bs[i] = in.nextInt();
			}

			String output = "";
			int res = solve(N, as, bs);
			if (res == -1)
				output = "Too Bad";
			else
				output = res + "";
			System.out.println("Case #" + n + ": " + output);
		}

		System.in.close();
		System.out.close();
	}

	public static int solve(int N, int[] as, int[] bs) {
		int stars = 0;
		int turns = 0;
		while (stars < N * 2) {
			int bi = -1;
			int minb = Integer.MAX_VALUE;
			for (int i = 0; i < N; i++) {
				if (bs[i] <= stars) {
					bi = i;
					minb = bs[i];
				}
			}
			if (bi != -1) {
				stars++;
				if (as[bi] != Integer.MAX_VALUE)
					stars++;
				bs[bi] = Integer.MAX_VALUE;
				as[bi] = Integer.MAX_VALUE;
				turns++;
				continue;
			}
			int ai = -1;
			int mina = Integer.MAX_VALUE;
			minb = Integer.MAX_VALUE;
			for (int i = 0; i < N; i++) {
				if (as[i] <= stars && (minb == Integer.MAX_VALUE || bs[i] > minb)) {
					ai = i;
					mina = as[i];
					minb = bs[i];
				}
			}
			if (ai != -1 && stars >= mina) {
				stars++;
				as[ai] = Integer.MAX_VALUE;
				turns++;
				continue;
			}
			return -1;
		}

		return turns;
	}

}
