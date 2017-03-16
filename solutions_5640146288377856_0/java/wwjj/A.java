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

public class A {

	public static void main(String[] args) throws IOException {
//		Path path = Paths.get("src/in.txt");
		Path path = Paths.get("src/A-small-attempt0.in");
		List<String> lines = Files.readAllLines(path);

		int numCases = parseInt(lines.get(0));

		List<String> ret = new LinkedList<>();
		for (int i = 0; i < numCases; i++) {
			System.out.println("Problem: " + (i + 1));
			int offset = i * 1;
//			int d = parseInt(lines.get(1 + offset));
			int[] items = Splitter.on(" ").splitToList(lines.get(1 + offset))
					.stream().mapToInt(Integer::parseInt).toArray();

			int r = solve(items);
			
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

	private static int solve(int[] items) {
		int r = items[0];
		int c = items[1];
		int w = items[2];

		int n = c / w * r;
		return n + (c % w == 0 ? w - 1 : w);
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