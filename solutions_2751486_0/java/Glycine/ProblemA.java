package glycine.gcj2013.rc;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ProblemA {
	static final String SPLIT_CHAR = " ";
	static final Pattern boin = Pattern.compile("[aiueo]+");

	public static class Solve {
		int n;
		String str;
		int result = 0;

		public Solve(String str, int n) {
			this.n = n;
			this.str = str;
		}

		public int baseCount(String base, int length) {
			return (base.length() - length) * 2 + 1;
		}

		public void solve() {
			String[] splitted = boin.split(this.str);
			Set<String> baseSet = new HashSet<String>();
			for (String split : splitted) {
				if (split.length() >= this.n)
					baseSet.add(split);
			}
			int tokenSize = 0;
			for (String base : baseSet) {
				Matcher m = Pattern.compile(base).matcher(str);
				List<Integer> startList = new ArrayList<Integer>();
				List<Integer> endList = new ArrayList<Integer>();
				while (m.find()) {
					startList.add(m.start());
					endList.add(m.end());
				}

				for (int i = 0; i < startList.size(); ++i) {
					int r = baseCount(base, n);
					r *= startList.get(i) + 1;
					r *= str.length() - endList.get(i) + 1;
					// r *= endList.get(i) - startList.get(i) + 1;

					if( i > 0 ){
						// かぶった場所を除去
						r -= startList.size();
					}

					result += r;
//					System.out.println("r: " + r + ", start: "
//							+ startList.get(i) + ", end: " + endList.get(i));
				}

				// String[] tokens = this.str.split(base);
				// tokenSize = tokens.length;
				// for (String token : tokens) {
				// if (token.length() == 0) {
				// tokenSize--;
				// continue;
				// } else {
				// r *= (token.length() + 1);
				// }
				// }
				// System.out.println("tokenSize: " + tokenSize);
				// r -= tokenSize;
			}
			result -= baseSet.size() - 1;

		}

	}

	public static void main(String[] args) throws IOException {
		if (args.length != 1) {
			System.err.println("Usage: <program> inputFilename");
			return;
		}
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		String line = reader.readLine();
		int times = Integer.parseInt(line);

		for (int i = 0; i < times; ++i) {
			line = reader.readLine();
			String[] tokens = line.split(SPLIT_CHAR);
			Solve solve = new Solve(tokens[0], Integer.parseInt(tokens[1]));
			solve.solve();
			System.out.println("Case #" + (i + 1) + ": " + solve.result);

		}

	}

}
