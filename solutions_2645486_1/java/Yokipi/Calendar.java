package roundonea2013;

import java.io.*;
import java.util.*;


public class Calendar {
	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(new File(
				"src/roundonea2013/Calendar.in")));
		FileWriter out = new FileWriter(new File(
				"src/roundonea2013/Calendar.out"));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int maximum = Integer.parseInt(st.nextToken());
			int recharge = Integer.parseInt(st.nextToken());
			int activities = Integer.parseInt(st.nextToken());
			
			int[] values = new int[activities];
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < activities; i++) {
				values[i] = Integer.parseInt(st.nextToken());
			}
			
			long answer = maximize(maximum, recharge, values, maximum, recharge);

			//Formatter format = new Formatter();
			//format.format("%.5f", answer);							 
			out.write("Case #" + t + ": " + answer + "\n");
		}

		in.close();
		out.close();
	}
	
	public static long maximize(int start, int end, int[] values, int max, int regen) {
		if (values.length == 0) {
			return 0;
		}
		else if (values.length == 1) {
			return (long) (Math.max(start-end+regen, 0))*values[0];
		}
		
		int peak = 0;
		int peakindex = -1;
		for (int i = 0; i < values.length; i++) {
			if (values[i] > peak) {
				peak = values[i];
				peakindex = i;
			}
		}
		
		long total = 0;
		boolean limitedleft = false;
		boolean limitedright = false;
		long available = max;
		if (max - (start+regen*peakindex) >= 0) {
			limitedleft = true;
			available = start+regen*peakindex;
		}
		if (end - regen*(values.length-peakindex) > 0) {
			limitedright = true;
			available -= end - regen*(values.length-peakindex);
		}
		total += available*peak;
		if (!limitedleft) total += maximize(start, max, Arrays.copyOfRange(values, 0, peakindex), max, regen);
		if (!limitedright) total += maximize(regen, end, Arrays.copyOfRange(values, peakindex+1, values.length), max, regen);
		
		return total;
	}
}
