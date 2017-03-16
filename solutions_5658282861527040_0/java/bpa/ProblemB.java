import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class ProblemB implements Runnable {

    void solveMultiTest() throws IOException {
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.println("Case #" + testCase + ": " + solveOneTest());
        }
    }

    String solveOneTest() throws IOException {
        int a = nextInt();
        int b = nextInt();
        int k = nextInt();
        int ans = 0;
        for (int x = 0; x < a; x++)
            for (int y = 0; y < b; y++)
                if ((x & y) < k)
                    ans++;
        return ans + "";
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
        new Thread(new ProblemB()).run();
    }
}