import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputReader in;
        try {
            in = new InputReader(new FileInputStream("C-small-attempt0.in"));
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
    final long MAXB = (long) (1e14);
    ArrayList<Long> fairAndSquare;

    public boolean isPalin(long x) {
        String s = String.valueOf(x);
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j)
            if (s.charAt(i) != s.charAt(j))
                return false;
        return true;
    }

    public Task() {
        fairAndSquare = new ArrayList<Long>();
        for (long x = 1; x * x <= MAXB; ++x)
            if (isPalin(x) && isPalin(x * x))
                fairAndSquare.add(x * x);
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long A = in.readLong();
        long B = in.readLong();
        int res = 0;
        for (long x : fairAndSquare)
            if (A <= x && x <= B)
                ++res;
        out.println("Case #" + testNumber + ": " + res);
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
