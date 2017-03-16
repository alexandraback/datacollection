import java.io.BufferedReader;
import java.io.IOException;

public class SolverModule {

	public StringBuilder process(BufferedReader in, StringBuilder builder)
			throws IOException {
		in.readLine();
		String line = in.readLine();
		int count = 1;
		while (line != null) {
			appendLine(line, builder,count);
			count++;
			line = in.readLine();
		}
		return builder;
	}

	public static void appendLine(String line, StringBuilder builder, int count) {
		builder.append("Case #"+count+": "+line + "\r\n");
	}
}
