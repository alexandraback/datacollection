import java.io.*;
import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;

public class Round2 implements Runnable {
    private static FastIO io;
    private static final String FILE_NAME = "C-small-attempt1";

    void solveMultiTest() throws IOException {
        int testCases = io.readInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            io.print(String.format(Locale.US, "Case #%d: %s", testCase, solveOneTest()));
        }
    }

    String solveOneTest() throws IOException {
        int nj = io.readInt();
        int np = io.readInt();
        int ns = io.readInt();
        int k = io.readInt();
        StringBuilder sb = new StringBuilder();
        int[][] jp = new int[nj][np];
        int[][] js = new int[nj][ns];
        int[][] ps = new int[np][ns];
        int total = 0;
        for (int j = 0; j < nj; j++) {
            for (int p = 0; p < np; p++) {
                if (jp[j][p] >= k) {
                    continue;
                }
                for (int s = 0; s < ns; s++) {
                    if (jp[j][p] >= k || js[j][s] >= k || ps[p][s] >= k) {
                        continue;
                    }
                    sb.append(j + 1).append(' ').append(p + 1).append(' ').append(s + 1).append('\n');
                    jp[j][p]++;
                    js[j][s]++;
                    ps[p][s]++;
                    total++;
                }
            }
        }
        return total + "\n" + sb.toString();
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