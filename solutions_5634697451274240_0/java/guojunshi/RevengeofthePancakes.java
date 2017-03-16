package qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class RevengeofthePancakes {
	public static String inPath = "/Users/guojunshi/Downloads/B-small-attempt0.in.txt";
	public static String outPath = "/Users/guojunshi/Downloads/B-small.out.txt";

	// public static String inPath =
	// "/Users/guojunshi/Downloads/A-large.in.txt";
	// public static String outPath =
	// "/Users/guojunshi/Downloads/A-large.out.txt";

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader in = new BufferedReader(new FileReader(inPath));
		BufferedWriter out = new BufferedWriter(new FileWriter(outPath));
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < T; i++) {
			int result = times(in.readLine());
			out.write("Case #" + (i + 1) + ": " + result);
			out.newLine();
		}
		in.close();
		out.close();
	}

	public static int times(String line) {
		if (line == null || line.length() == 0) {
			return 0;
		}
		char[] cs = line.toCharArray();
		int[] times = new int[cs.length];
		int len = cs.length;
		times[0] = cs[0] == '+' ? 0 : 1;
		for (int i = 1; i < len; i++) {
			if (cs[i] == '+' || cs[i - 1] == '-') {
				times[i] = times[i - 1];
			} else {
				times[i] = times[i - 1] + 2;
			}
		}
		return times[len - 1];
	}

}
