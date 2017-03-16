import java.io.*;
import java.util.*;

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
        nextInt();
        char[] c = nextToken().toCharArray();
        int sum = c[0] - '0';
        int ans = 0;
        for (int i = 1; i < c.length; i++) {
            if (i - sum > 0) {
                ans += Math.max(0, i - sum);
                sum = i;
            }
            sum += c[i] - '0';
        }
        out.println(ans);
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
