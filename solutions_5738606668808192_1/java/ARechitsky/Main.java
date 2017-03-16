import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Andrey Rechitsky (arechitsky@gmail.com)
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
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int j = in.nextInt();
        int n = in.nextInt();
        out.printLine("Case #%d:", testNumber);
        for (int i = 0; i < n; i++) {
            out.print('1');
            for (int k = 0; k < (j-2)/2; k++) {
                char c = ((i&(1<<k))>0)?'1':'0';
                out.print(c);
                out.print(c);
            }
            out.print('1');
            for (int k = 0; k < 9; k++) {
                out.print(' ');
                out.print(k+3);
            }
            out.printLine();
        }
    }
}

class FastScanner {

    private BufferedReader reader;
    private StringTokenizer st;

    public FastScanner(InputStream stream) {
        this.reader = new BufferedReader(new InputStreamReader(stream));
        this.st = new StringTokenizer("");
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String next() {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(readLine());
        }
        return st.nextToken();
    }

    private String readLine() {
        String line = tryReadLine();
        if (line == null) throw new InputMismatchException();
        return line;
    }

    private String tryReadLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

}

class FastPrinter {
    private final PrintWriter writer;

    public FastPrinter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void close() {
        writer.close();
    }

    public void printLine(String s) {
        writer.println(s);
    }

    public void printLine(String format, Object... args) {
        printLine(String.format(format, args));
    }

    public void printLine() {
        writer.println();
    }

    public void print(long i) {
        writer.print(i);
    }

    public void print(char c) {
        writer.print(c);
    }

}

