import java.io.BufferedReader;
import java.io.InputStreamReader;

public class DSmall {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		int ntests = Integer.parseInt(reader.readLine());
		for (int test = 1; test <= ntests; test++) {
			String[] fields = reader.readLine().split(" ");
			int x = Integer.parseInt(fields[0]);
			int r = Integer.parseInt(fields[1]);
			int c = Integer.parseInt(fields[2]);
			System.out.println("Case #" + test + ": " + solve(x, r, c));
		}
	}

	private static String solve(int x, int r, int c) {
		return canFill(x, r, c) ? "GABRIEL" : "RICHARD";
	}

	private static boolean canFill(int x, int r, int c) {
		if (x == 1)
			return true;
		if (x == 2)
			return r % 2 == 0 || c % 2 == 0;
		int min = Math.min(r, c);
		int max = Math.max(r, c);
		if (x == 3)
			return (min == 2 && max == 3) || (min == 3 && max == 3)
					|| (min == 3 && max == 4);
		if (x == 4)
			return (min == 3 && max == 4) || (min == 4 && max == 4);
		throw new AssertionError();
	}
}
