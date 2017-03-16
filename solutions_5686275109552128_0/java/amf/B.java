import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.concurrent.*;

public class B {
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
    int b[];

    boolean check (int time) {
        int[] a = Arrays.copyOf(b, b.length);
        int[] count = new int[n];
        Arrays.fill(count, 0);

        while (time > 0) {
            int index = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] > time) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                return true;
            } else {
                for (int i = 0; i < n; i++) {
                    a[i] += count[i];
                }
                time--;
                a[index] -= time;
                count[index]++;
            }
        }
        return false;
    }

    String solve() {
        int l = -1;
        int r = 10;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (check(m)) {
                r = m;
            } else {
                l = m;
            }
        }
        return String.valueOf(r);
    }

    public B() throws IOException {
        n = nextInt();
        b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = nextInt();
        }
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
            final B testCase = new B();
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