package codejam.dancingwiththegooglers;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;

import codejam.common.AbstractProblemSolver;

public class DancingScoresProblemSolver extends
		AbstractProblemSolver<DancingScores, Integer> {

	@Override
	public DancingScores readProblem(BufferedReader reader) throws IOException {
		return new DancingScores(reader.readLine());
	}

	@Override
	public Integer solveProblem(DancingScores problem) {
		return problem.maxNumberScoresAboveThreshold();
	}

	@Override
	public void writeSolution(int solutionNumber, Integer solution,
			BufferedWriter writer) throws IOException {
		writer.append("Case #" + solutionNumber + ": ");
		writer.append(solution.toString());
		writer.newLine();
	}

	public static void main(String[] args) {
		new DancingScoresProblemSolver().solve(new File(
				"D:/code/codejam/resources/dancing-input.txt"), new File(
				"D:/code/codejam/resources/dancing-output.txt"));
	}
}
