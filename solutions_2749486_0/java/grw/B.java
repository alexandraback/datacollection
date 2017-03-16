import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Map;
import java.util.NavigableMap;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeMap;

import static java.lang.Math.min;
import static java.lang.Math.max;
import static java.lang.Math.abs;

public class B {
	public static void main(String[] args) throws Exception {
		new Rename.Problem().solveAll(B.class.getName()+"-");
	}
	
	static class Rename {
		static class Task extends AbstractTask<Precomputed> {
			int X, Y;
			Task(Scanner s) {
				X = s.nextInt();
				Y = s.nextInt();
				s.nextLine();
			}
			@Override
			Object solve(Precomputed pd) {
				StringBuilder sb = new StringBuilder();
				if (X>0)
					for (int i=0; i<X; i++) {
						sb.append('W');
						sb.append('E');
					}
				else
					for (int i=0; i<-X; i++) {
						sb.append('E');
						sb.append('W');
					}					
				if (Y>0)
					for (int i=0; i<Y; i++) {
						sb.append('S');
						sb.append('N');
					}
				else
					for (int i=0; i<-Y; i++) {
						sb.append('N');
						sb.append('S');
					}					
				return sb;
			}			
		}
		
		static class Precomputed {
			Precomputed(Scanner s) {
			}
			public static void precompute(PrintWriter w) {
			}
		}
		
		static class Problem extends AbstractProblem<Task, Precomputed> {
			@Override
			Task createTask(Scanner s) {
				return new Task(s);
			}
			@Override
			void precompute(PrintWriter w) {
				Precomputed.precompute(w);
			}
			@Override
			Precomputed readPrecomputed(Scanner s) {
				return new Precomputed(s);
			}
		}
	}

	static class Osmos {
		static class Task extends SimpleTask {
			long A;
			int N;
			long m[];
			Task(Scanner s) {
				A = s.nextLong();
				N = s.nextInt();
				s.nextLine();
				m = new long[N];
				for (int i = 0; i<N; i++)
					m[i] = s.nextLong();
				s.nextLine();
			}
			@Override
			Object solve(Void pd) {
				Arrays.sort(m);
				return Integer.valueOf(numberOfOperations(A,0,N));
			}
			int numberOfOperations(long a, int i, int n) {
				if (n>0) {
					if (m[i]<a)
						return numberOfOperations(a+m[i], i+1, n-1);
					if (a==1)
						return n;
					return min(numberOfOperations(2*a-1, i, n)+1, n);
				}
				return 0;
			}
		}
		
		static class Problem extends SimpleProblem {
			@Override
			Task createTask(Scanner s) {
				return new Task(s);
			}
		}
	}
	
	static class Bullseye {
		static class Task extends SimpleTask {
			BigInteger R, T;
			Task(Scanner s) {
				R = BigInteger.valueOf(s.nextLong());
				T = BigInteger.valueOf(s.nextLong());
				s.nextLine();
			}
			@Override
			Object solve(Void pd) {
				BigInteger d = R.multiply(TWO).subtract(ONE);
				BigInteger delta = d.multiply(d).add(T.multiply(EIGHT));
				BigInteger deltaRoot = root(2, delta).floor;
				BigInteger b = ZERO.subtract(R.multiply(TWO)).add(ONE);
				BigInteger x1 = b.add(deltaRoot).divideAndRemainder(FOUR)[0];
				BigInteger x2 = b.subtract(deltaRoot).divideAndRemainder(FOUR)[0];
				if (x1.compareTo(x2) > 0)
					return x1;
				else
					return x2;				
			}
		}
		
		static class Problem extends SimpleProblem {
			@Override
			Task createTask(Scanner s) {
				return new Task(s);
			}
		}
	}

	static class Energy {
		static class Activity {
			final BigInteger value;
			final int pos;
			Activity(BigInteger v, int p) {
				value = v;
				pos = p;
			}
		}

		private static class Task extends SimpleTask {
			BigInteger E, R;
			int N;
			PriorityQueue<Activity> w;
			Task(Scanner s) {
				E = BigInteger.valueOf(s.nextLong());
				R = BigInteger.valueOf(s.nextLong());
				N = s.nextInt();
				s.nextLine();
				w = new PriorityQueue<>(N, new Comparator<Activity>() {
					@Override
					public int compare(Activity o1, Activity o2) {
						int d = o2.value.compareTo(o1.value);
						if (d == 0)
							if (o1.pos == o2.pos)
								return 0;
							else
								return o2.pos - o1.pos;
						else
							return d;
					}
				});
				for (int i = 0; i < N; i++)
					w.add(new Activity(
							BigInteger.valueOf(s.nextLong()), i));
				s.nextLine();				
			}
			@Override
			Object solve(Void pd) {
				NavigableMap<Integer, BigInteger> rs = new TreeMap<>();
				rs.put(0, E);
				rs.put(N, R.min(E));
				BigInteger gain = ZERO;
				while (!w.isEmpty()) {
					Activity a = w.remove();
					Map.Entry<Integer, BigInteger> r = rs.floorEntry(a.pos);
					Map.Entry<Integer, BigInteger> r1 = rs.higherEntry(a.pos);
					BigInteger d = r1
							.getValue()
							.subtract(
									R.multiply(BigInteger.valueOf(r1.getKey()
											.intValue() - a.pos))).max(ZERO);
					BigInteger e = r
							.getValue()
							.add(R.multiply(BigInteger.valueOf(a.pos
									- r.getKey().intValue()))).min(E);
					gain = gain.add(a.value.multiply(e.subtract(d)));
					rs.put(a.pos, e);
					rs.put(a.pos + 1, d.add(R).min(E));
				}
				return gain;
			}
		}

