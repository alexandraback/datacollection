import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class ProblemB {

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.UK);
        new ProblemB();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "B-small-attempt0";

    public ProblemB() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    private void solve() throws Exception {
        int T = nextInt();
        for (int ii = 0; ii < T; ++ii) {
            out.print("Case #" + (ii + 1) + ": ");
            int a = nextInt();
            int b = nextInt();
            int k = nextInt();
            long ans = 0;
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j) {
                    if ((i & j) < k) {
                        ans++;
                    }
                }
            }
            out.println(ans);
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
            