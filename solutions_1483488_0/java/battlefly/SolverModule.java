import java.io.BufferedReader;
import java.io.IOException;

public abstract class SolverModule {

	public StringBuilder process(BufferedReader in, StringBuilder builder)
			throws IOException {
		in.readLine();
		String line = in.readLine();
		int count = 1;
		while (line != null) {
			line = processLine(line);
			appendLine(line, builder,count);
			count++;
			line = in.readLine();
		}
		return builder;
	}

	abstract String processLine(String line) ;

	protected static void appendLine(String line, StringBuilder builder, int count) {
		builder.append("Case #"+count+": "+line + "\r\n");
	}
	
	protected int[] toIntegers(String[] split) {
		int[] ints = new int[split.length];
		for (int i = 0; i < split.length; i++) {
			ints[i] = Integer.valueOf(split[i]);
		}
		return ints;
	}
}
