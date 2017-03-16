import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Cookie_Clicker_Alpha {

	private Scanner sc = new Scanner(System.in);
	private PrintStream ps = new PrintStream(System.out);

	public void setIO(InputStream is, OutputStream os) {
		sc = new Scanner(is);
		ps = new PrintStream(os);
	}

	public void solve() throws FileNotFoundException {
		DecimalFormat df = new DecimalFormat("0.0000000");
		int cases = sc.nextInt();

		for (int tCases = 1; tCases <= cases; ++tCases) {
			double c = sc.nextDouble(), f = sc.nextDouble(), x = sc
					.nextDouble();
			double rate = 2, answer = 0;
			double time1 = x / rate, time2 = c / rate + x / (rate + f);

			while (time1 > time2) {
				answer += c / rate;
				rate += f;
				time1 = x / rate;
				time2 = c / rate + x / (rate + f);
			}

			answer += time1;
			ps.println("Case #" + tCases + ": " + df.format(answer));
		}

		sc.close();
	}

	public static void main(String[] args) throws FileNotFoundException {
		InputStream is = new FileInputStream(
				"Problems\\Cookie_Clicker_Alpha\\B-small-attempt0.in");
		OutputStream os = new FileOutputStream(
				"Problems\\Cookie_Clicker_Alpha\\B-small-attempt0.out");

		Cookie_Clicker_Alpha solver = new Cookie_Clicker_Alpha();
		solver.setIO(is, os);
		solver.solve();
	}
}
