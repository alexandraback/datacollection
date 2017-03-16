package codejam.speakingintongues;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;

import codejam.common.AbstractProblemSolver;

public class SpeakingInTonguesProblemSolver extends
		AbstractProblemSolver<String, String> {

	private Translator translator;

	@Override
	public String readProblem(BufferedReader reader) throws IOException {
		return reader.readLine();
	}

	@Override
	public String solveProblem(String problem) {
		return translator.translate(problem);
	}

	@Override
	public void writeSolution(int solutionNumber, String solution,
			BufferedWriter writer) throws IOException {
		writer.append("Case #" + solutionNumber + ": ");
		writer.append(solution);
		writer.newLine();
	}

	public static void main(String[] args) {
		SpeakingInTonguesProblemSolver solver = new SpeakingInTonguesProblemSolver();
		String[] trainingInput = { "y", "e", "q",
				"ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv" };
		String[] trainingOutput = { "a", "o", "z",
				"our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up" };
		solver.translator = new Translator(trainingInput, trainingOutput);
		solver.solve(new File("D:/code/codejam/resources/A-small.in"),
				new File("D:/code/codejam/resources/output-A-small.txt"));
	}

}
