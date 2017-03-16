import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * User: Igor Kirov
 * Date: 12.05.13
 */
public class Pogo implements Runnable {
    private void solve() throws IOException {
        int x = nextInt();
        int y = nextInt();

        String xx;
        if (x < 0) {
            xx = "EW";
        } else {
            xx = "WE";
        }

        String yy;
        if (y < 0) {
            yy = "NS";
        } else {
            yy = "SN";
        }

        for (int i = 0; i < Math.abs(x); i++) {
            writer.print(xx);
        }
        for (int i = 0; i < Math.abs(y); i++) {
            writer.print(yy);
        }
        writer.println();
    }

    public static void main(String[] args) {
        new Thread(null, new Pogo(), "", 64 * 1024 * 1024).start();
    }

    StringTokenizer tokenizer;
    BufferedReader reader;
    PrintWriter writer;

    public void run() {
        try {
            try {
                Locale.setDefault(Locale.US);
            } catch (Exception ignored) {
            }

            reader = new BufferedReader(new FileReader("Pogo.in"));
            writer = new PrintWriter(new FileWriter("Pogo.out"));
            tokenizer = null;

            int tests = nextInt();
            for (int i = 0; i < tests; i++) {
                writer.printf("Case #%d: ", i + 1);
                solve();
                writer.flush();
            }

            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private BigInteger nextBigInteger() throws IOException {
        return new BigInteger(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}