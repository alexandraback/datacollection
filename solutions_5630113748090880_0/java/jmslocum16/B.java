import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int testcase = 1; testcase <= T; testcase++) {
			int N = in.nextInt();
			List<Single> singles = new ArrayList<Single>();
			for (int i = 0; i < 2 * N - 1; i++) {
				int[] arr = new int[N];
				for (int j = 0; j < N; j++) {
					arr[j] = in.nextInt();
				}
				Single s = new Single(arr);
				singles.add(s);
			}
			IntWrapper index = new IntWrapper(0);
			Comparator<Single> comparator = new Comparator<Single>() {
				@Override
				public int compare(Single a, Single b) {
					return Integer.compare(a.arr[index.i], b.arr[index.i]);
				}
			};
			List<Pair> pairs = new ArrayList<Pair>();
			int oddRow = -1;
			for (int i = 0; i < N; i++) {
				index.i = i;
				Collections.sort(singles, comparator);
				Pair p;
				if (singles.size() == 1 || singles.get(0).arr[i] != singles.get(1).arr[i]) {
					p = new Pair(i, singles.get(0).arr, null);
					singles.remove(0);
					if (oddRow != -1) throw new IllegalStateException();
					oddRow = i;
				} else {
					p = new Pair(i, singles.get(0).arr, singles.get(1).arr);
					singles.remove(0);
					singles.remove(0);
				}
				pairs.add(p);
			}
			int[][] board = new int[N][N];

			// fill in the center of each one
			for (int i = 0; i < N; i++) {
				board[i][i] = pairs.get(i).a[i];
			}
			for (int i = 0; i < N; i++) {
				board[i][oddRow] = pairs.get(oddRow).a[i];
			}
			pairs.remove(oddRow);

			// all ones that are equal fill in and remove too
			List<Pair> newPairs = new ArrayList<Pair>();
			for (Pair p : pairs) {
				boolean same = true;
				for (int i = 0; i < N; i++) {
					if (p.a[i] != p.b[i]) {
						same = false;
						break;
					}
				}
				if (same) {
					for (int i = 0; i < N; i++) {
						board[i][p.index] = board[p.index][i] = p.a[i];
					}
				} else {
					newPairs.add(p);
				}
			}
			pairs = newPairs;

			while (!pairs.isEmpty()) {
				int startSize = pairs.size();
				newPairs = new ArrayList<Pair>();

				for (Pair p : pairs) {
					boolean oneWay = matches(p.index, p.a, p.b, board);
					boolean otherWay = matches(p.index, p.b, p.a, board);
					if (!oneWay && !otherWay) throw new IllegalStateException("No solution!");
					if (oneWay && otherWay) {
						newPairs.add(p);
					} else if (oneWay) {
						writeOut(p.index, p.a, p.b, board);
					} else {
						writeOut(p.index, p.b, p.a, board);
					}
				}

				pairs = newPairs;
				if (pairs.size() == startSize) throw new IllegalStateException("didn't get rid of any pairs!");
			}


			// output
			System.out.print("Case #" + testcase + ": ");
			for (int i = 0; i < N; i++) {
				if (i != 0) System.out.print(" ");
				System.out.print(board[oddRow][i]);
			}
			System.out.println();
		}
	}

	public static boolean matches(int index, int[] a, int[] b, int[][] board) {
		for (int i = 0; i < board.length; i++) {
			if (board[i][index] != 0 && board[i][index] != a[i]) {
				return false;
			}
		}
		for (int i = 0; i < board.length; i++) {
			if (board[index][i] != 0 && board[index][i] != b[i]) {
				return false;
			}
		}
		return true;
	}

	public static void writeOut(int index, int[] a, int[] b, int[][] board) {
		for (int i = 0; i < board.length; i++) {
			board[i][index] = a[i];
			board[index][i] = b[i];
		}
	}

	public static class IntWrapper {
		int i;
		public IntWrapper(int i) {
			this.i = i;
		}
	}

	public static class Single {
		int[] arr;
		public Single(int[] arr) {
			this.arr = arr;
		}
	}

	public static class Pair {
		int index;
		int[] a;
		int[] b;
		public Pair(int index, int[] a, int[] b) {
			this.index = index;
			this.a = a;
			this.b = b;
		}	
	}
	
}
