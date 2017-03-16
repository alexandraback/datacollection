package net.shivramk;

public class Solver {
	private int board[][];
	private int maxRow[];
	private int maxCol[];
	private int n;
	private int m;
	
	public Solver(int n_, int m_) {
		n = n_;
		m = m_;
		board = new int[n][];
		for (int i = 0; i < n; ++i) {
			board[i] = new int[m];
		}
		maxRow = new int[n];
		maxCol = new int[m];
		for (int i = 0 ; i < n; ++i) {
			maxRow[i] = Integer.MIN_VALUE;
		}
		for (int i = 0 ; i < m; ++i) {
			maxCol[i] = Integer.MIN_VALUE;
		}
	}
	
	public void addVal(int i, int j, int v) {
		board[i][j] = v;
		maxRow[i] = Math.max(maxRow[i], v);
		maxCol[j] = Math.max(maxCol[j], v);
	}

	public void solve() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (!isConsistent(i, j)) {
					System.out.println("NO");
					return;
				}
			}
		}
		System.out.println("YES");
	}

	private boolean isConsistent(int i, int j) {
		int maxR = maxRow[i];
		int maxC = maxCol[j];
		int val = board[i][j];
		
		return ((maxR <= val) || (maxC <= val));
	}
}