import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import java.util.Map;

import com.google.common.collect.ImmutableMap;
import com.google.common.collect.Lists;
import com.google.common.io.LineReader;


public class DancingWithGooglers {

	public static void main(String[] args) throws NumberFormatException, IOException {
		LineReader lineReader = new LineReader(new FileReader(args[0]));
		FileWriter out = new FileWriter(args[0] + "-out.txt"); 
		
		int t = Integer.parseInt(lineReader.readLine());
		for (int counter = 1; counter <= t; counter++) {
			String[] nums = lineReader.readLine().split(" ");
			int surprisingTriplets = Integer.parseInt(nums[1]);
			int bestResultMin = Integer.parseInt(nums[2]);
			List<Integer> totals = Lists.newArrayList();
			for (int i = 3; i < nums.length; i++) {
				totals.add(Integer.parseInt(nums[i]));
			}
			
			int result = compute(surprisingTriplets, bestResultMin, totals);
			out.write(String.format("Case #%d: %d\n", counter, result));
		}
		out.close();
	}

	private static int compute(int surprisingTriplets, int bestResultMin, List<Integer> totals) {
		// surpr = 1, bestMin = 5 | 15 13 11
		// 5, 3, 3 = 11 - surpr. min 
		// 5, 4, 4 = 13 - norm. min
		
		int surprMin = bestResultMin + 2 * Math.max(bestResultMin - 2, 0);
		int normMin = bestResultMin + 2 * Math.max(bestResultMin - 1, 0);
		
		int count = 0;
		for (int t : totals) {
			if (t >= normMin) {
				count++;
			} else if (t >= surprMin && surprisingTriplets > 0) {
				count++;
				surprisingTriplets--;
			}
		}
		
		return count;
	}


}
