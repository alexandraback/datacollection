import java.io.*;
import java.util.*;

public class Solution {

    void solve() {
        String s = readString();
        int flips = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                flips++;
            }
        }
        if (s.charAt(s.length() - 1) == '-') {
            flips++;
        }
        out.println(flips);
    }

    //region Commons

    StreamTokenizer in;
    PrintWriter out;

    Solution() {
        if (Objects.equals(System.getProperty("io"), "file")) {
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
    }

    double readDouble() {
        try {
            in.parseNumbers();
            in.nextToken();
            return in.nval;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    String readString() {
        try {
            in.ordinaryChars(21, 256);
            in.wordChars(21, 256);
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