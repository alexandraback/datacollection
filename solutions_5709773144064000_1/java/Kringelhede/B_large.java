package qual.b;

import java.io.BufferedWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.text.DecimalFormat;
import java.util.Locale;
import java.util.Scanner;

public class B_large {
	private void solve(long case_T, Scanner reader, BufferedWriter writer) throws Exception {
		double farm_C = reader.nextDouble();
		double extra_F = reader.nextDouble();
		double win_X = reader.nextDouble();
		double rate = 2d;
		double time = 0;

		double timeToFinish = win_X/rate;
		double timeToAffordFarm = farm_C/rate;
		double timeToFinishWithFarm = timeToAffordFarm+win_X/(rate+extra_F);
		while (timeToFinish>timeToFinishWithFarm) {
			time += timeToAffordFarm;
			rate += extra_F;

			timeToFinish = win_X/rate;
			timeToAffordFarm = farm_C/rate;
			timeToFinishWithFarm = timeToAffordFarm+win_X/(rate+extra_F);
		}
		time += timeToFinish;

		DecimalFormat df = new DecimalFormat("0.0000000");
		writeOutput(writer, case_T, df.format(time));
	}

	private void writeOutput(BufferedWriter writer, long case_T, String output) throws Exception {
		String result = String.format("Case #%d: %s",  case_T, output);

		System.out.println(result);
		writer.write(result+"\n");
	}

	private void run() throws Exception {
		Locale.setDefault(Locale.US);

		String filename = "src/qual/b/B-large";
		Path inputFile = Paths.get(filename+".in");
		Path outputFile = Paths.get(filename+".out");

		System.out.println("Input file:  "+inputFile.toFile().getAbsolutePath());
		System.out.println("Output file: "+outputFile.toFile().getAbsolutePath());

		try (
				Scanner reader = new Scanner(Files.newBufferedReader(inputFile));
				BufferedWriter writer = Files.newBufferedWriter(outputFile)) {
			long cases_T = new Long(reader.nextLine());

			for (long case_T = 1; case_T<=cases_T; case_T++) {
				solve(case_T, reader, writer);
			}
		}
	}

	public static void main(String... args) throws Exception {
		new B_large().run();
	}
}
