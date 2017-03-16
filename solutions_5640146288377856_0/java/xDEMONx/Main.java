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
        for (int i = 0; i < T; i++) {
            int r = nextInt(), c = nextInt(), w = nextInt();
            int answ = (c / w) * r;
            answ += (c % w > 0 ? w : w - 1);
            out.printf("Case #%d: %d\n", i + 1, answ);
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
