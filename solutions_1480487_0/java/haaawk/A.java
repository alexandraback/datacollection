import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;


public class A {
	
	private static final String NAME = "A-small";

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader("in/" + NAME + ".in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("out/" + NAME + ".out"));
		try {
			int t = Integer.parseInt(reader.readLine());
			for (int i = 0; i < t; ++i) {
				List<Integer> scores = new ArrayList<Integer>();
				List<Integer> res = new ArrayList<Integer>();
				String[] v = reader.readLine().split(" ");
				int best = 0;
				int sum = 0;
				int n = Integer.parseInt(v[0]);
				for (int j = 0; j < n; ++j) {
					int score = Integer.parseInt(v[j + 1]);
					scores.add(score);
					if (score > best) {
						best = score;
					}
					sum += score;
				}
				int oldSum = sum;
				for (int score : scores) {
					res.add(best - score);
					sum -= best - score;
				}
				while (sum < 0) {
					for (int j = 0; j < n; ++j) {
						if (res.get(j) > 0) {
							sum += 1;
							res.set(j, res.get(j) - 1);
						}
					}
				}
				int nn = 0;
				int limit = Integer.MAX_VALUE;
				for (int j = 0; j < n; ++j) {
					if (limit > scores.get(j) + res.get(j)) {
						limit = scores.get(j) + res.get(j);
					}
				}
				for (int j = 0; j < n; ++j) {
					if (limit == scores.get(j) + res.get(j)) {
						++nn;
					}
				}
				writer.write("Case #" + (i + 1) + ":");
				for (int j = 0; j < n; ++j) {
					double result = ((res.get(j) + (double)sum / nn) / oldSum) * 100;
					if (limit < scores.get(j) + res.get(j)) {
						result = 0;
					}
					writer.write(" " + result);
				}
				writer.newLine();
			}
		} finally {
			reader.close();
			writer.close();
		}
	}
	
	

}
