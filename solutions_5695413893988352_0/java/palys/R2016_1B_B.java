package r2016.round1b;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class R2016_1B_B {
	
	private final static String CASE = "Case #%d: ";
	
	private int t;
	
	public static void main(final String[] args) {
		new R2016_1B_B().solve();
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
	
	String first;
	String second;
	
	String result1;
	String result2;
	
	private void readCase(final Scanner in) {
		first = in.next();
		second = in.next();
	}
	
	private void solveCase() {
		brute();
	}
	
	private int max(int length) {
		int n = 1;
		for (int i = 0; i < length; i++) {
			n *= 10;
		}
		return n;
	}
	
	private void brute() {
		int bestC = 1000;
		int bestJ = 1000;
		int minDiff = 1000;
		int length = first.length();
		String formatString = "%0" + length + "d";
		
		for (int i = 0; i < max(length); i++) {
			for (int j = 0; j < max(length); j++) {
				if (matches(first, i, formatString) && matches(second, j, formatString)) {
					if (Math.abs(i - j) < minDiff) {
						minDiff = Math.abs(i - j);
						bestC = i;
						bestJ = j;
					} else if (Math.abs(i - j) == minDiff) {
						if (i < bestC) {
							bestC = i;
							bestJ = j;
						} else {
							if (i == bestC) {
								if (j < bestJ) {
									bestC = i;
									bestJ = j;
								}
							}
						}
					}
				}
			}
		}
		
		result1 = String.format(formatString, bestC);
		result2 = String.format(formatString, bestJ);
	}
	
	private boolean matches(String s, int n, String format) {
		String ss = String.format(format, n);
		//System.out.println(s + " " + n + " " + ss + " " + format);
		for (int i = 0; i < ss.length(); i++) {
			if (!(s.charAt(i) == '?' || s.charAt(i) == ss.charAt(i))) {
				return false;
			}
		}
		return true;
	}
	
	private void printOutput(final PrintStream out) {
		out.print(result1 + " " + result2);
	}
}
