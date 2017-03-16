import java.io.*;
import java.util.*;

public class B {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    void solve() throws IOException {
        int n = in.nextInt();
        double[] a = new double[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextDouble();
        double[] b = new double[n];
        for (int i = 0; i < n; i++)
            b[i] = in.nextDouble();
        Arrays.sort(a);
        Arrays.sort(b);
        boolean[] used = new boolean[n];
        int scoreWar = 0;
        for (int i = 0; i < n; i++) {
            boolean f = false;
            for (int j = 0; j < n; j++)
                if (!used[j] && b[j] > a[i]) {
                    used[j] = true;
                    f = true;
                    break;
                }
            if (!f)
                scoreWar++;
        }

        int scoreWar2 = 0;
        Arrays.fill(used, false);
        for (int i = 0; i < n; i++) {
            boolean f = false;
            for (int j = 0; j < n; j++)
                if (!used[j] && a[j] > b[i]) {
                    used[j] = true;
                    f = true;
                    break;
                }
            if (f)
                scoreWar2++;
        }
        out.println(scoreWar2 + " " + scoreWar);
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("B.in"));
            out = new PrintWriter(new File("B.out"));

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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }
}