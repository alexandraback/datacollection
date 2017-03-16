package codejam.recyclednumbers;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;

import codejam.common.AbstractProblemSolver;

public class RecycledNumbersProblemSolver extends
		AbstractProblemSolver<RecycledNumbersProblem, Integer> {

	@Override
	public RecycledNumbersProblem readProblem(BufferedReader reader)
			throws IOException {
		return new RecycledNumbersProblem(reader.readLine());
	}

	@Override
	public Integer solveProblem(RecycledNumbersProblem problem) {
		return problem.solve();
	}

	@Override
	public void writeSolution(int solutionNumber, Integer solution,
			BufferedWriter writer) throws IOException {
		writer.append("Case #" + solutionNumber + ": ");
		writer.append(solution.toString());
		writer.newLine();
	}

	public static void main(String[] args) {
		new RecycledNumbersProblemSolver().solve(new File(
				"D:/code/codejam/resources/numbers-input.txt"), new File(
				"D:/code/codejam/resources/numbers-output.txt"));
	}

}
