import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CodeJam {
	private static final String FILE_NAME = "E:/download/B-large.in";

	public static void main(String[] args) throws IOException {
		File file = new File(FILE_NAME);
		BufferedReader in = new BufferedReader(new FileReader(file));
		StringBuilder builder = new StringBuilder();
		SolverModule solver = new TestTwoSolver();
		builder = solver.process(in, builder);
		System.out.println(builder);
		file = new File(FILE_NAME.concat(".result"));
		FileWriter fileWriter = new FileWriter(file);
		fileWriter.append(builder);
		fileWriter.flush();
		fileWriter.close();
	}
}
