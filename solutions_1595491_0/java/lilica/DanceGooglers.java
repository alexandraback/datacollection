import java.io.*;
import java.util.*;

public class DanceGooglers {
	static String name = "B-small-attempt2";

	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(name + ".in"));
		PrintWriter out = new PrintWriter(name + ".out");
		int t = Integer.parseInt(in.readLine()), caseN = 1;
		while (caseN <= t) {
			int ans = 0;
			StringTokenizer tok = new StringTokenizer(in.readLine());
			int n = Integer.parseInt(tok.nextToken()), s = Integer.parseInt(tok
					.nextToken()), p = Integer.parseInt(tok.nextToken());

//			System.out.println(n + " " + s + " " + p);
			for (int i = 0; i < n; i++) {
				int total = Integer.parseInt(tok.nextToken());
//				System.out.println(total);
				if (total < p)
					continue;
				
				if (total >= p * 3 - 2) {
					ans++;
					continue;
				}

				if (total >= p * 3 - 4 && s > 0) {
					s--;
					ans++;
				}
			}
			out.print("Case #");
			out.print(caseN++);
			out.print(": ");
			out.println(ans);
//			System.out.println(caseN - 1 + " ans " + ans);
		}
		out.flush();
	}
}