package eu.grzegorzjankowski;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;

public class CookieClickerAlpha {

	public static void main(String[] args) {
		BufferedReader br = null;
		File file;

		Locale.setDefault(Locale.US);

		try {

			String sCurrentLine;
			file = new File("c:\\CodeJam\\CookieClickerAlpha\\result.txt");
			if (file.exists())
				file.delete();
			file.createNewFile();

			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);

			br = new BufferedReader(new FileReader(
					"c:\\CodeJam\\CookieClickerAlpha\\B-small-attempt0.in"));

			int t = Integer.parseInt(br.readLine());
			for (int i = 0; i < t; i++) {
				String[] data = br.readLine().split(" ");

				double result = solveIt(Double.parseDouble(data[0]),
						Double.parseDouble(data[1]),
						Double.parseDouble(data[2]));
				String formatedResult = String.format("%.7f", result);
				bw.write("Case #" + (i + 1) + ": " + formatedResult);
				bw.newLine();
				System.out.println(i + 1 + " -> " + (i + 1.0) * 100 / t + "%");

			}
			bw.close();
			System.out.println("done");

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}

	}

	private static double solveIt(double c, double f, double x) {
		System.out.println(c + " " + f + " " + x);
		double timeFactory = 0.0;
		double timeCakes;
		double min = Double.MAX_VALUE;
		for (int i = 0;; i++) {
			if (i > 0)
				timeFactory += (c / (2 + f * (i - 1)));
			timeCakes = x / (2 + f * i);
			double timeTotal = timeCakes + timeFactory;

			if (timeTotal < min)
				min = timeTotal;
			if (timeTotal > min)
				return min;
		}
	}
}
