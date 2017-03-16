import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.time.Duration;
import java.time.LocalTime;
import java.util.StringTokenizer;

/**
 * @author Roman Nefyodov
 */
public class B {

    public void solveCase() {
        int A = nextInt(), B = nextInt(), K = nextInt();
        int ans = 0;
        for (int i = 0; i < A; ++i)
            for (int j = 0; j < B; ++j) {
                if ((i & j) < K)
                    ans++;
            }
        pw.print(ans);
    }

    public void solve() {
        int T = nextInt();
        for (int i = 0; i < T; ++i) {
            pw.printf("Case #%d: ", i + 1);
            LocalTime start = LocalTime.now();
            pwerr.printf("Case %d started..\n", i + 1);
            pwerr.flush();
            solveCase();
            Duration duration = Duration.between(start, LocalTime.now());
            pwerr.printf("Case %d finished (%ds)..\n", i + 1, duration.getSeconds());
            pwerr.flush();
            pw.print('\n');
            pw.flush();
        }
    }

    public static void main(String[] args) {
        new B().run(args);
    }

    public void run(String[] args) {
        try {
            if (args.length == 1) {
                String filename = args[0];
                in = new BufferedReader(new FileReader(filename + ".in.txt"));
                pw = new PrintWriter(filename + ".out.txt");
            } else {
                in = new BufferedReader(new InputStreamReader(System.in));
                pw = new PrintWriter(System.out);
            }
            pwerr = new PrintWriter(System.err);
            st = new StringTokenizer("");
            solve();
            pw.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    private StringTokenizer st;
    private BufferedReader in;
    private PrintWriter pw;
    private PrintWriter pwerr;

    int curCase;

    boolean hasNext() {
        try {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null)
                    return false;
                st = new StringTokenizer(line);
            }
            return st.hasMoreTokens();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    String next() {
        return hasNext() ? st.nextToken() : null;
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }
}

