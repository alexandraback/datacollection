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
			else {
				if (x == 1) {
					winner = "GABRIEL";
				}
				if (x == 2) {
					winner = "GABRIEL";
				}
				if (x == 3) {
					if (r * c == 3) winner = "RICHARD";
					if (r * c == 6) winner = "GABRIEL";
					if (r * c == 9) winner = "GABRIEL";
					if (r * c == 12) winner = "GABRIEL";
				}
				if (x == 4) {
					if (r * c == 4) winner = "RICHARD";
					if (r * c == 8) winner = "RICHARD";
					if (r * c == 12) winner = "GABRIEL";
					if (r * c == 16) winner = "GABRIEL";
				}
			}
			out.printf("Case #%d: %s\n", tc, winner);
		}
		out.flush();
		System.exit(0);
	}
	
}
