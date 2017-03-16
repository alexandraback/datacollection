import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;

public class Safety {

	public static void main(String[] args) throws IOException {
		long t0 = System.currentTimeMillis();
		BufferedReader in = new BufferedReader(new FileReader("in.txt"));
		PrintWriter out = new PrintWriter("out.txt");
		int t = Integer.parseInt(in.readLine());
		for (int i = 1; i <= t; i++) {
			String[] ss = in.readLine().split(" ");
			int idx = 0;
			int n = Integer.parseInt(ss[idx++]);
			int[] set = new int[n];
			for (int j = 0; j < n; j++) {
				set[j] = Integer.parseInt(ss[idx++]);
			}
			String result = compute(i, set);
			out.println(result);
			System.out.println(result);
		}
		out.close();
		System.out.println("time: " + (System.currentTimeMillis() - t0));
	}

	private static String compute(int t, int[] set) {
		StringBuilder sb = new StringBuilder();
		sb.append("Case #").append(t).append(':');
		for (int i = 0; i < set.length; i++) {
			// sb.append(" ").append(set[i]);
			sb.append(" ").append(Math.max(0,compute(set, i)) * 100);
		}
		return sb.toString();

	}

	private static double compute(int[] set, int pos) {
		int sum = 0;
		int[] konkurrenz = new int[set.length - 1];
		for (int i = 0, p = 0; i < set.length; i++) {
			if (i != pos) {
				konkurrenz[p++] = set[i];
			}
			sum += set[i];
		}
		Arrays.sort(konkurrenz);
		double bestResult = 1.0;
		double scoreToBeat = 0;
		for (int i = 1; i <= konkurrenz.length; i++) {
			scoreToBeat += konkurrenz[i - 1];
			double p = (scoreToBeat + sum - i * set[pos]) / (sum * (i + 1));
			//System.out.println(set[i] + " " + p + " " + scoreToBeat + "/" + i);
			if (p < bestResult) {
				bestResult = p;
			}
		}
		return bestResult;
	}

}
