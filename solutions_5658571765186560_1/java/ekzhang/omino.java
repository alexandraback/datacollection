package gcj;

import java.io.*;
import java.util.*;

public class omino {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(
				new FileReader("omino.in"));
				//new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(
				new FileWriter("omino.out")));
				//new OutputStreamWriter(System.out)));
		int t = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= t; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			// richard wins if can't fill up, else gabriel
			String winner = "ERROR";
			if (r * c % x != 0) {
				winner = "RICHARD";
			}
			else if (x >= 7) {
				winner = "RICHARD";
			}
			else {
				if (r < x && c < x) {
					winner = "RICHARD";
				}
				else if (r <= (x + 1) / 2 || c <= (x + 1) / 2) {
					winner = "RICHARD";
				}
				else if (r + c - 1 <= x) {
					winner = "RICHARD";
				}
				else {
					winner = "GABRIEL";
				}
			}
			out.printf("Case #%d: %s\n", tc, winner);
		}
		out.flush();
		System.exit(0);
	}
	
}
