import java.io.BufferedReader;
import java.io.InputStreamReader;

public class PartElf {
	private static BufferedReader bufferedReader = new BufferedReader(
			new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {
		String line = bufferedReader.readLine();

		int cases = Integer.parseInt(line);

		for (int c = 1; c <= cases; c++) {
			solveCase(c);
		}
	}

	private static void solveCase(int c) throws Exception {
		String line = bufferedReader.readLine();
		String[] split = line.split("/");
		int P = Integer.parseInt(split[0]);
		int Q = Integer.parseInt(split[1]);

		int result = getMinGenerations(P * 2, Q, 1);
		if (result == Integer.MAX_VALUE) {
			System.out.println("Case #" + c + ": impossible");
		} else {
			System.out.println("Case #" + c + ": " + result);
		}
	}

	private static int getMinGenerations(int P, int Q, int generations) {
		if (Q % 2 > 0 || generations > 40) {
			return Integer.MAX_VALUE;
		}

		if (P / Q >= 1.0) {
			double r = ((double) P / (double) Q) - 1.0;
			if (r == 0 || r == 1.0
					|| getMinGenerations((P - Q) * 2, Q, generations) <= 40) {
				return generations;
			} else {
				return Integer.MAX_VALUE;
			}
		} else {
			return getMinGenerations(P * 2, Q, generations + 1);
		}
	}
}
