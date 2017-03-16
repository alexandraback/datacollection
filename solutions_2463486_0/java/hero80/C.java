package codejam.qual;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class C {

	private static BufferedReader br;

	private static Set<BigInteger> cache = new HashSet<BigInteger>(45000);
	private static List<BigInteger> list;
	private static final int LENGTH = 19;

	private static char[] num;

	public static void main(final String[] args) {
		buildCache();
		// setStreams("C:\\Users\\Yariv\\Desktop\\C-small-attempt0");
		br = new BufferedReader(new InputStreamReader(System.in));
		final int numCases = (int) readNumber();
		handleCases(numCases);
	}

	private static void setStreams(final String baseFileName) {
		try {
			System.setIn(new FileInputStream(baseFileName + ".in"));
			System.setOut(new PrintStream(baseFileName + ".out"));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void handleCases(final long numCases) {
		for (int i = 1; i <= numCases; i++) {
			handleCase(i);
		}
	}

	private static void handleCase(final int caseNumber) {
		final String[] numbers = readStrings();
		final BigInteger A = new BigInteger(numbers[0]);
		final BigInteger B = new BigInteger(numbers[1]);

		int num = 0;
		for (int i = 0; i < list.size(); i++) {
			final BigInteger curr = list.get(i);
			if (curr.compareTo(A) >= 0 && curr.compareTo(B) <= 0) {
				num++;
			}
		}

		System.out.println("Case #" + caseNumber + ": " + num);
	}

	private static void buildCache() {
		num = new char[LENGTH];
		final long start = System.currentTimeMillis();
		buildNum(0);
		calc("3");
		for (int i = 0; i <= LENGTH - 2; i++) {
			String cur = "2";
			for (int j = 0; j < i; j++) {
				cur = cur + '0';
			}
			buildPal(cur + '0');
			buildPal(cur + '1');
		}

		final long end = System.currentTimeMillis();

		cache.remove(new BigInteger("0"));
		list = new ArrayList<BigInteger>(cache);
		Collections.sort(list);
		log("Time = " + (end - start) + "ms");
		log("size: " + list.size() + " largest: " + list.get(list.size() - 1));
	}

	private static void buildNum(final int place) {
		if (place == LENGTH) {
			buildPal(String.valueOf(num));
			return;
		}
		final int newPlace = place + 1;
		num[place] = ('0');
		buildNum(newPlace);
		num[place] = ('1');
		buildNum(newPlace);
		if (place == LENGTH - 1) {
			num[place] = ('2');
			buildNum(newPlace);
		}
	}

	private static void buildPal(final String strNum) {
		final String str = removeLeadingZeroes(strNum);
		if (str.isEmpty()) {
			return;
		}

		final String rev = reverse(str);
		calc(str + rev);
		calc(str + rev.substring(1));
	}

	private static String removeLeadingZeroes(final String strNum) {
		for (int i = 0; i < strNum.length(); i++) {
			if (strNum.charAt(i) != '0') {
				return strNum.substring(i);
			}
		}

		return "";
	}

	private static void calc(final String string) {
		final BigInteger n = new BigInteger(string);
		final BigInteger square = n.multiply(n);
		if (checkPal(square.toString())) {
			cache.add(square);
			// log("Pal: " + n + ", " + square);
		}
	}

	private static boolean checkPal(final String string) {
		final int len = string.length() / 2;
		for (int i = 0; i < len; i++) {
			if (string.charAt(i) != string.charAt(string.length() - i - 1)) {
				return false;
			}
		}

		return true;
	}

	private static String reverse(final String word) {
		final char[] chs = word.toCharArray();

		int i = 0, j = chs.length - 1;
		while (i < j) {
			// swap chs[i] and chs[j]
			final char t = chs[i];
			chs[i] = chs[j];
			chs[j] = t;
			i++;
			j--;
		}
		return new String(chs);
	}

	private static long readNumber() {
		final String line = readLine();
		final long number = Long.parseLong(line);
		return number;
	}

	private static long[] readNumbers() {
		final String line = readLine();
		final String[] numbersStr = line.split(" ");
		final long[] numbers = new long[numbersStr.length];
		for (int i = 0; i < numbersStr.length; i++) {
			numbers[i] = Long.parseLong(numbersStr[i]);
		}
		return numbers;
	}

	private static String[] readStrings() {
		final String line = readLine();
		return line.split(" ");
	}

	private static String readLine() {
		String line = null;
		try {
			line = br.readLine();
		} catch (final IOException e) {
			e.printStackTrace();
		}
		return line;
	}

	private static void log(final String message) {
		// System.out.println(message);
	}
}
