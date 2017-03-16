import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new FileReader("b.in"));
        out = new PrintWriter("b.out");
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.print("Case #"+testCase+": ");
            solve();
        }
        out.close();
    }

    private static void solve() throws IOException {
        int n = nextInt();
        int x = nextInt(), y = nextInt();
        double answer = solve(n, x, y);
        out.println(answer);
    }

    private static double solve(int n, int x, int y) {
        if (n == 0) {
            return 0;
        }
        int h = 0;
        int sum = 1;
        while (true) {
            int nextSum = sum + 4 * h + 5;
            if (nextSum <= n) {
                h++;
                sum = nextSum;
            } else {
                break;
            }
        }
        x = Math.abs(x);
        if (x + y <= 2 * h) {
            return 1;
        }
        if (x + y > 2 * h + 2) {
            return 0;
        }
        int left = n - sum;
        if (left == 0) {
            return 0;
        }
        if (x == 0) {
            return 0;
        }
        double[] p = new double[2 * h + 3];
        p[0] = 1;
        double[] next = new double[2 * h + 3];
        int limitFall = 2 * h + 2;
        for (int fellAlready = 0; fellAlready < left; fellAlready++) {
            Arrays.fill(next, 0);
            for (int fellLeft = 0; fellLeft <= limitFall && fellLeft <= fellAlready; fellLeft++) {
                int fellRight = fellAlready - fellLeft;
                if (fellRight > limitFall) {
                    continue;
                }
                if (fellLeft < limitFall && fellRight < limitFall) {
                    next[fellLeft] += p[fellLeft] * 0.5;
                    next[fellLeft+1] += p[fellLeft] * 0.5;
                } else {
                    if (fellLeft == limitFall) {
                        next[fellLeft] += p[fellLeft];
                    } else {
                    if (fellRight == limitFall) {
                        next[fellLeft + 1] += p[fellLeft];
                    }
                    }
                }
            }
            double[] tmp = next;
            next = p;
            p = tmp;
        }
        double ret = 0;
        for (int i = y + 1; i < p.length; i++) {
            ret += p[i];
        }
        return ret;


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
