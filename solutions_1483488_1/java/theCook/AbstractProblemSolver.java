package codejam.common;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public abstract class AbstractProblemSolver<P, S> {

	public void solve(File input, File output) {
		try (BufferedReader reader = new BufferedReader(new FileReader(input));
				BufferedWriter writer = new BufferedWriter(new FileWriter(
						output))) {
			String line = reader.readLine();
			int numberCases = Integer.parseInt(line);
			for (int i = 1; i <= numberCases; i++) {
				P problem = readProblem(reader);
				S solution = solveProblem(problem);
				writeSolution(i, solution, writer);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public abstract P readProblem(BufferedReader reader) throws IOException;

	public abstract S solveProblem(P problem);

	public abstract void writeSolution(int solutionNumber, S solution,
			BufferedWriter writer) throws IOException;

}
