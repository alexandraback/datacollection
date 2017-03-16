import java.io.*;
import java.util.*;

public class ASmall {
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

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static void main(String[] args) throws IOException {
        new ASmall().run();
    }

    int rev(int x) {
        int y = 0;
        while (x > 0) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        return y;
    }

    int bfs(int n) {
        int[] q = new int[1_000_000];
        HashMap<Integer, Integer> d = new HashMap<>();
        d.put(1, 1);
        int last = 0;
        int first = 0;
        q[last++] = 1;
        while (last != first) {
            int u = q[first++];
            int v = u + 1;
            if (v <= n && !d.containsKey(v)) {
                d.put(v, d.get(u) + 1);
                q[last++] = v;
            }
            if (v == n) {
                return d.get(v);
            }
            v = rev(u);
            if (v <= n && !d.containsKey(v)) {
                d.put(v, d.get(u) + 1);
                q[last++] = v;
            }
            if (v == n) {
                return d.get(v);
            }
        }
        return -1;
    }

    public void solve() throws IOException {
        int t = nextInt();
        for (int ii = 1; ii <= t; ii++) {
            System.out.println(ii);
            int n = nextInt();
            out.println("Case #" + ii + ": " + bfs(n));
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("a-small.in"));
            out = new PrintWriter("a-small.txt");

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}