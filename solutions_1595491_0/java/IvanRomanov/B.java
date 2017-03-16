import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class B {

    private String solve(int n) throws IOException {
        int s = nextInt();
        int p = nextInt();
        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = nextInt();
        }
        int cool = 0;
        for (int x : t) {
            int rem3 = x % 3;
            int max = x / 3;
            if (rem3 > 0) {
                max++;
            }
            // no surprise
            if (max >= p) {
                cool++;
            } else if (s > 0) {
                // try surprise
                if (rem3 == 0 && x > 0) {
                    max++;
                } else if (rem3 == 2) {
                    max++;
                }
                if (max >= p) {
                    cool++;
                    s--;
                }
            }
        }
        return "" + cool;
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        String problem = "B-small-attempt0";
        reader = new BufferedReader(new FileReader(problem + ".in"));
        PrintWriter writer = new PrintWriter(new File(problem + ".out"));
        try {
            int cases = nextInt();
            int tc = 1;
            while (tc <= cases) {
                writer.print("Case #" + tc + ": ");
                int n = nextInt();
                writer.println(solve(n));
                tc++;
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new B().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}