import java.io.*;
import java.util.*;

public class C {

    MyScanner in;
    PrintWriter out;
    final static String FILENAME = "c";

    public static void main(String[] args) throws Exception {
        new C().run();
    }

    public void run() throws Exception {
        in = new MyScanner(FILENAME + ".in");
        out = new PrintWriter(FILENAME + ".out");

        int tests = in.nextInt();
        out.println("Case #1:");
        solve();

        out.close();
    }

    int n, m, r, k;
    int[] prod;
    int[] set;
    int[] ans;
    
    public void solve() throws Exception {
        r = in.nextInt();
        n = in.nextInt();
        m = in.nextInt();
        k = in.nextInt();
        for (int i = 0; i < r; i++) {
            prod = new int[k];
            set = new int[n];
            ans = new int[n];
            for (int j = 0; j < k; j++) {
                prod[j] = in.nextInt();
            }
            sets(0);
            for (int j = 0; j < n; j++) {
                out.print(ans[j]);
            }
            out.println();
        }
    }

    List<Integer> factorize(int n) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for (int i = 2; i <= m; i++) {
            while (n % i == 0) {
                ans.add(i);
                n /= i;
            }
        }
        return ans;
    }
    
    int[] pf;
    void genprod2s(int depth) {
        if (depth >= n) {
            int ans = 1;
            for (int pr : pf) {
                ans *= pr;
            }
            prod2s.add(ans);
        } else {
            pf[depth] = 1;
            genprod2s(depth + 1);
            pf[depth] = set[depth];
            genprod2s(depth + 1);
        }
    }
    
    List<Integer> prod2s;
    void check() {
        int pset = 1;
        pf = new int[n];
        prod2s = new ArrayList<Integer>();
        genprod2s(0);
        for (int i = 0; i < k; i++) {
            List<Integer> pr = factorize(prod[i]);
            int pprod = 1;
            List<Integer> sset = new ArrayList<Integer>();
            for (int d : set) {
                sset.add(d);
            }
            for (int p : pr) {
                if (p != 2) {
                    if (!sset.contains(p)) {
                        return;
                    } else {
                        sset.remove((Object) p);
                    }
                } else {
                    pprod *= p;
                }
            }
            if (!prod2s.contains(pprod)) {
                return;
            }
        }
        for (int i = 0; i < n; i++) {
            ans[i] = set[i];
        }
    }
    
    void sets(int depth) {
        if (depth >= n) {
            check();
        } else {
            for (int c = 2; c <= m; c++) {
                set[depth] = c;
                sets(depth + 1);
            }
        }
    }
    
    class MyScanner {

        BufferedReader br;
        StringTokenizer st;

        public MyScanner(String file) throws Exception {
            br = new BufferedReader(new FileReader(file));
        }

        String next() throws Exception {
            while ((st == null) || (!st.hasMoreTokens())) {
                String t = br.readLine();
                if (t == null) {
                    return null;
                }
                st = new StringTokenizer(t);
            }
            return st.nextToken();
        }

        int nextInt() throws Exception {
            return Integer.parseInt(next());
        }

        double nextDouble() throws Exception {
            return Double.parseDouble(next());
        }

        boolean nextBoolean() throws Exception {
            return Boolean.parseBoolean(next());
        }

        long nextLong() throws Exception {
            return Long.parseLong(next());
        }
    }
}
