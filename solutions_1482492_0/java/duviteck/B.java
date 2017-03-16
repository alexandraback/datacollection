import java.io.*;
import java.util.StringTokenizer;

public class B implements Runnable {
    private static BufferedReader reader;
    private static StringTokenizer st;
    private static double D;
    private static double[] time;
    private static double[] speed;
    private static double[] pos;
//    private static int len;


    public static void main(String[] args) {
        new Thread(new B()).start();
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (IOException e) {}
    }

    private void solve() throws IOException {
        reader = new BufferedReader(new FileReader("b.in"));
        PrintWriter writer = new PrintWriter(new FileWriter("b.out"));

        int numOfTests = nextInt();
        for (int i = 1; i <= numOfTests; i++) {
            writer.println("Case #" + i + ":");
            D = nextDouble();
            int n = nextInt();
            time = new double[n];
            pos = new double[n];
            speed = new double[n];
            int k = nextInt();
            for (int j = 0; j < n; j++) {
                time[j] = nextDouble();
                pos[j] = nextDouble();
//                if (pos[j] <= D) {
//                    len++;
//                }
            }
            for (int j = 1; j < n; j++) {
                speed[j] = (pos[j] - pos[j - 1]) / (time[j] - time[j - 1]);
            }
            for (int j = 0; j < k; j++) {
                writer.println(calcAns(nextDouble()));
            }
        }

        writer.close();
    }

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(reader.readLine());
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static double calcAns(double a) {
        //System.out.println(time.length);
        if (time.length < 2) return Math.sqrt(2 * D / a);
        double t1 = (D - pos[0]) / speed[1];
        double t2 = Math.sqrt(2 * D / a);
        return Math.max(t1, t2);
    }

}