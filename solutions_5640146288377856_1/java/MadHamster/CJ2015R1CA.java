package com.google.code.codejam2015.r1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class CJ2015R1CA {

	final String fileName = "files/com/google/code/codejam2015/r1c/A-large";

	public static void main(String[] args) {

		final CJ2015R1CA problem = new CJ2015R1CA();
		problem.solve();
	}

	private class Solution implements Callable<String> {

		final int R;
		final int C;
		final int W;

		public Solution(final Scanner in) {

			R = in.nextInt();
			C = in.nextInt();
			W = in.nextInt();
		}

		@Override
		public String call() throws Exception {

			final int result;
			if (W == 1) {
				result = R * C;
			} else if (W == C) {
				result = R + C - 1;
			} else {
				if (C % W == 0) {
					result = R * (C / W) + (W - 1);
				} else {
					result = R * (C / W) + W;
				}
			}

			return String.valueOf(result);
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
