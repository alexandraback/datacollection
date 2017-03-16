package by.bsu.fpm.semenkev;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

public class RevengeOfThePancakes {
	
	public static void main(String[] args) throws Exception {
		solve(args.length > 0 ? args[0] : "B-large.in");
	}
	
	private static int solveCase(String s) {
		s = s.replaceAll("\\+{2,}", "+").replaceAll("-{2,}", "-");
		return s.endsWith("+") ? s.length() - 1 : s.length();
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
			String test = input.readLine().trim();
			int answer = solveCase(test);
			output.format("Case #%d: %d\n", i+1, answer);
		}
	}
	
}
