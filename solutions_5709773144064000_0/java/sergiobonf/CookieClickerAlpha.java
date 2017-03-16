package cookieClickerAlpha;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.List;

public class CookieClickerAlpha {

    public static void main(String[] args) throws IOException {
	String mainDir = "/Users/sergio/Downloads";
	Path path = FileSystems.getDefault().getPath(mainDir, "B-small-attempt0.in");
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

	    double result = neededSeconds(cookieSec, farmCost, farmCookieSec,
		    targetCookies);

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
}
