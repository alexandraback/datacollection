package CodeJam2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	static String vowels = "aioue";

	public static void main(String[] args) throws IOException {
		FileReader in = new FileReader("A-small-attempt0.in");
		BufferedReader buff = new BufferedReader(in);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"A-small-attempt0.out")));
		// BufferedReader buff = new BufferedReader(new InputStreamReader(
		// System.in));
		int T = Integer.parseInt(buff.readLine());
		StringTokenizer st;
		for (int i = 1; i <= T; i++) {
			st = new StringTokenizer(buff.readLine());
			String str = st.nextToken();
			int n = Integer.parseInt(st.nextToken());
			out.println("Case #" + i + ": " + solve(str, n));
		}

		in.close();
		out.close();
	}

	private static String solve(String str, int n) {
		int answer = 0;
		for (int i = 0; i < str.length(); i++) {
			loop: for (int j = i; j < str.length(); j++) {
				int cons = 0;
				for (int k = i; k <= j; k++) {
					if (!vowels.contains("" + str.charAt(k))) {
						cons++;
					} else {
						if (cons >= n) {
							answer++;
							continue loop;
						}
						cons = 0;
					}
				}
				if (cons >= n) {
					answer++;
				}
			}
		}
		return answer + "";
	}

}
