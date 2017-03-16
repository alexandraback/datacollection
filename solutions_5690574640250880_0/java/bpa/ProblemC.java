import java.io.*;
import java.util.*;

public class ProblemC implements Runnable {

    void solveMultiTest() throws IOException {
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.print("Case #" + testCase + ":\n" + solveOneTest());
        }
    }

    String solveOneTest() throws IOException {
        int r = nextInt();
        int c = nextInt();
        int m = nextInt();
        int size = r * c;

        if (size - m == 1)
            return simpleAns(r, c, m);
        if (r == 1 || c == 1) {
            return simpleAns(r, c, m);
        }
        if (r == 2 || c == 2) {
            if (size - m < 4 || m % 2 == 1)
                return "Impossible\n";
            if (c == 2)
                return simpleAns(r, c, m);
            else
                return simpleAns(1, c, m / 2).replace('c', '.') + simpleAns(1, c, m / 2);
        }
        if (m <= size - 2 * c && (m + 1) % c != 0)
            return simpleAns(r, c, m);
        if (m <= size - 3 * c && (m + 1) % c == 0)
            return simpleAns((m + 1) / c, c, m - 1).replace('c', '.') + simpleAns(r - (m + 1) / c, c, 1);
        if (size - m > 7) {
            String ans = simpleAns(r - 3, c, (r - 3) * c).replace('c', '*');
            m -= (r - 3) * c;
            r = 3;
            if (m <= c - 2)
                return ans + simpleAns(r, c, m);
            if (m % 2 == c % 2) {
                ans += simpleAns(1, c, c - 2).replace('c', '.');
                m -= c - 2;
            } else {
                ans += simpleAns(1, c, c - 3).replace('c', '.');
                m -= c - 3;
            }
            ans += simpleAns(1, c, m / 2).replace('c', '.');
            ans += simpleAns(1, c, m / 2);
            return ans;
        }
        if ((size - m) == 4 || (size - m) == 6) {
            String ans = simpleAns(r - 2, c, (r - 2) * c).replace('c', '*');
            m -= (r - 2) * c;
            ans += simpleAns(1, c, m / 2).replace('c', '.');
            ans += simpleAns(1, c, m / 2);
            return ans;
        }
        return "Impossible\n";
    }

    String simpleAns(int r, int c, int m) {
        String ans = "";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == r - 1 && j == c - 1)
                    ans += 'c';
                else {
                    if (m-- > 0)
                        ans += '*';
                    else
                        ans += '.';
                }
            }
            ans += '\n';
        }
        return ans;
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public void run() {
        try {
            InputStream input = System.in;
            PrintStream output = System.out;
            File file = new File("c.in");
            if (file.exists() && file.canRead()) {
                input = new FileInputStream(file);
                output = new PrintStream(new File("c.out"));
            }
            br = new BufferedReader(new InputStreamReader(input));
            out = new PrintWriter(output);
            solveMultiTest();
            out.close();
        } catch (IOException e) {
        }
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public static void main(String[] args) {
        new Thread(new ProblemC()).run();
    }
}