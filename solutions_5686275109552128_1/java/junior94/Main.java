import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Agostinho Junior (junior94)
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int d = in.readInt();
		int[] p = new int[d];
		for (int i = 0; i < d; i++) {
			p[i] = in.readInt();
		}

		int ans = Integer.MAX_VALUE;
		for (int max = 1; max <= 2000; max++) {
			int temp = 0;
			for (int i = 0; i < d; i++) {
				temp += p[i] / max;
				if (p[i] % max == 0) {
					temp--;
				}
			}
			ans = Math.min(ans, temp + max);
		}

		out.printfln("Case #%d: %d", testNumber, ans);
	}

}

class InputReader {
	private BufferedReader input;
	private StringTokenizer line = new StringTokenizer("");

	public InputReader(InputStream in) {
		input = new BufferedReader(new InputStreamReader(in));
	}

	public void fill() {
		try {
			if(!line.hasMoreTokens()) line = new StringTokenizer(input.readLine());
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}

	public String next() {
		fill();
		return line.nextToken();
	}

	public int readInt() {
		fill();
		return Integer.parseInt(line.nextToken());
	}

}

class OutputWriter {
	private PrintWriter output;

	public OutputWriter(OutputStream out) {
		output = new PrintWriter(out);
	}

	public void printfln(String format, Object... o) {
		output.printf(format + "\n", o);
	}

	public void close() {
		output.close();
	}
}

