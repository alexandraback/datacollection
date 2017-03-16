import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new FileReader("a.in"));
        out = new PrintWriter("a.out");
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.print("Case #"+testCase+": ");
            solve();
        }
        out.close();
    }

    private static void solve() throws IOException {
        long us = nextInt();
        int n = nextInt();
        long[] others = new long[n];
        for (int i = 0; i < n; i++) {
            others[i] = nextInt();
        }
        Arrays.sort(others);
        int bestAnswer = n;
        int alreadySpent = 0;
        if (us > 1) for (int eat = 1; eat <= n; eat++) {
            while (us <= others[eat-1]) {
                alreadySpent++;
                us += us - 1;
            }
            us += others[eat-1];
            int curAnswer = alreadySpent + n - eat;
            if (bestAnswer > curAnswer) {
                bestAnswer = curAnswer;
            }
        }
        out.println(bestAnswer);
    }

    static StringTokenizer st;
    static BufferedReader br;
    static PrintWriter out;

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }


}
