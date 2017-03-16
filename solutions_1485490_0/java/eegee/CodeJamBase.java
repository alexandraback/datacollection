package reusable;

import java.io.IOException;
import java.math.BigInteger;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public abstract class CodeJamBase {
	private final List<String> inputLines;
	private final String filename;
	private int testCases;
	private int index = 0;

	public CodeJamBase(String filename) {
		this.filename = (filename != "") ? filename : "sample";

		try {
			inputLines = Files.readAllLines(Paths.get("data/" + this.filename + ".in"), Charset.defaultCharset());
		} catch (IOException e) {
			throw new RuntimeException("Failed to read file: '" + this.filename + "'");
		}

		setup();
	}

	protected void setup() {
		setTestCases(nextInt());
	}

	protected abstract String solution();

	public void run() {
		long startTime = System.currentTimeMillis();

		List<String> outputLines = new ArrayList<>();

		for (int i = 0; i < testCases; i++) {
			String outputLine = "Case #" + (i + 1) + ": " + solution();
			outputLines.add(outputLine);
			System.out.println(outputLine);
		}

		try {
			Files.write(Paths.get("data/" + filename + ".out"), outputLines, Charset.defaultCharset());
		} catch (IOException e) {
			throw new RuntimeException("Failed to write file: '" + filename + "'");
		}

		System.out.println();
		System.err.println("Total run time: " + ((System.currentTimeMillis() - startTime) / 1000d) + "s");
	}

	protected final String nextString() {
		return inputLines.get(index++);
	}

	protected final int nextInt() {
		return Integer.parseInt(nextString());
	}

	protected final double nextDouble() {
		return Double.parseDouble(nextString());
	}

	protected final String[] nextStringArray() {
		return inputLines.get(index++).split(" ");
	}

	protected final int[] nextIntArray() {
		String[] items = nextStringArray();

		int[] result = new int[items.length];

		for (int i = 0; i < items.length; i++) {
			result[i] = Integer.parseInt(items[i]);
		}

		return result;
	}

	protected final BigInteger[] nextBigIntegerArray() {
		String[] items = nextStringArray();

		BigInteger[] result = new BigInteger[items.length];

		for (int i = 0; i < items.length; i++) {
			result[i] = new BigInteger(items[i]);
		}

		return result;
	}

	protected final double[] nextDoubleArray() {
		String[] items = nextStringArray();

		double[] result = new double[items.length];

		for (int i = 0; i < items.length; i++) {
			result[i] = Double.parseDouble(items[i]);
		}

		return result;
	}

	public final void setTestCases(int testCases) {
		this.testCases = testCases;
	}
}
