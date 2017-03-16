import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Jelle Prins
 */
public class CookieClicker {

	public static void main(String[] args) {
		String input = "input.txt";
		String output = "output.txt";
		if (args.length >= 1) {
			input = args[0];
			if (args.length >= 2) {
				output = args[1];
			}
		}
		new CookieClicker(input, output);
	}

	private class Case {
		private double cookieFarmPrice;
		private double cookiesPerFarm;
		private double goal;

		public Case(String line) {
			String[] split = line.split(" ");
			cookieFarmPrice = Double.parseDouble(split[0]);
			cookiesPerFarm = Double.parseDouble(split[1]);
			goal = Double.parseDouble(split[2]);
		}
	}

	public CookieClicker(String inputString, String outputString) {
		File input = new File(inputString);
		File output = new File(outputString);
		if (!input.isFile()) {
			System.err.println("input file not found");
			System.exit(1);
		}
		if (output.exists()) {
			output.delete();
		}

		try {
			Case[] cases = readInput(input);
			String[] results = executeCases(cases);
			writeOutput(output, results);
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	private Case[] readInput(File file) throws Exception {
		Scanner scanner = new Scanner(file);
		int caseCount = scanner.nextInt();
		scanner.nextLine();
		Case[] cases = new Case[caseCount];
		for (int i = 0; i < caseCount; i++) {
			cases[i] = new Case(scanner.nextLine());
		}
		scanner.close();
		return cases;
	}

	private String[] executeCases(Case[] cases) {
		String[] output = new String[cases.length];
		for (int i = 0; i < cases.length; i++) {
			output[i] = executeCase(i + 1, cases[i]);
		}
		return output;
	}

	private void writeOutput(File output, String[] results) throws Exception {
		PrintWriter pw = new PrintWriter(new FileWriter(output));
		for (int i = 0; i < results.length; i++) {
			if (i != results.length - 1) {
				pw.println(results[i]);
			} else {
				pw.print(results[i]);
			}
		}
		pw.close();
	}

	private String executeCase(int caseID, Case input) {
		double cps = 2; // cookies per second;
		double currentTotalTime = 0;
		double previousFinishTime = Double.MAX_VALUE;
		double currentFinishTime = 0;

		while (true) {
			currentFinishTime = currentTotalTime + input.goal / cps;
			if (previousFinishTime < currentFinishTime) {
				break;
			}

			currentTotalTime += input.cookieFarmPrice / cps;
			cps += input.cookiesPerFarm;
			previousFinishTime = currentFinishTime;
		}

		return parseOutput(caseID, previousFinishTime);
	}

	private String parseOutput(int caseID, double answer) {
		String output = "Case #" + caseID + ": " + answer;
		System.out.println(output);
		return output;
	}
}
