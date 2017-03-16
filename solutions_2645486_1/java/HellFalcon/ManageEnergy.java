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

public class ManageEnergy {

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
		long e, r;
		int n;
		long[] v;
		
		public Solver(int testId, long e, long r, int n, long[] v) {
			this.testId = testId;
			this.e = e;
			this.r = r;
			this.n = n;
			this.v = v;
		}
		
		public Result call() {
			long ce = e;
			long total = 0;
			for (int i = 0; i < n; i++, ce += r) {
				int j;
				for (j = i+1; j < n; j++) {
					if (v[j] > v[i]) break;
				}
				if (j == n) {
					total += v[i] * ce;
					ce = 0;
				}
				else {
					long te = Math.max(0, e - (j-i) * r);
					if (ce > te) {
						total += v[i] * (ce-te);
						ce = te;											
					}
				}
			}
			Result result = new Result();
			result.add("Case #" + testId + ": " + total);
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
				long e = Integer.parseInt(tokenizer.nextToken());
				long r = Integer.parseInt(tokenizer.nextToken());
				int n = Integer.parseInt(tokenizer.nextToken());
				long[] v = new long[n];
				tokenizer = new StringTokenizer(in.readLine());
				for (int i = 0; i < n; i++) v[i] = Integer.parseInt(tokenizer.nextToken());
				results.add(executor.submit(new Solver(testId, e, r, n, v)));
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
