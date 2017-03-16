package codejam.year2016.round1B;

import java.util.*;
import java.io.*;
import java.math.*;

public class A {
	private static Scanner sc;

	public static void main(final String[] args) {
		// setStreams("C:\\Users\\Yariv\\Desktop\\test");
		setStreams("C:\\Users\\Yariv\\Desktop\\A-small-attempt0");
		// setStreams("C:\\Users\\Yariv\\Desktop\\A-large");
		sc = new Scanner(System.in);
		final int numCases = sc.nextInt();
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
		String line = sc.next();
		Map<Character, Long> map = new HashMap<>();
		for (int i = 0; i < line.length(); i++) {
			Character l = line.charAt(i);
			if (map.get(l) == null) {
				map.put(l, 1L);
			} else {
				long val = map.get(l);
				map.put(l, val + 1);
			}
		}

		long[] nums = new long[10];
		if (map.get('Z') != null && map.get('Z') > 0) {
			nums[0] = map.get('Z');
			map.put('Z', map.get('Z') - nums[0]);
			map.put('R', map.get('R') - nums[0]);
			map.put('E', map.get('E') - nums[0]);
			map.put('O', map.get('O') - nums[0]);
		}

		if (map.get('X') != null && map.get('X') > 0) {
			nums[6] = map.get('X');
			map.put('X', map.get('X') - nums[6]);
			map.put('S', map.get('S') - nums[6]);
			map.put('I', map.get('I') - nums[6]);
		}

		if (map.get('U') != null && map.get('U') > 0) {
			nums[4] = map.get('U');
			map.put('U', map.get('U') - nums[4]);
			map.put('F', map.get('F') - nums[4]);
			map.put('R', map.get('R') - nums[4]);
			map.put('O', map.get('O') - nums[4]);
		}

		if (map.get('W') != null && map.get('W') > 0) {
			nums[2] = map.get('W');
			map.put('W', map.get('W') - nums[2]);
			map.put('T', map.get('T') - nums[2]);
			map.put('O', map.get('O') - nums[2]);
		}

		if (map.get('O') != null && map.get('O') > 0) {
			nums[1] = map.get('O');
			map.put('O', map.get('O') - nums[1]);
			map.put('N', map.get('N') - nums[1]);
			map.put('E', map.get('E') - nums[1]);
		}

		if (map.get('F') != null && map.get('F') > 0) {
			nums[5] = map.get('F');
			map.put('F', map.get('F') - nums[5]);
			map.put('I', map.get('I') - nums[5]);
			map.put('V', map.get('V') - nums[5]);
			map.put('E', map.get('E') - nums[5]);
		}

		if (map.get('V') != null && map.get('V') > 0) {
			nums[7] = map.get('V');
			map.put('V', map.get('V') - nums[7]);
			map.put('S', map.get('S') - nums[7]);
			map.put('N', map.get('N') - nums[7]);
			map.put('E', map.get('E') - (nums[7] * 2));
		}

		if (map.get('R') != null && map.get('R') > 0) {
			nums[3] = map.get('R');
			map.put('R', map.get('R') - nums[3]);
			map.put('T', map.get('T') - nums[3]);
			map.put('H', map.get('H') - nums[3]);
			map.put('E', map.get('E') - (nums[3] * 2));
		}

		if (map.get('T') != null && map.get('T') > 0) {
			nums[8] = map.get('T');
			map.put('T', map.get('T') - nums[8]);
			map.put('I', map.get('I') - nums[8]);
			map.put('H', map.get('H') - nums[8]);
			map.put('G', map.get('G') - nums[8]);
			map.put('E', map.get('E') - nums[8]);
		}

		if (map.get('I') != null && map.get('I') > 0) {
			nums[9] = map.get('I');
		}

		String res = "";
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < nums[i]; j++) {
				res += Integer.toString(i);
			}
		}
		System.out.println("Case #" + caseNumber + ": " + res);
	}

	private static void log(final String message) {
		// System.out.println(message);
	}
}
