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

public class FairAndSquire {

	private static final class Result extends LinkedList<String> {
		
		private static final long serialVersionUID = 201212121200L;

		public void writeTo(Appendable appendable) throws IOException {
			for (String line : this) {
				appendable.append(line + "\n");
			}
		}
	}

	private static final class Solver implements Callable<Result> {
		
		static int MAX_ROOT = 10000000;
		
		static long reverse(long v) {
			long r = 0;
			while (v > 0) {
				r = 10 * r + v % 10;
				v /= 10;
			}
			return r;
		}
		
		private static final int[] COUNTS = new int[MAX_ROOT + 1];
		static {
			int total = 0;
			for (int v = 1; v <= MAX_ROOT; v++) {
				long vv = (long)v*(long)v;
				if (v == reverse(v) &&  vv == reverse(vv)) total++;
				COUNTS[v] += total;
			}
		}
		
		private int testId;
		private long aa, bb;
		
		public Solver(int testId, long a, long b) {
			this.testId = testId;
			aa = a;
			bb = b;
		}
		
		public Result call() {
			int a = (int) Math.sqrt(aa);
			while ((long)a*(long)a < aa) a++;
			int b = (int) Math.sqrt(bb) + 1;
			while ((long)b*(long)b > bb) b--;
			Result result = new Result();
			result.add("Case #" + testId + ": " + (COUNTS[b] - COUNTS[a-1]));
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
			in = new BufferedReader(new FileReader(new File("C-small-attempt0.in")), 256 << 10);
			out = new BufferedWriter(new FileWriter(new File("output.txt")), 256 << 10);

			executor = Executors.newFixedThreadPool(5);
			List<Future<Result>> results = new LinkedList<Future<Result>>();

			int testsNumber = Integer.parseInt(in.readLine().trim());
			for (int testId = 1; testId <= testsNumber; testId++) {
				StringTokenizer tokenizer = new StringTokenizer(in.readLine());
				long a = Long.parseLong(tokenizer.nextToken());
				long b = Long.parseLong(tokenizer.nextToken());
				results.add(executor.submit(new Solver(testId, a, b)));
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
