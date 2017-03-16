import java.io.*;
import java.util.*;

public class ProblemC implements Runnable {

    void solveMultiTest() throws IOException {
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.println("Case #" + testCase + ": " + solveOneTest());
        }
    }

    String solveOneTest() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] a = new int[1000001];
        Arrays.fill(a, 1000000000);
        for (int i = 2; i < n; i++)
            for (int j = 2; j < m; j++) {
                int min = (i - 1) * 2 + (j - 1) * 2;
                int x = (i + 1) * (j + 1) - 4;
                if (min < a[x])
                    a[x] = min;
            }
        for (int i = 2; i < n * m; i++) {
            if (a[i] <= n * m) {
                a[i - 2] = minim(a[i] - 1, a[i - 2]);
            }
        }
        for (int i = n * m; i > 0; i--)
            if (a[i - 1] > a[i])
                a[i - 1] = a[i];
        a[1] = 1;
        for (int i = 1; i <= n * m; i++)
            if (a[i - 1] + 1 < a[i])
                a[i] = a[i - 1] + 1;
        int k = nextInt();
        return a[k] + "";
    }

    int minim(int a, int b) {
        return a < b ? a : b;
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public void run() {
        try {
            InputStream input = System.in;
            PrintStream output = System.out;
            File file = new File("a.in");
            if (file.exists() && file.canRead()) {
                input = new FileInputStream(file);
                output = new PrintStream(new File("a.out"));
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