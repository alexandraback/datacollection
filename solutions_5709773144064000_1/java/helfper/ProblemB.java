import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemB {
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		double c, f, x, best, prev, curr, rate;
		
		c = in.nextDouble();
		f = in.nextDouble();
		x = in.nextDouble();
		
		rate = 2.0;
		best = x / rate;
		prev = 0.0;
		while (true) {
			prev += c / rate;
			rate += f;
			curr = prev + x / rate;
			if (curr < best) {
				best = curr;
			} else {
				break;
			}
		}
		out.printf("%.7f", best);
	}

	public static void main(String[] args) {
		try {
			in = new Scanner(new FileReader(args[0]));
			out = new PrintWriter(new FileWriter(args[1]));
			int tests = in.nextInt();
			for (int test = 1; test <= tests; test++) {
				System.out.println("Processing case #" + test);
				out.print("Case #" + test + ": ");
				new ProblemB().solve();
				out.println();
			}
			in.close();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
