import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class ProblemUtils {

	public static String[] readInput(String path) throws Exception {
		FileInputStream in = new FileInputStream(path);
		BufferedReader reader = new BufferedReader(new InputStreamReader(in));
		int nlines = Integer.parseInt(reader.readLine());
		String[] lines = new String[nlines];
		for (int i = 0; i < nlines; i++) {
			lines[i] = reader.readLine();
		}
		return lines;
	}
	
	public static void writeOutput(String path, String[] lines) throws Exception {
		FileOutputStream out = new FileOutputStream(path);
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(out));
		for (int i = 0; i < lines.length; i++) {
			writer.write("Case #" + (i + 1) + ": " + lines[i]);
			if (i + 1 < lines.length) {
				writer.write("\n");
			}
		}
		writer.flush();
		out.close();
	}
	
}
