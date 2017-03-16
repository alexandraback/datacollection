import java.io.*;
import java.util.*;


public class Solution {
    private BufferedReader in;
    private StringTokenizer line;
    private PrintWriter out;

    private static final int mm = 1000000007;

    private ArrayList<Integer>[] g;
    private boolean[] b;


    private int get_max_level(int v) {
        int res = 0;
        for (Integer i : g[v]) {
            if (!b[i]) {
                res = Math.max(res, get_max_level(i));
            }
        }
        return res + 1;
    }

    public void solve() throws IOException {
        int n = nextInt();
        int[] a = nextIntArray(n);
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            a[i]--;
            g[a[i]].add(i);
        }
        int res = 0;
        int[] d = new int[n];
        {
            for (int i = 0; i < n; i++) {
                b = new boolean[n];
                int cnt = 1;
                d[cnt - 1] = i;
                b[i] = true;
                while (true) {
                    int nxt = a[d[cnt - 1]];
                    if (b[nxt]) break;
                    d[cnt] = nxt;
                    cnt++;
                    b[nxt] = true;
                }
                if (d[0] == a[d[cnt - 1]]) {
                    res = Math.max(res, cnt);
                }
            }
        }
        {
            int rs = 0;
            b = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (!b[i] && a[a[i]] == i){
                    b[i] = true;
                    b[a[i]] = true;
                    rs += 2;
                    {
                        int tmp_max = 0;
                        for (Integer j : g[i]) {
                            if (!b[j]) {
                                tmp_max = Math.max(tmp_max, get_max_level(j));
                            }
                        }
                        rs += tmp_max;
                    }
                    {
                        int tmp_max = 0;
                        for (Integer j : g[a[i]]) {
                            if (!b[j]) {
                                tmp_max = Math.max(tmp_max, get_max_level(j));
                            }
                        }
                        rs += tmp_max;
                    }
                }
            }
            res = Math.max(res, rs);
        }
        out.println(res);
    }

    public static void main(String[] args) throws IOException {
        new Solution().run(args);
    }

    public void run(String[] args) throws IOException {
        if (args.length > 0 && "DEBUG_MODE".equals(args[0])) {
            in = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
        } else {
            in = new BufferedReader(new InputStreamReader(System.in));
        }
//        out = new PrintWriter(System.out);
        out = new PrintWriter("output.txt");

        int t = nextInt();
//        int t = 1;
        for (int i = 0; i < t; i++) {
            out.print("Case #" + (i + 1) + ": ");
            solve();
        }

        in.close();
        out.flush();
        out.close();
    }

    private int[] nextIntArray(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    private long[] nextLongArray(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private String nextToken() throws IOException {
        while (line == null || !line.hasMoreTokens()) {
            line = new StringTokenizer(in.readLine());
        }
        return line.nextToken();
    }

    private static class Pii {
        private int key;
        private int value;

        public Pii(int key, int value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pii pii = (Pii) o;

            if (key != pii.key) return false;
            return value == pii.value;

        }

        @Override
        public int hashCode() {
            int result = key;
            result = 31 * result + value;
            return result;
        }
    }

    private static class Pair<K, V> {
        private K key;
        private V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair<?, ?> pair = (Pair<?, ?>) o;

            if (key != null ? !key.equals(pair.key) : pair.key != null) return false;
            return !(value != null ? !value.equals(pair.value) : pair.value != null);

        }

        @Override
        public int hashCode() {
            int result = key != null ? key.hashCode() : 0;
            result = 31 * result + (value != null ? value.hashCode() : 0);
            return result;
        }
    }
}