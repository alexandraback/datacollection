import java.io.*;
import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;

public class Round2 implements Runnable {
    private static FastIO io;
    private static final String FILE_NAME = "B-large";

    void solveMultiTest() throws IOException {
        int testCases = io.readInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            io.println(String.format(Locale.US, "Case #%d: %s", testCase, solveOneTest()));
        }
    }

    String solveOneTest() throws IOException {
        long b = io.readLong();
        long m = io.readLong();
        if ((1L << (b - 2)) < m) {
            return "IMPOSSIBLE";
        }
        StringBuilder sb = new StringBuilder();
        String s = Long.toBinaryString(m) + "0";
        if ((1L << (b - 2)) == m) {
            s = Long.toBinaryString(m - 1) + "1";
        }
        sb.append("POSSIBLE\n");
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < b - 1; j++) {
                if (j <= i) {
                    sb.append(0);
                } else {
                    sb.append(1);
                }
            }
            if (s.length() > 0) {
                sb.append(s.charAt(s.length() - 1));
                s = s.substring(0, s.length() - 1);
            } else {
                sb.append(0);
            }
            if (i != b - 1) {
                sb.append('\n');
            }
        }
        return sb.toString();
    }

    public void run() {
        try (FastIO fastIO = new FastIO(FILE_NAME)) {
            io = fastIO;
            solveMultiTest();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Thread(new Round2()).start();
    }
}

class FastIO implements AutoCloseable {
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    public FastIO() {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }

    public FastIO(String file) throws FileNotFoundException {
        if (file == null) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else {
            in = new BufferedReader(new FileReader(file + ".in"));
            out = new PrintWriter(file + ".out");
        }
    }

    public String readLine() throws IOException {
        st = null;
        return in.readLine();
    }

    public String readToken() throws IOException {
        return nextToken();
    }

    public int readInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public long readLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    public void print(Object o) {
        out.print(o.toString());
    }

    public void println(Object o) {
        out.println(o.toString());
    }

    @Override
    public void close() throws IOException {
        in.close();
        out.close();
    }
}