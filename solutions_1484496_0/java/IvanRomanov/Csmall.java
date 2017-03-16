import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class Csmall {

    private String solve() throws IOException {
        int n = nextInt();
        int[] s = new int[n];
        long cnt = 1;
        for (int i = 0; i < n; i++) {
            s[i] = nextInt();
            cnt *= 3;
        }
        for (long opt = 1; opt < cnt; opt++) {
            int sum1 = 0;
            int sum2 = 0;
            long mask = opt;
            for (int i = 0; i < n; i++) {
                long choice = mask % 3;
                mask /= 3;
                if (choice == 1){
                    sum1 += s[i];
                } else if (choice == 2) {
                    sum2 += s[i];
                }
            }
            if (sum1 == sum2) {
                StringBuilder sb = new StringBuilder();
                print(s, sb, opt, 1);
                print(s, sb, opt, 2);
                return sb.toString();
            }
        }
        return "\nImpossible";
    }

    private void print(int[] s, StringBuilder sb, long opt, int choice) {
        boolean first = true;
        for (int value : s) {
            if (opt % 3 == choice) {
                if (first) {
                    sb.append('\n');
                    first = false;
                } else {
                    sb.append(' ');
                }
                sb.append(value);
            }
            opt /= 3;
        }
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
        String problem = "C-small-attempt0";
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
            new Csmall().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}