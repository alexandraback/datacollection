
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class LawnMower implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new LawnMower(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();

            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/input.txt"));
            out = new PrintWriter("src/lawnoutput.txt");

            Locale.setDefault(Locale.US);
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    // solution
    void solve() throws IOException {
        int ct = readInt();
        int n = 0;
        while (ct-- > 0) {
            solveTestCase(++n);
        }
    }
    static final char EMPTY = '.';

    void solveTestCase(int number) throws IOException {
        out.print("Case #" + number + ": ");
        int n = readInt();
        int m = readInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = readInt();
            }
        }
        boolean success = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                success &= isPossible(a, i, j);
            }
        }
        if (success) {
            out.println("YES");
        } else {
            out.println("NO");
        }
    }

    boolean isPossible(int[][] a, int x, int y) {
        boolean success = true;
        for (int i = 0; i < a.length; i++) {
            success &= (a[i][y] <= a[x][y]);
        }
        if (success) {
            return true;
        }
        success = true;
        for (int j = 0; j < a[0].length; j++) {
            success &= (a[x][j] <= a[x][y]);
        }
        return success;
    }
}