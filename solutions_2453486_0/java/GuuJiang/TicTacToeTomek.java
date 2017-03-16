import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;


public class TicTacToeTomek {
	
	private BufferedReader cin;
	private PrintStream cout;
	
	private char[][] board = new char[4][4];
	
	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		new TicTacToeTomek().solve();
	}
	
	public void solve() throws Exception {
		cin = new BufferedReader(new InputStreamReader(System.in));
		cout = System.out;
		int no = Integer.parseInt(cin.readLine());
		for (int i = 1; i <= no; ++i) {
			cout.printf("Case #%d: %s\n", i, solveCase(i));
		}
	}

	private String solveCase(int no) throws Exception {
		String line;
		for (int i = 0; i < 4; ++i) {
			line = cin.readLine();
			for (int j = 0; j < 4; ++j) {
				board[i][j] = line.charAt(j);
			}
		}
		cin.readLine();
		
		List<Iterable<Character>> iters = new LinkedList<>();
		for (int i = 0; i < 4; ++i) {
			iters.add(new RowIterator(i));
			iters.add(new ColumnIterator(i));
		}
		iters.add(new DiagIterator(true));
		iters.add(new DiagIterator(false));
		
		boolean complete = true;
		outer:
		for (Iterable<Character> iter : iters) {
			boolean o = true;
			boolean x = true;
			for (char c : iter) {
				if (c == '.') {
					complete = false;
					continue outer;
				}
				if (c != 'T') {
					if (c == 'O') {
						x = false;
					} else {
						o = false;
					}
				}
			}
			if (o) {
				return "O won";
			}
			if (x) {
				return "X won";
			}
		}
		return complete ? "Draw" : "Game has not completed";
	}
	
	private class ColumnIterator implements Iterator<Character>, Iterable<Character> {
		private final int row;
		private int col = 0;
		
		public ColumnIterator(int row) {
			this.row = row;
		}
		
		@Override
		public boolean hasNext() {
			return col < 4;
		}

		@Override
		public Character next() {
			return board[row][col++];
		}

		@Override
		public void remove() {
		}

		@Override
		public Iterator<Character> iterator() {
			return this;
		}		
	}
	
	private class RowIterator implements Iterator<Character>, Iterable<Character> {
		private final int col;
		private int row;
		
		public RowIterator(int col) {
			this.col = col;
		}

		@Override
		public boolean hasNext() {
			return row < 4;
		}

		@Override
		public Character next() {
			return board[row++][col];
		}

		@Override
		public void remove() {
		}

		@Override
		public Iterator<Character> iterator() {
			return this;
		}
	}
	
	private class DiagIterator implements Iterator<Character>, Iterable<Character> {
		private final boolean direction;
		private int row = 0;
		
		public DiagIterator(boolean direction) {
			this.direction = direction;
		}

		@Override
		public boolean hasNext() {
			return row < 4;
		}

		@Override
		public Character next() {
			int col = direction ? row : 3 - row;
			char c = board[row][col];
			++row;
			return c;
		}

		@Override
		public void remove() {
		}

		@Override
		public Iterator<Character> iterator() {
			return this;
		}		
	}
}