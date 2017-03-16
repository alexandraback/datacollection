import java.io.*;
import java.util.*;

public class Solution {

    void solve() {
        long n = readLong();
        if (n == 0) {
            out.println("INSOMNIA");
            return;
        }

        boolean[] b = new boolean[10];
        int count = 0;

        int iter = 0;
        while (count < b.length) {
            iter++;
            long x = iter * n;
            while (x > 0) {
                int d = (int) (x % 10);
                if (!b[d]) {
                    b[d] = true;
                    count++;
                }
                x /= 10;
            }
        }

        out.println(n * iter);
    }

    //region Commons

    StreamTokenizer in;
    PrintWriter out;

    Solution() {
        if (Objects.equals(System.getProperty("input"), "file")) {
            try {
                in = new StreamTokenizer(new BufferedReader(new FileReader("input.txt")));
                out = new PrintWriter(new FileWriter("output.txt"));
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        } else {
            in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
            out = new PrintWriter(new OutputStreamWriter(System.out));
        }
        in.wordChars(21, 256);
    }

    double readDouble() {
        try {
            in.nextToken();
            return in.nval;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    String readString() {
        try {
            in.nextToken();
            return in.sval;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    int readInt() {
        return (int) readDouble();
    }

    long readLong() {
        return (long) readDouble();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.solveTestCases();
        solution.out.flush();
    }

    void solveTestCases() {
        for (int t = 1, ts = readInt(); t <= ts; t++) {
            out.print("Case #");
            out.print(t);
            out.print(": ");
            solve();
        }
    }

    //endregion

}