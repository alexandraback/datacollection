import java.io.*;
import java.util.*;

public class CodeJam— {
	
	static final String path = "C:/gcj2014/Qual/C/";
	static final String problem = "C-small100";
	
	Scanner in;
	static PrintWriter out;
	boolean swap;
	
	
	void printSwapped(char ans[][], int sizeX, int sizeY) {
//		checkDFS(ans, 0, 0);
//		for (int y = 0; y < sizeY; y++) {
//			for (int x = 0; x < sizeX; x++) {
//				asserT(ans[y][x] != '.');
//			}
//		}
		if (!swap) {
			for (int y = 0; y < sizeY; y++) {
				for (int x = 0; x < sizeX; x++) {
					out.print(ans[y][x]);
				}
				out.println();
			}
		} else {
			for (int x = 0; x < sizeX; x++) {
				for (int y = 0; y < sizeY; y++) {
					out.print(ans[y][x]);
				}
				out.println();
			}
		}
	}
	
	void printSwappedAns(int sizeX, int sizeY, int free) {
		char [][]ans = new char[sizeY][sizeX];
		asserT(free != 0);
		for (int x = 0; x < sizeX; x++) {
			for (int y = 0; y < sizeY; y++) {
				if (free != 0) {
					ans[y][x] = '.';
					free--;
				} else {
					ans[y][x] = '*';
				}
			}
		}
		ans[0][0] = 'c';
		printSwapped(ans, sizeX, sizeY);
	}
	
	void divModOutSwapped(int sizeX, int sizeY, int w, int h, int modH, int mines) {
		char [][]ans = new char[sizeY][sizeX];
		for (int x = 0; x < sizeX; x++) {
			for (int y = 0; y < sizeY; y++) {
				if (x < w && y < h) {
					ans[y][x] = '.';
				} else if (x == w && y < modH) {
					ans[y][x] = '.';
				} else {
					ans[y][x] = '*';
					mines--;
				}
			}
		}
		ans[0][0] = 'c';

		printSwapped(ans, sizeX, sizeY);
		asserT(mines == 0);
	}
	
	void checkDFS(char [][]s, int x, int y) {
		if (s[y][x] == 'G') {
			return;
		}
		s[y][x] = 'G';
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int sx = x + dx;
				int sy = y + dy;
				if (0 <= sx && sx < s[0].length && 0 <= sy && sy < s.length) {
					if (s[sy][sx] == '*') {
						return;
					}
				}
			}
		}
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int sx = x + dx;
				int sy = y + dy;
				if (0 <= sx && sx < s[0].length && 0 <= sy && sy < s.length) {
					checkDFS(s, sx, sy);
				}
			}
		}
		
	}
	
	void divModOutSwappedBlack(int sizeX, int sizeY, int w, int h, int modH, int mines) {
		char [][]ans = new char[sizeY][sizeX];
		for (int x = 0; x < sizeX; x++) {
			for (int y = 0; y < sizeY; y++) {
				if (x < w && y < h) {
					ans[y][x] = '.';
				} else if (x == w && y < modH) {
					ans[y][x] = '.';
				} else {
					ans[y][x] = '*';
					mines--;
				}
			}
		}
		ans[h-1][w-1] = '*';
		mines--;
		asserT(mines == 0);
		ans[0][0] = 'c';
		printSwapped(ans, sizeX, sizeY);
	}
	
	
	boolean doAs(int sizeX, int sizeY, int mines) {
		int free = sizeX * sizeY - mines;
		if (free == 0) {
			return false;
		}
		if (mines == 0 || free == 1) {
			printSwappedAns(sizeX, sizeY, free);
			return true;
		}
		
		if (sizeY == 1) {
			printSwappedAns(sizeX, sizeY, free);
			return true;
		} else {
			// ÎÂÔËÏ ‚˚ÍÛÚ‡Ò˚
			for (int ySizeFree = 2; ySizeFree <= sizeY; ySizeFree++) {
				int cols = free / ySizeFree;
				int addedRowsInLastCol = free % ySizeFree;
				if (1 < cols && cols <= sizeX) {
					if (addedRowsInLastCol == 1) {
						continue;
					}
					if (cols == sizeX && addedRowsInLastCol != 0) {
						continue;
					}
					divModOutSwapped(sizeX, sizeY, cols, ySizeFree, addedRowsInLastCol, mines);
					return true;
				}
			}
			if (sizeX > 3 && mines == sizeY - 1 && sizeY != 2) {
				divModOutSwappedBlack(sizeX, sizeY, sizeX - 1, sizeY, 2, mines);
				return true;
			}	
			return false;
		}

	}
	
	boolean solveOne() {
		int sizeY = in.nextInt();
		int sizeX = in.nextInt();
		
		int mines = in.nextInt();
		swap = false;
		if (doAs(sizeX, sizeY, mines)) {
			return true;
		} else {
			swap = true;
			return doAs(sizeY, sizeX, mines);
		}
	}
	
	void solve() {
		in.useLocale(Locale.US);
		int nTests = in.nextInt();
		for (int i = 1; i <= nTests; i++) {
			out.println("Case #" + i + ":");
			if (!solveOne()) {
				out.println("Impossible");
			}
		}
	}
	
	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	public void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(new FileWriter(path + problem + ".out"));
		} catch (IOException e) {
			System.out.println("Guten Tag>");
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new CodeJam—().run();
	}
}