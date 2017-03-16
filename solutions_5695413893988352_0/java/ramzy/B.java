package codejam.y2016.r2b;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

public class B {
	private static final String DIR = "/Users/ramzy/dev/workspaces/codejam/codejam/";
	private static final String FILE_NAME = "b-small";
	
	public static class Params {
		int t;
		// add input params
		String C;
		String J;
		// add input params
	}

	public void solve(Scanner scanner, PrintWriter writer) {
		int T = scanner.nextInt();
		for (int t = 1; t <= T; t++) {
			Params params = new Params();
			params.t = t;
			// read params
			params.C = scanner.next();
			params.J = scanner.next();
			// read params
			submit(params);
		}
		printSolution(writer);
	}

	private static String solve(Params params) {
		char[] c = params.C.toCharArray();
		char[] j = params.J.toCharArray();

		int l = c.length;
		int min = Integer.MAX_VALUE;
		int kNum = Integer.MAX_VALUE;
		String c1 = null;
		String j1 = null;

		if (l == 1) {
			if (c[0] == '?' && j[0] == '?') {
				c[0] = j[0] = '0';
			} else if (c[0] == '?') {
				c[0] = j[0];
			} else {
				j[0] = c[0];
			}
			c1 = new String(c);
			j1 = new String(j);
		} else if (l == 2) {
			for (int i = 0; i < 100; i++) {
				if ((c[0] != '?' && c[0] - '0'!= i / 10) || (c[1] != '?' && c[1]- '0' != i % 10)) {
					continue;
				}
				for (int k = 0; k < 100; k++) {
					if ((j[0] != '?' && j[0] - '0'!= k / 10) || (j[1] != '?' && j[1]- '0' != k % 10)) {
						continue;
					} else {
						int diff = Math.abs(k - i);
						if (diff < min || (diff == min && kNum > k)) {
							kNum = k;
							min = diff;
							c1 = i / 10 + "" + i % 10;
							j1 = k / 10 + "" + k % 10;
						}
					}
				}
			}
		} else {
			for (int i = 0; i < 1000; i++) {
				int d1 = i / 100;
				int d2 = (i/10) % 10;
				int d3 = i % 10;
				if ((c[0] != '?' && c[0]- '0' != d1) || (c[1] != '?' && c[1]- '0' != d2)  || (c[2] != '?' && c[2]- '0' != d3)) {
					continue;
				}
				for (int k = 0; k < 1000; k++) {
					int dd1 = k / 100;
					int dd2 = (k/10) % 10;
					int dd3 = k % 10;
					if ((j[0] != '?' && j[0] - '0' != dd1) || (j[1] != '?' && j[1] - '0' != dd2)  || (j[2] != '?' && j[2]- '0' != dd3)) {
						continue;
					} else {
						int diff = Math.abs(k - i);
						if (diff < min || (diff == min && kNum > k)) {
							kNum = k;
							min = diff;
							c1 = d1 + "" + d2 + "" + d3;
							j1 = dd1 + "" + dd2 + "" + dd3;
						}
					}
				}
			}
		}

		return c1 + " " + j1;
	}
	
	private static String solve2(Params params) {
		char[] c = params.C.toCharArray();
		char[] j = params.J.toCharArray();
		char[] c1 = params.C.toCharArray();
		char[] j1 = params.J.toCharArray();
		
		boolean difference = false;
		boolean cIsBigger = false;
		int last = Integer.MAX_VALUE;
		for (int i = 0; i < c.length; i++) {
			if (c[i] == '?' && j[i] == '?') {
				if (i < last)
					last = i;
			}
			if (!difference) {
				if (c[i] == '?') {
					if (j[i] == '?') {
						c[i] = '0';
						j[i] = '0';
					} else {
						c[i] = j[i];
					}
				} else {
					if (j[i] == '?') {
						j[i] = c[i];
					} else {
						if (c[i] == j[i])
							continue;
						else if (c[i] > j[i]) {
							cIsBigger = true;
							difference = true;
						}
						else {
							cIsBigger = false;
							difference = true;
						}
					}
				}
			} else {
				if (cIsBigger) {
					if (c[i] == '?')
						c[i] = '0';
					if (j[i] == '?')
						j[i] = '9';
				} else {
					if (c[i] == '?')
						c[i] = '9';
					if (j[i] == '?')
						j[i] = '0';
				}
			}
		}
		
		for (int i = 0; i < c.length; i++) {
			if (c1[i] == '?') {
				if (j1[i] == '?') {
					if (i > last) {
						c1[i] = '0';
						j1[i] = '0';
					} else if (i == last) {
						if (cIsBigger) {
							c1[i] = '0';
							j1[i] = '1';
						} else {
							c1[i] = '1';
							j1[i] = '0';
						}
					}
				} else {
					if (i > last) {
						c1[i] = j1[i];
					} else {
						if (cIsBigger) {
							c1[i] = '9';
						} else {
							c1[i] = '0';
						}
					}
				}
			} else {
				if (j1[i] == '?') {
					if (i < last) {
						j1[i] = c1[i];
					} else {
						if (cIsBigger) {
							j1[i] = '0';
						} else {
							j1[i] = '9';
						}
					}
				} else {
					difference = true;
				}
			}
		}
		
		String x = new String(c);
		String y = new String(j);
		String x1 = new String(c1);
		String y1 = new String(j1);
		BigInteger z1 = new BigInteger(x);
		BigInteger z2 = new BigInteger(y);
		BigInteger z3 = new BigInteger(x1);
		BigInteger z4 = new BigInteger(y1);
		
		z1 = z1.subtract(z2);
		z3 = z3.subtract(z4);
		z1 = z1.abs();
		z3 = z3.abs();
		return (z3.compareTo(z1) == -1) ? x1 + ' ' + y1 : x + ' ' + y;
	}
	
	/************************************************************************/
	
	public static void main(String[] args) throws Exception {
		PrintWriter writer = new PrintWriter(new FileOutputStream(DIR + FILE_NAME + ".out"));
		Scanner scanner = new Scanner(new FileInputStream(DIR + FILE_NAME + ".in"));
		B problem = new B(Runtime.getRuntime().availableProcessors() / 2);
		Instant before = Instant.now();
		problem.solve(scanner, writer);
		Instant after = Instant.now();
		System.out.println("took " + ChronoUnit.MILLIS.between(before, after) + " millis");
		writer.close();
		scanner.close();
	}

	public B(int threadsNum) {
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
