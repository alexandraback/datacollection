import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    boolean can(int r, int c, int m, boolean print) {
        boolean[][] bomb = new boolean[r][c];
        for (int st = 0; st < 1 << (r * c); st++) {
            if (Integer.bitCount(st) == m) {
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++) {
                        if (((1 << (i + j * r)) & st) != 0) {
                            bomb[i][j] = true;
                        } else {
                            bomb[i][j] = false;
                        }
                    }
                int[][] cnt = new int[r][c];
                for (int x = 0; x < r; x++)
                    for (int y = 0; y < c; y++)
                        if (!bomb[x][y]) {
                            for (int dx = -1; dx < 2; dx++)
                                for (int dy = -1; dy < 2; dy++) {
                                    int nx = x + dx, ny = y + dy;
                                    if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                                        cnt[x][y] += bomb[nx][ny] ? 1 : 0;
                                    }
                                }
                        }
                int[] qX = new int[r * c];
                int[] qY = new int[r * c];
                for (int xc = 0; xc < r; xc++)
                    for (int yc = 0; yc < c; yc++)
                        if (!bomb[xc][yc]) {
                            boolean[][] seen = new boolean[r][c];
                            int qIt = 0;
                            int qSz = 1;
                            qX[0] = xc;
                            qY[0] = yc;
                            seen[xc][yc] = true;
                            for (int i = 0; i < r; i++)
                                for (int j = 0; j < c; j++)
                                    if (bomb[i][j])
                                        seen[i][j] = true;
                            while (qIt < qSz) {
                                int x = qX[qIt];
                                int y = qY[qIt++];
                                if (cnt[x][y] == 0) {
                                    for (int dx = -1; dx < 2; dx++)
                                        for (int dy = -1; dy < 2; dy++) {
                                            int nx = x + dx, ny = y + dy;
                                            if (nx >= 0 && nx < r && ny >= 0
                                                    && ny < c) {
                                                if (!seen[nx][ny]) {
                                                    seen[nx][ny] = true;
                                                    qX[qSz] = nx;
                                                    qY[qSz++] = ny;
                                                }
                                            }
                                        }
                                }
                            }
                            int cntSeen = 0;
                            for (int i = 0; i < r; i++)
                                for (int j = 0; j < c; j++)
                                    if (seen[i][j])
                                        cntSeen++;
                            if (cntSeen == r * c) {
                                if (print) {
                                    for (int i = 0; i < r; i++) {
                                        for (int j = 0; j < c; j++) {
                                            out.print(bomb[i][j] ? '*'
                                                    : (xc == i && yc == j ? 'c'
                                                            : '.'));
                                        }
                                        out.println();
                                    }
                                }
                                return true;
                            }
                        }
            }
        }
        return false;
    }

    void solve2() throws IOException {
        int r = in.nextInt();
        int c = in.nextInt();
        int m = in.nextInt();
        int near = 1;
        if (r > 1)
            near++;
        if (c > 1)
            near++;
        if (r > 1 && c > 1)
            near++;
        if (r * c == m + 1 || r * c >= m + near) {
            // if (!can(r, c, m, false))
            // throw new AssertionError(r + " " + c + " " + m);
            char[][] a = new char[r][c];
            for (int i = 0; i < r; i++)
                Arrays.fill(a[i], '?');
            a[r - 1][c - 1] = 'c';
            if (r * c != m + 1) {
                if (r > 1 && c > 1)
                    a[r - 2][c - 2] = '.';
                if (r > 1)
                    a[r - 2][c - 1] = '.';
                if (c > 1)
                    a[r - 1][c - 2] = '.';
            }
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++) {
                    if (a[i][j] == '?')
                        if (m > 0) {
                            m--;
                            a[i][j] = '*';
                        } else {
                            a[i][j] = '.';
                        }
                }
            if (m != 0)
                throw new AssertionError();
            out.println();
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    out.print(a[i][j]);
                }
                out.println();
            }
        } else {
            if (can(r, c, m, false)) {
                can(r, c, m, true);
                throw new AssertionError(r + " " + c + " " + m);
            }
            out.println();
            out.println("Impossible");
        }
    }

    void solve() throws IOException {
        int r = in.nextInt();
        int c = in.nextInt();
        int m = in.nextInt();
        out.println();
        if (!can(r, c, m, true)) {
            out.println("Impossible");
        }
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            int testNumber = in.nextInt();
            for (int test = 1; test <= testNumber; test++) {
                out.print("Case #" + (test) + ": ");
                solve();
                System.out.println(test);
            }

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        try {
            solve();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
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

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        new A().run();
    }
}