import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileInputStream;
import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.util.Comparator;
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
			final String regex = "C-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int L = in.readInt();
		int X = in.readInt();

		int[] a = getArray(XString.repeat(in.next(), X));

		int[][] mul = {
				{0, 1, 2, 3},
				{1, 4, 3, 6},
				{2, 7, 4, 1},
				{3, 2, 5, 4}
		};

		int n = a.length;

		int[] prefixMul = new int[n];
		prefixMul[0] = a[0];
		for (int i = 1; i < n; i++) {
			int prev = prefixMul[i - 1];
			int cur = a[i];
			prefixMul[i] = (mul[prev % 4][cur] + 4 * (prev / 4)) % 8;
		}

		int[] first = new int[8];
		int[] last = new int[8];
		Arrays.fill(first, n);
		Arrays.fill(last, 0);
		for (int i = 0; i < n; i++) {
			first[prefixMul[i]] = Math.min(first[prefixMul[i]], i);
			last[prefixMul[i]] = Math.max(last[prefixMul[i]], i);
		}

		String ans;
		if (first[1] < last[3] && last[4] == n - 1) {
			ans = "YES";
		} else {
			ans = "NO";
		}

		out.printfln("Case #%d: %s", testNumber, ans);
	}

	private int[] getArray(String s) {
		int[] a = new int[s.length()];
		for (int i = 0; i < s.length(); i++) {
			a[i] = "1ijk".indexOf(s.charAt(i) + "");
		}
		return a;
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

class XString {

	public static String repeat(String s, int t) {
		StringBuilder ans = new StringBuilder();
		while (t-- > 0) {
			ans.append(s);
		}
		return ans.toString();
	}


}

