import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.concurrent.*;

public class A {
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

    static public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    int n;
    String s;


    String solve() {
        long ans = 0;
        long now = 0;
        for (int i = 0; i < s.length(); i++) {
            int cur = (int)(s.charAt(i) - '0');
            if (now < i) {
                ans += (i - now);
                now = i;
            }
            now += cur;
        }
        return String.valueOf(ans);
    }

    public A() throws IOException {
        n = nextInt();
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
            final A testCase = new A();
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