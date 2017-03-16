package codejam.year2014.qual;

import java.util.*;
import java.io.*;
import java.math.*;

public class D {

	private static Scanner sc;
	private static int N;

	public static void main(final String[] args) {
		// setStreams("C:\\Users\\Yariv\\Desktop\\testD");
		// setStreams("C:\\Users\\Yariv\\Desktop\\D-small-attempt0");
		setStreams("C:\\Users\\Yariv\\Desktop\\D-large");
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
		N = sc.nextInt();

		final List<Double> myList = new ArrayList<>(N);
		final List<Double> hisList = new ArrayList<>(N);
		for (int i = 0; i < N; i++) {
			myList.add(i, sc.nextDouble());
		}
		Collections.sort(myList);
		for (int i = 0; i < N; i++) {
			hisList.add(i, sc.nextDouble());
		}
		Collections.sort(hisList);

		final int war = calcWar(new ArrayList<Double>(myList),
				new ArrayList<Double>(hisList));
		final int dwar = calcDWar(new ArrayList<Double>(myList),
				new ArrayList<Double>(hisList));
		System.out.println("Case #" + caseNumber + ": " + dwar + " " + war);
	}

	private static int calcWar(final List<Double> myList,
			final List<Double> hisList) {
		int count = 0;
		while (!myList.isEmpty()) {
			final Double my = myList.remove(myList.size() - 1);
			int index = hisList.size() - 1;
			while (hisList.get(index) > my) {
				index--;
				if (index < 0) {
					break;
				}
			}
			if (index == hisList.size() - 1) {
				count++;
				hisList.remove(0);
			} else {
				hisList.remove(index + 1);
			}
		}

		return count;
	}

	private static int calcDWar(final List<Double> myList,
			final List<Double> hisList) {
		return N - calcWar(hisList, myList);
	}

	private static void log(final String message) {
		System.out.println(message);
	}
}
