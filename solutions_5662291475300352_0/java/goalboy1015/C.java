import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "C";
	static final String INPUT = "small1";
	static final String ID = "0";
	static final String PATH = "/Users/wangkai/Documents/codejam-commandline-1.2-beta1/source/";

	public static void main(String[] args) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int N = in.nextInt();
			List<Hiker> hikers = new ArrayList<Hiker>();
			for (int i = 0; i < N; i++) {
				int D = in.nextInt();
				int H = in.nextInt();
				int M = in.nextInt();
				for (int j = 0; j < H; j++) {
					hikers.add(new Hiker(D, M + j));
				}
			}

			int encounter;
			if (hikers.size() <= 1) {
				encounter = 0;
			} else {
				Hiker faster = hikers.get(0);
				Hiker slower = hikers.get(1);
				if (faster.time > slower.time) {
					Hiker temp = faster;
					faster = slower;
					slower = temp;
				}

				if (faster.time == slower.time) {
					encounter = 0;
				} else {
					int distance;
					if (faster.pos <= slower.pos) {
						distance = slower.pos - faster.pos + 360;
					} else {
						distance = 360 - (faster.pos - slower.pos);
					}

					if ((long) distance * faster.time > (360L - slower.pos)
							* (slower.time - faster.time)) {
						encounter = 0;
					} else {
						encounter = 1;
					}
				}
			}

			out.println(encounter);
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}
}

class Hiker {
	int pos;
	int time;

	Hiker(int pos, int time) {
		this.pos = pos;
		this.time = time;
	}
}