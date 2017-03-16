import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class FallingDiamonds {

	private static final class Result extends LinkedList<String> {
		
		private static final long serialVersionUID = 201212121200L;

		public void writeTo(Appendable appendable) throws IOException {
			for (String line : this) {
				appendable.append(line + "\n");
			}
		}
	}

	private static final class Solver implements Callable<Result> {
		
		private int testId;
		int n, x, y;
		
		public Solver(int testId, int n, int x, int y) {
			this.testId = testId;
			this.n = n;
			this.x = Math.abs(x);
			this.y = y;
		}
		
		double probability(int n, int size, int id) {
			double[][] p = new double[size+1][size+1];
			p[0][0] = 1.0;
			for (int i = 1; i <= size; i++) {
				p[0][i] += p[0][i-1] * 0.5;
				p[i][0] += p[i-1][0] * 0.5;
			}
			for (int i = 1; i < size; i++)
				for (int j = 1; j < size; j++) {
					p[i][j] = 0.5 * p[i-1][j] + 0.5 * p[i][j-1];
				}
			for (int i = 1; i < size; i++) {
				p[i][size] = p[i-1][size] + 0.5 * p[i][size-1];
				p[size][i] = p[size][i-1] + 0.5 * p[size-1][i];
			}
			p[size][size] = p[size-1][size] + p[size][size-1];
			double r = 0.0;
			for (int i = id; i <= size; i++)
				for (int j = 0; j <= size; j++)
					if (i+j == n) r += p[i][j];
			return r;
		}
		
		public Result call() {
			int ring = 0;
			int diamonds = 1;
			while (n >= diamonds) {
				ring++;
				diamonds += 4*ring + 1;
			}
			diamonds -= 4*ring + 1;
			n -= diamonds;
			int rring = (x+y)/2;
			int rid = y+1;
			double p = 0.0;
			if (rring < ring)
				p = 1.0;
			else if (rring == ring) {
				int size = 2 * ring;
				if (size + rid <= n)
					p = 1.0;
				else if (n < rid)
					p = 0.0;
				else {
					p = probability(n, size, rid);
				}
			}

			Result result = new Result();
			result.add("Case #" + testId + ": " + p);
			return result;
		}
	}
	
	private static void release(Closeable resource) {
		if (resource == null) return;
		try {
			resource.close();
		}
		catch (IOException ignore) {};
	}

	private static void release(ExecutorService resource) {
		if (resource == null) return;
		resource.shutdown();
	}

	public static void main(String[] args) {
		long startTime = System.currentTimeMillis();
		BufferedReader in = null;
		BufferedWriter out = null;
		ExecutorService executor = null;
		try {
			in = new BufferedReader(new FileReader(new File("B-large.in")), 256 << 10);
			out = new BufferedWriter(new FileWriter(new File("output.txt")), 256 << 10);

			executor = Executors.newFixedThreadPool(5);
			List<Future<Result>> results = new LinkedList<Future<Result>>();

			int testsNumber = Integer.parseInt(in.readLine().trim());
			for (int testId = 1; testId <= testsNumber; testId++) {
				StringTokenizer tokenizer = new StringTokenizer(in.readLine());
				int n = Integer.parseInt(tokenizer.nextToken());
				int x = Integer.parseInt(tokenizer.nextToken());
				int y = Integer.parseInt(tokenizer.nextToken());
				results.add(executor.submit(new Solver(testId, n, x, y)));
			}
			int testId = 1;
			for (Future<Result> future : results) {
				future.get().writeTo(out);
				System.out.println("Test #" + testId++ + " is completed");
			}
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
		finally {
			release(in);
			release(out);
			release(executor);
		}
		System.out.println("Execution completed in approximately " + (System.currentTimeMillis() - startTime) + " milliseconds");
	}
}
