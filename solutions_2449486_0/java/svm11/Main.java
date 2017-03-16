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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.readInt();
        int m = in.readInt();
        int[][] h = new int[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                h[i][j] = in.readInt();
        int[] mhRow = new int[n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                mhRow[i] = Math.max(mhRow[i], h[i][j]);
        int[] mhCol = new int[m];
        for (int j = 0; j < m; ++j)
            for (int i = 0; i < n; ++i)
                mhCol[j] = Math.max(mhCol[j], h[i][j]);
        boolean possible = true;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (h[i][j] != Math.min(mhRow[i], mhCol[j]))
                    possible = false;
        out.println("Case #" + testNumber + ": " + (possible ? "YES" : "NO"));
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