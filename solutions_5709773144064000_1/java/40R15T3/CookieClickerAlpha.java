package gcj;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;

public class CookieClickerAlpha {

	public static void main(String[] args) throws Exception {
		String name = "B-large";
		Locale.setDefault(Locale.US);
		NumberFormat formatter = NumberFormat.getInstance();
		formatter.setMaximumFractionDigits(7);
		formatter.setMinimumFractionDigits(7);
		Scanner scanner = new Scanner(new File("C:\\Users\\m\\Desktop\\training\\"+name+".in"));
		final long len = scanner.nextInt() + 1;
		FileWriter fw = new FileWriter("C:\\Users\\m\\Desktop\\training\\"+name+".out");
		BufferedWriter out = new BufferedWriter(fw);
		for (int n = 1; n < len; n++) {
			double C = scanner.nextDouble();
			double F = scanner.nextDouble();
			double X = scanner.nextDouble();
			String str = "Case #" + n + ": " + formatter.format(solve(C, F, X));
			System.out.println(str);
			out.write(str);
			out.newLine();
		}
		out.flush();
		out.close();
	}

	private static double solve(double C, double F, double X) {
		double rate = 2;
		double duration = 0;
		double durationToC;
		double durationToX;
		double durationToCThenX;
		do {
			durationToC = C / rate;
			durationToX = X / rate;
			durationToCThenX = durationToC + X / (rate + F);
			if (durationToCThenX > durationToX) {
				duration += durationToX;
				break;
			} else {
				duration += durationToC;
				rate += F;
			}
		} while (true);
		return duration;
	}
}
