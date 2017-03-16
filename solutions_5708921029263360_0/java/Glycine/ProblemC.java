package gcj2016.c;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ProblemC {
	public static void main(String args[]) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File(args[0])));
		int lineNum = Integer.parseInt(reader.readLine());
		ProblemC problemC = new ProblemC();
		for (int i = 0; i < lineNum; ++i) {
			String[] tokens = reader.readLine().split(" ");
			int jackets = Integer.parseInt(tokens[0]);
			int pants = Integer.parseInt(tokens[1]);
			int shirts = Integer.parseInt(tokens[2]);
			int kinds = Integer.parseInt(tokens[3]);
			List<String> results = problemC.solve(jackets, pants, shirts, kinds);
			System.out.println("Case #" + (i + 1) + ": " + results.size());
			for (String str : results) {
				System.out.println(str);
			}
		}
		reader.close();
	}

	public List<String> solve(int jackets, int pants, int shirts, int kinds) {
		List<String> results = new ArrayList<>();
		for (int i = 0; i < jackets; ++i) {
			for (int j = 0; j < pants; ++j) {
				for (int k = 0; k < shirts; ++k) {
					results.add((i + 1) + " " + (j + 1) + " " + (k + 1));
				}
			}
		}
		return results;
	}
}
