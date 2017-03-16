
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class Osmos implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new Osmos(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();

            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/input.txt"));
            out = new PrintWriter("src/osmos-output.txt");

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
        long current = readLong();
        int n = readInt();
       // System.out.println(n);
        long[] a = new long[n];
        for (int i = 0; i < a.length; i++) {
            a[i] = readLong();
        }
        Arrays.sort(a);
        int cost = 0;
        int result = Integer.MAX_VALUE / 2;
        for (int i = 0; i < a.length; i++) {
           /// out.println(i + " " + a[i] + " " + current);
            if (current > a[i]) {
                current += a[i];
            } else {
                result = Math.min(result, cost + (a.length - i));
                if (current == 1) {
                    cost += a.length - i;
                    break;
                }
                while (current <= a[i]) {
                    current += (current - 1);
                    cost++;
                }
                current += a[i];
            }
        }
        result = Math.min(result, cost);
        out.println(result);
    }
}