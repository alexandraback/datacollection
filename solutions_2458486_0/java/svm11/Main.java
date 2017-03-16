import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputReader in;
        try {
            in = new InputReader(new FileInputStream("D-small-attempt1.in"));
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
        int k = in.readInt();
        int n = in.readInt();
        int[] haveKey = new int[200];
        for (int i = 0; i < k; ++i)
            ++haveKey[in.readInt() - 1];
        int[] whoKey = new int[n];
        int[] numKey = new int[n];
        int[][] getKey = new int[n][200];
        for (int i = 0; i < n; ++i) {
            whoKey[i] = in.readInt() - 1;
            numKey[i] = in.readInt();
            for (int j = 0; j < numKey[i]; ++j)
                ++getKey[i][in.readInt() - 1];
        }
        String[] res = new String[1 << n];
        res[0] = "";
        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; ++i) if ((mask & (1 << i)) != 0) {
                int pMask = mask - (1 << i);
                if (res[pMask] == null) continue;
                int cntWhoKey = haveKey[whoKey[i]];
                for (int j = 0; j < n; ++j) if ((pMask & (1 << j)) != 0) {
                    if (whoKey[j] == whoKey[i]) --cntWhoKey;
                    cntWhoKey += getKey[j][whoKey[i]];
                }
                if (cntWhoKey == 0) continue;
                String curRes = res[pMask] + " " + (i + 1);
                if (res[mask] == null || curRes.compareTo(res[mask]) < 0)
                    res[mask] = curRes;
            }
        }
        out.println("Case #" + testNumber + ": " + (res[(1 << n) - 1] != null ? res[(1 << n) - 1].trim() : "IMPOSSIBLE"));
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