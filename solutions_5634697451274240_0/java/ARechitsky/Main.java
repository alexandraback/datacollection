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
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        out.print("Case #%d: ", testNumber);
        char [] s = in.next().toCharArray();
        char p = '\0';
        int ans = 0;
        for (char c:s){
            ans+=(p!=c)?1:0;
            p = c;
        }
        ans -= (s[s.length-1]=='+')?1:0;
        out.printLine(ans);
    }
}

class FastScanner {

    private BufferedReader reader;
    private StringTokenizer st;

    public FastScanner(InputStream stream) {
        this.reader = new BufferedReader(new InputStreamReader(stream));
        this.st = new StringTokenizer("");
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

    public void printLine(long i) {
        writer.println(i);
    }

    public void print(String s) {
        writer.print(s);
    }

    public void print(String format, Object... args) {
        print(String.format(format, args));
    }

}

