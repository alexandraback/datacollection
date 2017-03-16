import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

    public static final int M = 1000000007;
    private static final int MAX = 11111;

    boolean[] edge;
    int[][] ng;

    public void run() {
        long startTime = System.nanoTime();

        int cases = nextInt();
        for (int tc = 1; tc <= cases; tc++) {

            int n = nextInt();
            int m = nextInt();
            int k = nextInt();
            int s = n * m;
            edge = new boolean[s];
            for (int i = 0; i < n; i++) {
                edge[i * m] = edge[i * m + m - 1] = true;
            }
            for (int i = 0; i < m; i++) {
                edge[i] = edge[s - m + i] = true;
            }
            ng = new int[s][];
            int[] W = new int[4];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int z = 0;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int ii = i + di, jj = j + dj;
                            if (di * di + dj * dj == 1 && 0 <= ii && ii < n && 0 <= jj && jj < m) {
                                W[z++] = ii * m + jj;
                            }
                        }
                    }
                    ng[i * m + j] = Arrays.copyOf(W, z);
                }
            }

            int res = n == 1 || m == 1 ? k : Math.min(k, 2 * (n + m - 2));
            M:
            for (int msk = 0; msk < 1 << s; msk++) {
                if (Integer.bitCount(msk) >= res) {
                    continue;
                }
                int t = 0;
                for (int i = 0; i < s; i++) {
                    if (enc(i, msk) && ++t == k) {
                        res = Integer.bitCount(msk);
                        continue M;
                    }
                }
            }

            printf("case #%d: %s\n", tc, res);

        }


        if (fileIOMode) {
            System.out.println((System.nanoTime() - startTime) / 1e9);
        }
        out.close();
    }

    private boolean enc(int i, int msk) {
        if ((msk & 1 << i) != 0) {
            return true;
        }
        if (edge[i]) {
            return false;
        }
        msk |= 1 << i;
        for (int j : ng[i]) {
            if (!enc(j, msk)) {
                return false;
            }
        }
        return true;
    }

    public void runn() {
        long startTime = System.nanoTime();

        int cases = nextInt();
        for (int tc = 1; tc <= cases; tc++) {

            int n = nextInt();
            int[] p = new int[n];
            char[][] s = new char[n][];
            int[] c = new int[26];
            int[] min = new int[26];
            int[] max = new int[26];
            int[][] mmn = new int[n][26];
            int[][] mmx = new int[n][26];
            for (int i = 0; i < n; i++) {
                p[i] = i;
                s[i] = nextToken().toCharArray();
                Arrays.fill(mmn[i], MAX);
                for (int j = 0; j < s[i].length; j++) {
                    c[s[i][j] -= 'a']++;
                    char g = s[i][j];
                    mmn[i][g] = Math.min(mmn[i][g], j);
                    mmx[i][g] = Math.max(mmx[i][g], j);
                }
            }
            int res = 0;
            M:
            do {

                Arrays.fill(min, MAX);
                Arrays.fill(max, 0);
                int off = 0;
                for (int t = 0; t < n; t++) {
                    int i = p[t];
                    int[] a = mmn[i];
                    int[] b = mmx[i];
                    for (int j = 0; j < 26; j++) {
                        if (a[j] != MAX) {
                            min[j] = Math.min(min[j], off + a[j]);
                            max[j] = Math.max(max[j], off + b[j]);
                        }
                    }
                    off += s[i].length;
                }
                for (int i = 0; i < 26; i++) {
                    if (c[i] > 0 && max[i] - min[i] + 1 != c[i]) {
                        continue M;
                    }
                }
                res++;

            } while (nextPermutation(p));
            printf("case #%d: %s\n", tc, res);

        }


        if (fileIOMode) {
            System.out.println((System.nanoTime() - startTime) / 1e9);
        }
        out.close();
    }

    public static boolean nextPermutation(int[] a) {
        if (a.length <= 1) {
            return false;
        }
        int next = a.length - 1;
        while (true) {
            int next1 = next;
            if (a[--next] < a[next1]) {
                int middle = a.length;
                while (a[--middle] < a[next]) ;
                swap(a, next, middle);
                reverse(a, next1, a.length);
                return (true);
            }
            if (next == 0) {
                reverse(a, 0, a.length);
                return false;
            }
        }
    }

    private static void reverse(int[] a, int first, int last) {
        while (first != last && first != --last) {
            swap(a, first++, last);
        }
    }

    private static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    //-----------------------------------------------------------------------------------

    private static boolean fileIOMode;
    private static String problemName = "a";
    private static BufferedReader in;
    private static PrintWriter out;
    private static StringTokenizer tokenizer;

    public static void main(String[] args) throws Exception {
        fileIOMode = args.length > 0 && args[0].equals("!");
        if (fileIOMode) {
            in = new BufferedReader(new FileReader(problemName + ".in"));
            out = new PrintWriter(problemName + ".out");
        } else {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }
        tokenizer = new StringTokenizer("");

        new Thread(new A()).start();
    }

    private static String nextLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    private static String nextToken() {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    private static int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private static long nextLong() {
        return Long.parseLong(nextToken());
    }

    private static double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    private static BigInteger nextBigInteger() {
        return new BigInteger(nextToken());
    }

    private static void print(Object o) {
        if (fileIOMode) {
            System.out.print(o);
        }
        out.print(o);
    }

    private static void println(Object o) {
        if (fileIOMode) {
            System.out.println(o);
        }
        out.println(o);
    }

    private static void printf(String s, Object... o) {
        if (fileIOMode) {
            System.out.printf(s, o);
        }
        out.printf(s, o);
    }
}
