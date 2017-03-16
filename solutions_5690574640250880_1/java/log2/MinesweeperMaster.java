import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Arrays;

public class MinesweeperMaster {

	private static final class Solver {

		private int r;
		private int c;
		private int m;

		private enum CellStatus {
			HAS_MINE, NO_NEARBY_MINE, ONE_OR_MORE_NEARBY_MINES, CLICK
		}

		private CellStatus[][] board;

		Solver(int r, int c, int m) {
			this.r = r;
			this.c = c;
			this.m = m;
			board = new CellStatus[r][c];

			for (CellStatus[] boardRow : board) {
				Arrays.fill(boardRow, CellStatus.NO_NEARBY_MINE);
			}
		}

		public void solveAndWriteTo(PrintWriter writer) {
			if (fillAndCheck())
				writeBoard(writer);
			else
				writer.println("Impossible");
		}

		private void writeBoard(PrintWriter writer) {
			for (int i = 0; i < r; i++) {
				CellStatus[] boardRow = board[i];
				for (int j = 0; j < c; j++) {
					switch (boardRow[j]) {
					case CLICK:
						writer.print("c");
						break;

					case HAS_MINE:
						writer.print("*");
						break;

					case NO_NEARBY_MINE:
					case ONE_OR_MORE_NEARBY_MINES:
					default:
						writer.print(".");
						break;
					}
				}
				writer.println();
			}
		}

		private boolean fillAndCheck() {
			int remainingMines = m;
			int offsetR = 0;
			int offsetC = 0;

			int remainingR = r;
			int remainingC = c;

			while (remainingMines >= remainingC || remainingMines >= remainingR) {
				// Place some mines
				boolean canPlaceHorizontally = remainingMines >= remainingC;
				boolean canPlaceVertically = remainingMines >= remainingR;
				boolean placeVertically = canPlaceVertically
						&& (!canPlaceHorizontally || remainingC > remainingR);
				boolean placeHorizontally = canPlaceHorizontally
						&& !placeVertically;
				if (placeVertically) {
					fillVertically(offsetR, offsetC, remainingR);
					remainingMines -= remainingR;
					offsetC++;
					remainingC--;
				} else if (placeHorizontally) {
					fillHorizontally(offsetR, offsetC, remainingC);
					remainingMines -= remainingC;
					offsetR++;
					remainingR--;
				}
			}

			// Place remaining mines if any
			if (remainingMines > 0) {
				int optimalMinesPerAxis = (remainingMines + 1) / 2;
				int size1 = optimalMinesPerAxis;
				int size2 = Math.max(1, remainingMines - size1 + 1);
				int majorSize = Math.max(size1, size2);
				int minorSize = Math.min(size1, size2);
				int horizontalStripeLength;
				int verticalStripeLength;
				if (remainingC > remainingR) {
					horizontalStripeLength = majorSize;
					verticalStripeLength = minorSize;
				} else {
					verticalStripeLength = majorSize;
					horizontalStripeLength = minorSize;
				}
				if (verticalStripeLength + 1 == remainingR
						|| horizontalStripeLength + 1 == remainingC)
					return false;
				// Distribute remaining mines across axes
				fillVertically(offsetR, offsetC, verticalStripeLength);
				fillHorizontally(offsetR, offsetC, horizontalStripeLength);
			}

			// Fill surroundings if any
			// Fill vertical stripe near offset
			// dumpBoard();
			for (int i = offsetR - 1; i < r; i++) {
				for (int j = offsetC - 1; j <= offsetC; j++) {
					if (i >= 0 && j >= 0 && board[i][j] == CellStatus.HAS_MINE) {
						markNearby(i, j);
					}
				}
			}
			// dumpBoard();
			// Fill horizontal stripe near offset
			for (int j = offsetC - 1; j < c; j++) {
				for (int i = offsetR - 1; i <= offsetR; i++) {
					if (i >= 0 && j >= 0 && board[i][j] == CellStatus.HAS_MINE) {
						markNearby(i, j);
					}
				}
			}
			// dumpBoard();
			// Check for at least one blank, or only one non-blank/non-mine
			// available
			// to click on
			int blanksFound = 0;
			int nearbyMinesFound = 0;

			int targetR = -1;
			int targetC = -1;

			for (int i = offsetR; i < r; i++) {
				for (int j = offsetC; j < c; j++) {
					switch (board[i][j]) {
					case HAS_MINE:
						break;

					case NO_NEARBY_MINE:
						blanksFound++;
						targetR = i;
						targetC = j;
						break;

					case ONE_OR_MORE_NEARBY_MINES:
						nearbyMinesFound++;
						targetR = i;
						targetC = j;
						break;

					default:
						break;
					}
				}
			}
			if ((blanksFound == 0 && nearbyMinesFound == 1)
			) {
				// Just one cell to click on, no need to expand recursively
				board[targetR][targetC] = CellStatus.CLICK;
				return true;
			} else if (blanksFound > 0) {
				// At least one blank found, this can expand recursively
				// onto the whole board, so this is a solution
				board[targetR][targetC] = CellStatus.CLICK;
				return true;
			}
			return false;
		}

