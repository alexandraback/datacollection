package qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Fractiles {
	public static String inPath = "/Users/guojunshi/Downloads/D-small-attempt0.in.txt";
	public static String outPath = "/Users/guojunshi/Downloads/D-small.out.txt";

	// public static String inPath =
	// "/Users/guojunshi/Downloads/A-large.in.txt";
	// public static String outPath =
	// "/Users/guojunshi/Downloads/A-large.out.txt";

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader in = new BufferedReader(new FileReader(inPath));
		BufferedWriter out = new BufferedWriter(new FileWriter(outPath));
		int T = Integer.parseInt(in.readLine()), K, C, S;
		for (int i = 0; i < T; i++) {
			String line = in.readLine();
			String elements[] = line.trim().split("\\s+");
			K = Integer.parseInt(elements[0]);
			C = Integer.parseInt(elements[1]);
			S = Integer.parseInt(elements[2]);
			long gap = 1;
			for (int j = 1; j < C; j++) {
				gap *= K;
			}
			out.write("Case #" + (i + 1) + ":");
			long index = 1;
			for (int j = 0; j < S; j++) {
				out.write(" " + index);
				index += gap;
			}
			out.newLine();
		}
		in.close();
		out.close();
	}

}
