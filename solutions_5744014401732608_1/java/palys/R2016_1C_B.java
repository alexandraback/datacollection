package r2016.round1c;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class R2016_1C_B {
	
	private final static String CASE = "Case #%d: ";
	
	private int t;
	
	public static void main(final String[] args) {
		new R2016_1C_B().solve();
	}
	
	public void solve(final Scanner in, final PrintStream out) throws IOException {
		readNumberCases(in);
		for (int i = 0; i < numberCases(); i++) {
			printCaseLabel(i, out);
			readCase(in);
			solveCase();
			printOutput(out);
			out.println();
		}
	}

	private String folder() {
		return this.getClass().getSimpleName() + "_cases";
	}

	private String inFolder() {
		return folder() + "/in";
	}
	
	private String outFolder() {
		return folder() + "/out";
	}
	
	private void ensureDirectoryExists(final File f) {
		if (!f.isDirectory()) {
			f.mkdir();
		}
	}
	
	private String filePath(final String file, final String dir) {
		return dir + "/" + file;
	}
	
	private String caseLabel(final int n) {
		return String.format(CASE, n + 1);
	}
	
	private void printCaseLabel(final int n, final PrintStream out) {
		out.print(caseLabel(n));
	}
	
	private void solve() {
		
		final File directory = new File(folder());
		final File inDirectory = new File(inFolder());
		final File outDirectory = new File(outFolder());
		
		ensureDirectoryExists(directory);
		ensureDirectoryExists(outDirectory);
		ensureDirectoryExists(inDirectory);
		
		for (final String in : inDirectory.list()) {
			final String fileNameCore = in.replace(".in", "");
			final String outFileName = fileNameCore + ".out";
			
			final File inFile = new File(filePath(in, inFolder()));
			final File outFile = new File(filePath(outFileName, outFolder()));
			try (final PrintStream ps =  new PrintStream(outFile);
					final Scanner s = new Scanner(inFile)){
				solve(s, ps);
			} catch (final IOException e) {
				e.printStackTrace();
			} 
		}
	}
	
	private int numberCases() {
		return t;
	}
	
	private void readNumberCases(final Scanner in) {
		t = in.nextInt();
	}
	
	int B;
	long M;
	
	boolean G[][];
	boolean possible;
	
	private void readCase(final Scanner in) {
		B = in.nextInt();
		M = in.nextLong();
	}
	
	private void better() {
		String s = Long.toBinaryString(M);
		
		boolean first = false;
		
		if (M == (1l << B - 2)) {
			G = full(0);
			return;
		}
		
		while(s.length() < B) {
			s = "0" + s;
		}
		
		for (int i = 0; i < B; i++) {
			boolean x = (s.charAt(i) == '1');
			if (first) {
				G[0][i - 1] = x;
			} else {
				if (x) {
					if (!first) {
						first = true;
						G = full(i - 1);
					} 
					G[0][i - 1] = true;
				} 
			}
		}
	}
	
	private boolean[][] empty() {
		boolean g[][] = new boolean[B][B];
		for (int i = 0; i < B; i++) {
			for (int j = 0; j < B; j++) {
				g[i][j] = false;
			}
		}
		return g;
 	}
	
	private void solveCase() {
		//G = full(0);
		G = empty();
		//int c = count(G, 0, B - 1);
		
		long c = 1l << (B - 2);
		//System.out.println(B + " " + c);
		possible = true;
		if (c < M) {
			possible = false;
			return;
		}
		
		//solve(G, 0, 0);
		better();
	}
	
	private boolean solve(boolean G[][], int x, int y) {
		
		//int c = count(G, 0, B - 1);
		
		int c = 1 << (B - 2);
		System.out.println(B + " " + c);
		
		if (c < M) {
			return false;
		} else if (c == M) {
			return true;
		}
		
		for (int i = x; i < B; i++) {
			for (int j = (i == x) ? y : i + 1; j < B; j++) {
				if (G[i][j]) {
					G[i][j] = false;
					if (solve(G, i, j)) {
						return true;
					}
					G[i][j] = true;
				}
			}
		}
		return false;
	}
	
	private int count(boolean[][] g, int src, int target) {
		if (src == target) {
			return 1;
		}
		
		int res = 0;
		for (int i = 0; i < B; i++) {
			if (g[src][i]) {
				res += count(g, i, target);
			}
		}
		return res;
	}
	
	private boolean[][] full(int src) {
		boolean[][] g = new boolean[B][B];
		for (int i = src; i < B; i++) {
			for (int j = src; j < B; j++) {
				g[i][j] = (i < j);
			}
		}
		return g;
	}
	
	private void printOutput(final PrintStream out) {
		if (possible) {
			out.println("POSSIBLE");
			for (int i = 0; i < B; i++) {
				for (int j = 0; j < B; j++) {
					out.print(G[i][j] ? 1 : 0);
				}
				out.println();
			}
		} else {
			out.print("IMPOSSIBLE");
		}
	}
}