		private void dumpBoard() {
			StringWriter stringWriter = new StringWriter();
			PrintWriter writer = new PrintWriter(stringWriter);
			writeBoard(writer);
			System.out.println(stringWriter.toString());
		}

		private void markNearby(int i, int j) {
			markIfPossible(i + 1, j);
			markIfPossible(i + 1, j + 1);
			markIfPossible(i, j + 1);
		}

		private void markIfPossible(int i, int j) {
			if (i < r && j < c && board[i][j] == CellStatus.NO_NEARBY_MINE) {
				board[i][j] = CellStatus.ONE_OR_MORE_NEARBY_MINES;
			}
		}

		private void fillHorizontally(int fromR, int fromC, int len) {
			for (int j = fromC; j < fromC + len; j++) {
				board[fromR][j] = CellStatus.HAS_MINE;
			}
		}

		private void fillVertically(int fromR, int fromC, int len) {
			for (int i = fromR; i < fromR + len; i++) {
				board[i][fromC] = CellStatus.HAS_MINE;
			}
		}
	}

	private File from;
	private File to;

	public MinesweeperMaster(String in, String out) {
		from = new File(in);
		to = new File(out);
	}

	public static void main(String[] args) throws IOException {
		new MinesweeperMaster(args[0], args[1]).go();
	}

	private void go() throws IOException {
		try (FileReader fileReader = new FileReader(from)) {
			try (BufferedReader bufferedReader = new BufferedReader(fileReader)) {
				int cases = getNextInt(bufferedReader);
				translateAll(cases, bufferedReader);
			}
		}

	}

	private int getNextInt(BufferedReader bufferedReader) throws IOException {
		String readLine = bufferedReader.readLine();
		return Integer.valueOf(readLine);
	}

	private void translateAll(int count, BufferedReader bufferedReader)
			throws IOException {
		try (PrintWriter writer = new PrintWriter(new FileWriter(to))) {
			for (int i = 1; i <= count; i++) {
				translateNext(i, bufferedReader, writer);
			}
		}
	}

	private void translateNext(int caseIndex, BufferedReader bufferedReader,
			PrintWriter writer) throws IOException {
		int[] rcm = readVector(bufferedReader);
		int r = rcm[0];
		int c = rcm[1];
		int m = rcm[2];

		writer.println("Case #" + caseIndex + ":");

		new Solver(r, c, m).solveAndWriteTo(writer);
	}

	private int[] readVector(BufferedReader bufferedReader) throws IOException {
		String line = bufferedReader.readLine();
		String[] parts = line.split(" ");
		int[] values = new int[parts.length];
		for (int i = 0; i < parts.length; i++) {
			values[i] = Integer.valueOf(parts[i]);
		}
		return values;
	}
}
