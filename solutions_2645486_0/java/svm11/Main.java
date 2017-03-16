import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputReader in;
        try {
            in = new InputReader(new FileInputStream("B-small-attempt0.in"));
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
    int E;
    int R;
    int n;
    int[] v;

    int[][] dp;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        E = in.readInt();
        R = in.readInt();
        n = in.readInt();
        v = new int[n];
        for (int i = 0; i < n; ++i)
            v[i] = in.readInt();
        dp = new int[n + 1][E + 1];
        for (int[] temp : dp)
            Arrays.fill(temp, -1);
        out.println("Case #" + testNumber + ": " + rec(0, E));
    }

    public int rec(int i, int e) {
        if (i == n) return 0;
        if (dp[i][e] != -1) return dp[i][e];
        dp[i][e] = 0;
        for (int x = 0; x <= e; ++x)
            dp[i][e] = Math.max(dp[i][e], v[i] * x + rec(i + 1, Math.min(E, e - x + R)));
        return dp[i][e];
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