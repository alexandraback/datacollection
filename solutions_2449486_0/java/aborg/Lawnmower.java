package googlecodejam2013.qualification.lawnmower;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collection;

public class Lawnmower {
	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0])
						: new InputStreamReader(System.in));
		try {
			Writer out = new BufferedWriter(args.length > 1 ? new FileWriter(
					args[1]) : new OutputStreamWriter(System.out));
			try {
				int testCases = Integer.parseInt(br.readLine().trim());
				for (int i = 1; i <= testCases; ++i) {
					String[] sizeLine = br.readLine().split(" ");
					int n = Integer.parseInt(sizeLine[0]);
					int m = Integer.parseInt(sizeLine[1]);
					String[] board = new String[n];
					for (int j = n; j-- > 0;) {
						board[j] = br.readLine();
					}
					out.write("Case #" + i + ": " + evaluate(toInts(board, m))
							+ lineSep);
				}
			} finally {
				out.close();
			}
		} finally {
			br.close();
		}
	}

	private static int[][] toInts(String[] board, int m) {
		int size = board.length;
		int[][] ret = new int[size][m];
		for (int i = size; i-- > 0;) {
			String[] parts = board[i].split(" ");
			for (int j = m; j-- > 0;) {
				ret[i][j] = Integer.parseInt(parts[j]);
			}
		}
		return ret;
	}

	private static String evaluate(int[][] board) {
		int max = findMax(board), min = 1;
		while (isPossible(board) && min < max) {
			// if (min > 1) {
			// System.out.println(min);
			// }
			board = elevate(board, ++min);
		}
		return isPossible(board) ? "YES" : "NO";
	}

	private static int[][] elevate(int[][] board, int newMinValue) {
		int[][] ret = new int[board.length][board[0].length];
		for (int i = ret.length; i-- > 0;) {
			for (int j = ret[i].length; j-- > 0;) {
				ret[i][j] = Math.max(board[i][j], newMinValue);
			}
		}
		return ret;
	}

	private static int findMax(int[][] board) {
		int ret = Integer.MIN_VALUE;
		for (int i = board.length; i-- > 0;) {
			for (int j = board[i].length; j-- > 0;) {
				ret = Math.max(ret, board[i][j]);
			}
		}
		return ret;
	}

	private static boolean isPossible(int[][] board) {
		int[][] flipped = flip(board);
		boolean ok = checkHorizontally(board, flipped);
		ok &= checkHorizontally(flipped, board);
		return ok;
	}

	private static boolean checkHorizontally(int[][] board, int[][] flipped) {
		boolean allOK = true;
		for (int i = board.length; i-- > 0;) {
			int min = findMin(board[i]);
			Collection<Integer> minIndices = findIndices(board[i], min);
			if (minIndices.size() < board[i].length) {
				for (int index : minIndices) {
					if (!checkLine(flipped[index], min)) {
						return false;
					}
				}
			}
		}
		return allOK;
	}

	private static boolean checkLine(int[] is, int min) {
		for (int i : is) {
			if (i > min) {
				return false;
			}
		}
		return true;
	}

	private static Collection<Integer> findIndices(int[] is, int min) {
		Collection<Integer> ret = new ArrayList<Integer>();
		for (int i = 0; i < is.length; ++i) {
			if (is[i] == min) {
				ret.add(i);
			}
		}
		return ret;
	}

	private static int findMin(int[] is) {
		int ret = is[0];
		for (int i : is) {
			if (i < ret) {
				ret = i;
			}
		}
		return ret;
	}

	private static int[][] flip(int[][] board) {
		int n = board.length;
		int m = board[0].length;
		int[][] ret = new int[m][n];
		for (int i = n; i-- > 0;) {
			for (int j = m; j-- > 0;) {
				ret[j][i] = board[i][j];
			}
		}
		return ret;
	}
}
