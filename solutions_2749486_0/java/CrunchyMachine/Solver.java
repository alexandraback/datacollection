package abc;

import java.util.ArrayList;
import java.util.List;

import abc.template.AbstractCase;
import abc.template.AbstractSolver;

public class Solver extends AbstractSolver {

	@Override
	protected List<AbstractCase> parseInputLines(List<String> lines) {
		List<List<String>> groupedCases = groupByCase(lines, 1, -1);
		List<AbstractCase> cases = new ArrayList<>();
		int caseNr = 1;
		for (List<String> groupedCase : groupedCases) {
			for (String caseLine : groupedCase) {
				String[] splitCaseLine = caseLine.split(" ");
				long x = Long.parseLong(splitCaseLine[0]);
				long y = Long.parseLong(splitCaseLine[1]);
				cases.add(new Case(caseNr, x, y));
				caseNr++;
			}
		}
		return cases;
	}

	@Override
	protected boolean useMultithreading() {
		return false;
	}

	public static void main(String[] args) throws Exception {
		long time = System.currentTimeMillis();
		Solver solver = new Solver();

		solver.solve("example.in");
		solver.solve("B-small-attempt0.in");
		solver.solve("B-small-attempt1.in");
		//solver.solveSpecial("something.in", "something.out");

		System.err.println("Time: " + (System.currentTimeMillis() - time) + "ms");
	}
}