import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class Equals {

	public static void main(String[] args) throws IOException {
		long t0 = System.currentTimeMillis();
		BufferedReader in = new BufferedReader(new FileReader("in.txt"));
		PrintWriter out = new PrintWriter("out.txt");
		int t = Integer.parseInt(in.readLine());
		for (int i = 1; i <= t; i++) {
			String[] ss = in.readLine().split(" ");
			int idx = 0;
			int n = Integer.parseInt(ss[idx++]); // number of Googlers
			int[] set = new int[n];
			for (int j = 0; j < n; j++) {
				set[j] = Integer.parseInt(ss[idx++]);
			}
			String result = compute(set);
			out.println("Case #" + i + ": " + result);
			System.out.println("Case #" + i + ": " + result);
		}
		out.close();
		System.out.println("time: " + (System.currentTimeMillis() - t0));
	}

	private static String compute(int[] set) {
		Map<Integer, Integer> sumToGen = new HashMap<Integer, Integer>();
		for (int i = 1; i < 1 << 20; i++) {
			int sum = 0;
			for (int b = 0; b < 20; b++) {
				if ((i & (1 << b)) > 0) {
					sum += set[b];
				}
			}
			Integer dup = sumToGen.put(sum, i);
			if (dup != null) {
				return "\n" + decode(set, dup) + "\n" + decode(set, i);
			}
		}
		return "Impossible";
	}

	private static String decode(int[] set, Integer i) {
		StringBuilder sb = new StringBuilder();
		for (int b = 0; b < 20; b++) {
			if ((i & (1 << b)) > 0) {
				sb.append(set[b]);
				sb.append(" ");
			}
		}
		return sb.toString().trim();
	}

}
