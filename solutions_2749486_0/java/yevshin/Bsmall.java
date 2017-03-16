package y2013r1c;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Bsmall {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		int ntests = Integer.parseInt(reader.readLine());
		for (int test = 1; test <= ntests; test++) {
			String f[] = reader.readLine().split(" ");
			int x = Integer.parseInt(f[0]);
			int y = Integer.parseInt(f[1]);
			System.out.println("Case #" + test + ": " + path(x, y));
		}
	}

	private static String path(int x, int y) {
		StringBuilder result = new StringBuilder();
		if (x > 0)
			for (int i = 0; i < x; i++)
				result.append("WE");
		else
			for (int i = 0; i < -x; i++)
				result.append("EW");
		if (y > 0)
			for (int i = 0; i < y; i++)
				result.append("SN");
		else
			for (int i = 0; i < -y; i++)
				result.append("NS");
		return result.toString();
	}
}
