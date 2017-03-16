package sochi.round;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;

public class A extends Solver {

	public A() throws IOException {
		super(2);
	}

	@Override
	public List<Callable<String>> getTestCases(final List<String> lines) throws Exception {
		List<Callable<String>> tasks = new ArrayList<Callable<String>>();

		int testCases = StringUtils.getInteger(lines.get(0));

		for (int t = 1; t <= testCases; ++t) {

			// Instantiation
			final int caseNumber = t;
			final int skipLines = (caseNumber - 1) + 1;

			// Test-case processing itself
			tasks.add(new Callable<String>() {

				@Override
				public String call() {

					String row = lines.get(skipLines);
					List<Integer> integers = StringUtils.extractIntegers(row);

					int rows = integers.get(0);
					int columns = integers.get(1);
					int width = integers.get(2);

					int points = columns / width;
					int mod = columns % width;
					int result = points * rows + width;

					if (mod == 0) {
						result -= 1;
					}

					return Integer.toString(result);
				}
			});
		}

		// Definitions
		return tasks;
	}

	public static void main(String[] args) throws Exception {
		new A().start();
	}
}
