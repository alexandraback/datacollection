import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemB {
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int a, b, k, pairs;
		
		a = in.nextInt();
		b = in.nextInt();
		k = in.nextInt();
		
		pairs = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if ((i & j) < k) {
					pairs++;
				}
			}
		}
		out.print(pairs);
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
