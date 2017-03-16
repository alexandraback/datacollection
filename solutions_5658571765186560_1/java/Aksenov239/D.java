import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

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

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public void solve() throws IOException {
        int x = nextInt();
        int r = nextInt();
        int c = nextInt();
        int n = Math.min(r, c);
        int m = Math.max(r, c);

        int l = (x + 1) / 2;

        if (x >= 7 || m < x || n < l || (r * c) % x != 0) {
            out.println("RICHARD");
            return;
        }

        if (n > l) {
            out.println("GABRIEL");
            return;
        }

        boolean check = true;
        for (int tail = 0; tail <= x - l; tail++) {
            boolean can = false;
            for (int pos = (x - l - tail) + 1; pos <= m - tail; pos++) {
                int left = (pos - 1) * n - (x - l - tail);
                if (left % x == 0) {
                    can = true;
                }
            }
            check &= can;
        }

        if (check) {
            out.println("GABRIEL");
        } else {
            out.println("RICHARD");
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int t = nextInt();
            for (int i = 0; i < t; i++) {
                out.print(String.format("Case #%d: ", i + 1));
                solve();
            }

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
