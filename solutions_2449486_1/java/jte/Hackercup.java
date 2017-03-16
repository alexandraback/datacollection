/**
 * Created with IntelliJ IDEA.
 * User: brzezinsky
 * Date: 1/26/13
 * Time: 7:58 AM
 * To change this template use File | Settings | File Templates.
 */

import com.sun.servicetag.SystemEnvironment;

import java.io.*;
import java.util.*;
import java.util.concurrent.atomic.AtomicReferenceArray;

public class Hackercup extends Thread {
    public Hackercup(String inputFileName, String outputFileName) {
        try {
            if (inputFileName != null) {
                this.input = new BufferedReader(new FileReader(inputFileName));
            } else {
                this.input = new BufferedReader(new InputStreamReader(System.in));
            }
            if (outputFileName != null) {
                this.output = new PrintWriter(outputFileName);
            } else {
                this.output = new PrintWriter(System.out);
            }
            this.setPriority(Thread.MAX_PRIORITY);
        } catch (Throwable e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(666);
        }
    }

    final int []dx = {-1, 0, 1, 0};
    final int []dy = {0, 1, 0, -1};

    static final boolean in(int x, int y, int n, int m) {
        return x >= 0 && x  < n && y >= 0 && y < m;
    }

    final String doit() throws IOException {
        int n = nextInt(), m = nextInt();
        int [][]a = new int[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = nextInt();
            }
        }
        boolean okay = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int t = a[i][j];
                boolean at = false;
                for (int dirV = 0; dirV < 2; ++dirV) {
                    boolean now = true;
                    int xx = i, yy = j;
                    while (in(xx = xx + dx[dirV], yy = yy + dy[dirV], n, m)) {
                        now &= a[xx][yy] <= t;
                    }
                    xx = i; yy = j;
                    while (in(xx = xx + dx[dirV + 2], yy = yy + dy[dirV + 2], n, m)) {
                        now &= a[xx][yy] <= t;
                    }
                    at |= now;
                }
                okay &= at;
            }
        }
        return okay ? "YES" : "NO";
    }


    private void solve() throws Throwable {

        int n = nextInt();
        for (int i = 1; i <= n; ++i) {
            output.printf("Case #%d: ", i);
            output.println(doit());
        }
    }

    public void run() {
        try {
            solve();
        } catch (Throwable e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(666);
        } finally {
            output.close();
        }
    }

    public static void main(String... args) {
       // new Hackercup(null, null).start();
        new Hackercup("/users/brzezinsky/IdeaProjects/contests/codeforces155/input.txt", "/users/brzezinsky/IdeaProjects/contests/codeforces155/output.txt").start();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    private String nextLine() throws IOException {
        return input.readLine();
    }


    private String next() throws IOException {
        while (tokens == null || !tokens.hasMoreTokens()) {
            tokens = new StringTokenizer(input.readLine());
        }
        return tokens.nextToken();
    }

    private StringTokenizer tokens;
    private BufferedReader input;
    private PrintWriter output;
}