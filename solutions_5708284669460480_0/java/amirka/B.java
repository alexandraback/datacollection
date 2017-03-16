import java.util.*;
import java.io.*;

public class B {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = false;

    int k, l, s;
    String s1, s2;
    long max;

    long ttt(String res) {
        long ans = 0;
        for (int i = 0; i < s - l + 1; i++) {
            if (res.substring(i, i + l).equals(s2)) {
                ans++;
            }
        }
        return ans;
    }

    long count(String res) {
        if (res.length() == s) {
            long k = ttt(res);
            max = Math.max(max, k);
            return k;
        }
        long ans = 0;
        for (int i = 0; i < k; i++) {
            ans += count(res + s1.charAt(i));
        }
        return ans;
    }


    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            k = in.nextInt();
            l = in.nextInt();
            s = in.nextInt();
            s1 = in.next();
            s2 = in.next();
            max = 0;
            double ans = count("");
            ans = max - ans / Math.pow(k, s);
            out.print("Case #" + (test + 1) + ": ");
            out.println(ans);
        }
    }

    public void run() {
        try {
            if (systemIO) {
                in = new FastScanner(System.in);
                out = new PrintWriter(System.out);
            } else {
                in = new FastScanner(new File("a.in"));
                out = new PrintWriter(new File("a.out"));
            }
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

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                return null;
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

        long nextLong() {
            return Long.parseLong(next());
        }

    }

    public static void main(String[] arg) {
        new B().run();
    }
}