import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;


public class Squarer {

	private static ExecutorService executor;
	private BigInteger min;
	private BigInteger max;

	public Squarer(BigInteger min, BigInteger max) {
		this.min = min;
		this.max = max;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		int cases = s.nextInt();
		for (int i = 0; i < cases; i++) {
			executor = Executors.newCachedThreadPool();
			BigInteger min = s.nextBigInteger();
			BigInteger max = s.nextBigInteger();

			Squarer sq = new Squarer(min, max);
			System.out.println("Case #" + (i + 1) + ": " + sq.getN().toString());
			executor.shutdown();
		}

		s.close();
	}

	private BigInteger getN() {
		BigInteger part = max.add(BigInteger.ONE).subtract(min).divide(new BigInteger("10"));
		
		BigInteger sum = BigInteger.ZERO;
		
		List<Future<BigInteger>> futures = new ArrayList<>();
		for (int i = 0; i < 9; i++) {
			Callable<BigInteger> c = new SquarerCallable(min.add(part.multiply(BigInteger.valueOf(i))), min.add(part.multiply(BigInteger.valueOf(i + 1)).subtract(BigInteger.ONE)));
			futures.add(executor.submit(c));
		}
		
		Callable<BigInteger> c = new SquarerCallable(min.add(part.multiply(BigInteger.valueOf(9))), max);
		futures.add(executor.submit(c));
		
		for (Future<BigInteger> fut : futures) {
			try {
				sum = sum.add(fut.get());
			} catch (InterruptedException | ExecutionException e) {
				e.printStackTrace();
			}
		}
		
		return sum;
	}

	
	class SquarerCallable implements Callable<BigInteger>
	{

		private BigInteger min;
		private BigInteger max;

		public SquarerCallable(BigInteger min, BigInteger max) {
			this.min = min;
			this.max = max;
		}

		@Override
		public BigInteger call() throws Exception {
			BigInteger a = sqrt(min);
			
			BigInteger b = sqrt(max);
			if (b.multiply(b).compareTo(max) > 0) {
				b = b.subtract(BigInteger.ONE);
			}
			BigInteger sum = BigInteger.ZERO;
			
			BigInteger startPalin = a;
			while (!isPalindrom(startPalin)) {
				startPalin = startPalin.add(BigInteger.ONE);
			}
			
			for (BigInteger i = startPalin; i.compareTo(b) <= 0; i = nextPalindrom(i)) {
				if (isPalindrom(i.multiply(i))) {
					sum = sum.add(BigInteger.ONE);
				}
			}
			
			return sum;
		}

		private BigInteger nextPalindrom(BigInteger bi) {
			String str = bi.toString();
			if (str.matches("^9+$")) {
				return bi.add(BigInteger.valueOf(2));
			}
			char[] chars = str.toCharArray();
			if (str.length() % 2 == 0) {
				int r = str.length() / 2;
				int l = str.length() / 2 - 1;
				while (str.charAt(l) == '9') {
					chars[l--] = '0';
					chars[r++] = '0';
				}
				
				chars[l]++;
				chars[r]++;
			} else {
				int pos = str.length() / 2;
				if (chars[pos] == '9') {
					int i = 1;
					while (chars[pos + i] == '9') {
						chars[pos + i] = '0';
						chars[pos - i] = '0';
						++i;
					}
					chars[pos + i]++;
					chars[pos - i]++;
					chars[pos] = '0';
				} else {
					chars[pos]++;
				}
			}
			
			return new BigInteger(String.valueOf(chars));
		}

		private BigInteger sqrt(BigInteger bi) {
			if (bi.compareTo(BigInteger.ZERO) <= 0) {
				return BigInteger.ZERO;
			}
			BigDecimal bd = new BigDecimal(bi);
			BigDecimal x = BigDecimal.valueOf(bi.toString().length() / 2 + 1);
			for (int i = 0; i < 50; i++) {
				x = x.add(bd.divide(x, MathContext.DECIMAL32)).divide(BigDecimal.valueOf(2));
			}
			BigInteger start = x.toBigInteger();
			while (start.multiply(start).compareTo(bi) >= 0) {
				start = start.subtract(BigInteger.ONE);
			}
			
			do {
				start = start.add(BigInteger.ONE);
			} while (start.multiply(start).compareTo(bi) < 0);
			return start;
		}

		private boolean isPalindrom(BigInteger n) {
			char[] chars = n.toString().toCharArray();
			int length = chars.length;
			for (int i = 0; i < length / 2; i++) {
				if (chars[i] != chars[length - 1 - i]) {
					return false;
				}
			}
			
			
			return true;
		}
	}
}
