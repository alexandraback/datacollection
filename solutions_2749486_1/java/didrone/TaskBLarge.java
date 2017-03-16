import java.io.*;
import java.util.StringTokenizer;

public class TaskBLarge {

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new TaskBLarge().run();
    }

    void run() throws IOException {
        br = new BufferedReader(new FileReader("B-large.in"));
        out = new PrintWriter("output.txt");
        solve();

        out.close();
    }

    void solve() throws IOException {
        int t = nextInt();
        for (int i = 0; i < t; i++)
            solveCase();
    }

    int testCounter = 1;
    void solveCase() throws IOException {
        int x = nextInt();
        int y = nextInt();

        int cx = 0;
        int cy = 0;
        StringBuilder sb = new StringBuilder();

        int step = 1;
        loop: while (!(cx == x && cy == y)) {
            int dx = Math.abs(cx - x);
            int dy = Math.abs(cy - y);

            int pdx = Math.min(Math.abs(cx + step - x), Math.abs(cx - step - x));
            int pdy = Math.min(Math.abs(cy + step - y), Math.abs(cy - step - y));

            if (pdx >= dx && pdy >= dy) {
                for (int i = 0; i < dx; i++) {
                    if (x > cx)
                        sb.append("WE");
                    else
                        sb.append("EW");
                }
                for (int i = 0; i < dy; i++) {
                    if (y > cy)
                        sb.append("SN");
                    else
                        sb.append("NS");
                }
                break loop;
            } else if (pdx < dx && (pdx < pdy || pdy >= dy)) {
                if (Math.abs(cx + step - x) < Math.abs(cx - step - x)) {
                    sb.append('E');
                    cx += step;
                } else {
                    sb.append('W');
                    cx -= step;
                }
            } else {
                if (Math.abs(cy + step - y) < Math.abs(cy - step - y)) {
                    sb.append('N');
                    cy += step;
                } else {
                    sb.append('S');
                    cy -= step;
                }
            }

            step++;
        }

        out.printf("Case #%d: %s\n", testCounter++, sb.toString());
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

}
