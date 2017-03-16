package r2016.round1b;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Scanner;

public class R2016_1B_A {
	
	private final static String CASE = "Case #%d: ";
	
	private int t;
	
	public static void main(final String[] args) {
		new R2016_1B_A().solve();
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
	
	String s;
	
	int T[];
	
	char[] indicators = new char[]{'Z', 'O', 'W', 'T', 'U', 'F', 'X', 'S', 'G', 'E'};
	
	int[] order = new int[]{0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
	
	String[] numbers = new String[]{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	
	private void readCase(final Scanner in) {
		s = in.next();
	}
	
	private void solveCase() {
		T = new int[10];
		for (int i = 0; i < 10; i++) {
			T[i] = 0;
		}
		
		HashMap<Character, Integer> chars = new HashMap<>();
		
		for (int i = 0; i < s.length(); i++) {
			if (chars.containsKey(s.charAt(i))) {
				int prev = chars.get(s.charAt(i));
				chars.put(s.charAt(i), prev + 1);
			} else {
				chars.put(s.charAt(i), 1);
			}
		}
		
		for (int i = 0; i < 10; i++) {
			int digit = order[i];
			char indicator = indicators[digit];
			if (chars.containsKey(indicator) && chars.get(indicator) > 0) {
				int count = chars.get(indicator);
				T[digit] = count;
				String str = numbers[digit];
				for (int j = 0; j < str.length(); j++) {
					char c = str.charAt(j);
					chars.put(c, chars.get(c) - count);
				}
			}
		}
		
	}
	
	private void printOutput(final PrintStream out) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < T[i]; j++) {
				out.print(i);
			}
		}
	}
}
