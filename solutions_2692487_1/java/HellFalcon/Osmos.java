import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Osmos {

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
		int mote, n;
		int[] motes;
		
		public Solver(int testId, int mote, int n, int[] motes) {
			this.testId = testId;
			this.mote = mote;
			this.n = n;
			this.motes = motes.clone();
		}
		
		public Result call() {
			Arrays.sort(motes);
			int req = 0;
			int minMoves = n;
			if (mote > 1) {
				for (int i = 0; i < n; i++) {
					while (mote <= motes[i]) {
						mote += mote-1;
						req++;
					}
					mote += motes[i];
					minMoves = Math.min(minMoves, n-i-1+req);
				}				
			}
			Result result = new Result();
			result.add("Case #" + testId + ": " + minMoves);
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
			in = new BufferedReader(new FileReader(new File("A-large.in")), 256 << 10);
			out = new BufferedWriter(new FileWriter(new File("output.txt")), 256 << 10);

			executor = Executors.newFixedThreadPool(5);
			List<Future<Result>> results = new LinkedList<Future<Result>>();

			int testsNumber = Integer.parseInt(in.readLine().trim());
			for (int testId = 1; testId <= testsNumber; testId++) {
				StringTokenizer tokenizer = new StringTokenizer(in.readLine());
				int mote = Integer.parseInt(tokenizer.nextToken());
				int n = Integer.parseInt(tokenizer.nextToken());
				tokenizer = new StringTokenizer(in.readLine());
				int[] motes = new int[n];
				for (int i = 0; i < n; i++) motes[i] = Integer.parseInt(tokenizer.nextToken());
				results.add(executor.submit(new Solver(testId, mote, n, motes)));
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