		static class Problem extends SimpleProblem {
			@Override
			protected Task createTask(Scanner s) {
				return new Task(s);
			}
		}
	}

	/*
	 * =====================================================
	 */
	
	static abstract class AbstractTask<T> {
		abstract Object solve(T d);
	}
	
	static abstract class AbstractProblem<T extends AbstractTask<P>, P> {
		abstract void precompute(PrintWriter w);
		abstract P readPrecomputed(Scanner s);
		abstract T createTask(Scanner s);
		
		Object solveTask(Scanner s, P p) {
			return createTask(s).solve(p);
		}

		static final String DOWNLOADS = "Downloads";
		static final String UPLOADS = "workspace/java/CodeJam2013/src";
		static final Charset ENCODING = StandardCharsets.US_ASCII;

		static final String home = getHome();

		void printCaseHead(PrintWriter writer, int i, String total) {
			writer.print("Case #");
			writer.print(i);
			writer.print(total);
			writer.print(": ");
		}

		void printCaseHead(PrintWriter writer, int i) {
			printCaseHead(writer, i, "");
		}

		void solveBatch(Scanner preScanner, Scanner scanner,
				PrintWriter writer) throws IOException {
			P p = readPrecomputed(preScanner);
			int t = scanner.nextInt();
			scanner.nextLine();
			PrintWriter stdout = new PrintWriter(System.out);
			String total = "/" + t;
			for (int i = 1; i <= t; i++) {
				printCaseHead(writer, i);
				printCaseHead(stdout, i, total);
				stdout.flush();
				String solution = solveTask(scanner, p).toString();
				writer.println(solution);
				stdout.println(solution);
				stdout.flush();
			}
		}

		void solveBatch(Path pre, Path input, Path output)
				throws IOException {
			Scanner preScanner = null;
			try {
				preScanner = new Scanner(pre, ENCODING.name());
			} catch (NoSuchFileException e) {
			}
			try (Scanner scanner = new Scanner(input, ENCODING.name());
					PrintWriter writer = new PrintWriter(
							Files.newBufferedWriter(output, ENCODING))) {
				solveBatch(preScanner, scanner, writer);
			} finally {
				if (preScanner != null)
					preScanner.close();
			}
		}

		Path getPrecomputedFilePath() {
			return Paths.get(home, UPLOADS, getClass().getName() + ".pre");
		}

		void solveBatch(String file) throws IOException {
			solveBatch(getPrecomputedFilePath(),
					Paths.get(home, DOWNLOADS, file + ".in"),
					Paths.get(home, UPLOADS, file + ".out"));
		}

		void solveAll(String prefix) throws IOException {
			for (Path entry : Files.newDirectoryStream(Paths.get(home,
					DOWNLOADS))) {
				if (!Files.isDirectory(entry)) {
					String fn = entry.getFileName().toString();
					if (fn.startsWith(prefix) && fn.endsWith(".in")) {
						String base = fn.substring(0, fn.length() - 3);
						System.out.print(base);
						if (!Paths.get(home, UPLOADS, base + ".out").toFile()
								.exists()) {
							System.out.println(" - new file. processing");
							solveBatch(base);
						} else {
							System.out
									.println(" - already processed. skipping");
						}
					}
				}
			}
		}

		void precompute() throws IOException {
			precompute(new PrintWriter(Files.newBufferedWriter(
					getPrecomputedFilePath(), ENCODING)));
		}

		static String getHome() {
			String home = System.getenv().get("HOME");
			if (home == null)
				home = System.getenv().get("USERPROFILE");
			if (home == null)
				throw new RuntimeException("no home dir");
			return home;
		}
	}
	
	static abstract class SimpleTask extends AbstractTask<Void> {
	}
	
	static abstract class SimpleProblem extends AbstractProblem<SimpleTask, Void> {
		@Override
		Void readPrecomputed(Scanner s) {
			return null;
		}
		@Override
		void precompute(PrintWriter w) {
		}		
	}

	public static class FloorAndCeil<T> {
		public final T floor, ceil;
		public FloorAndCeil(T f, T c) {
			floor = f;
			ceil = c;
		}
	}

	public final static BigInteger ZERO = BigInteger.ZERO;
	public final static BigInteger ONE = BigInteger.ONE;
	public final static BigInteger TWO = ONE.add(ONE);
	public final static BigInteger THREE = TWO.add(ONE);
	public final static BigInteger FOUR = TWO.multiply(TWO);
	public final static BigInteger EIGHT = FOUR.multiply(TWO);

	/**
	 * Computes a floor and ceil for a 'p' degree root of BigInteger 'a'
	 */
	public static FloorAndCeil<BigInteger> root(int p, BigInteger a) {
		if (ZERO.equals(a))
			return new FloorAndCeil<>(ZERO, ZERO);
		if (ONE.equals(a))
			return new FloorAndCeil<>(ONE, ONE);
		BigInteger floor = ONE;
		BigInteger ceilPlusOne = floor.add(ONE);
		BigInteger ceil = a;
		while (!ceilPlusOne.equals(ceil)) {
			BigInteger mid = ceilPlusOne.add(ceil).shiftRight(1);
			int cmp = mid.pow(p).compareTo(a);
			if (cmp == 0)
				return new FloorAndCeil<>(mid, mid);
			if (cmp > 0) {
				ceil = mid;
			} else {
				floor = mid;
				ceilPlusOne = floor.add(ONE);
			}
		}
		return new FloorAndCeil<BigInteger>(floor, ceil);
	}
	
}
