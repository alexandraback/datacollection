import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputReader in;
        try {
            in = new InputReader(new FileInputStream("A-large.in"));
        } catch (FileNotFoundException e) {
            in = new InputReader(System.in);
        }
        PrintWriter out;
        try {
            out = new PrintWriter(new FileOutputStream("Output.out"));
        } catch (FileNotFoundException e) {
            out = new PrintWriter(System.out);
        }
        Task solver = new Task();
        int testCount = in.readInt();
        for (int i = 1; i <= testCount; ++i)
            solver.solve(i, in, out);
        out.close();
    }
}

class Task {
    final BigInteger TWO = BigInteger.valueOf(2);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        BigInteger r = new BigInteger(in.readString());
        BigInteger t = new BigInteger(in.readString());
        BigInteger lo = BigInteger.ONE, hi = t;
        while (hi.compareTo(lo) >= 0) {
            BigInteger mid = (lo.add(hi)).divide(TWO);
            BigInteger req = mid.multiply(TWO.multiply(mid.add(r)).subtract(BigInteger.ONE));
            if (t.compareTo(req) > 0) lo = mid.add(BigInteger.ONE);
            else if (t.compareTo(req) < 0) hi = mid.subtract(BigInteger.ONE);
            else {
                out.println("Case #" + testNumber + ": " + mid);
                return;
            }
        }
        out.println("Case #" + testNumber + ": " + hi);
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        this.reader = new BufferedReader(new InputStreamReader(stream));
        this.tokenizer = null;
    }

    public String readLine() {
        String res;
        try {
            do {
                res = reader.readLine();
            } while (res == null);
        } catch (IOException e) {
            throw new InputMismatchException();
        }
        return res;
    }

    public String readString() {
        while (tokenizer == null || !tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(readLine());
        return tokenizer.nextToken();
    }

    public int readInt() {
        return Integer.parseInt(readString());
    }

    public long readLong() {
        return Long.parseLong(readString());
    }

    public double readDouble() {
        return Double.parseDouble(readString());
    }
}