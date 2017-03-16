import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Daniyar Itegulov on 03-05-2014.
 */

public class Lottery {
    FastScanner in;
    PrintWriter out;

    public long probability(int a, int i) {
        return ((long) (a >> (i + 1)) + 1) * ((long) (a % (int)(Math.pow(2, i))) + 1);
    }

    public void solve() throws IOException {
        int t = in.nextInt();
        for (int test = 0; test < t; test++) {
            out.print("Case #" + (test + 1) + ": ");
            int a = in.nextInt();
            int b = in.nextInt();
            int k = in.nextInt();
            long answer = 0;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    if ((i & j) < k) {
                        answer++;
                    }
                }
            }
            out.println(answer);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("lottery.in"));
            out = new PrintWriter(new File("lottery.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new Lottery().run();
    }
}