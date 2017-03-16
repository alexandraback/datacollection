import java.util.*;
import java.io.*;

public class C {
    FastScanner in;
    PrintWriter out;

    int[] next;
    int[] d;
    int[] num;
    int[] own;

    int[] circles;
    int[] circleNum;
    int circCount;
    int[] sizes;

    public int gen(int i, int cnt) {
        if (d[i] != -1) {
            return d[i];
        } else {
            if (num[i] != 0) {
                int x = i;
                int number = 0;
                do {
                    circles[x] = number++;
                    d[x] = 0;
                    own[x] = x;
                    circleNum[x] = circCount;

                    x = next[x];
                } while (x != i);
                sizes[circCount] = number;
                circCount++;
                return 0;
            } else {
                num[i] = cnt;
                int ans = gen(next[i], cnt + 1);
                if (d[i] == -1) {
                    own[i] = own[next[i]];
                    return d[i] = ans + 1;
                } else {
                    return d[i];
                }
            }
        }
    }

    int log = 20;
    int[][] binup;

    int getLCA(int u, int v) {
        if (u == v) {
            return u;
        }
        if (d[u] > d[v]) {
            int tmp = u;
            u = v;
            v = tmp;
        }
        v = up(v, d[u]);
        if (v == u) return v;
        for (int i = log - 1; i >= 0; i--) {
            if (binup[v][i] != binup[u][i]) {
                v = binup[v][i];
                u = binup[u][i];
            }
        }
        if (next[v] != next[u]) {
            throw new AssertionError(v + " " + u);
        }
        return next[v];
    }

    int up(int v, int dist) {
        for (int i = log - 1; i >= 0; i--) {
            if (d[binup[v][i]] == 0 && binup[v][i] != own[v]) {
                continue;
            }
            if (d[binup[v][i]] >= dist) {
                v = binup[v][i];
            }
        }
        return v;
    }

    public void solveTest() throws IOException {
        int n = in.nextInt();
        next = new int[n];
        Arrays.setAll(next, i -> in.nextInt() - 1);
        d = new int[n];
        num = new int[n];
        Arrays.fill(d, -1);
        circles = new int[n];
        circleNum = new int[n];
        circCount = 0;
        sizes = new int[n];
        own = new int[n];
        for (int i = 0; i < n; i++) {
            if (d[i] == -1) {
                gen(i, 1);
            }
        }

        binup = new int[n][log];
        for (int i = 0; i < n; i++) {
            binup[i][0] = next[i];
        }
        for (int i = 1; i < log; i++) {
            for (int j = 0; j < n; j++) {
                binup[j][i] = binup[binup[j][i - 1]][i - 1];
            }
        }
        int[] curAns = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int ci = own[i];
                int cj = own[j];
                if (circleNum[ci] != circleNum[cj]) continue;
                if (ci != cj && sizes[circleNum[ci]] == 2) {
                    curAns[Math.min(ci, cj)] = Math.max(d[i] + d[j] + Math.abs(num[cj] - num[ci]) + 1, curAns[Math.min(ci, cj)]);
                }
            }
        }
        int ans = Arrays.stream(curAns).sum();
        for (int i = 0; i < circCount; i++) {
            ans = Math.max(ans, sizes[i]);
        }
        out.println(ans);
    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 1; test <= tests; test++) {
            out.print("Case #" + test + ": ");
            System.out.println("test " + test);
            long start = System.currentTimeMillis();
            solveTest();
            System.out.println("passed in " + (System.currentTimeMillis() - start) + " ms");
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("C-large.in"));
            out = new PrintWriter(new File("C-large.out"));
            Locale.setDefault(Locale.US);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new C().run();
    }
}