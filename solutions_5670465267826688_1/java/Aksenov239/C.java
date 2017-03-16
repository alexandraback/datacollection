import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
    public static void main(String[] args) {
        new C().run();
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

    public long nextLong() throws IOException{
        return Long.parseLong(nextToken());
    }

    int[][] table = {{1, 2, 3, 4}, {2, -1, 4, -3}, {3, -4, -1, 2}, {4, 3, -2, -1}};

    public int multiply(int x, int y) {
        return (int) (Math.signum(x) * Math.signum(y) * table[Math.abs(x) - 1][Math.abs(y) - 1]);
    }

    String x = "ijk";

    public void solve() throws IOException {
        int l = nextInt();
        long x = nextLong();

        char[] c = nextToken().toCharArray();
        int one = 1;
        for (int i = 0; i < c.length; i++) {
            c[i] = (char) (this.x.indexOf(c[i]) + 2);
            one = multiply(one, c[i]);
        }

        int total = 1;
        for (int i = 0; i < x % 4; i++) {
            total = multiply(total, one);
        }

        int f = -1;
        int ns = 1;
        long s = -1;
        int ne = 1;
        for (int t = 0; t < Math.min(4, x); t++) {
            for (int i = 0; i < c.length; i++) {
                ns = multiply(ns, c[i]);
                if (ns == 2 && f == -1) {
                    f = t * l + (i + 1);
                }

                ne = multiply(c[c.length - i - 1], ne);
                if (ne == 4 && s == -1) {
                    s = x * l - t * l - (i + 1);
                }
            }
        }

        if (total == -1 && s > f && f != -1) {
            out.println("YES");
        } else {
            out.println("NO");
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
