package round1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Problem2 {

	static ArrayList<Long> fs = new ArrayList<>();
	private static long currMax;

	public static void main(String[] args) throws IOException {
		
		File file = new File(args[0]);
		BufferedReader reader = new BufferedReader(new FileReader(file));

		String line;
		line = reader.readLine();
		int n = Integer.parseInt(line);

		for (int j = 0; j < n; j++) {
			line = reader.readLine();
			String[] lineArr = line.split("\\s");
			long max = Long.parseLong(lineArr[0]);
			long regain = Long.parseLong(lineArr[1]);
			int activities = Integer.parseInt(lineArr[2]);
			
			line = reader.readLine();
			lineArr = line.split("\\s");
			long[] acts = new long[activities];
			for (int i = 0; i < acts.length; i++) {
				acts[i] = Long.parseLong(lineArr[i]);
			}
			currMax = 0l;
			solve(max, max, regain, acts, 0,0);
//			solve(j, x, y);
			System.out.println("Case #" + (j + 1) + ": " + currMax);
		}

		reader.close();
	}

	private static void solve(long max, long curr, long regain, long[] acts, int pos, long totalgain) {
		if(totalgain > currMax){
			currMax = totalgain;
		}
		
		if(pos >= acts.length){
			return;
		}
		
		for (int i = 0; i <= curr; i++) {
			long gain = acts[pos] * i;
			solve(max, Math.min(max, curr - i + regain), regain, acts, pos + 1, totalgain + gain);
		}
	}
}
