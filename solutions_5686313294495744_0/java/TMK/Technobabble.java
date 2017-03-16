package codejam2016.round1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;

public class Technobabble {	
	public static long max;
	public void run() throws IOException {
		BufferedReader fin = new BufferedReader(new FileReader(new File("in.txt")));
		PrintWriter fout = new PrintWriter(new File("out.txt"));
		int numCases = Integer.parseInt(fin.readLine());
		for (int cases = 0; cases < numCases; cases++) {
			max = 0;
			String[] str = fin.readLine().split(" ");
			int n = Integer.parseInt(str[0]);
			HashMap<String, Integer> firstFrequency = new HashMap<String, Integer>();
			HashMap<String, Integer> secondFrequency = new HashMap<String, Integer>();
			String[][] topics = new String[n][];
			for (int i = 0 ; i < n; i++) {
				topics[i] = fin.readLine().split(" ");
				if (!firstFrequency.containsKey(topics[i][0])) firstFrequency.put(topics[i][0], 0);
				if (!secondFrequency.containsKey(topics[i][1])) secondFrequency.put(topics[i][1], 0);
				firstFrequency.put(topics[i][0], firstFrequency.get(topics[i][0])+1);
				secondFrequency.put(topics[i][1], secondFrequency.get(topics[i][1])+1);
			}
//			int counter = 0;
//			while (firstFrequency.get(topics[counter][]))
			int ans = 0;
//			for (int i = n-1; i >= 0; i--) {
////			for (int i = 0; i < n; i++) {
//				if (firstFrequency.get(topics[i][0]) > 1 && secondFrequency.get(topics[i][1]) > 1) {
//					firstFrequency.put(topics[i][0], firstFrequency.get(topics[i][0])-1);
//					secondFrequency.put(topics[i][1], secondFrequency.get(topics[i][1])-1);
//					ans++;
//					System.out.println(i + " " + firstFrequency.get(topics[i][0]) + " " + secondFrequency.get(topics[i][1]));
//				}
//			}
			dfs(topics, firstFrequency, secondFrequency, 0, 0);
			System.out.format("Case #%d: %d\n", cases+1, max);
			fout.format("Case #%d: %d\n", cases+1, max);
		}
		fin.close();
		fout.close();
	}
	
	public void dfs(String[][] topics, HashMap<String, Integer> firstFrequency, HashMap<String, Integer> secondFrequency, int pos, int num) {
		if (pos == topics.length) {
			if (num > max) {
				max = num;
			}
			return;
		}
		if (firstFrequency.get(topics[pos][0]) > 1 && secondFrequency.get(topics[pos][1]) > 1) {
			firstFrequency.put(topics[pos][0], firstFrequency.get(topics[pos][0])-1);
			secondFrequency.put(topics[pos][1], secondFrequency.get(topics[pos][1])-1);
			dfs(topics, firstFrequency, secondFrequency, pos+1, num+1);
			firstFrequency.put(topics[pos][0], firstFrequency.get(topics[pos][0])+1);
			secondFrequency.put(topics[pos][1], secondFrequency.get(topics[pos][1])+1);
		}
		dfs(topics, firstFrequency, secondFrequency, pos+1, num);
	}

	public static void main(String[] args) throws IOException {
		Technobabble test = new Technobabble();
		test.run();
	}
}
