import java.util.*;
import java.io.*;

public class B {
    FastScanner in;
    PrintWriter out;

    public void solveTest() throws IOException {
        char[] s = in.next().toCharArray();
        int first = 0;
        int ans = 0;
        for (int i = 0; i < s.length; i++) {
            if (s[i] != s[first]) {
                ans++;
                first = i;
            }
        }
        if (s[first] == '-') {
            ans++;
        }
        out.println(ans);
    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            out.print("Case #" + (test + 1) + ": ");
            System.out.println("test " + (test + 1));
            solveTest();
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-small-attempt0.in"));
            out = new PrintWriter(new File("B-small-attempt0.out"));
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
        new B().run();
    }
}