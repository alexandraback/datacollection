import java.io.InputStreamReader;
import java.io.IOException;
import java.io.FileReader;
import java.util.Arrays;
import java.io.FileWriter;
import java.util.Iterator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.Writer;
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
    OutputWriter out = new OutputWriter("output.txt");

    public void solve(int testNumber, InputReader in, OutputWriter cout) {
        int armin = in.nextInt();

        int[] motes = in.nextIntArray(in.nextInt());

        Arrays.sort(motes);

        int answer = Integer.MAX_VALUE;

        int used = 0;

        for (int i = 0; i < motes.length; i++) {
            answer = Math.min(answer, used + motes.length - i);
            if (motes[i] < armin) {
                armin += motes[i];
            } else {
                used++;

                if (armin == 1) {
                    break;
                }

                armin += armin - 1;
                i--;
            }
        }

        if (armin != 1) {
            answer = Math.min(answer, used);
        }

        out.format("Case #%d: %d\n", testNumber, answer);

        out.flush();
    }
}

class OutputWriter extends PrintWriter {

    public OutputWriter(String fileName) {
        super(getWriter(fileName));
    }

    private static Writer getWriter(String s) {
        Writer writer;

        try {
            writer = new FileWriter(s);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        return writer;
    }

    public OutputWriter(OutputStream outputStream) {
        super(outputStream);
    }

    public OutputWriter(Writer writer) {
        super(writer);
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

    public int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        return a;
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

