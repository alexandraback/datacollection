package gcj2016r1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class ProblemA {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		ProblemA obj = new ProblemA();
		obj.solve(fileName);
	}

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		char[][] CH = { { 'Z', 'W', 'U', 'X', 'G' }, { 'O', 'H', 'F' },
				{ 'V', 'I'} };
		String[][] ST = { { "ZERO", "TWO", "FOUR", "SIX", "EIGHT" },
				{ "ONE", "THREE", "FIVE" }, { "SEVEN", "NINE"} };
		int[][] NUM = { { 0, 2, 4, 6, 8 }, { 1, 3, 5 }, { 7, 9} };
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String S = br.readLine();
			int[] cnt = new int[26];
			int[] ans = new int[10];
			for (int a = 0; a < S.length(); a++) {
				cnt[(int) (S.charAt(a) - 'A')]++;
			}
			for (int j = 0; j < CH.length; j++) {
				for (int k = 0; k < CH[j].length; k++) {
					int n = cnt[(int) (CH[j][k] - 'A')];
					ans[NUM[j][k]] = n;
					for (char c : ST[j][k].toCharArray()) {
						cnt[(int) (c - 'A')] = cnt[(int) (c - 'A')] - n;
					}
				}
			}

			StringBuffer buf = new StringBuffer();
			for (int j = 0 ; j < ans.length ; j++) {
				for (int k = 0 ; k < ans[j] ; k++ ) {
					buf.append(Integer.toString(j));
				}
			}
			bw.write("Case #" + (i + 1) + ": " + buf.toString());
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}
}
