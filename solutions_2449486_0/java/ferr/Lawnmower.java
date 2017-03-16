import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

/**
 * @author Roman Nefyodov
 */
public class Lawnmower implements Runnable {

    public void solveCase(int caseNumber) throws IOException{
        int n = nextInt(), m = nextInt();
        int[][] arr = new int[n][m];
        Set<Integer> numbers = new TreeSet<Integer>();
        numbers.add(100);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                arr[i][j] = nextInt();
                numbers.add(arr[i][j]);
            }
        Integer[] hs = numbers.toArray(new Integer[0]);
        all:for (int id = 0; id + 1 < hs.length; ++id) {
            int h = hs[id];
            int nexth = hs[id + 1];
            boolean[] rows = new boolean[n];
            for (int i = 0; i < n; ++i) {
                int qh = 0;
                for (int j = 0; j < m; ++j)
                    qh += arr[i][j] == h ? 1 : 0;
                rows[i] = qh == m;
            }

            boolean[] columns = new boolean[m];
            for (int j = 0; j < m; ++j) {
                int qh = 0;
                for (int i = 0; i < n; ++i) {
                    qh += arr[i][j] == h ? 1 : 0;
                }
                columns[j] = qh == n;
            }
            for (int i = 0; i < n; ++i)
                if (rows[i])
                    for (int j = 0; j < m; ++j)
                        arr[i][j] = nexth;

            for (int j = 0; j < m; ++j)
                if (columns[j])
                    for (int i = 0; i < n; ++i)
                        arr[i][j] = nexth;

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (arr[i][j] == h) break all;
        }
        boolean ans = true;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans &= arr[i][j] == 100;
        pw.printf("Case #%d: ", caseNumber);
        pw.print(ans ? "YES" : "NO");
        pw.println();
    }

    public void solve() throws IOException {
        int T = nextInt();
        for (int i = 0; i < T; ++i) {
            solveCase(i + 1);
        }
    }

    public static void main(String[] args) {
        new Lawnmower().run();
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
