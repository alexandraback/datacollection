import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class ProblemC {

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.UK);
        new ProblemC();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "C-small-attempt0";

    public ProblemC() throws Exception {
        init();
        int T = nextInt();
        for (int ii = 0; ii < T; ++ii) {
            out.print("Case #" + (ii + 1) + ": ");
            solve();
        }
        in.close();
        out.close();
    }

    int[] zip;
    ArrayList<Integer>[] edges;
    int n, m;

    int[] heap;
    int size;
    int[] ans;

    boolean[][] ed;

    private void solve() throws Exception {
        n = nextInt();
        m = nextInt();
        zip = new int[n];
        for (int i = 0; i < n; ++i) {
            zip[i] = nextInt();
        }
        edges = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            edges[i] = new ArrayList<Integer>();
        }
        ed = new boolean[n][n];
        for (int i = 0; i < m; ++i) {
            int u = nextInt() - 1;
            int v = nextInt() - 1;
            edges[u].add(v);
            edges[v].add(u);
            ed[u][v] = ed[v][u] = true;
        }
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        ans = null;
        do {
            int[] stack = new int[n];
            stack[0] = p[0];
            int sz = 1;
            boolean flag = true;
            boolean better = false;
            if (ans != null && zip[p[0]] > ans[0]) {
                flag = false;
                continue;
            }
            if (ans == null || zip[p[0]] < ans[0]) {
                better = true;
            }
            for (int i = 1; i < n; ++i) {
                if (!better && ans != null && zip[p[i]] > ans[i]) {
                    flag = false;
                    break;
                }
                while (sz > 0 && !ed[stack[sz - 1]][p[i]]) {
                    sz--;
                }
                if (sz == 0) {
                    flag = false;
                    break;
                }
                stack[sz++] = p[i];
                if (!better && ans[i] > zip[p[i]]) {
                    better = true;
                }
            }
            if (flag) {
                if (ans == null) {
                    ans = new int[n];
                }
                for (int i = 0; i < n; ++i) {
                    ans[i] = zip[p[i]];
                }
            }
         } while (next_permutation(p));


//        int minidx = 0;
//        for (int i = 1; i < n; ++i) {
//            if (zip[minidx] > zip[i]) {
//                minidx = i;
//            }
//        }
//        heap = new int[n + 10];
//        size = 0;
//        add(i);
//        int[] cur = go();
//        if (ans == null) {
//            ans = cur;
//        } else if (cur != null) {
//            for (int j = 0; j < n; ++j) {
//                if (ans[j] > cur[j]) {
//                    ans = cur;
//                    break;
//                }
//            }
//        }
        for (int i = 0; i < n; ++i) {
            out.print(ans[i]);
        }
        out.println();
    }

    boolean next_permutation(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
            if (p[a] < p[a + 1])
                for (int b = p.length - 1;; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        return false;
    }

    private int[] go() {
        boolean[] was = new boolean[n];
        int[] cur = new int[n];
        int cnt = 0;
        while (size > 0) {
            int v = get();
            cur[cnt++] = zip[v];
            was[v] = true;
            for (Integer u : edges[v]) {
                if (!was[u]) {
                    add(u);
                    was[u] = true;
                }
            }
        }
        return cnt < n ? null : cur;
    }

    private void add(int v) {
        heap[size++] = v;
        siftUp(size - 1);
    }

    private int get() {
        int ret = heap[0];
        heap[0] = heap[--size];
        siftDown(0);
        return ret;
    }

    private void swap(int i, int j) {
        int t = heap[i];
        heap[i] = heap[j];
        heap[j] = t;
    }

    private void siftUp(int i) {
        if (i == 0) {
            return;
        }
        if (zip[heap[(i - 1) / 2]] > zip[heap[i]]) {
            swap((i - 1) / 2, i);
            siftUp((i - 1) / 2);
        }
    }

    private void siftDown(int i) {
        int j1 = i * 2 + 1;
        int j2 = i * 2 + 2;
        if (j1 >= size) {
            return;
        }
        int j = j2 >= size ? j1 : (zip[heap[j1]] < zip[heap[j2]] ? j1 : j2);
        if (zip[heap[j]] < zip[heap[i]]) {
            swap(i, j);
            siftDown(j);
        }
    }


    private void init() throws FileNotFoundException {
        if (fileName.equals("#Console")) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else if (fileName.equals("#IOtxt")) {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } else {
            in = new BufferedReader(new FileReader(fileName + ".in"));
            out = new PrintWriter(fileName + ".out");
        }
    }


    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }


    private String nextToken() throws IOException {
        while (!tok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            tok = new StringTokenizer(s);
        }
        return tok.nextToken();
    }

}
            