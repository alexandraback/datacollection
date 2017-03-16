import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

/**
 * Created by yujiahao on 4/15/16.
 */
public class gc_2016_1a_a {
    final String f = "A-small-attempt0";

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;

    void solve() throws IOException {
        String s = next();
        char[] arr = s.toCharArray();
        String res = arr[0]+"";

        for (int i=1; i<arr.length; i++){
            char cur = s.charAt(i);
            if (cur-res.charAt(0)<0){
                res = res+cur;
            }else{
                res = cur+res;
            }
        }

        out.println(res);
    }

    public void run() throws IOException {
        in = new BufferedReader(new FileReader(f + ".in"));
        out = new PrintWriter(f + ".out");

        eat("");

        int tests = nextInt();
        for (int test = 0; test < tests; ++test) {
            System.out.println("Test #" + (test + 1));
            out.print("Case #" + (test + 1) + ": ");
            solve();
        }

        in.close();
        out.close();
    }

    private void eat(String str) {
        st = new StringTokenizer(str);
    }

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new gc_2016_1a_a().run();
    }
}
