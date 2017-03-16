package r2016.roundq;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class R2016Q_C {
	
	private final static String CASE = "Case #%d: ";
	
	private int t;
	
	public static void main(final String[] args) {
		new R2016Q_C().solve();
	}
	
	public void solve(final Scanner in, final PrintStream out) throws IOException {
		readNumberCases(in);
		for (int i = 0; i < numberCases(); i++) {
			printCaseLabel(i, out);
			readCase(in);
			solveCase();
			printOutput(out);
			out.println();
		}
	}

	private String folder() {
		return this.getClass().getSimpleName() + "_cases";
	}

	private String inFolder() {
		return folder() + "/in";
	}
	
	private String outFolder() {
		return folder() + "/out";
	}
	
	private void ensureDirectoryExists(final File f) {
		if (!f.isDirectory()) {
			f.mkdir();
		}
	}
	
	private String filePath(final String file, final String dir) {
		return dir + "/" + file;
	}
	
	private String caseLabel(final int n) {
		return String.format(CASE, n + 1);
	}
	
	private void printCaseLabel(final int n, final PrintStream out) {
		out.print(caseLabel(n));
	}
	
	private void solve() {
		
		final File directory = new File(folder());
		final File inDirectory = new File(inFolder());
		final File outDirectory = new File(outFolder());
		
		ensureDirectoryExists(directory);
		ensureDirectoryExists(outDirectory);
		ensureDirectoryExists(inDirectory);
		
		for (final String in : inDirectory.list()) {
			final String fileNameCore = in.replace(".in", "");
			final String outFileName = fileNameCore + ".out";
			
			final File inFile = new File(filePath(in, inFolder()));
			final File outFile = new File(filePath(outFileName, outFolder()));
			try (final PrintStream ps =  new PrintStream(outFile);
					final Scanner s = new Scanner(inFile)){
				solve(s, ps);
			} catch (final IOException e) {
				e.printStackTrace();
			} 
		}
	}
	
	private int numberCases() {
		return t;
	}
	
	private void readNumberCases(final Scanner in) {
		t = in.nextInt();
	}
	
	private int N;
	
	private int J;
	
	private String[] numbers;
	
	private long[][] divisors;
	
	private BigInteger curent;
	
	private void readCase(final Scanner in) {
		N = in.nextInt();
		J = in.nextInt();
	}
	
	private void solveCase() {
		curent = convert("10000000000000000000000000000001", 2);
		numbers = new String[J];
		divisors = new long[J][];
		int i = 0;
		while(i < J) {
			String n = nextNumber();
			if (isJamcoin(n)) {
				numbers[i] = n;
				divisors[i] = divisors(n);
				i++;
				System.out.println(String.format("%d: %s", i, n));
			}
		}
	}
	
	private String nextNumber() {
		String n = curent.toString(2);
		curent = curent.add(BigInteger.ONE);
		return n;
	}
	
	private boolean isJamcoin(String n) {
		if (n.charAt(n.length() - 1) == '0') {
			return false;
		}
		for (int base = 2; base <= 10; base++) {
			BigInteger number = convert(n, base);
			if (isPrime(number)) {
				return false;
			}
		}
		return true;
	}
	
	private BigInteger convert(String n, int base) {
		BigInteger number = BigInteger.ZERO;
		BigInteger b = BigInteger.valueOf(base);
		for (int i = 0; i < n.length(); i++) {
			number = number.multiply(b);
			number = number.add(BigInteger.valueOf(n.charAt(i) - '0'));
		}
		return number;
	}
	
	private static final BigInteger TWO = BigInteger.valueOf(2);
	
	private boolean isPrime(BigInteger number) {
		if (number.equals(BigInteger.ONE)) {
			return false;
		}
		if (number.equals(TWO)) {
			return true;
		}
		if (number.mod(TWO).equals(BigInteger.ZERO)) {
			return false;
		}
		for (long i = 3l; i < 100; i+=2) {// break if it is hard to find divisors
			if (number.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO)) {
				return false;
			}
		}
		return true;
	}
	
	private long divisor(BigInteger number) {
		if (number.mod(TWO).equals(BigInteger.ZERO)) {
			return 2;
		}
		for (long i = 3;; i+=2) {
			if (number.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO)) {
				return i;
			}
		}
	}
	
	private long[] divisors(String n) {
		long[] div = new long[9];
		for (int i = 2; i <= 10; i++) {
			BigInteger number = convert(n, i);
			div[i - 2] = divisor(number);
		}
		return div;
	}
	
	private void printOutput(final PrintStream out) {
		out.println();
		for (int i = 0; i < J; i++) {
			out.print(numbers[i]);
			for (int j = 0; j < divisors[i].length; j++) {
				out.print(" " + divisors[i][j]);
			}
			out.println();
		}
	}
}
