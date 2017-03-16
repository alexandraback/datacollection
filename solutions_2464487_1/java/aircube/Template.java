import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

/**
 * Created with IntelliJ IDEA.
 * User: 1
 * Date: 25.02.13
 * Time: 3:21
 * To change this template use File | Settings | File Templates.
 */
public class Template {
    private StringTokenizer tokenizer;
    private BufferedReader reader;
    private PrintWriter writer;

    public static void main(String[] args) throws IOException {
        new Template().run();
    }




    private void run() throws IOException {
//        reader = new BufferedReader(new InputStreamReader(System.in));
//        writer = new PrintWriter(System.out);
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter("output.txt");
        solve();
        writer.flush();
    }

    private void solve() throws IOException {
        int tc = nextInt();
        for (int i = 1; i <= tc; ++i) {
            BigInteger R = BigInteger.valueOf(nextLong());
            BigInteger t = BigInteger.valueOf(nextLong());
            long l = 1, r = (long)1e18, res = 0;
            while (l <= r) {
                long m = (l+r) / 2;
                BigInteger tot = BigInteger.valueOf(2).multiply(R).multiply(BigInteger.valueOf(m)).add(BigInteger.valueOf(1 + 2 * (m-1)).multiply(BigInteger.valueOf(m)));
                if (tot.compareTo(t) <= 0) {
                    res = Math.max(res, m);
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            writer.print("Case #" + Integer.toString(i) + ": " + Long.toString(res) + "\n");
        }
    }



    private int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    private double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
    private long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    private String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine()) ;
        }
        return tokenizer.nextToken();
    }
}