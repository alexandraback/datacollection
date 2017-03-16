import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CodeJam {
	private static final String FILE_NAME = "E:/workspace/codejam_module/C-small-attempt0.in";

	public static void main(String[] args) throws IOException {
		File file = new File(FILE_NAME);
		BufferedReader in = new BufferedReader(new FileReader(file));
		StringBuilder builder = new StringBuilder();
		SolverModule solver = new CSolver();
		builder = solver.process(in, builder);
		System.out.println(builder);
		file = new File(FILE_NAME.concat(".result"));
		FileWriter fileWriter = new FileWriter(file);
		fileWriter.append(builder);
		fileWriter.flush();
		fileWriter.close();
	}
}
