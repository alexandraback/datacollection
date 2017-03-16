import java.lang.reflect.Array;
import java.util.*;
import java.io.*;

public class CStupid {
    FastScanner in;
    PrintWriter out;
    int[] next;
    int ans;

    void gen(int[] a, int pos, boolean[] used) {
        if (pos == a.length) {

            for (int cnt = 1; cnt <= a.length; cnt++) {
                boolean ok = true;
                for (int i = 0; i < cnt; i++) {
                    int n1 = i == 0 ? a[cnt - 1] : a[i - 1];
                    int n2 = i == cnt - 1 ? a[0] : a[i + 1];
                    if (next[a[i]] != n1 && next[a[i]] != n2) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans = Math.max(ans, cnt);
                }
            }
        } else {
            for (int i = 0; i < a.length; i++) {
                if (!used[i]) {
                    a[pos] = i;
                    used[i] = true;
                    gen(a, pos + 1, used);
                    used[i] = false;
                    a[pos] = 0;
                }
            }
        }
    }

    public void solveTest() throws IOException {
        int n = in.nextInt();
        next = new int[n];
        Arrays.setAll(next, i -> in.nextInt() - 1);
        ans = 0;
        gen(new int[n], 0, new boolean[n]);
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
            in = new FastScanner(new File("C-small-attempt2.in"));
            out = new PrintWriter(new File("C-small-attempt2.out"));
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
        new CStupid().run();
    }
}