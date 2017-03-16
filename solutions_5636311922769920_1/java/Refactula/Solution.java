import java.io.*;

public class Solution {

    void solve() {
        int k = readInt();
        int c = readInt();
        int s = readInt();

        int min = k / c + (k % c == 0 ? 0 : 1);
        if (s < min) {
            out.println("IMPOSSIBLE");
            return;
        }

        long q = 1;
        long p = 1;
        for (int i = 0; i < k; i++) {
            q += i * p;
            p *= k;
            if ((i + 1) % c == 0) {
                out.print(q);
                out.print(' ');

                q = 1;
                p = 1;
            }
        }

        if (k % c > 0) {
            out.print(q);
            out.print(' ');
        }

        out.println();
    }

    void debug(int k, int c) {
        int n = 1 << k;
        for (int i = 0; i < n; i++) {
            String s = genKey(k, i);
            out.println(s + ": " + generation(s, c));
        }
    }

    String generation(String key, int c) {
        String s = key;
        while (c > 1) {
            s = nextGen(s, key);
            c--;
        }
        return s;
    }

    String genKey(int k, int i) {
        StringBuilder builder = new StringBuilder();
        while (k > 0) {
            builder.append(i % 2 == 0 ? 'L' : 'G');
            k--;
            i /= 2;
        }
        builder.reverse();
        return builder.toString();
    }

    String nextGen(String gen, String key) {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < gen.length(); i++) {
            if (gen.charAt(i) == 'L') {
                builder.append(key);
            } else {
                for (int j = 0; j < key.length(); j++) {
                    builder.append('G');
                }
            }
        }
        return builder.toString();
    }

    //region Commons

    StreamTokenizer in;
    PrintWriter out;
    boolean isDevMode;

    Solution() {
        try {
            if (System.getProperty("input.file") != null) {
                in = new StreamTokenizer(new BufferedReader(new FileReader(System.getProperty("input.file"))));
            } else {
                in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
            }
            if (System.getProperty("output.file") != null) {
                out = new PrintWriter(new FileWriter(System.getProperty("output.file")));
            } else {
                out = new PrintWriter(new OutputStreamWriter(System.out));
            }
            isDevMode = System.getProperty("dev") != null;
        } catch (IOException e) {
            throw new RuntimeException(e);
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
        if (solution.isDevMode) {
            solution.solve();
        } else {
            solution.solveTestCases();
        }
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