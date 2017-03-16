package com.google.code.codejam2015.r1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class CJ2015R1CB {

	final String fileName = "files/com/google/code/codejam2015/r1c/B-small-attempt0";

	public static void main(String[] args) {

		final CJ2015R1CB problem = new CJ2015R1CB();
		problem.solve();
	}

	private class Solution implements Callable<String> {

		final int K;
		final int L;
		final int S;
		final String keys;
		final String target;

		public Solution(final Scanner in) {

			K = in.nextInt();
			L = in.nextInt();
			S = in.nextInt();
			in.nextLine();
			keys = in.nextLine();
			target = in.nextLine();
		}

		@Override
		public String call() throws Exception {

			double result = 0;
			
			for (int i = 0; i < L; i++) {
				final String let = target.substring(i, i + 1);
				if (!keys.contains(let)) {
					return "0.0";
				}
			}

			int overlap = 0;
			for (int i = 0; i < L; i++) {
				String line = target.substring(0, i);
				if (target.endsWith(line)) {
					overlap = i;
				}
			}

			int maxBananas = S / L;
			if (overlap > 0) {
				maxBananas = 1 + (S - (L - overlap)) / overlap;
			} else {
				overlap = L;
			}

			final Map<String, Double> alph = new HashMap<String, Double>();
			for (int i = 0; i < K; i++) {
				final String let = keys.substring(i, i + 1);
				Double count = alph.get(let);
				if (count == null) {
					count = 0.0d;
				}
				alph.put(let, count + 1);
			}

			for (Map.Entry<String, Double> entry : alph.entrySet()) {
				Double val = entry.getValue();
				val /= K;
				entry.setValue(val);
			}

			double targetProb = 1.0d;
			for (int i = 0; i < L; i++) {
				targetProb *= alph.get(target.substring(i, i + 1));
			}

			double overProb = 1.0d;
			for (int i = 1; i <= overlap; i++) {
				overProb *= alph.get(target.substring(target.length() - i, target.length() - i + 1));
			}
			int rest = (S - (L - overlap)) % overlap;
			double restProb = 0.0d;
			for (int i = 0; i < rest; i++) {
				final String let = target.substring(i, i + 1);
				final String beg = target.substring(0, i + 1);
				if (target.equals(target.substring(i + 1) + beg)) {
					if (restProb == 0.0d) {
						restProb = alph.get(let);
					} else {
						restProb *= alph.get(let);
					}
				} else {
					break;
				}
			}

			double gotBananas = targetProb + overProb * ((S - L) / overlap) + restProb;
			result = (double)maxBananas - gotBananas;
			return String.format("%.6f", result);
		}
		
	}

	@SuppressWarnings("unchecked")
	public void solve() {

		try (Scanner reader = new Scanner(new File(fileName + ".in"));
				PrintWriter writer = new PrintWriter(new File(fileName + ".out"))) {

			final ScheduledThreadPoolExecutor pool = new ScheduledThreadPoolExecutor(5);

			final int T = reader.nextInt();
			final Future<String>[] cases = new Future[T];
			for (int t = 0; t < T; t++) {
				cases[t] = pool.submit(new Solution(reader));
			}

			for (int t = 0; t < T; t++) {
				final String result = "Case #" + (t + 1) + ": " + cases[t].get();
				System.out.println(result);
				writer.println(result);
			}

			pool.shutdown();
		} catch (FileNotFoundException e) {
			System.out.println("Cannot find the file");
			e.printStackTrace(System.out);
		} catch (InterruptedException e) {
			System.out.println("Thread was interrupted while waiting for task completion");
			e.printStackTrace(System.out);
		} catch (ExecutionException e) {
			System.out.println("Execution time exception occured");
			e.printStackTrace(System.out);
		}
	}
}
