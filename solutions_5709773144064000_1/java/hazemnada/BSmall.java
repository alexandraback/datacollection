import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class BSmall {
	public static void main(String[] args) throws IOException {
		BufferedReader buf = new BufferedReader(new FileReader(
				"B-large.in"));
		PrintWriter writer = new PrintWriter("Blarge.out");
		int tCases = Integer.parseInt(buf.readLine().trim());
		for (int t = 1; t <= tCases; t++) {
			System.out.println(t);
			StringTokenizer str = new StringTokenizer(buf.readLine());
			double c = Double.parseDouble(str.nextToken());
			double f = Double.parseDouble(str.nextToken());
			double x = Double.parseDouble(str.nextToken());
			double sum = 0;
			double r = 2;
			double prev = x / r;
			sum += c / r;
			r += f;
			while (true) {
				double t1 = c / r;
				double t2 = x / r + sum;
				if (prev < t2) {
					sum = prev;
					break;
				}
				r += f;
				sum += t1;
				prev = t2;
			}
			writer.printf("Case #%d: %.7f\n", t, sum);
		}
		writer.close();
	}
}
