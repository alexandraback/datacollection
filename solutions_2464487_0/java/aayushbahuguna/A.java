package codejam2013Round1A;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws IOException {
		boolean large = false;
		// large = true;
		String dir = "/home/aayush/Dropbox/workspace/workspaceWindows/AlgorithmJava/GoogleCodeJam/codejam2013Round1A/";
		Scanner st = new Scanner(System.in);
		//String InputFile = st.next();
		String OutputFile = dir + (large ? "A-large.out" : "A-small.out");
		BufferedWriter fw = new BufferedWriter(new FileWriter(OutputFile));
		//st = new Scanner(new BufferedReader(new FileReader(InputFile)));
		int T = st.nextInt();
		for (int cases = 1; cases <= T; cases++) {
			double r = st.nextDouble(); 
			double t = st.nextDouble();
			int n = (int)((-(2 * r - 1) + Math.sqrt(4 * r * r + 1 - 4 * r + 8 * t)) / 4);
			if((2 * n * n + (2 * r - 1) * n) > t) n = n - 1;
			fw.write("Case #" + cases + ": " + n + "\n");
			System.out.println("Case #" + cases + ": " + n);
		}
		fw.flush();
		fw.close();
	}
}
