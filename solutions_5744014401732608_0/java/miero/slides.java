import java.io.*;
import java.util.*;

public class slides {
    private static final String NAME = "B-small";
    private static boolean SUBMIT = true;

    static int b;
    static int m;
    static int sl[][];
    static long co[];
    static boolean cycle;
    static long round;

    static boolean edge(int x, int y) {
        if (x == y)
            return false;
        if (x == 0 && y == b - 1) {
            /* bit 0 */
            return (round & 1) != 0;
        } else if (x == 0) {
            /* bits: 1..b-2 */
            return (round & (1 << (1 + y - 1))) != 0;
        } else if (y == b - 1) {
            /* bits: b-1..2b-3 */
            return (round & (1 << (b - 1 + y - 1))) != 0;
        } else {
            /* bits: 2b-3..2b+7 */
            long p = round >> (2*b - 3);
            if (x == 1 && y == 2)
                return p % 3 == 1;
            if (x == 2 && y == 1)
                return p % 3 == 2;
            p /= 3;

            if (x == 1 && y == 3)
                return p % 3 == 1;
            if (x == 3 && y == 1)
                return p % 3 == 2;
            p /= 3;

            if (x == 2 && y == 3)
                return p % 3 == 1;
            if (x == 3 && y == 2)
                return p % 3 == 2;
            p /= 3;

            if (x == 1 && y == 4)
                return p % 3 == 1;
            if (x == 4 && y == 1)
                return p % 3 == 2;
            p /= 3;

            if (x == 2 && y == 4)
                return p % 3 == 1;
            if (x == 4 && y == 2)
                return p % 3 == 2;
            p /= 3;

            if (x == 3 && y == 4)
                return p % 3 == 1;
            if (x == 4 && y == 3)
                return p % 3 == 2;
        }
        return false;
    }

    static void check(int x)
    {
        int c = 0;
        co[x] = -2;
        for (int i = 0; i < b; i++) {
            if (i == x)
                continue;
            if (edge(i, x)) {
                if (co[i] == -2) {
                    cycle = true;
                    return;
                }
                if (co[i] == -1)
                    check(i);
                c += co[i];
            }
            if (cycle)
                return;
        }
        co[x] = c;
    }

    private static void main_slides() throws IOException {
        int i, j, k;
        int r;

        b = in.nextInt();
        m = in.nextInt();
        sl = new int[b][b];
        co = new long[b];

        long stop = 1 << (2*b + 8) - 1;
        for (round = 0; round < stop ; round++) {
            for (i = 0; i < b; i++)
                co[i] = -1;
            co[0] = 1;
            cycle = false;
            check(b - 1);
/*
            if (!cycle)
                System.out.println("r=" + round + " mm=" + co[b-1]);
*/
            if (!cycle && co[b - 1] == m) {
                out.println("POSSIBLE");
                for (i = 0; i < b; i++) {
                    for (j = 0; j < b; j++) {
                        out.print(edge(i, j) ? "1" : "0");
                    }
                    out.println();
                }
                break;
            }
            cycle = true;
        }
        if (cycle) {
            out.println("IMPOSSIBLE");
        }
    }

    private static InputReader in;
    private static PrintWriter out;

    public static void main(String[] args) throws IOException {
        if (SUBMIT) {
            in = new InputReader(new FileInputStream(new File(NAME + ".in")));
            out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
        } else {
            in = new InputReader(System.in);
            out = new PrintWriter(System.out, true);
        }
        int numCases = in.nextInt();
        for (int test = 1; test <= numCases; test++) {
            out.print("Case #" + test + ": ");
            main_slides();
        }
        out.close();
        System.exit(0);
    }

    private static class InputReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}