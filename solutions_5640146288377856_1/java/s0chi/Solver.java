package sochi.round;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.text.NumberFormat;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

/**
 * Parent class easing execution handling
 */
public abstract class Solver extends Thread {

	// Location
	private static final String LOCATION = System.getProperty("user.dir");
	private static final String SEPARATOR = System.getProperty("file.separator");
	private static final String INPUT_FORMAT = LOCATION + SEPARATOR + "input-%s.txt";
	private static final String OUTPUT_FORMAT = LOCATION + SEPARATOR + "output-%s.txt";

	private final String inputPath;
	private final String outputPath;

	private final List<String> inputContent;
	private final List<String> outputContent;

	// Threads
	private int threadCount;

	/**
	 * Constructor
	 */
	public Solver(int threads) throws IOException {
		String taskName = getClass().getSimpleName().toLowerCase();
		inputPath = String.format(INPUT_FORMAT, taskName);
		outputPath = String.format(OUTPUT_FORMAT, taskName);

		inputContent = FileUtils.getFileContent(inputPath);
		if (inputContent.isEmpty()) {
			throw new IllegalArgumentException("Incorrect input");
		}

		threadCount = threads;
		outputContent = new ArrayList<String>();
	}

	public void run() {
		ExecutorService executor = Executors.newFixedThreadPool(threadCount);
		List<Future<String>> tasks = new ArrayList<Future<String>>();

		try {

			List<String> lines = Collections.unmodifiableList(inputContent);
			for (Callable<String> task : getTestCases(lines)) {
				tasks.add(executor.submit(task));
			}

			for (int t = 0; t < tasks.size(); ++t) {
				String answer = tasks.get(t).get();
				String lineOutput = "Case #" + (t + 1) + ": " + answer;
				System.out.println(lineOutput);
				outputContent.add(lineOutput);
			}

			// Processing output
			FileUtils.setFileContent(outputContent, outputPath);
		}
		// Catching everything
		catch (Throwable t) {
			t.printStackTrace();
		}
		// Closing
		finally {
			executor.shutdown();
		}
	}

	/**
	 * Necessary method to implement
	 */
	public abstract List<Callable<String>> getTestCases(final List<String> lines) throws Exception;

	/**
	 * File operation handling
	 */
	protected static enum FileUtils {
		;

		private static final Charset ENCODING = StandardCharsets.UTF_8;

		public static List<String> getFileContent(String fileName) throws IOException {
			return Files.readAllLines(Paths.get(fileName), ENCODING);
		}

		public static Path setFileContent(List<String> lines, String fileName) throws IOException {
			return Files.write(Paths.get(fileName), lines, ENCODING);
		}
	}

	/**
	 * Utility class for Strings
	 */
	protected enum StringUtils {
		;

		/**
		 * Explodes a string into a list of substrings which in the original
		 * string is separated by the given separator
		 */
		public static List<String> explode(String text, String separator) {
			List<String> list = new ArrayList<String>();
			if (text != null && separator != null && !text.isEmpty()) {
				Collections.addAll(list, text.split(separator));
			}

			return list;
		}

		public static String implode(Iterator<String> itr, String seperator) {
			StringBuilder builder = new StringBuilder();
			boolean first = true;

			while (itr.hasNext()) {
				if (!first) {
					builder = builder.append(seperator);
				}

				first = false;
				builder = builder.append(itr.next());
			}

			return builder.toString();
		}

		/**
		 * Returns a string containing a string representation of all the list
		 * elements in the same order, with the separator string between each
		 * element
		 */
		public static String implode(Collection<? extends Object> parts, String separator) {
			StringBuilder builder = new StringBuilder();
			for (Object part : parts) {
				builder.append(separator + part);
			}

			if (builder.length() > separator.length()) {
				return builder.substring(separator.length());
			}

			return builder.toString();
		}

		/**
		 * Without separator, only digit characters
		 */
		public static List<Integer> extractDigits(String string) {
			List<Integer> integers = new ArrayList<Integer>();
			if (string == null || string.isEmpty()) {
				return integers;
			}

			for (int position = 0; position < string.length(); ++position) {
				int numericValue = Character.getNumericValue(string.charAt(position));
				if (numericValue >= 0) {
					integers.add(numericValue);
				}
			}

			return integers;
		}

		/**
		 * Extract all integers from a string
		 */
		public static List<Integer> extractIntegers(String string) {
			List<Integer> integers = new ArrayList<Integer>();

			Scanner scanner = new Scanner(string);
			scanner.useDelimiter("\\D");

			while (scanner.hasNextInt() || scanner.hasNext()) {
				if (scanner.hasNextInt()) {
					integers.add(scanner.nextInt());
				}
				else {
					scanner.next();
				}
			}

			scanner.close();
			return integers;
		}

		/**
		 * Extract all longs from a string
		 */
		public static List<Long> extractLongs(String string) {
			List<Long> longs = new ArrayList<Long>();

			Scanner scanner = new Scanner(string);
			scanner.useDelimiter("\\D");

			while (scanner.hasNextLong() || scanner.hasNext()) {
				if (scanner.hasNextLong()) {
					longs.add(scanner.nextLong());
				}
				else {
					scanner.next();
				}
			}

			scanner.close();
			return longs;
		}

		/**
		 * Extract all floats from a string
		 */
		public static List<Float> extractFloats(String string) {
			List<Float> floats = new ArrayList<Float>();

			Scanner scanner = new Scanner(string);
			scanner.useDelimiter("[^\\d,]");

			while (scanner.hasNextFloat() || scanner.hasNext()) {
				if (scanner.hasNextFloat()) {
					floats.add(scanner.nextFloat());
				}
				else {
					scanner.next();
				}
			}

			scanner.close();
			return floats;
		}

		/**
		 * Type-casting numbers
		 */
		public static Number getNumber(String string) throws ParseException {
			return NumberFormat.getInstance().parse(string);
		}

		public static int getInteger(String string) throws ParseException {
			return getNumber(string).intValue();
		}
	}
}
