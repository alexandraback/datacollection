package contest.codejam.codejam2016r0;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.UncheckedIOException;
import java.io.Writer;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Optional;
import java.util.StringTokenizer;
import java.util.Vector;
import java.util.stream.IntStream;

/**
 * @author julian
 */
public class C {

	public static final void main(String[] args) throws IOException {
		(new C()).run();
	}

	private String className = getClass().getSimpleName();
	private String inputFile = this.className + ".in";
	private String outputFile = this.className + ".out";

	private final BigInteger zero = new BigInteger("" + 0);

	private final long tableSize = 1000000;
	// making this table larger allows finding more jamcoins

	private final int firstBase = 2;
	private final int lastBase = 10;

	private int n;
	private int j;
	private PrimeNumberTable table = null;

	public C() {
	}

	public void run() throws IOException {
		Reader input = new FileReader(this.inputFile);
		Writer output = new FileWriter(this.outputFile);
		execute(input, output);
		input.close();
		output.close();
	}

	public void execute(Reader input0, Writer output0) throws IOException {
		BufferedReader input = new BufferedReader(input0);
		BufferedWriter output = new BufferedWriter(output0);
		int t = Integer.parseInt(input.readLine());
		precompute();
		IntStream.range(0, t).forEach(index -> {
			reset();
			read(input);
			write(output, index, solve());
		});
		output.flush();
	}

	public void precompute() {
		this.table = new PrimeNumberTable(this.tableSize);
	}

	public void reset() {
	}

	public void read(BufferedReader in) {
		try {
			String line = in.readLine();
			StringTokenizer stok = new StringTokenizer(line);
			this.n = Integer.parseInt(stok.nextToken());
			this.j = Integer.parseInt(stok.nextToken());
		} catch (IOException e) {
			throw new UncheckedIOException(e);
		}
	}

	public void write(BufferedWriter out, int index, String solution) {
		try {
			out.write("Case #" + (index + 1) + ":" + solution + "\n");
		} catch (IOException e) {
			throw new UncheckedIOException(e);
		}
	}

	Optional<String> format(long number, int digits) {
		String num = Long.toString(number, 2);
		StringBuilder sb = new StringBuilder();
		IntStream.range(0, (digits - 2) - num.length()).forEach(x -> sb.append("0"));
		String ret = "1" + sb.toString() + num + "1";
		if (ret.length() == digits) {
			return Optional.of(ret);
		} else {
			return Optional.empty();
		}
	}

	Optional<Long> getDivisor(BigInteger number) {
		Optional<Long> ret = null;
		List<Long> primes = this.table.getTable();
		boolean searching = true;
		Iterator<Long> it = primes.iterator();
		for (int k = 0; searching && (k < primes.size()); k++) {
			long prime = it.next();
			BigInteger bigPrime = new BigInteger("" + prime);
			if (number.mod(bigPrime).equals(zero)) {
				if (number.equals(bigPrime)) {
					ret = Optional.empty();
				} else {
					ret = Optional.of(prime);
				}
				searching = false;
			}
		}
		if (searching) {
			ret = Optional.empty();
		}
		return ret;
	}

	Optional<List<Long>> getDivisors(String str) {
		List<Long> ret = new ArrayList<>();
		boolean isCandidate = true;
		for (int base = this.firstBase; isCandidate && base < (this.lastBase + 1); base += 1) {
			BigInteger number = new BigInteger(str, base);
			Optional<Long> optNum = getDivisor(number);
			if (optNum.isPresent()) {
				ret.add(optNum.get());
			} else {
				isCandidate = false;
			}
		}
		if (isCandidate) {
			return Optional.of(ret);
		} else {
			// some valid jamcoins might be discarded when the table of prime
			// numbers is not big enough
			return Optional.empty();
		}
	}

	public String solve() {
		StringBuilder ret = new StringBuilder();
		long index = 0;
		int quantity = 0;
		boolean sizeIsAcceptable = true;
		while (sizeIsAcceptable && quantity < this.j) {
			Optional<String> optStr = format(index, this.n);
			if (optStr.isPresent()) {
				String str = optStr.get();
				Optional<List<Long>> optDivisors = getDivisors(str);
				if (optDivisors.isPresent()) {
					ret.append("\n");
					ret.append(str);
					optDivisors.get().forEach(number -> {
						ret.append(" ");
						ret.append(number);
					});
					quantity += 1;
				}
				index += 1;
			} else {
				sizeIsAcceptable = false;
			}
		}
		return ret.toString();
	}

	class PrimeNumberTable {

		private final long maxNumber;
		private Vector<Long> tableOfPrimes;

		public PrimeNumberTable(long maxNumber) {
			this.maxNumber = maxNumber;
			this.tableOfPrimes = primeTable(maxNumber);
		}

		public long getMaxNumber() {
			return this.maxNumber;
		}

		public Vector<Long> getTable() {
			return this.tableOfPrimes;
		}

		public boolean isPrime(long n, Vector<Long> table) {
			long top = (long) Math.sqrt((double) n);
			boolean prime = true;
			for (int k = 0; prime && (k < table.size()) && (table.get(k) <= top); k++) {
				prime = (n % table.get(k)) != 0;
			}
			if (prime && table.get(table.size() - 1) <= top) {
				throw new RuntimeException();
			}
			return prime;
		}

		public Vector<Long> primeTable(long maxNumber) {
			Vector<Long> table = new Vector<Long>();
			table.add((long) 2);
			for (long i = 3; i <= maxNumber; i++) {
				if (isPrime(i, table)) {
					table.add(i);
				}
			}
			return table;
		}

	}

}
