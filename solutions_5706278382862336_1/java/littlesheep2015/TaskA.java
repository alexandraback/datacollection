import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author sheep
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }
}

class TaskA {
    private static final long MAX_VALUE = (1L << 40L);
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String[] number = in.next().split("/");
        long upper = Long.parseLong(number[0]);
        long lower = Long.parseLong(number[1]);
        long gcd = BigInteger.valueOf(upper).gcd(BigInteger.valueOf(lower)).longValue();
        upper /= gcd;
        lower /= gcd;

        if (MAX_VALUE % lower != 0) {
            out.println("Case #" + testNumber + ": impossible");
            return;
        }

        for (int i = 1; ; ++i) {
            if (compare(1, 1 << i, upper, lower)) {
                out.println("Case #" + testNumber + ": " + i);
                return;
            }
        }
    }

    private boolean compare(long u1, long d1, long u2, long d2) {
        return u1 * (MAX_VALUE / d1) <= u2 * (MAX_VALUE / d2);
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

}

