import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Artem Gilmudinov
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("A-small-attempt0.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Reader in = new Reader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task {
    public void solve(int testNumber, Reader in, PrintWriter out) {
        int t = in.ni();
        for(int test = 0; test < t; test++) {
            int n = in.ni();
            int[] a = new int[n + 1];
            Arrays.fill(a, Integer.MAX_VALUE);
            a[1] = 1;
            for(int i = 1; i <= n - 1; i++) {
                int reverse = rotate(i);
                if(reverse <= n) {
                    a[reverse] = Math.min(a[reverse], a[i] + 1);
                }
                a[i + 1] = Math.min(a[i + 1], a[i] + 1);
            }
            out.println(String.format("Case #%d: %d ", test + 1, a[n]));
        }
    }

    public int rotate(int a) {
        int maxPow = 1;
        while(true) {
            if(maxPow * 10 > a) {
                break;
            }
            maxPow *= 10;
        }
        int res = 0;
        int curPow = 1;
        while(maxPow != 0) {
            res += curPow * (a / maxPow);
            a -= (a / maxPow) * maxPow;
            maxPow /= 10;
            curPow *= 10;
        }
        return res;

    }
}

class Reader {
    private BufferedReader in;
    private StringTokenizer st = new StringTokenizer("");
    private String delim = " ";

    public Reader(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
    }

    public String next() {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(rl());
        }
        return st.nextToken(delim);
    }

    public String rl() {
        try {
            return in.readLine();
        } catch(IOException e) {
            throw new RuntimeException(e);
        }
    }

    public int ni() {
        return Integer.parseInt(next());
    }

}

