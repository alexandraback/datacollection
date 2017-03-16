import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author RiaD
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Reader in = new Reader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		ManageYourEnergy solver = new ManageYourEnergy();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class ManageYourEnergy {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int e = in.nextInt();
        int r = in.nextInt();
        int n = in.nextInt();

        int[] v = in.nextIntArray(n);

        int[][] dp = new int[n + 1][e + 1];
        for(int i = 0; i < n; ++i){
            for(int prev = 0; prev <= e; ++prev) {
                for(int used = 0; used <= prev; ++used) {
                    dp[i + 1][Math.min(e, prev - used + r)] = Math.max(dp[i + 1][Math.min(e, prev - used + r)], dp[i][prev] + used * v[i]);
                }
            }
        }
        int mx = 0;
        for(int i = 0; i <= e; ++i){
            mx = Math.max(dp[n][i], mx);
        }
        out.println("Case #" + testNumber + ": " + mx);
    }
}

class Reader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Reader(BufferedReader reader) {
        this.reader = reader;
    }

    public Reader(InputStream stream) {
        this(new BufferedReader(new InputStreamReader(stream)));
    }

    public String nextString() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public String next() {
        return nextString();
    }

    public int[] nextIntArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nextInt();
        }
        return array;
    }

    private String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

class OutputWriter extends PrintWriter {

	public OutputWriter(OutputStream out) {
		super(out);
	}

	public OutputWriter(java.io.Writer writer){
		super(writer);
	}

	}

