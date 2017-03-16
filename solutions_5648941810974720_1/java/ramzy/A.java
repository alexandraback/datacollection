package codejam.y2016.r2b;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

public class A {
	private static final String DIR = "/Users/ramzy/dev/workspaces/codejam/codejam/";
	private static final String FILE_NAME = "A-large";
	
	public static class Params {
		int t;
		// add input params
		String S;
		// add input params
	}

	public void solve(Scanner scanner, PrintWriter writer) {
		int T = scanner.nextInt();
		for (int t = 1; t <= T; t++) {
			Params params = new Params();
			params.t = t;
			// read params
			params.S = scanner.next();
			// read params
			submit(params);
		}
		printSolution(writer);
	}

	// solve the problem
	public String solve(Params params) {
		Map<Character, Integer> map = toMap(params.S);
		int[] numbers = new int[10];

		remove(map, numbers, 0, 'Z', "ZERO");
		remove(map, numbers, 2, 'W', "TWO");
		remove(map, numbers, 4, 'U', "FOUR");
		remove(map, numbers, 6, 'X', "SIX");
		remove(map, numbers, 8, 'G', "EIGHT");
		
		remove(map, numbers, 3, 'H', "THREE");
		remove(map, numbers, 7, 'S', "SEVEN");
		
		remove(map, numbers, 5, 'V', "FIVE");

		remove(map, numbers, 1, 'O', "ONE");
		
		remove(map, numbers, 9, 'I', "NINE");
		
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j < numbers[i]; j++) {
				sb.append(i);
			}
		}
		return sb.toString();
	}

	private void remove(Map<Character, Integer> map, int[] numbers, int number, char c, String string) {
		if (map.get(c) == null || map.get(c) == 0) {
			return;
		}
		numbers[number] = map.get(c);
		for (int i = 0; i < string.length(); i++) {
			char c2 = string.charAt(i);
			map.put(c2, map.get(c2) - numbers[number]);
		}
	}

	private Map<Character, Integer> toMap(String s) {
		Map<Character, Integer> map = new HashMap<Character, Integer>(s.length());
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			Integer counter = map.get(c);
			if (counter == null) {
				map.put(c, 1);
			} else {
				map.put(c, counter+1);
			}
		}
		return map;
	}

	/************************************************************************/
	
	public static void main(String[] args) throws Exception {
		PrintWriter writer = new PrintWriter(new FileOutputStream(DIR + FILE_NAME + ".out"));
		Scanner scanner = new Scanner(new FileInputStream(DIR + FILE_NAME + ".in"));
		A problem = new A(Runtime.getRuntime().availableProcessors() / 2);
		Instant before = Instant.now();
		problem.solve(scanner, writer);
		Instant after = Instant.now();
		System.out.println("took " + ChronoUnit.MILLIS.between(before, after) + " millis");
		writer.close();
		scanner.close();
	}

	public A(int threadsNum) {
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
