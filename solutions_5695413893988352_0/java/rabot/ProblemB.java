package gcj2016r1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.StringTokenizer;

public class ProblemB {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		ProblemB obj = new ProblemB();
		obj.solve(fileName);
	}

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String str = br.readLine();
			StringTokenizer token = new StringTokenizer(str, " ");
			String CC = token.nextToken();
			String JJ = token.nextToken();
			long min_diff = Long.MAX_VALUE;
			long min_c = Long.MAX_VALUE;
			long min_j = Long.MAX_VALUE;

			String fmt = "";
			for (int j = 0; j < CC.length(); j++) {
				fmt += "0";
			}
			DecimalFormat df = new DecimalFormat(fmt);
			LOOP_C: for (int c = 0; c < Math.pow(10, CC.length()); c++) {
				String C = df.format(c);
				for (int a = 0; a < C.length(); a++) {
					if (C.charAt(a) != CC.charAt(a) && CC.charAt(a) != '?') {
						continue LOOP_C;
					}
				}
				LOOP_J: for (int j = 0; j < Math.pow(10, JJ.length()); j++) {
					String J = df.format(j);
					for (int a = 0; a < J.length(); a++) {
						if (J.charAt(a) != JJ.charAt(a)
								&& JJ.charAt(a) != '?') {
							continue LOOP_J;
						}
					}
					if (Math.abs(c - j) < min_diff) {
						min_diff = Math.abs(c - j);
						min_c = c;
						min_j = j;
					} else if (Math.abs(c - j) == min_diff) {
						if (c < min_c) {
							min_c = c;
							min_j = j;
						} else if (c == min_c) {
							if (j < min_j) {
								min_j = j;
							}
						}
					}
				}
			}

			bw.write("Case #" + (i + 1) + ": " + df.format(min_c) + " " + df.format(min_j));
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}
}
