import java.io.*;
import java.util.Scanner;

public class Main {
    private static StreamTokenizer in;
    private static Scanner ins;
    private static PrintWriter out;

    public static void main(String[] args) {

        try {
            in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
            ins = new Scanner(System.in);
            out = new PrintWriter(System.out);
            try {
                if (System.getProperty("xDx") != null) {
                    in = new StreamTokenizer(new BufferedReader(new FileReader("input.txt")));
                    ins = new Scanner(new FileReader("input.txt"));
                    out = new PrintWriter(new FileWriter("output.txt"));
                }
            } catch (Exception e) {
                in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
                ins = new Scanner(System.in);
                out = new PrintWriter(System.out);
            }
            new Main().run(args);
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }

    private void run(String[] args) throws Exception {
        int T = nextInt();
        for (int t = 0; t < T; t++) {
            int c = nextInt(), d = nextInt(), v = nextInt();
            int preSum = 0;
            int answ = 0;
            for (int i = 0; i < d; i++) {
                int a = nextInt();
                while (a - 1 > preSum) {
                    answ++;
                    preSum += preSum + 1;
                }
                preSum += a;
            }
            while (preSum < v) {
                answ++;
                preSum += preSum + 1;
            }
            out.printf("Case #%d: %d\n", t + 1, answ);

        }
    }


    private int nextInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }

    private long nextLong() throws IOException {
        in.nextToken();
        return (long) in.nval;
    }

    private double nextDouble() throws IOException {
        in.nextToken();
        return in.nval;
    }

    private String nextString() throws IOException {
        in.nextToken();
        return in.sval;
    }

}
