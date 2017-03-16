package net.ujjwal.codejam.gcj14.round1c;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class PartElf2 implements Callable<String> {

	private long p;
	private long q;

	public PartElf2(long p, long q) {
		this.p = p;
		this.q = q;
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException, InterruptedException, ExecutionException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.valueOf(in.readLine());
		ExecutorService executorService = Executors.newCachedThreadPool();
		List<Future<String>> futures = new ArrayList<Future<String>>();
		for (int i = 0; i < t; ++i) {
			String line = in.readLine();
			String[] split = line.split("/");
			long p = Long.valueOf(split[0]);
			long q = Long.valueOf(split[1]);
			futures.add(executorService.submit(new PartElf2(p, q)));
		}

		for (int i = 0; i < t; ++i) {
			System.out.printf("Case #%d: %s%n", i + 1, futures.get(i).get());
		}

		executorService.shutdown();
		executorService.shutdownNow();
	}

	@Override
	public String call() throws Exception {

		long gcd = gcd(p, q);
		if (gcd > 1) {
			p = p / gcd;
			q = q / gcd;
		}
		// At this point, q = 2^x, and x is the answer. If q != 2^x then it is
		// impossible.

		int numBits = numBits(q);

		if (numBits > 1) {
			return "impossible";
		} else {
			Integer pow2 = pow2(q);
			if (pow2 > 40) {
				return "impossible";
			} else {
				// Now we figure out how many times p * 2 >= q;
				int count = 0;
				while (p < q) {
					++count;
					p <<= 1;
				}
				return String.valueOf(count);
			}
		}

	}

	private Integer pow2(long v) {
		int c = 0;
		if (v > 0) {
			v = (v ^ (v - 1)) >> 1; // Set v's trailing 0s to 1s and zero rest
			for (c = 0; v > 0; c++) {
				v >>= 1;
			}
		} else {
			c = Long.SIZE;
		}
		return c;
	}

	private int numBits(long v) {
		int c = 0;
		for (c = 0; v > 0; c++) {
			v &= v - 1; // clear the least significant bit set
		}
		return c;
	}

	private static long gcd(final long p, final long q) {
		long a, b;
		if (p < q) {
			a = q;
			b = p;
		} else {
			a = p;
			b = q;
		}
		while (b > 0) {
			long rem = a % b;
			a = b;
			b = rem;
		}
		return a;
	}

}
