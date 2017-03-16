import java.io.*;
import java.util.StringTokenizer;

public class Main implements Runnable {

    boolean canLose(int i, double p, int sum, int[] s) {
        double pro = 1-p;
        double have = s[i] + p*sum;
        for (int j = 0; j < s.length; j++) {
            if (j == i) continue;
            double cur = s[j];
            if (cur >= have) continue;
            double need = have-cur;
            pro -= need/sum;
        }
        return pro >= 0;
    }

    void solveCase(int tc) throws Exception {
        out.print("Case #" + (tc+1) + ":");
        int n = nextInt();
        int[] s = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            s[i] = nextInt();
            sum += s[i];
        }
        for (int i = 0; i < n; i++) {
            double l = 0, r = 1;
            while (r-l > 1e-10) {
                double m = (l+r)/2;
                if (canLose(i, m, sum, s))
                    l = m;
                else
                    r = m;
            }
            out.printf(" %.6f", 100*(l+r)/2);
        }
        out.println();
    }

    void solution() throws Exception {
        int tc = nextInt();
        for (int i = 0; i < tc; i++)
            solveCase(i);
    }

    ///////////////////// Template definitions //////////////////////////
    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String l = in.readLine();
            if (l == null) return null;
            st = new StringTokenizer(l);
        }
        return st.nextToken();
    }

    public static void main(String args[]) {
        //Locale.setDefault(Locale.UK);
        new Thread(new Main()).start();
    }

    public void run() {
        try {
            //boolean online = System.getProperty("ONLINE_JUDGE") != null;
            boolean online = false;
            Reader reader = online
                    ? new InputStreamReader(System.in)
                    : new FileReader("A-small-attempt0.in");
            in = new BufferedReader(reader);
            //out = new PrintWriter(System.out);
            out = new PrintWriter(new File("A-small-attempt0.out"));
            solution();
            out.flush();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(202);
        }
    }

    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
}