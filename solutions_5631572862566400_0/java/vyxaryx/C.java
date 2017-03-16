import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C implements Runnable {
    static class ProblemData {
        private final BufferedReader rd;
        private final PrintWriter wr;
        private StringTokenizer tok = null;

        public ProblemData(BufferedReader rd, PrintWriter wr) {
            this.rd = rd;
            this.wr = wr;
        }

        public static ProblemData files(String ifn, String ofn) throws IOException {
            BufferedReader rd = new BufferedReader(new FileReader(new File(ifn)));
            PrintWriter wr = new PrintWriter(new FileWriter(ofn));
            return new ProblemData(rd, wr);
        }

        public static ProblemData console() {
            BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter wr = new PrintWriter(System.out);
            return new ProblemData(rd, wr);
        }

        public void close() {
            try {
                rd.close();
            } catch (Exception ignored) {
            }
            try {
                wr.close();
            } catch (Exception ignored) {
            }
        }

        public String readToken() throws IOException {
            while (tok == null || !tok.hasMoreTokens()) {
                tok = new StringTokenizer(rd.readLine());
            }
            return tok.nextToken();
        }

        public void writeLine(String line) {
            wr.println(line);
        }
    }

    public static void enforce(boolean condition) {
        if (!condition) {
            throw new AssertionError();
        }
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        new Thread(new C()).start();
    }

    private void solve() throws IOException {
        ProblemData data = ProblemData.files("c.in", "c.out");
        int tn = Integer.parseInt(data.readToken());
        for (int ti = 0; ti < tn; ++ti) {
            long result = solveTest(data);
            data.writeLine(String.format("Case #%d: %s", ti + 1, result));
        }
        data.close();
    }

    int n;
    int[] f;
    ArrayList<Integer>[] rf;

    int[] r;
    int[] c;
    int[] s;
    int sl;

    private int dfs(int x) {
        if(r[x] != -1) {
            return r[x];
        }
        if(c[x] == 1) {
            int ret = 1;
            for(int i = sl - 1; i >= 0; --i) {
                if(s[i] == x) {
                    break;
                }
                ++ret;
            }
            return ret;
        }
        enforce(c[x] == 0);
        c[x] = 1;
        s[sl] = x;
        ++sl;
        int ret = dfs(f[x]);
        r[x] = ret;
        --sl;
        c[x] = 2;
        return ret;
    }

    private int bestrp(int x, int p) {
        int ret = 0;
        for(Integer y: rf[x]) {
            if(y == p) {
                continue;
            }
            ret = Math.max(ret, bestrp(y, p));
        }
        return ret + 1;
    }

    private long solveTest(ProblemData data) throws IOException {
        n = Integer.parseInt(data.readToken());
        f = new int[n];
        rf = new ArrayList[n];
        for(int i = 0; i < n; ++i) {
            rf[i] = new ArrayList<>();
        }
        for(int i = 0; i < n; ++i) {
            int p = Integer.parseInt(data.readToken()) - 1;
            f[i] = p;
            rf[p].add(i);
        }

        c = new int[n];
        r = new int[n];
        Arrays.fill(c, 0);
        Arrays.fill(r, -1);
        s = new int[n];
        sl = 0;
        int bestcycle = 0;
        for(int i = 0; i < n; ++i) {
            if(c[i] == 0) {
                bestcycle = Math.max(bestcycle, dfs(i));
            }
        }
        int bestchain = 0;
        for(int i = 0; i < n; ++i) {
            if(f[f[i]] == i && f[i] > i) {
                bestchain += bestrp(i, f[i]) + bestrp(f[i], i);
            }
        }
        return Math.max(bestcycle, bestchain);
    }
}
