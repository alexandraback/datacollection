package codejam.year2014.qual;

import java.util.*;
import java.io.*;
import java.math.*;

public class C {

	private static Scanner sc;
	private static int R, C, M;

	private static int caseNumber;
	private static Set<Integer> indexes;

	public static void main(final String[] args) {
		// setStreams("C:\\Users\\Yariv\\Desktop\\testC");
		setStreams("C:\\Users\\Yariv\\Desktop\\C-small-attempt2");
		// setStreams("C:\\Users\\Yariv\\Desktop\\C-large");
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
			caseNumber = i;
			handleCase();
		}
	}

	private static void handleCase() {
		R = sc.nextInt();
		C = sc.nextInt();
		M = sc.nextInt();

		final char[][] table = new char[R][C];

		indexes = new HashSet<>(R * C);
		for (int i = 0; i < R * C; i++) {
			indexes.add(i);
		}
		System.out.println("Case #" + caseNumber + ":");
		if (!solve(M, 0, table)) {
			System.out.println("Impossible");
		}
	}

	private static boolean solve(final int leftMines, final int index,
			final char[][] table) {
		if (index == R * C) {
			if (leftMines > 0) {
				return false;
			}
			return trySolve(table);
		}
		final int row = index / C;
		final int col = index % C;
		if (leftMines > 0) {
			table[row][col] = '*';
			indexes.remove(index);
			if (solve(leftMines - 1, index + 1, table)) {
				return true;
			}
			indexes.add(index);
		}
		table[row][col] = '.';
		return solve(leftMines, index + 1, table);
	}

	private static boolean trySolve(final char[][] table) {
		final Set<Integer> currIndexes = new HashSet<>(indexes);
		for (final int index : currIndexes) {
			final int row = index / C;
			final int col = index % C;

			table[row][col] = 'c';
			final Queue<Integer> toOpen = new ArrayDeque<>();
			toOpen.add(index);
			indexes.remove(index);
			if (open(table, toOpen)) {
				return true;
			}
			indexes.add(index);
			table[row][col] = '.';
		}
		return false;
	}

	private static boolean open(final char[][] table,
			final Queue<Integer> toOpen) {

		if (indexes.isEmpty()) {
			printTable(table);
			return true;
		}

		final int index = toOpen.remove();
		final int row = index / C;
		final int col = index % C;
		final Set<Integer> removed = new HashSet<>();
		if (row > 0) {
			if (table[row - 1][col] == '.') {
				final int currIndex = buildIndex(row - 1, col);
				if (indexes.contains(currIndex)) {
					removed.add(currIndex);
				}
			} else if (table[row - 1][col] == '*') {
				return false;
			}
			if (col > 0) {
				if (table[row - 1][col - 1] == '.') {
					final int currIndex = buildIndex(row - 1, col - 1);
					if (indexes.contains(currIndex)) {
						removed.add(currIndex);
					}
				} else if (table[row - 1][col - 1] == '*') {
					return false;
				}
			}
			if (col < (C - 1)) {
				if (table[row - 1][col + 1] == '.') {
					final int currIndex = buildIndex(row - 1, col + 1);
					if (indexes.contains(currIndex)) {
						removed.add(currIndex);
					}
				} else if (table[row - 1][col + 1] == '*') {
					return false;
				}
			}
		}

		if (row < (R - 1)) {
			if (table[row + 1][col] == '.') {
				final int currIndex = buildIndex(row + 1, col);
				if (indexes.contains(currIndex)) {
					removed.add(currIndex);
				}
			} else if (table[row + 1][col] == '*') {
				return false;
			}
			if (col > 0) {
				if (table[row + 1][col - 1] == '.') {
					final int currIndex = buildIndex(row + 1, col - 1);
					if (indexes.contains(currIndex)) {
						removed.add(currIndex);
					}
				} else if (table[row + 1][col - 1] == '*') {
					return false;
				}
			}
			if (col < (C - 1)) {
				if (table[row + 1][col + 1] == '.') {
					final int currIndex = buildIndex(row + 1, col + 1);
					if (indexes.contains(currIndex)) {
						removed.add(currIndex);
					}
				} else if (table[row + 1][col + 1] == '*') {
					return false;
				}
			}
		}

		if (col > 0) {
			if (table[row][col - 1] == '.') {
				final int currIndex = buildIndex(row, col - 1);
				if (indexes.contains(currIndex)) {
					removed.add(currIndex);
				}
			} else if (table[row][col - 1] == '*') {
				return false;
			}
		}
		if (col < (C - 1)) {
			if (table[row][col + 1] == '.') {
				final int currIndex = buildIndex(row, col + 1);
				if (indexes.contains(currIndex)) {
					removed.add(currIndex);
				}
			} else if (table[row][col + 1] == '*') {
				return false;
			}
		}

		for (final int remove : removed) {
			indexes.remove(remove);
			toOpen.add(remove);
		}

		while (!toOpen.isEmpty()) {
			if (open(table, toOpen)) {
				return true;
			}
		}
		for (final int remove : removed) {
			indexes.add(remove);
		}

		return false;
	}

	private static void printTable(final char[][] table) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				System.out.print(table[i][j]);
			}
			System.out.println("");
		}
	}

	private static int buildIndex(final int row, final int col) {
		return row * C + col;
	}

	private static void log(final String message) {
		System.out.println(message);
	}
}
