import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class Solution {

	private static BufferedReader in;
	private static FileWriter out;

	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		out = new FileWriter("out");

		doWork();

		in.close();
		out.close();
	}

	private static void doWork() throws Exception {
		int testCases = Integer.parseInt(in.readLine());

		for (int i = 0; i < testCases; i++) {
			String[] split = in.readLine().split(" ");
			double c = Double.parseDouble(split[0]);
			double f = Double.parseDouble(split[1]);
			double x = Double.parseDouble(split[2]);

			println("Case #" + (i + 1) + ": " + solve(c, f, x));
		}
	}

	private static double solve(double c, double f, double x) {
		if (x <= c) {
			return x / 2;
		}

		double speed = 2;
		double time = c / speed;

		while ((x - c) / speed > x / (speed + f)) {
			// buy
			speed += f;
			time += c / speed;
		}

		time += (x - c) / speed;

		return time;
	}

	static void println(String line) throws Exception {
		out.write(line + '\n');
		System.out.println(line);
	}
}
