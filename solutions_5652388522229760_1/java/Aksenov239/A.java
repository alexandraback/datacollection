import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by vaksenov on 16.01.2016.
 */
public class A {
    public static void main(String[] args) {
        new A().run();
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public void solve() throws IOException {
        int n = nextInt();
        if (n == 0) {
            out.println("INSOMNIA");
            return;
        }
        boolean[] seen = new boolean[10];
        int x = n;
        int t = 0;
        int total = 0;
        while (total < 10) {
            int xx = x;
            while (xx > 0) {
                int digit = xx % 10;
                if (!seen[digit]) {
                    total++;
                    seen[digit] = true;
                }
                xx /= 10;
            }

            x += n;
            t++;
        }
        out.println(x - n);
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int t = nextInt();
            for (int i = 0; i < t; i++) {
                out.print("Case #" + (i + 1) + ": ");
                solve();
                System.err.println("Finished " + (i + 1) + " test");
            }

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
