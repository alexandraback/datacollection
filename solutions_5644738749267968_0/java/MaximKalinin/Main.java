import java.io.StreamTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		TokenizerReader in = new TokenizerReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
    static class Stone implements Comparable<Stone> {
        double weight;
        int whose;
        Stone(double w, int h) {
            weight = w;
            whose = h;
        }

        public int compareTo(Stone that) {
            return weight < that.weight ? -1 : 1;
        }
    }

    public void solve(int testNumber, TokenizerReader in, PrintWriter out) {
        int n = in.nextInt();
        Stone[] stones = new Stone[2*n];
        for (int i = 0; i < 2*n; ++i)
            stones[i] = new Stone(in.nextDouble(), i < n ? 1 : -1);
        Arrays.sort(stones);
        int[] p = new int[2*n];
        for (int i = 0; i < 2*n; ++i)
            p[i] = stones[i].whose;

        out.println("Case #" + testNumber + ": " + deceitfulWar(p) + " " + war(p));
    }

    private int deceitfulWar(int[] p) {
        int n = p.length, res = n/2;
        int cur = 0, j = n;
        for (int i = 0; i < j; ++i) {
            cur += p[i];
            if (cur > 0) {
                do {
                    --j;
                } while (p[j] > 0);
                assert j > i;
                --cur;
                --res;
            }
        }
        return res;
    }

    private int war(int[] p) {
        int best = 0, cur = 0;
        for (int i = p.length-1; i >= 0; --i) {
            cur += p[i];
            best = Math.max(best, cur);
        }
        return best;
    }
}

class TokenizerReader extends StreamTokenizer {
    public TokenizerReader(InputStream in) {
        super(new BufferedReader(new InputStreamReader(in)));
        defaultConfig();
    }

    public String nextString() {
        try {
            nextToken();
        } catch (IOException e) {
            throw new RuntimeException("nextString: exception in line " + lineno(), e);
        }
        return sval;
    }

    public String next() {
        return nextString();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public double nextDouble() {
        return Double.parseDouble(nextString());
    }

    public void defaultConfig() {
        resetSyntax();
        wordChars(33, 126);
        whitespaceChars(0, ' ');
    }

}

