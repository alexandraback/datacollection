import static java.lang.Integer.parseInt;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.LinkedList;
import java.util.List;

import com.google.common.base.Splitter;


// Library: May use Guava (https://github.com/google/guava)

public class B {

	public static void main(String[] args) throws IOException {
		Path path = Paths.get("src/B-small-attempt0.in");
//		Path path = Paths.get("src/in.txt");
		List<String> lines = Files.readAllLines(path);

		int numCases = parseInt(lines.get(0));

		List<String> ret = new LinkedList<>();
		for (int i = 0; i < numCases; i++) {
			System.out.println("Problem: " + (i + 1));
			int offset = i * 3;
			int[] items = Splitter.on(" ").splitToList(lines.get(1 + offset))
					.stream().mapToInt(Integer::parseInt).toArray();


			double r = solve(items[2], lines.get(2 + offset), lines.get(3 + offset));
			
			ret.add(r + "");
		}

		StringBuilder stringBuilder = new StringBuilder();
		for (int i = 0; i < ret.size(); i++) {
			String line = "Case #" + (i + 1) + ": " + ret.get(i);
			stringBuilder.append(line + "\n");
		}
		String resultStr = stringBuilder.toString();
		Files.write(Paths.get("src/out.txt"), resultStr.getBytes(StandardCharsets.UTF_8));

		System.out.println("resultStr =\n" + resultStr);
		check();
	}

	static long tries = 0;
	static long found = 0;
	static long max = 0;

	private static double solve(int s, String k, String t) {
		 tries = 0;
		 found = 0;
		 max = 0;

		outer:
		for (int i = 0; i < t.length(); i++) {
			char t1 = t.charAt(i);
			for (int j = 0; j < k.length(); j++) {
				char k1 = k.charAt(j);
				if (t1 == k1) {
					continue outer;
				}
			}
			return 0;
		}

		doit(0, new char[s], k, t);

		System.out.println("max = " + max);
		System.out.println("found = " + found);
		System.out.println("tries = " + tries);

		return max - (found / ((double) tries));
	}

	private static void doit(int idx, char[] s, String k, String t) {
		if (idx == s.length) {
			tries++;

			int foundL = 0;

			outer:
			for (int i = 0; i < s.length - (t.length() - 1); i++) {
				for (int j = 0; j < t.length(); j++) {
					if (s[i + j] != t.charAt(j)) {
						continue outer;
					}
				}
				foundL++;
			}

			max = Math.max(max, foundL);
			found += foundL;
			return;
		}

		for (int i = 0; i < k.length(); i++) {
			char k1 = k.charAt(i);

			s[idx] = k1;

			doit(idx + 1, s, k, t);
		}

	}


	private static void check() {
		try {
			List<String> written = Files.readAllLines(Paths.get("src/out.txt"));
			List<String> expected = Files.readAllLines(Paths.get("src/exp.txt"));

			if (written.size() != expected.size()) {
				throw new RuntimeException("number of lines not matching: " + expected.size() + " vs " + written.size());
			}

			int errors = 0;
			for (int i = 0; i < written.size(); i++) {
				String w = written.get(i);
				String e = expected.get(i);
				if (!w.equals(e)) {
					System.out.println("expected: '" + e + "', was: '" + w + "'");
					errors++;
				}
			}

			System.out.println();
			if (errors > 0) {
				System.out.println("Found " + errors + " errors!");
			} else {
				System.out.println(":)");
			}

		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

}