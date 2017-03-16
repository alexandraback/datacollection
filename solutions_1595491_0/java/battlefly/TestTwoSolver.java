import java.io.BufferedReader;
import java.io.IOException;

public class TestTwoSolver extends SolverModule {

	public StringBuilder process(BufferedReader in, StringBuilder builder)
			throws IOException {
		in.readLine();
		String line = in.readLine();
		int count = 1;
		while (line != null) {
			line = processline(line);
			appendLine(line, builder, count);
			count++;
			line = in.readLine();
		}
		return builder;
	}

	private String processline(String line) {
		int[] lines = toIntegers(line.split(" "));
		int bestResultCount = 0;
		int S = lines[1];
		int p = lines[2];
		for (int i = 3; i < lines.length; i++) {
			if (lines[i] >= (p - 1) * 2 + p) {
				bestResultCount++;
			} else {
				if (lines[i] >= (p - 2) * 2 + p) {
					if (S > 0 && (p - 2) >= 0) {
						S--;
						bestResultCount++;
					}
				}
			}
		}
		return String.valueOf(bestResultCount);
	}

	private int[] toIntegers(String[] split) {
		int[] ints = new int[split.length];
		for (int i = 0; i < split.length; i++) {
			ints[i] = Integer.valueOf(split[i]);
		}
		return ints;
	}
}
