import java.io.*;
import java.util.ArrayDeque;
import java.util.Locale;
import java.util.StringTokenizer;

public class B implements Runnable {

    private static final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer tok = new StringTokenizer("");

    private void init() throws FileNotFoundException {
        Locale.setDefault(Locale.US);
        String fileName = "";
        if (ONLINE_JUDGE && fileName.isEmpty()) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else {
            if (fileName.isEmpty()) {
                in = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            } else {
                in = new BufferedReader(new FileReader(fileName + ".in"));
                out = new PrintWriter(fileName + ".out");
            }
        }
    }

    String readString() {
        while (!tok.hasMoreTokens()) {
            try {
                tok = new StringTokenizer(in.readLine());
            } catch (Exception e) {
                return null;
            }
        }
        return tok.nextToken();
    }

    int readInt() {
        return Integer.parseInt(readString());
    }

    long readLong() {
        return Long.parseLong(readString());
    }

    double readDouble() {
        return Double.parseDouble(readString());
    }

    int[] readIntArray(int size) {
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = readInt();
        }
        return a;
    }

    public static void main(String[] args) {
        //new Thread(null, new _Solution(), "", 128 * (1L << 20)).start();
        new B().run();
    }

    long timeBegin, timeEnd;

    void time() {
        timeEnd = System.currentTimeMillis();
        System.err.println("Time = " + (timeEnd - timeBegin));
    }

    @Override
    public void run() {
        try {
            timeBegin = System.currentTimeMillis();
            init();
            solve();
            out.close();
            time();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    String caseNum(int number) {
        return "Case #" + number + ": ";
    }

    private void solve() {
        int T = readInt();
        for (int test = 1; test <= T; test++) {
            int n = readInt();
            long m = readLong();

            long maxCountOfWays = 1l << (n - 2);
            //out.println(maxCountOfWays);
            if (maxCountOfWays < m) {
                out.println(caseNum(test) + "IMPOSSIBLE");
                continue;
            }

            boolean[][] graph = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j > i) {
                        graph[i][j] = true;
                    }
                }
            }

            if (m < maxCountOfWays) {
                graph[0][n - 1] = false;
                //long mask = (1l << (n - 1)) - 1;
                for (int i = 0; i < n - 1; i++) {
                    if (Long.bitCount(m & (1l << i)) == 0) {
                        graph[i + 1][n - 1] = false;
                    }
                }
            }

            out.println(caseNum(test) + "POSSIBLE");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    out.print(graph[i][j] ? "1" : "0");
                }
                out.println();
            }

        }
    }
}
