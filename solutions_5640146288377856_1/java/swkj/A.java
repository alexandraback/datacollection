package codejam_2015_1c;
import java.util.*;
import java.io.*;

public class A {

	public static int finalRow(int r, int c, int w) {
		int full = c/w + w - 1;
		int partial = c%w; 
		if (partial > 0) full++;
		return full;
	}
	
	public static void solve(int r, int c, int w) {
		int count = 0;
		// to clear a row 
		int clearRow = c/w + w - 1;
		count += clearRow * (r-1);
		count += finalRow(r,c,w);
		System.out.println(count);
	}
	
	public static void solve() throws IOException {
		String homeFolder = "//Users//user//Documents//workspace//Runnables//src//" 
							+ A.class.getName().replaceFirst("\\..*", "")+ "//";
		String inFile = homeFolder + "A-large.in"; //"B-small-attempt.in";
		String outFile = homeFolder + "A big output";

		Scanner in = new Scanner(new FileReader(inFile));
		FileWriter out = new FileWriter(outFile);
		int totalRounds = in.nextInt();
		for (int round = 1; round <= totalRounds; round++) {
			// FORMATTING HERE
			int r = in.nextInt();
			int c = in.nextInt();
			int w = in.nextInt();
			System.out.format("Case #%d: ", round);
			solve(r,c,w);
		}
		in.close();
		out.close();
	}
	
	public static void main(String[] args) throws IOException {
		solve();
	}
	
}
