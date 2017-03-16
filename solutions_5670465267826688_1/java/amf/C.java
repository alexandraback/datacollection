import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.concurrent.*;

import static java.lang.Math.abs;

public class C {
    static BufferedReader br;
    static StringTokenizer in;
    static PrintWriter out;

    static public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens())
            in = new StringTokenizer(br.readLine());
        return in.nextToken();
    }

    static public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    int n;
    long m;
    String s;
    int[][] quater;
    long usedBlocks;
    int oneline;

    int find_expected(int expected, int start) {
        int last = -1;
        int cur = 1;
        for (int block = 0; block < 4; block++) {
            for (int i = start; i < n; i++) {
                cur = multiply(cur, toInt(s.charAt(i)));
                if (cur == expected) {
                    last = i;
                    break;
                }
            }
            if (last != -1) {
                break;
            }
            start = 0;
            usedBlocks++;
        }
        return last;
    }

    String solve() {
        oneline = 1;
        for (int i = 0; i < s.length(); i++) {
            oneline = multiply(oneline, toInt(s.charAt(i)));
        }
        if (power(oneline, m) != -1) {
            return "NO";
        }

        usedBlocks = 1;
        int next = find_expected(2, 0);

        if (next == -1) {
            return "NO";
        }
        int start;
        if (next < n - 1) {
            start = next + 1;
        } else {
            start = 0;
            usedBlocks++;
        }
        next = find_expected(3, start);
        if (next == -1 || usedBlocks > m) {
            return "NO";
        }

        return "YES";
    }

    int sign(int a) {
        return (a < 0 ? -1 : 1);
    }

    int power(int n, long k) {
        if (k == 0) {
            return 1;
        } if (k % 2 == 1) {
            int tmp = power(n, k - 1);
            return multiply(tmp, n);
        }
        int tmp = power(n, k / 2);
        return multiply(tmp, tmp);
    }

    int toInt(char c) {
        if (c == 'i') {
            return 2;
        } else if (c == 'j') {
            return 3;
        } else {
            return 4;
        }

    }
    int multiply(int a, int b) {
        if (abs(a) == 1 || abs(b) == 1) {
            return a * b;
        }

        return quater[abs(a)-2][abs(b)-2] * sign(a) * sign(b);
    }

    void fill_quater() {
        quater = new int [3][3];
        quater[0][0] = -1; // i * i
        quater[0][1] = 4; // i * j
        quater[0][2] = -3; // i * k
        quater[1][0] = -4; // j * i
        quater[1][1] = -1; // j * j
        quater[1][2] = 2; // j * k
        quater[2][0] = 3; // k * i
        quater[2][1] = -2; // k * j
        quater[2][2] = -1; // k * k
    }

    public C() throws IOException {
        fill_quater();
        n = nextInt();
        m = nextLong();
        s = nextToken();
    }

    public static void main(String[] args) throws IOException, InterruptedException, ExecutionException {
        ExecutorService executor = Executors.newFixedThreadPool(4);
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int tests = nextInt();
        @SuppressWarnings("unchecked")
        Future<String>[] outputs = new Future[tests];
        for (int t = 0; t < tests; t++) {
            final C testCase = new C();
            outputs[t] = executor.submit(new Callable<String>() {
                @Override
                public String call() {
                    return testCase.solve();
                }
            });
        }
        for (int t = 0; t < tests; t++) {
            out.println("Case #" + (t + 1) + ": " + outputs[t].get());
        }
        out.close();
        executor.shutdown();
    }
}