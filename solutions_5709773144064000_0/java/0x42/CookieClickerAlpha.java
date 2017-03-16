import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.text.DecimalFormat;
import java.util.Arrays;

public class CookieClickerAlpha {

	public static void main(String[] args) throws Exception {
		CookieClickerAlpha object = new CookieClickerAlpha();
		object.work();
	}

	private void work() throws Exception {
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(
				new FileReader(this.getClass().getSimpleName() + ".in")));
		PrintWriter pw = new PrintWriter(new FileWriter(this.getClass()
				.getSimpleName() + ".out"));

		st.nextToken();
		int tcases = (int) st.nval;

		for (int tc = 1; tc <= tcases; tc++) {
			st.nextToken();
			double c = st.nval;

			st.nextToken();
			double f = st.nval;

			st.nextToken();
			double x = st.nval;

			DecimalFormat df = new DecimalFormat("0.00000000");
			pw.write("Case #" + tc + ": " + df.format(solve(c, f, x)) + "\r\n");
		}

		pw.close();
	}

	private double solve(double c, double f, double x) {

		double best = 1e100;

		double sum[] = new double[100011];
		Arrays.fill(sum, 0.0);

		double rq = 2.0;
		for (int s = 1; s < sum.length; s++) {

			sum[s] = sum[s - 1] + (1.0 / rq);
			rq += f;
		}

		for (int farms = 0; farms <= x + 2; farms++) {

			double current = (x / (2.0 + farms * f));
			current += c * sum[farms];

			best = Math.min(best, current);
		}

		return best;
	}

}
