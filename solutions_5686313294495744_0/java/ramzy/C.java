package codejam.y2016.r2b;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

public class C {
	private static final String DIR = "/Users/ramzy/dev/workspaces/codejam/codejam/";
	private static final String FILE_NAME = "c-small";
	
	public static class Params {
		int t;
		// add input params
		int N;
		String[][] W;
		// add input params
	}

	public void solve(Scanner scanner, PrintWriter writer) {
		int T = scanner.nextInt();
		for (int t = 1; t <= T; t++) {
			Params params = new Params();
			params.t = t;
			// read params
			int N = scanner.nextInt();
			params.N = N;
			params.W = new String[N][2];
			for (int i = 0; i < N; i++) {
				params.W[i] = new String[] {scanner.next(), scanner.next()};
			}
			// read params
			submit(params);
		}
		printSolution(writer);
	}

	// solve the problem
	public int solve(Params params) {
		int result = 0;
		Set<String> s1 = new HashSet<String>(params.N);
		Set<String> s2 = new HashSet<String>(params.N);
		Set<String> s3 = new HashSet<String>(params.N);
		for (int i = 0; i < params.N; i++) {
			String w1 = params.W[i][0];
			String w2 = params.W[i][1];
			String w3 = w1 + " " + w2;
			if (!s3.contains(w3)) {
				s1.add(w1);
				s2.add(w2);
				s3.add(w3);
			} else {
				result++;
			}
		}
		int r1 = params.N - result - s1.size();
		int r2 = params.N - result - s2.size();
		int min = Math.min(r1, r2);
		return result + min;
	}

	/************************************************************************/
	
	public static void main(String[] args) throws Exception {
		PrintWriter writer = new PrintWriter(new FileOutputStream(DIR + FILE_NAME + ".out"));
		Scanner scanner = new Scanner(new FileInputStream(DIR + FILE_NAME + ".in"));
		C problem = new C(Runtime.getRuntime().availableProcessors() / 2);
		Instant before = Instant.now();
		problem.solve(scanner, writer);
		Instant after = Instant.now();
		System.out.println("took " + ChronoUnit.MILLIS.between(before, after) + " millis");
		writer.close();
		scanner.close();
	}

	public C(int threadsNum) {
		executor = Executors.newFixedThreadPool(threadsNum);
	}

	private void printSolution(PrintWriter writer) {
		List<String> results = collect();
		results.forEach(result -> writer.println(result));
		System.out.println("------------------------------------");
		results.forEach(result -> System.out.println(result));
	}

	public String solveString(Params params) {
		return "Case #" + params.t + ": " + solve(params);
	}

	private class Worker implements Callable<String> {
		private Params params;
		public Worker(Params params) {
			this.params = params;
		}
		public String call() {
			String solution = solveString(params);
			System.out.println(solution);
			return solution;
		}
	}
	
	private List<Future<String>> results = new ArrayList<Future<String>>();
	private ExecutorService executor;
	
	public void submit(Params params) {
		Future<String> result = executor.submit(new Worker(params));
		results.add(result);
	}
	
	public List<String> collect() {
		executor.shutdown();
		try {
			executor.awaitTermination(1, TimeUnit.HOURS);
		} catch (InterruptedException e) {
			throw new RuntimeException("interrupted", e);
		}
		return results.parallelStream()
				.map(future -> {
					try {
						return future.get();
					} catch (Exception e) {
						throw new RuntimeException("not cool", e);
					}
				})
				.collect(Collectors.toList());
	}
}
