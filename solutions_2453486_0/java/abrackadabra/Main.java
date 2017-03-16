import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileReader;
import java.util.Arrays;
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
		A solver = new A();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class A {
    String result = "";

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int[][] a = new int[4][4];
        boolean notDraw = false;
        for (int i = 0; i < 4; i++) {
            String s = in.nextLine();
            for (int j = 0; j < 4; j++) {
                switch (s.charAt(j)) {
                    case '.' : a[i][j] = 0; notDraw = true; break;
                    case 'X' : a[i][j] = 1; break;
                    case 'O' : a[i][j] = 2; break;
                    case 'T' : a[i][j] = 3; break;
                }
            }
        }
        in.nextLine();

        result = "Game has not completed";

        if (!notDraw) {
            result = "Draw";
        }

        for (int i = 0; i < 4; i++) {
            check("" + a[i][0] + a[i][1] + a[i][2] + a[i][3]);
            check("" + a[0][i] + a[1][i] + a[2][i] + a[3][i]);
        }

        check("" + a[0][0] + a[1][1] + a[2][2] + a[3][3]);
        check("" + a[0][3] + a[1][2] + a[2][1] + a[3][0]);

        out.printCase(testNumber);
        out.println(result);
    }

    void check(String s) {
        if (s.replace('3','1').equals("1111")) {
            result = "X won";
        }
        if (s.replace('3','2').equals("2222")) {
            result = "O won";
        }
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

    public PrintWriter printf(String format, Object... args) {
        return out.printf(format, args);
    }

    /* My helper methods */

    public void printCase(int index) {
        printf("Case #%d: ", index);
    }

    }

