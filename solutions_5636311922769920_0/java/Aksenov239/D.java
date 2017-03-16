import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by vaksenov on 16.01.2016.
 */
public class D {
    public static void main(String[] args) {
        new D().run();
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
        int k = nextInt();
        int c = nextInt();
        int s = nextInt();
        if (k != s) {
            out.println("IMPOSSIBLE");
            return;
        }
        for (int i = 0; i < k; i++) {
            out.print((i + 1) + " ");
        }
        out.println();
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
