package r2016.round1b;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class R2016_1B_C {
	
	private final static String CASE = "Case #%d: ";
	
	private int t;
	
	public static void main(final String[] args) {
		new R2016_1B_C().solve();
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
	
	int N;
	
	int noLeft;
	
	int noRight;
	
	HashMap<String, ArrayList<String>> leftToRight;
	
	HashMap<String, LinkedList<String>> rightToLeft;
	
	int result;
	
	private void readCase(final Scanner in) {
		N = in.nextInt();
		leftToRight = new HashMap<>();
		rightToLeft = new HashMap<>();
		
		for (int i = 0; i < N; i++) {
			String s1 = in.next();
			String s2 = in.next();
			
			if (!leftToRight.containsKey(s1)) {
				leftToRight.put(s1, new ArrayList<>());
			}
			
			leftToRight.get(s1).add(s2);
			
			if (!rightToLeft.containsKey(s2)) {
				rightToLeft.put(s2, new LinkedList<>());
			}
			
			rightToLeft.get(s2).add(s1);
		}
	}
	
	private void solveCase() {
		result = solve(0, leftToRight.keySet().iterator().next());
	}
	
	int solve(int res, String prevLeft) {
		boolean skipped = false;
		int rmax = res;
			
		for (String left : leftToRight.keySet()) {
			
			if (!skipped) {
				if (left.equals(prevLeft)) {
					skipped = true;
				} else {
					continue;
				}
			}
			
			if (leftToRight.get(left).size() > 1) {
				for (int i = 0; i < leftToRight.get(left).size(); i++) {
					String right = leftToRight.get(left).get(i);
					if (rightToLeft.get(right).size() > 1) {
						int r = tryRemove(left, right, res + 1);
						rmax = Math.max(rmax, r);
					}


				}
			}
		}
		
		return rmax;
	}
	
	private int tryRemove(String left, String right, int res) {
		int rightPos = leftToRight.get(left).indexOf(right);
		int leftPos = rightToLeft.get(right).indexOf(left);
		
		leftToRight.get(left).remove(rightPos);
		rightToLeft.get(right).remove(leftPos);
		
		int result = solve(res, left);
		
		leftToRight.get(left).add(rightPos, right);
		rightToLeft.get(right).add(leftPos, left);
		
		return result;
		
	}
	
	private void printOutput(final PrintStream out) {
		out.print(result);
	}
}
