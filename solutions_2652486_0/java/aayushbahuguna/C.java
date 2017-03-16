package codejam2013Round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class C {

	public static void main(String[] args) throws IOException {
		boolean large = false;
		// large = true;
		String dir = "/home/aayush/Dropbox/workspace/workspaceWindows/AlgorithmJava/GoogleCodeJam/codejam2013Round1A/";
		String OutputFile = dir + (large ? "C-large.out" : "C-small.out");
		BufferedWriter fw = new BufferedWriter(new FileWriter(OutputFile));
		String inputFile = dir + "B-small-attempt0.in";
		Scanner st = new Scanner(System.in);
		// Scanner st = new Scanner(new BufferedReader(new
		// FileReader(inputFile)));
		fw.write("Case #1:\n");
		System.out.println("Case #1:");
		int T = st.nextInt();
		int R = st.nextInt();
		int N = st.nextInt();
		int M = st.nextInt();
		int K = st.nextInt();
		int[] P = new int[K];
		for (int i = 0; i < R; i++) {
			int[] f = new int[3];
			int[] ran = new int[] { 2, 3, 5 };
			for (int j = 0; j < K; j++) {
				P[j] = st.nextInt();
				int r = P[j];
				for (int k = 0; k < 3; k++) {
					while (r % ran[k] == 0) {
						r /= ran[k];
						f[k]++;
					}
				}
			}
			String result = "";
			int x = (f[0] > 0 ? 1 : 0) * 100 + (f[1] > 0 ? 1 : 0) * 10 + (f[2] > 0 ? 1 : 0);
			switch (x) {
			case 0:
				result = "222";
				break;
			case 1:
				result = "555";
				break;
			case 10:
				result = "333";
				break;
			case 11:
				if (f[1] > f[2])
					result = "335";
				else
					result = "553";
				break;
			case 100:
				if (f[0] == 8) {
					result = "444";
				} else if (f[0] >= 6)
					result = "442";
				else if (f[0] <= 3) {
					result = "222";
				} else {
					result = "224";
				}
				break;
			case 101:
				if (f[2] > 2) {
					result = "255";
				} else if (f[0] > 3) {
					result = "245";
				} else {
					result = "225";
				}
				break;
			case 110:
				if (f[0] > 4)
					result = "432";
				else
					result = "223";
				break;
			case 111:
				if (f[0] > 4)
					result = "235";
				else
					result = "435";
				break;
			}
			fw.write(result + "\n");
			System.out.println(result);
		}
		fw.flush();
		fw.close();

	}
}
