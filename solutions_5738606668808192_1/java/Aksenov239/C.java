import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by vaksenov on 16.01.2016.
 */
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

    public void solve() throws IOException {
        int n = nextInt();
        int j = nextInt();

        out.println();

        for (int mask = (1 << (n / 2 - 1)) + 1; mask < 1 << n / 2  && j > 0; mask += 2, j--) {
            int value = mask * (1 << (n / 2)) + mask;
            String t = Integer.toBinaryString(mask);
            out.print(Integer.toBinaryString(value) + " ");
            for (int i = 2; i <= 10; i++) {
                long divisor = 0;
                for (int k = 0; k < t.length(); k++) {
                    divisor = divisor * i + (t.charAt(k) - '0');
                }
                out.print(divisor + " ");
            }
            out.println();
        }

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
