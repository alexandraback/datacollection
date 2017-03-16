import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileReader;
import java.util.Locale;
import java.util.Iterator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Abrackadabra
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		B solver = new B();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class B {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();

        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = in.nextInt();
            }
        }

        int[] maxR = new int[n];
        int[] maxC = new int[m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxR[i] = Math.max(a[i][j], maxR[i]);
                maxC[j] = Math.max(a[i][j], maxC[j]);
            }
        }

        boolean ok = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int c = a[i][j];

                if (c < maxR[i] && c < maxC[j]) {
                    ok = false;
                }
            }
        }

        out.printCase(testNumber);
        out.println(ok ? "YES" : "NO");
    }
}

class InputReader implements Iterable<String> {
    BufferedReader br;
    StringTokenizer in;

    public InputReader(String fileName) {
        try {
            br = new BufferedReader(new FileReader(fileName));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public InputReader(InputStream inputStream) {
        br = new BufferedReader(new InputStreamReader(inputStream));
    }

    String lastLine = null;

    boolean hasMoreTokens() {
        while (in == null || !in.hasMoreTokens()) {
            lastLine = nextLine();
            if (lastLine == null) {
                return false;
            }
            in = new StringTokenizer(lastLine);
        }
        return true;
    }

    public String nextString() {
        return hasMoreTokens() ? in.nextToken() : null;
    }

    public String nextLine() {
        boolean somethingLeft = in != null && in.hasMoreTokens();
        in = null;
        if (somethingLeft) {
            return lastLine;
        }
        try {
            return br.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public String next() {
        return nextString();
    }

    public Iterator<String> iterator() {
        return new Iterator<String>() {
            @Override
            public boolean hasNext() {
                return hasMoreTokens();
            }

            @Override
            public String next() {
                return nextString();
            }

            @Override
            public void remove() {
                throw new RuntimeException();
            }
        };
    }
}

class OutputWriter {

    final PrintWriter out;

    public OutputWriter(String fileName) {
        try {
            out = new PrintWriter(fileName);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public OutputWriter(OutputStream outputStream) {
        out = new PrintWriter(outputStream);
    }

    public OutputWriter(Writer writer) {
        out = new PrintWriter(writer);

    }

    /* PrintWriter methods */

    public void close() {
        out.close();
    }

    public void println(String x) {
        out.println(x);
    }

    public void printf(String format, Object... args) {
        out.printf(format, args);
    }

    /* My helper methods */

    public void printCase(int index) {
        printf("Case #%d: ", index);
    }
}

