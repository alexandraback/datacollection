import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {
		int numTests = nextInt();
		for (int test = 1; test <= numTests; test++) {
			int height = nextInt();
			int width = nextInt();
			int mines = nextInt();
			out.println("Case #" + test + ":");
			//out.println(height + " " + width + " " + mines);
			boolean ok = false;
			for (Solver s : solvers) {
				s.setup(height, width, mines);
				if (s.solve()) {
					s.registerHit();
					ok = true;
					printBoard(s.getBoard());
					break;
				}
			}
			if (!ok) {
				out.println("Impossible");
			}
		}
		for (Solver s : solvers) {
			System.err.println(s.getClass()+  " " + s.getNumHits());
		}
	}

	Solver[] solvers = {
			//new LikelyToBeCorrectSolver(),
			//new BfsSolver(),
			//new RowByRowSolver(),
			//new RowAlterntatingSolver(),
			//new ColByColSolver(),
			//new ColAlterntatingSolver(),			
			new BruteForceSolver(),
	};

	private void printBoard(char[][] s) throws IOException {
		for (int i = 0; i < s.length; i++) {
			out.println(new String(s[i]));
		}
	}

	interface Solver {
		public void setup(int height, int width, int mines);
		public boolean solve();
		public char[][] getBoard();
		public void registerHit();
		public int getNumHits();
	}

	class DummySolver implements Solver {
		char[][] s;
		int height, width, mines;
		boolean solved;
		int numHits;
		public void setup(int height, int width, int mines) {
			this.height = height;
			this.width = width;
			this.mines = mines;
			this.s = new char[height][width];
			for (char[] row : s) {
				Arrays.fill(row, '.');
			}
			this.solved = false;
		}
		public boolean solve() {
			solved = false;
			return solved;
		}
		public char[][] getBoard() {
			if (!solved) {
				return null;
			}
			char[][] ret = new char[height][];
			for (int i = 0; i < height; i++) {
				ret[i] = Arrays.copyOf(s[i], width);
			}
			return ret;
		}
		public void placeTheClick() {
			for (int r = 0; r < height; r++) {
				for (int c = 0; c < width; c++) {
					boolean ok = true;
					for (int dr = -1; dr <= 1; dr++) {
						for (int dc = -1; dc <= 1; dc++) {
							int nr = r + dr;
							int nc = c + dc;
							if (nr < 0 || nr >= height || nc < 0 || nc >= width) continue;
							if (s[nr][nc] == '*') {
								ok = false;
							}
						}
					}
					if (ok) {
						solved = true;
						s[r][c] = 'c';
						return;
					}
				}
			}
			int er = -1;
			int ec = -1;
			int numEmpty = 0;
			for (int r = 0; r < height; r++) {
				for (int c = 0; c < width; c++) {
					if (s[r][c] != '*') {
						er = r;
						ec = c;
						++numEmpty;
					}
				}
			}
			if (numEmpty == 1) {
				solved = true;
				s[er][ec] = 'c';
			}
		}
		public void registerHit() {
			++numHits;
		}
		public int getNumHits() {
			return numHits;
		}
	}

	class BfsSolver extends DummySolver {
		public boolean solve() {
			int[] qr = new int[height*width];
			int[] qc = new int[height*width];
			boolean[][] was = new boolean[height][width];
			int qt = 0;
			int qh = 1;
			was[0][0] = true;
			while (qt < qh) {
				int r = qr[qt];
				int c = qc[qt];
				++qt;
				for (int dr = -1; dr <= 1; dr++) {
					for (int dc = -1; dc <= 1; dc++) {
						if (dr == 0 ^ dc == 0) {
							int nr = r + dr;
							int nc = c + dc;
							if (nr < 0 || nr >= height || nc < 0 || nc >= width) continue;
							if (was[nr][nc]) continue;
							was[nr][nc] = true;
							qr[qh] = nr;
							qc[qh] = nc;
							++qh;
						}
					}
				}
			}
			for (int i = 0; i < mines; i++) {
				s[qr[i]][qc[i]] = '*';
			}
			placeTheClick();
			return solved;
		}
	}
	
	class RowByRowSolver extends DummySolver {
		public boolean solve() {
			int[] qr = new int[height*width];
			int[] qc = new int[height*width];
			int k = 0;
			for (int r = 0; r < height; r++) {
				for (int c = 0; c < width; c++) {
					qr[k] = r;
					qc[k] = c;
					++k;
				}
			}
			for (int i = 0; i < mines; i++) {
				s[qr[i]][qc[i]] = '*';
			}
			placeTheClick();
			return solved;
		}
	}
	
	class RowAlterntatingSolver extends DummySolver {
		public boolean solve() {
			int[] qr = new int[height*width];
			int[] qc = new int[height*width];
			int k = 0;
			for (int r = 0; r < height; r++) {
				for (int c = 0; c <= width - c - 1; c++) {
					qr[k] = r;
					qc[k] = c;
					++k;
					if (c != width - c - 1) {
						qr[k] = r;
						qc[k] = width - c - 1;
						++k;
					}
				}
			}
			for (int i = 0; i < mines; i++) {
				s[qr[i]][qc[i]] = '*';
			}
			placeTheClick();
			return solved;
		}
	}
	
	class ColByColSolver extends DummySolver {
		public boolean solve() {
			int[] qr = new int[height*width];
			int[] qc = new int[height*width];
			int k = 0;
			for (int c = 0; c < width; c++) {
				for (int r = 0; r < height; r++) {				
					qr[k] = r;
					qc[k] = c;
					++k;
				}
			}
			for (int i = 0; i < mines; i++) {
				s[qr[i]][qc[i]] = '*';
			}
			placeTheClick();
			return solved;
		}
	}
	
	class ColAlterntatingSolver extends DummySolver {
		public boolean solve() {
			int[] qr = new int[height*width];
			int[] qc = new int[height*width];
			int k = 0;
			for (int c = 0; c < width; c++) {
				for (int r = 0; r <= height - r - 1; r++) {				
					qr[k] = r;
					qc[k] = c;
					++k;
					if (r < height - r - 1) {
						qr[k] = height - r - 1;
						qc[k] = c;
						++k;	
					}
				}
			}
			for (int i = 0; i < mines; i++) {
				s[qr[i]][qc[i]] = '*';
			}
			placeTheClick();
			return solved;
		}
	}

	class BruteForceSolver extends DummySolver {
		public boolean solve() {
			deg = new int[height][width];
			was = new boolean[height][width];
			int n = height*width;
			for (int mask = 0; mask < 1<<n; mask++) {
				if (Integer.bitCount(mask) != mines) continue;
				for (int r = 0; r < height; r++) {
					for (int c = 0; c < width; c++) {
						if ((mask & (1 << (r*width + c))) > 0) {
							s[r][c] = '*';
						} else {
							s[r][c] = '.';
						}
					}
				}
				for (int[] arr : deg) {
					Arrays.fill(arr, 0);
				}				
				for (int r = 0; r < height; r++) {
					for (int c = 0; c < width; c++) {
						if (s[r][c] == '*') {
							deg[r][c] = -1;
							continue;
						}
						for (int dr = -1; dr <= 1; dr++) {
							for (int dc = -1; dc <= 1; dc++) {
								if (dr == 0 && dc == 0) continue;
								int nr = r + dr;
								int nc = c + dc;
								if (nr < 0 || nr >= height || nc < 0 || nc >= width) continue;
								if (s[nr][nc] == '*') ++deg[r][c];
							}
						}
					}
				}
				for (int r = 0; r < height; r++) {
					for (int c = 0; c < width; c++) {
						if (s[r][c] == '*') continue;
						visited = 0;
						for (boolean[] arr : was) {
							Arrays.fill(arr, false);
						}
						dfs(r, c);
						if (visited == height*width - mines) {
							s[r][c] = 'c';
							solved = true;
							return solved;
						}
					}
				}				
			}
			solved = false;
			return solved;
		}
		
		int visited;
		boolean[][] was;
		int[][] deg;
		void dfs(int r, int c) {
			if (was[r][c]) return;
			if (deg[r][c] < 0) return;
			++visited;
			was[r][c] = true;
			if (deg[r][c] != 0) return;
			for (int dr = -1; dr <= 1; dr++) {
				for (int dc = -1; dc <= 1; dc++) {
					if (dr == 0 && dc == 0) continue;
					int nr = r + dr;
					int nc = c + dc;
					if (nr < 0 || nr >= height || nc < 0 || nc >= width) continue;
					dfs(nr, nc);
				}
			}
		}
	}
	
	class LikelyToBeCorrectSolver extends DummySolver {
		public boolean solve() {
			if (height == 1) {
				s[0][0] = 'c';
				for (int i = 0; i < mines; i++) {
					s[0][width - i - 1] = '*';
				}
				solved = true;
				return solved;
			} 
			if (width == 1) {
				s[0][0] = 'c';
				for (int i = 0; i < mines; i++) {
					s[height - i - 1][0] = '*';
				}
				solved = true;
				return solved;
			}
			int freeCells = height * width - mines;
			if (freeCells >= 4 || freeCells == 1) {
				s[0][0] = 'c';
				int placed = 0;
				for (int r = height - 1; r >= 0; r--) {
					for (int c = width - 1; c >= 0; c--) {
						if (r == 0 && c == 0) {
							continue;
						}
						if (freeCells != 1 && (r < 2 && c < 2)) {
							continue;
						}
						if (placed == mines) {
							continue;
						}
						s[r][c] = '*';
						++placed;
					}
				}
				solved = true;
				return solved;
			}
			solved = false;
			return solved;
		}
	}

	

	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String rl = in.readLine();
			if (rl == null)
				return null;
			st = new StringTokenizer(rl);
		}
		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader("C-small-attempt5.in"));
			out = new PrintWriter(new FileWriter("C-small-attempt5.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
