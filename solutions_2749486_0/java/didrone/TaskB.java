import java.io.*;
import java.util.StringTokenizer;

public class TaskB {

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new TaskB().run();
    }

    void run() throws IOException {
        br = new BufferedReader(new FileReader("B-small-attempt0.in"));
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

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < Math.abs(x); i++) {
            if (x > 0)
                sb.append("WE");
            else
                sb.append("EW");
        }
        for (int i = 0; i < Math.abs(y); i++) {
            if (y > 0)
                sb.append("SN");
            else
                sb.append("NS");
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
