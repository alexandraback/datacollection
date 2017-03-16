package codejam.quali_round_2016;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;

import codejam.util.Helper;

/**
 * Coin Jam
 */
public class C {
	
	private static String solve(int N, int J) {
		ExecutorService executor = Executors.newCachedThreadPool();
		AtomicInteger validCount = new AtomicInteger(0);
		
		BlockingQueue<Future<String>> jamcoinLineFutQueue = new ArrayBlockingQueue<>(30);
		StringBuffer sb = new StringBuffer();
		
		Future<Boolean> computationFuture = executor.submit(() -> {
			for (int i=0; i<Math.pow(2, N-2) && validCount.intValue()<J; i++) {
				final int _i = i;
				// System.out.printf("Processing %s ... valid count: %s%n", i, validCount);
				jamcoinLineFutQueue.put( executor.submit(() -> {
					return getJamcoinLine(_i, N);
				}) );
			}
			return true;
		});
		
		Future<Boolean> resultFuture = executor.submit(() -> {
			Future<String> jamcoinLineFut;
			while (validCount.intValue()<J && (jamcoinLineFut = jamcoinLineFutQueue.take()) != null) {
				String line;
				try {
					line = jamcoinLineFut.get(500, TimeUnit.MILLISECONDS);
					if (line != null) {
						if (validCount.intValue() > 0) {
							sb.append('\n');
						}
						sb.append(line);
						validCount.incrementAndGet();
					}
				} catch (Exception e) {
					
				}
			}
			return true;
		});
		
		try {
			computationFuture.get();
			resultFuture.get();
		} catch (InterruptedException | ExecutionException e) {

		}
		
		executor.shutdown();
		return sb.toString();
	}
	
	private static String getJamcoinLine(int i, int N) {
		String jamcoin = String.format("1%0" + (N-2) + "d1", Integer.parseInt(Integer.toString(i, 2)));
		// System.out.printf("Trying %s (%s) ...%n", jamcoin, i);
		boolean isValid = true;
		StringBuilder lineBuffer = new StringBuilder();
		lineBuffer.append(jamcoin);
		for (int base=2; isValid && base<=10; base++) {
			BigInteger num = new BigInteger(jamcoin, base);
			// System.out.printf("  base=%s, num=%s, sqrt=%s%n", base, num, Math.sqrt(num.doubleValue()));
			BigInteger nonTrivialDivisor = getNonTrivialDivisor(num);
			if (nonTrivialDivisor != null) {
				lineBuffer.append(" " + nonTrivialDivisor);
			} else {
				return null;
			}
		}
		return lineBuffer.toString();
	}
	
	private static BigInteger getNonTrivialDivisor(BigInteger n) {
		long[] primes = {2, 3, 5, 7};
		for (int i=0; i<primes.length; i++) {
			if (BigInteger.ZERO.equals(n.remainder(BigInteger.valueOf(primes[i]))))
				return BigInteger.valueOf(primes[i]);
		}
		final BigInteger START = BigInteger.valueOf(12), INCREMENT = BigInteger.valueOf(6);
		for (BigInteger i=START; i.doubleValue() < Math.sqrt(n.doubleValue()); i=i.add(INCREMENT)) {
			BigInteger[] trials = {i.subtract(BigInteger.ONE), i.add(BigInteger.ONE)};
			for (int j=0; j<trials.length; j++) {
				if (BigInteger.ZERO.equals( n.remainder(trials[j]) )) {
					return trials[j];
				}
			}
		}
		return null;
	}
	
	private static void verifyOutput(File file) {
		try (FileInputStream is = new FileInputStream(file);
			BufferedReader r = new BufferedReader(new InputStreamReader(is))) {
			String line;
			while ((line = r.readLine()) != null) {
				if (!line.startsWith("Case #")) {
					String[] tokens = line.split("\\s");
					String jamcoin = tokens[0];
					for (int i=1; i<=tokens.length-1; i++) {
						BigInteger num = new BigInteger(jamcoin, i+1);
						String divisor = tokens[i];
						if (!BigInteger.ZERO.equals(num.remainder(new BigInteger(divisor)))) {
							System.err.printf("Incorrect divisor %s for %s in base %s%n", divisor, jamcoin, i+1);
						}
					}
				}
			}
		} catch (IOException e) {
			
		}
	}
	
	public static void main(String[] args) {
		Helper helper = new Helper(C.class, args);
		try (Scanner sc = helper.getScanner(); PrintStream out = helper.getPrintStream()) {
			int T = sc.nextInt();
			for (int i=0; i<T; i++) {
				int N = sc.nextInt(), J = sc.nextInt();
				String result = solve(N, J);
				out.printf("Case #%d:%n%s%n", i+1, result);
			}
		}
	}
}
