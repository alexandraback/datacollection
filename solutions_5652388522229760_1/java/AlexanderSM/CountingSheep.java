package by.bsu.fpm.semenkev;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

public class CountingSheep {

	public static void main(String[] args) throws Exception {
		solve(args.length > 0 ? args[0] : "A-large.in");
	}
	
	private static int solve(int n) {
		if (n == 0) {
			return -1;
		}
		int curr = n;
		boolean[] dig = digOf(curr);
		while(!isAllTrue(dig)) {
			curr += n;
			dig = join(dig, digOf(curr));
		}
		return curr;
	}
	
	private static boolean[] digOf(int n) {
		boolean[] res = new boolean[10];
		String s = String.valueOf(n);
		for(int i=0; i<s.length(); i++) {
			String sdig = s.substring(i, i+1);
			res[Integer.valueOf(sdig)] = true;
		}
		return res;
	}
	
	private static boolean[] join(boolean[] trg, boolean[] val) {
		for(int i=0; i<trg.length; i++) {
			trg[i] = trg[i] || val[i];
		}
		return trg;
	}
	
	private static boolean isAllTrue(boolean[] arr) {
		for (boolean b : arr) {
			if(!b) return false;
		}
		return true;
	}
	
	private static String getFileName(String filePath) {
		return filePath.replaceAll("\\.([^\\.]*)$", "");
	}
	
	private static void solve(String testFile) throws Exception {
		File inputFile = new File(testFile);
		File outputFile = new File(getFileName(inputFile.getAbsolutePath())+".out");
		BufferedReader input = new BufferedReader(new FileReader(inputFile));
		PrintWriter output = new PrintWriter(outputFile);
		solve(input, output);
		input.close();
		output.close();
	}
	
	private static void solve(BufferedReader input, PrintWriter output) throws Exception {
		int testNum = Integer.parseInt(input.readLine());
		for (int i=0; i<testNum; i++) {
			int task = Integer.valueOf(input.readLine());
			int answer = solve(task);
			if (answer == -1) {
				output.format("Case #%d: INSOMNIA", i+1);
			} else {
				output.format("Case #%d: %d", i+1, answer);
			}
			output.write('\n');
		}
	}
	
}
