package gcj;

import java.io.*;
import java.util.*;

public class pancake {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("pancake.in"));
				//new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("pancake.out")));
				//new OutputStreamWriter(System.out)));
		int t = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= t; tc++) {
			int plates = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			int[] pancakes = new int[plates];
			int maxPancakes = 0;
			for (int i = 0; i < plates; i++) {
				pancakes[i] = Integer.parseInt(st.nextToken());
				if (pancakes[i] > maxPancakes) {
					maxPancakes = pancakes[i];
				}
			}
			int ans = maxPancakes;
			int test;
			for (test = maxPancakes - 1; test > 0; test--) {
				int currAns = test;
				for (int i = 0; i < plates; i++) {
					// add special minutes to total
					currAns += (pancakes[i] - 1) / test;
				}
				if (currAns < ans) {
					ans = currAns;
				}
			}
			out.printf("Case #%d: %d\n", tc, ans);
		}
		out.flush();
		System.exit(0);
	}
	
}
