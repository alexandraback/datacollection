
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

import static java.lang.Math.*;

public class Lawnmower {

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
		private int n, m;
		private int[][] pattern;
		
		public Solver(int testId, int n, int m, int[][] pattern) {
			this.testId = testId;
			this.n = n;
			this.m = m;
			this.pattern = pattern;
		}
		
		public Result call() {
			String answer = "YES";
			mainLoop:
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					int ok = 2;
					int v = pattern[i][j];
					for (int ii = 0; ii < n; ii++)
						if (v < pattern[ii][j]) {
							ok--; break;
						}
					for (int jj = 0; jj < m; jj++)
						if (v < pattern[i][jj]) {
							ok--; break;
						}
					if (ok == 0) {
						answer = "NO";
						break mainLoop;
					}
				}
			Result result = new Result();
			result.add("Case #" + testId + ": " + answer);
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
			in = new BufferedReader(new FileReader(new File("B-small-attempt0.in")), 256 << 10);
			out = new BufferedWriter(new FileWriter(new File("output.txt")), 256 << 10);

			executor = Executors.newFixedThreadPool(5);
			List<Future<Result>> results = new LinkedList<Future<Result>>();

			int testsNumber = Integer.parseInt(in.readLine().trim());
			for (int testId = 1; testId <= testsNumber; testId++) {
				StringTokenizer tokenizer = new StringTokenizer(in.readLine());
				int n = Integer.parseInt(tokenizer.nextToken());
				int m = Integer.parseInt(tokenizer.nextToken());
				int[][] pattern = new int[n][m];
				for (int i = 0; i < n; i++) {
					tokenizer = new StringTokenizer(in.readLine());
					for (int j = 0; j < m; j++) {
						pattern[i][j] = Integer.parseInt(tokenizer.nextToken());
					}
				}
				results.add(executor.submit(new Solver(testId, n, m, pattern)));
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
