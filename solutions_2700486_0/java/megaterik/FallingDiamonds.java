
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;
import java.nio.charset.Charset;
import java.nio.file.Files;

public class FallingDiamonds implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new FallingDiamonds(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();

            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/input.txt"));
            out = new PrintWriter("src/falling-diamonds-output.txt");

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
    String[] words;
    // solution

    void solve() throws IOException {
        int ct = readInt();
        int n = 0;
        while (ct-- > 0) {
            System.out.println(n + 1);
            solveTestCase(++n);
        }
    }
    int[] level;
    int n;
    double probability;

    void solveTestCase(int number) throws IOException {
        out.print("Case #" + number + ": ");
        n = readInt();
        int x = readInt();
        int y = readInt();
        level = new int[4 * n + 100];
        probability = 0;
        simulate(n, 0, x, y, 1.0);
        System.out.println(probability);
        out.println(probability);
    }

    int get(int x) {
        return level[x + n * 2];
    }

    void increase(int x) {
        level[x + n * 2]++;
    }

    void decrease(int x) {
        level[x + n * 2]--;
    }

    void simulate(int remaining, int x, int tx, int ty, double p) //p is a probability to get here
    {
        if (remaining == 0) {
            return;
        }

        if (get(x) <= get(x - 1) && get(x) <= get(x + 1)) {
            increase(x);
            if (!probablyIncreaseProbability(remaining, x, get(x), tx, ty, p)) {
                simulate(remaining - 1, 0, tx, ty, p);
            }
            decrease(x);
            return;
        }

        if (get(x) == get(x - 1) && get(x) > get(x + 1)) {
            if (get(x + 2) > get(x + 1)) {
                simulate(remaining, x + 1, tx, ty, p);
            } else {
                simulate(remaining, x + 2, tx, ty, p);
            }
        } else if (get(x) == get(x + 1) && get(x) > get(x - 1)) {
            if (get(x - 2) > get(x - 1)) {
                simulate(remaining, x - 1, tx, ty, p);
            } else {
                simulate(remaining, x - 2, tx, ty, p);
            }
        } else if (get(x) > get(x + 1) && get(x) > get(x - 1)) {
            if (get(x + 2) > get(x + 1)) {
                simulate(remaining, x + 1, tx, ty, p / 2);
            } else {
                simulate(remaining, x + 2, tx, ty, p / 2);
            }
            if (get(x - 2) > get(x - 1)) {
                simulate(remaining, x - 1, tx, ty, p / 2);
            } else {
                simulate(remaining, x - 2, tx, ty, p / 2);
            }
        } else {
            throw new RuntimeException("wat?");
        }
    }

    boolean probablyIncreaseProbability(int remaining, int x, int y, int tx, int ty, double p) {
        y--;
        if (tx % 2 == 0 && ty % 2 == 0) {
            if (x == tx && y == ty) {
                probability += p;
                return true;
            }
        }
        if (tx % 2 == 1 && ty % 2 == 1)
        {
            if (x == tx && y == ty - 1)
            {
                probability += p;
                return true;
            }
        }
        return false;
    }
}