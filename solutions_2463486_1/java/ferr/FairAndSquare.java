import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * @author Roman Nefyodov
 */
public class FairAndSquare implements Runnable {

    int MAXN = 10000005;

    boolean[] isFS = new boolean[MAXN];

    int[] tmp = new int[30];

    boolean checkPalindrome(long t) {
        int id = 0;
        while (t > 0) {
            tmp[id++] = (int) (t % 10);
            t /= 10;
        }
        for (int i = 0, j = id - 1; i < j; i++,j--)
            if (tmp[i] != tmp[j])
                return false;
        return true;
    }

    int[] countTo = new int[MAXN];

    List<Long> cands = new ArrayList<Long>();

    void precalc() {
        for (int i = 1; i < MAXN; ++i) if (checkPalindrome(i)) {
            long sq = 1L * i * i;
            isFS[i] = checkPalindrome(sq);
        }
        for (int i = 1; i < MAXN; ++i) {
            countTo[i] = countTo[i - 1] + (isFS[i] ? 1 : 0);
        }
        for (int i = 1; i < MAXN; ++i) {
            if (isFS[i])
                cands.add(1L * i * i);
        }
    }

    public void solveCase(int caseNumber) throws IOException{
        long a = Long.parseLong(next()), b = Long.parseLong(next());

        // now a1^2 >= a
        int ans = 0;
        for (long c : cands) {
            if (a <= c && c <= b)
                ans++;
        }

        pw.printf("Case #%d: ", caseNumber);
        pw.print(ans);
        pw.println();
    }

    public void solve() throws IOException {
        precalc();
        int T = nextInt();
        for (int i = 0; i < T; ++i) {
            solveCase(i + 1);
        }
    }

    public static void main(String[] args) {
        new FairAndSquare().run();
    }

    static final String filename = "A";
    static final boolean fromConsole = true;

    public void run() {
        try {
            if (!fromConsole) {
                in = new BufferedReader(new FileReader(filename + ".in"));
                pw = new PrintWriter(filename + ".out");
            } else {
                in = new BufferedReader(new InputStreamReader(System.in));
                pw = new PrintWriter(System.out);
            }
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

    boolean hasNext() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return false;
            }
            st = new StringTokenizer(line);
        }
        return st.hasMoreTokens();
    }

    String next() throws IOException {
        return hasNext() ? st.nextToken() : null;
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
}
