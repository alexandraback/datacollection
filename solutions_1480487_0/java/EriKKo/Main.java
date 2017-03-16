import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Erik Odenman
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("safetyinnumbers.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		SafetyInNumbers solver = new SafetyInNumbers();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class SafetyInNumbers {

    static int[] s;
    static int N;
    static double tot;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
        N = in.getInt();
        s = new int[N];
        tot = 0;
        for (int i = 0; i < N; i++) {
            s[i] = in.getInt();
            tot += s[i];
        }
        double[] res = new double[N];
        for (int i = 0; i < N; i++) {
            double lo = 0;
            double hi = 1;
            for (int j = 0; j < 500; j++) {
                double mid = lo+(hi-lo)/2;
                if (possible(i, mid)) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            res[i] = lo*100;
        }
        out.print("Case #"+testNumber+":");
        for (int i = 0; i < N ; i++) {
            out.print(" " + res[i]);
        }
        out.println();
	}

    static boolean possible(int n, double d) {
        double score = s[n] + tot*d;
        double acc = d;
        for (int i = 0; i < N; i++) {
            if (i == n) continue;
            double need = Math.max(0, score - s[i]);
            acc += need/tot;
        }
        return acc > 1;
    }
}

class InputReader {
    private BufferedReader in;
    private StringTokenizer st;
    String token;

    public InputReader(InputStream inStream) {
        in = new BufferedReader(new InputStreamReader(inStream));
    }

    public int getInt() {
        return Integer.parseInt(next());
    }

    public String next() {
        String res = peekToken();
        token = null;
        return res;
    }

    public String peekToken() {
        if (token != null) return token;
        while (st == null || !st.hasMoreTokens()) {
            String line = null;
            try {
                line = in.readLine();
            } catch (IOException e) {
                throw new RuntimeException("No more tokens was found");
            }
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return token = st.nextToken();
    }

    }

class OutputWriter  {

    PrintWriter out;

    public OutputWriter(OutputStream outStream) {
        out = new PrintWriter(outStream);
    }

    public OutputWriter(Writer writer) {
        out = new PrintWriter(writer);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) out.print(' ');
            out.print(objects[i]);
        }
    }

    public void println(Object... objects) {
        print(objects);
        out.println();
    }

    public void close() {
        out.close();
    }
}

