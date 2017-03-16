import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class P101 {
	static String test = "3 2 5 0.6 0.6 1 20 1 3 4 1 0.9 0.1";

	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		int t = inp.nextInt();
		int i = 1;
		while (t > 0) {
			int a = inp.nextInt();
			int b = inp.nextInt();
			List<Double> d = new ArrayList<Double>();
			for (int c = 0; c < a; c++) {
				d.add(inp.nextDouble());
			}
			System.out.println("Case #" + i + ": " + calc(a, b, d));
			--t;
			++i;
		}

	}

	private static String calc(int a, int b, List<Double> d) {
		double expected = b + 2;
		double[] prob = new double[b];
		for (int i = 0; i < b; i++) {
			double p;
			if (i < a) {
				p = d.get(i);
			} else {
				p = 1;
			}
			if (i > 0) {
				p *= prob[i - 1];
			}
			prob[i] = p;
		}

		for (int i = 0; i < a; i++) {
			int k = (a - i) + (b - i) + 1;
			double p = 1;
			if (i > 0) {
				p = prob[i - 1];
			}
			double e = p * k + (1 - p) * (k + b + 1);
			if (e < expected) {
				expected = e;
			}
		}
		double ent = prob[a - 1] * (1 + b - a) + (1 - prob[a - 1])
				* (1 + b - a + b + 1);
		if (ent < expected)
			expected = ent;
		String out = String.format("%6f", expected);
		return out;
	}
}
