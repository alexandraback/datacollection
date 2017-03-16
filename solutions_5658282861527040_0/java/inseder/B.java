package codejam_round1_14;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class B {
	public static void main(String[] args) throws NumberFormatException,
			IOException {

		BufferedReader br = new BufferedReader(
				new InputStreamReader(System.in), 1024 * 1024 * 2);

		int t = Integer.parseInt(br.readLine());

		StringBuilder sb = new StringBuilder();
		for (int x = 1; x <= t; x++) {
			int p[] = readArrayLine(br.readLine(), 3);
			int a = p[0];
			int b = p[1];
			int k = p[2];
			long ret = 0;

			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					if ((i & j) < k) {
						ret++;
						// System.out.println(i + " " + j + " == " + (i & j));
					}
				}
			}
			sb.append("Case #" + x + ": " + ret + "\n");
		}
		BufferedWriter bw = new BufferedWriter(new FileWriter("ii/outBJam.txt"));
		bw.write(sb.toString());
		bw.close();
		System.out.println(sb.toString());
	}

	public static int[] readArrayLine(String line, int n) {
		int[] ret = new int[n];
		int start = 0;
		int end = line.indexOf(' ', start);
		for (int i = 0; i < n; i++) {
			if (end > 0)
				ret[i] = Integer.parseInt(line.substring(start, end));
			else
				ret[i] = Integer.parseInt(line.substring(start));
			start = end + 1;
			end = line.indexOf(' ', start);
		}
		return ret;
	}
}
