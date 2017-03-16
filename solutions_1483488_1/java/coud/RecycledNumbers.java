import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Set;

import com.google.common.collect.Sets;
import com.google.common.io.LineReader;


public class RecycledNumbers {

	public static void main(String[] args) throws NumberFormatException, IOException {
		LineReader lineReader = new LineReader(new FileReader(args[0]));
		FileWriter out = new FileWriter(args[0] + "-out.txt"); 
		
		int t = Integer.parseInt(lineReader.readLine());
		for (int counter = 1; counter <= t; counter++) {
			String[] nums = lineReader.readLine().split(" ");
			int result = compute(Integer.parseInt(nums[0]), Integer.parseInt(nums[1]));
			out.write(String.format("Case #%d: %d\n", counter, result));
		}
		out.close();
	}

	private static int compute(int a, int b) {
		Set<Integer> set = Sets.newHashSet();
		int count = 0;
		for (int n = a; n < b; n++) {
			String nStr = Integer.toString(n);
			set.clear();
			for (int i = 1; i < nStr.length(); i++) {
				String fst = nStr.substring(i);
				String snd = nStr.substring(0, i);
				int m = Integer.parseInt(fst + snd);
				if (m > n && m <= b && !set.contains(m)) {
					set.add(m);
					count++;
				}
			}
		}
		
		return count;
	}
}
