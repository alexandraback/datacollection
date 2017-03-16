package codejam.round1A;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class C {

	private static long r, n, k, m;
	private static BufferedReader br;

	public static void main(final String[] args) {
		// setStreams("C:\\Users\\Yariv\\Desktop\\test2");
		setStreams("C:\\Users\\Yariv\\Desktop\\C-small-1-attempt1");
		// setStreams("C:\\Users\\Yariv\\Desktop\\C-large");
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
		final long[] numbers = readNumbers();
		r = numbers[0];
		n = numbers[1];
		m = numbers[2];
		k = numbers[3];

		final long[][] rows = new long[(int) r][(int) k];
		for (int i = 0; i < r; i++) {
			final long[] rowNums = readNumbers();
			for (int j = 0; j < k; j++) {
				rows[i][j] = rowNums[j];
			}
		}

		final Map<String, Set<Integer>> map = new HashMap<>();
		Set<Integer> set = new HashSet<Integer>();
		set.add(1);
		set.add(2);
		set.add(4);
		set.add(8);
		map.put("222", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(2);
		set.add(3);
		set.add(4);
		set.add(12);
		set.add(6);
		map.put("223", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(2);
		set.add(4);
		set.add(8);
		set.add(16);
		map.put("224", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(2);
		set.add(5);
		set.add(10);
		set.add(4);
		set.add(20);
		map.put("225", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(2);
		set.add(3);
		set.add(9);
		set.add(6);
		set.add(18);
		map.put("233", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(2);
		set.add(3);
		set.add(4);
		set.add(6);
		set.add(8);
		set.add(12);
		set.add(24);
		map.put("234", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(2);
		set.add(3);
		set.add(5);
		set.add(6);
		set.add(10);
		set.add(15);
		set.add(30);
		map.put("235", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(2);
		set.add(4);
		set.add(5);
		set.add(8);
		set.add(10);
		set.add(20);
		set.add(40);
		map.put("245", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(3);
		set.add(9);
		set.add(27);
		map.put("333", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(3);
		set.add(4);
		set.add(9);
		set.add(12);
		set.add(36);
		map.put("334", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(3);
		set.add(5);
		set.add(9);
		set.add(15);
		set.add(45);
		map.put("335", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(3);
		set.add(4);
		set.add(5);
		set.add(12);
		set.add(15);
		set.add(20);
		set.add(60);
		map.put("345", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(4);
		set.add(16);
		set.add(64);
		map.put("444", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(4);
		set.add(2);
		set.add(16);
		set.add(32);
		map.put("442", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(4);
		set.add(3);
		set.add(12);
		set.add(16);
		set.add(48);
		map.put("443", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(4);
		set.add(5);
		set.add(16);
		set.add(20);
		set.add(80);
		map.put("445", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(5);
		set.add(25);
		set.add(125);
		map.put("555", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(2);
		set.add(10);
		set.add(5);
		set.add(25);
		set.add(50);
		map.put("552", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(3);
		set.add(15);
		set.add(5);
		set.add(25);
		set.add(75);
		map.put("553", set);

		set = new HashSet<Integer>();
		set.add(1);
		set.add(4);
		set.add(20);
		set.add(5);
		set.add(25);
		set.add(100);
		map.put("554", set);

		System.out.println("Case #" + caseNumber + ": ");
		for (int line = 0; line < r; line++) {
			boolean found2 = false;
			for (final Entry<String, Set<Integer>> entry : map.entrySet()) {
				boolean found = true;
				for (int i = 0; i < k; i++) {
					final Set<Integer> set2 = entry.getValue();
					if (!set2.contains((int) rows[line][i])) {
						found = false;
						break;
					}
				}
				if (found) {
					found2 = true;
					System.out.println(entry.getKey());
					break;
				}
			}

			if (!found2) {
				System.out.println("222");
			}
		}
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
		System.out.println(message);
	}
}
