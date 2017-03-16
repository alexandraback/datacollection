package abc.template;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public abstract class AbstractSolver {

	public void solve(String inputFileName) throws Exception {
		Util.assertTrue(inputFileName.endsWith(".in"));
		Util.assertTrue(inputFileName.length() > 3);
		String outputFileName = inputFileName.substring(0, inputFileName.length() - 3) + ".out";
		solveSpecial(inputFileName, outputFileName);
	}

	public void solveSpecial(String inputFileName, String outputFileName) throws Exception {
		List<String> lines = Util.readFile("input/" + inputFileName);
		List<AbstractCase> cases = parseInputLines(lines);
		List<String> outputLines = new ArrayList<>();
		if (useMultithreading()) {
			int processors = Runtime.getRuntime().availableProcessors();
			ExecutorService service = Executors.newFixedThreadPool(processors);
			List<Future<String>> results = service.invokeAll(cases);
			service.shutdown();
			for (Future<String> result : results) {
				outputLines.add(result.get());
			}
		}
		else {
			for (AbstractCase caseItem : cases) {
				//System.err.println(caseItem.caseNumber);
				outputLines.add(caseItem.call());
			}
		}

		//Util.writeToStdout(outputLines);
		Util.writeToFile("output/" + outputFileName, outputLines);
	}

	protected List<List<String>> groupByFixedCase(List<String> lines, int caseSize) {
		return groupByCase(lines, caseSize, -1, -1);
	}

	//First line of case is case size.
	protected List<List<String>> groupByDynamicCase(List<String> lines) {
		return groupByCase(lines, 1, 0, -1);
	}

	protected List<List<String>> groupByCase(List<String> lines, int nrOfFixedLines, int dynamicLineCountLine) {
		return groupByCase(lines, nrOfFixedLines, dynamicLineCountLine, -1);
	}

	//Fixed amount of lines + a dynamic amount of lines determined by one of the fixed lines.
	protected List<List<String>> groupByCase(List<String> lines, int nrOfFixedLines, int dynamicLineCountLine, int dynamicLineSplitCount) {
		int nrOfCases = Integer.parseInt(lines.get(0));
		Util.assertTrue((nrOfCases * nrOfFixedLines) + 1 <= lines.size());
		List<List<String>> groupedCases = new ArrayList<>();
		int linesPointer = 1;
		for (int caseNr = 0; caseNr < nrOfCases; caseNr++) {
			List<String> groupedCase = new ArrayList<>();
			for (int i = 0; i < nrOfFixedLines; i++) {
				groupedCase.add(lines.get(linesPointer));
				linesPointer++;
			}
			if (dynamicLineCountLine >= 0) {
				int dynamicLines;
				if (dynamicLineSplitCount >= 0) {
					String[] splitString = groupedCase.get(dynamicLineCountLine).split(" ");
					Util.assertTrue(splitString.length >= dynamicLineSplitCount + 1);
					dynamicLines = Integer.parseInt(splitString[dynamicLineSplitCount]);
				}
				else {
					dynamicLines = Integer.parseInt(groupedCase.get(dynamicLineCountLine));
				}
				for (int i = 0; i < dynamicLines; i++) {
					groupedCase.add(lines.get(linesPointer));
					linesPointer++;
				}
			}
			groupedCases.add(groupedCase);
		}
		return groupedCases;
	}

	protected List<Long> lineToNumberList(String line, int nrOfNumbers) {
		String[] splitLine = line.split(" ");
		Util.assertTrue(splitLine.length == nrOfNumbers);
		List<Long> outputList = new ArrayList<>();
		for (String linePart : splitLine) {
			outputList.add(Long.parseLong(linePart));
		}
		return outputList;
	}

	protected abstract List<AbstractCase> parseInputLines(List<String> lines);

	protected abstract boolean useMultithreading();
}
