package minesweeperMaster;

import java.nio.charset.StandardCharsets;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.List;

public class MineSweeperMaster {

    public static void main(String[] args) throws Exception {
	String mainDir = "/Users/sergio/Downloads";
	Path path = FileSystems.getDefault().getPath(mainDir, "B-large.in");
	Path outputFile = FileSystems.getDefault().getPath(mainDir,
		"output.txt");

	List<String> inputLines = Files.readAllLines(path,
		StandardCharsets.UTF_8);

	List<String> outputLines = new ArrayList<String>();

	long start = System.currentTimeMillis();

	int numCases = Integer.parseInt(inputLines.get(0));

	double cookieSec = 2d;
	for (int i = 1; i < numCases + 1; i++) {

	    String[] parameters = inputLines.get(i).split(" ");
	    double farmCost = Double.parseDouble(parameters[0]);
	    double farmCookieSec = Double.parseDouble(parameters[1]);
	    double targetCookies = Double.parseDouble(parameters[2]);

	    double result2 = neededSeconds2(cookieSec, farmCost, farmCookieSec,
		    targetCookies);
	    double result = -1;
	    try {
		result = neededSeconds(cookieSec, farmCost, farmCookieSec,
			targetCookies);
	    } catch (StackOverflowError e) {
	    }
	    if (result != -1 && Math.abs(result - result2) > 0.0000001)
		System.out.println("Correct: " + result + ", res2: " + result2);

	    String caseResult = "Case #" + (i) + ": " + result;
	    outputLines.add(caseResult);
	    System.out.println(caseResult);

	}
	System.out.println("Completed: " + (System.currentTimeMillis() - start)
		/ 1000d + " s");

	StandardOpenOption option;
	if (!Files.exists(outputFile)) {
	    option = StandardOpenOption.CREATE_NEW;
	} else {
	    option = StandardOpenOption.TRUNCATE_EXISTING;
	}
	Files.write(outputFile, outputLines, option);

    }

    public static double neededSeconds(double cookieSec, double farmCost,
	    double farmCookieSec, double targetCookies) {

	double neededSeconds = (targetCookies) / cookieSec;
	double secToBuyFarm = (farmCost) / cookieSec;
	double neededSecondsWithFarm = (targetCookies)
		/ (cookieSec + farmCookieSec);

	if (secToBuyFarm + neededSecondsWithFarm > neededSeconds) {
	    return neededSeconds;
	} else {
	    return Math.min(
		    neededSeconds,
		    secToBuyFarm
			    + neededSeconds(cookieSec + farmCookieSec,
				    farmCost, farmCookieSec, targetCookies));
	}
    }

    public static double neededSeconds2(double cookieSec, double farmCost,
	    double farmCookieSec, double targetCookies) {
	double currentCookieSec = cookieSec;
	double neededSeconds = (targetCookies) / cookieSec;
	double secToBuyFarm = (farmCost) / cookieSec;
	double neededSecondsWithFarm = (targetCookies)
		/ (cookieSec + farmCookieSec);

	double total = 0;
	while (secToBuyFarm + neededSecondsWithFarm < neededSeconds) {

	    total += secToBuyFarm;

	    currentCookieSec += farmCookieSec;

	    secToBuyFarm = (farmCost) / currentCookieSec;
	    neededSecondsWithFarm = (targetCookies)
		    / (currentCookieSec + farmCookieSec);

	    neededSeconds = (targetCookies) / currentCookieSec;
	}
	total += neededSeconds;

	return total;

    }

}
