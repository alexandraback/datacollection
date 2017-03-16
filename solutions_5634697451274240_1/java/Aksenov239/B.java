import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by vaksenov on 16.01.2016.
 */
public class B {
    public static void main(String[] args) {
        new B().run();
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
        char[] c = nextToken().toCharArray();
        int diff = 0;
        for (int i = 1; i < c.length; i++) {
            if (c[i] != c[i - 1]) {
                diff++;
            }
        }
        if (c[c.length - 1] == '-') {
            diff++;
        }

        out.println(diff);
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
