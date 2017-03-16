import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.LinkedHashMap;

public class Main3 {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		int n;// no of test cases
		BufferedReader bufferedReader = new BufferedReader(
				new InputStreamReader(new FileInputStream(new File(args[0]))));
		BufferedWriter bufferedWriter = new BufferedWriter(
				new OutputStreamWriter(new FileOutputStream(new File(args[1]))));
		n = Integer.parseInt(bufferedReader.readLine());
		for (int i = 0; i < n; i++) {
			String[] cases = bufferedReader.readLine().split(" ");
			int boxCases = Integer.parseInt(cases[0]);
			double[][] boxCasesIntegers = new double[boxCases][2];
			int toyCases = Integer.parseInt(cases[1]);
			double[][] toyCasesIntegers = new double[toyCases][2];
			String[] boxCaseStrings = bufferedReader.readLine().split(" ");
			for (int j = 0; j < boxCaseStrings.length; j++) {
				boxCasesIntegers[j / 2][j % 2] = Double
						.parseDouble(boxCaseStrings[j]);
			}
			String[] toyCaseStrings = bufferedReader.readLine().split(" ");
			for (int j = 0; j < toyCaseStrings.length; j++) {
				toyCasesIntegers[j / 2][j % 2] = Double
						.parseDouble(toyCaseStrings[j]);
			}
			// HashMap of type and remainingBoxes
			HashMap<Double, Double> remainingBoxes = new LinkedHashMap<Double, Double>();
			long noOfToys = 0;
			for (int p = 0, q = 0; p < boxCases && q < toyCases; p++, q++) {
				// Check type
				if (boxCasesIntegers[p][1] == toyCasesIntegers[q][1]) {
					// take smallest number
					noOfToys += Math.min(boxCasesIntegers[p][0],
							toyCasesIntegers[q][0]);
				} else {
					if ((p + 1) < boxCases
							&& toyCasesIntegers[q][1] == boxCasesIntegers[p + 1][1]) {
						noOfToys += Math.min(boxCasesIntegers[p + 1][0],
								toyCasesIntegers[q][0]);
					}
				}
			}
			bufferedWriter.write("Case #" + (i + 1) + ": " + noOfToys + "\n");
			bufferedWriter.flush();
		}
		bufferedReader.close();
		bufferedWriter.close();
	}
}

