import static java.util.Arrays.deepToString;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class ProblemB_Pogo {

	// final static String FILENAME = "A-large";
	final static String FILENAME = "B-small-attempt1";
	// final static String FILENAME = "sample";
	final static String FILENAME_IN = FILENAME + ".in";
	final static String FILENAME_OUT = FILENAME + ".out";

	final static int THREADS = 1; // use 1 to solve them sequentially

	// VM arguments: -ea -Xms4096M -Xmx4096M

	static class Solver implements Callable<String> {

		// PROBLEM SOLUTION STARTS HERE
		// -----------------------------------------------------------
		// ----------------------------------------------------------------------------------------

		Solver(Scanner in, int testId) {
			this.testId = testId;

			// TODO: Read input
			X = in.nextInt();
			Y = in.nextInt();
		}

		// TODO: Define input variables

		private final int X, Y;

		class State {
			int x, y;

			int[] xold;
			int[] yold;

			public State() {
				yold = xold = new int[0];
			}

			@Override
			public int hashCode() {
				final int prime = 31;
				int result = 1;
				result = prime * result + x;
				result = prime * result + y;
				return result;
			}

			@Override
			public boolean equals(Object obj) {
				State s = (State) obj;
				return x == s.x && y == s.y;
			}

			@Override
			public String toString() {
				return "State [x=" + x + ", y=" + y + ", xold=" + Arrays.toString(xold) + ", yold="
						+ Arrays.toString(yold) + "]";
			}

			public State(State parent, int xinc, int yinc) {
				xold = Arrays.copyOf(parent.xold, parent.xold.length + 1);
				yold = Arrays.copyOf(parent.yold, parent.yold.length + 1);

				x = parent.x + xinc * xold.length;
				y = parent.y + yinc * yold.length;

				xold[xold.length - 1] = x;
				yold[yold.length - 1] = y;

			}

			public List<State> returnsNextStates() {
				List<State> ret = new ArrayList<>();
				ret.add(new State(this, 1, 0));
				ret.add(new State(this, -1, 0));
				ret.add(new State(this, 0, 1));
				ret.add(new State(this, 0, -1));
				return ret;
			}
		}

		@Override
		public String call() throws Exception {
			long now = System.nanoTime();

			// TODO: Solve problem here and return result as a string

			Set<State> cache = new HashSet<>();
			Queue<State> queue = new LinkedList<>();
			queue.add(new State());
			long min = Long.MAX_VALUE;
			int[] xmin = null, ymin = null;

			State state;
			while ((state = queue.poll()) != null) {

				if (min < 500) {
					break;
				}

				for (State add : state.returnsNextStates()) {
					if (add.x == X && add.y == Y) {
						if (min > add.xold.length) {
							min = add.xold.length;
							xmin = add.xold;
							ymin = add.yold;
						}
					} else if (add.xold.length + 1 < min && add.xold.length < 500) {
						if (!cache.contains(add)) {
							queue.add(add);
							cache.add(add);
						}
					}
				}
			}

			StringBuilder str = new StringBuilder();
			int xold = 0, yold = 0;
			for (int i = 0; i < xmin.length; i++) {
				if (xmin[i] == xold) {
					if (ymin[i] > yold) {
						str.append('N');
					} else {
						str.append('S');
					}
				} else {
					if (xmin[i] > xold) {
						str.append('E');
					} else {
						str.append('W');
					}
				}
				xold = xmin[i];
				yold = ymin[i];
			}

			String res = str.toString();

			System.err.println(String.format("%4d ms %s", (System.nanoTime() - now) / 1000000, res));
			return res;
		}

		// PROBLEM SOLUTION ENDS HERE
		// -------------------------------------------------------------
		// ----------------------------------------------------------------------------------------

		final int testId;
	}

	static void debug(Object... os) {
		System.err.println(deepToString(os));
	};

	public static void main(String[] args) throws FileNotFoundException, InterruptedException {
		long now = System.nanoTime();
		System.setIn(new FileInputStream(FILENAME_IN));
		System.setOut(new PrintStream(new FileOutputStream(FILENAME_OUT)));
		Scanner in = new Scanner(System.in);
		int numTests = in.nextInt();
		in.nextLine();
		System.err.println(String.format("TESTS: %d", numTests));
		List<Solver> solvers = new ArrayList<Solver>();
		for (int i = 0; i < numTests; i++) {
			solvers.add(new Solver(in, i + 1));
		}
		ExecutorService executor = Executors.newFixedThreadPool(THREADS);
		List<Future<String>> solutions = executor.invokeAll(solvers);
		for (int i = 0; i < numTests; i++) {
			try {
				System.out.println(String.format("Case #%d: %s", solvers.get(i).testId, solutions.get(i).get()));
			} catch (Exception e) {
				System.out.println(String.format("Case #%d: EXCEPTION !!!!!", solvers.get(i).testId));
				System.err.println(String.format("Case #%d: EXCEPTION !!!!!", solvers.get(i).testId));
				e.printStackTrace(System.err);
			}
		}
		executor.shutdown();
		System.err.println(String.format("TOTAL: %d ms", (System.nanoTime() - now) / 1000000));
	}

}