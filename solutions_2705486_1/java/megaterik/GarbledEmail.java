
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;
import java.nio.charset.Charset;
import java.nio.file.Files;

public class GarbledEmail implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new GarbledEmail(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();

            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/input.txt"));
            out = new PrintWriter("src/garbled-email-output.txt");

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
        words = Files.readAllLines(new File("dictionary.txt").toPath(), Charset.defaultCharset()).toArray(new String[0]);
        int ct = readInt();
        int n = 0;
        while (ct-- > 0) {
            System.out.println(n + 1);
            solveTestCase(++n);
        }
    }
    static final char EMPTY = '.';

    void solveTestCase(int number) throws IOException {
        out.print("Case #" + number + ": ");
        String s = readString();
        int[][] f = new int[s.length() + 1][5];
        for (int i = 0; i < f.length; i++) {
            for (int j = 0; j < f[0].length; j++) {
                f[i][j] = Integer.MAX_VALUE / 2;
            }
        }
        f[0][0] = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int cost = 0; cost < 5; cost++) // System.out.println(i + " " + f[i]);
            {
                if (f[i][cost] == Integer.MAX_VALUE / 2) {
                    continue;
                }
                for (int j = 0; j < words.length; j++) {
                    if (i + words[j].length() <= s.length()) {
                        Point r = cost(words[j], s.substring(i, i + words[j].length()), cost);
                        if (r.y > 4) {
                            r.y = 0;
                        }
                        f[i + words[j].length()][r.y] = Math.min(f[i + words[j].length()][r.y], f[i][cost] + r.x);
                        // f[i + words[j].length()] = Math.min(f[i + words[j].length()], f[i] + cost(words[j], s.substring(i, i + words[j].length())));
                    }
                }
            }
        }
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < 5; i++) {
            result = Math.min(result, f[s.length()][i]);
        }
        out.println(result);
    }

    Point cost(String s1, String s2, int lastChange) {
        if (lastChange == 0) {
            lastChange = Integer.MIN_VALUE / 2;
        } else {
            lastChange = -lastChange;
        }
        int total = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                if (lastChange > i - 5) {
                    return new Point(Integer.MAX_VALUE / 2, 0);
                }
                lastChange = i;
                total++;
            }
        }
        return new Point(total, (s1.length() - lastChange));
    }
}