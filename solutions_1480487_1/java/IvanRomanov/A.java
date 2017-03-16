import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class A {

    private String solve() throws IOException {
        int n = nextInt();
        int[] s = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            s[i] = nextInt();
            sum += s[i];
        }
        double[] x = new double[n];
        for (int i = 0; i < n; i++) {
//            int score = s[i];
//            x[i] = (sum - score) / (score * (n - 2) + sum);


            double min = 0.0;
            double max = 1.0;

            for (int it = 0; it < 50; it++) {
                double teil = (min + max) * 0.5;
                double score = s[i] + sum * teil;
                double rest = 1.0 - teil;
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        if (s[j] < score) {
                            double spend = (score - s[j]) / sum;
                            rest -= spend;
                        }
                    }
                }
                if (rest > 0) {
                    min = teil;
                } else {
                    max = teil;
                }
            }
            x[i] = (min + max) * 50;
        }
        StringBuilder sb = new StringBuilder();
        for (double z : x) {
            sb.append(' ');
            sb.append(String.format("%.6f", z));
        }
        return sb.toString();
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
        Locale.setDefault(Locale.US);
        String problem = "A-large";
        reader = new BufferedReader(new FileReader(problem + ".in"));
        PrintWriter writer = new PrintWriter(new File(problem + ".out"));
        try {
            int n = nextInt();
            for (int tc = 1; tc <= n; tc++) {
                writer.print("Case #" + tc + ": ");
                writer.println(solve());
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new A().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}