import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

    public void run() {
        long startTime = System.nanoTime();

        int t = nextInt();
        for (int cs = 0; cs < t; cs++) {

            int a = nextInt();
            int b = nextInt();
            int k = nextInt();

            int res = 0;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    res += (i & j) < k ? 1 : 0;
                }
            }
            printf("Case #%d: %d\n", cs + 1, res);

        }

        if (fileIOMode) {
            System.out.println((System.nanoTime() - startTime) / 1e9);
        }
        out.close();
    }

    //-----------------------------------------------------------------------------------

    private static boolean fileIOMode;
    private static String problemName = "a";
    private static BufferedReader in;
    private static PrintWriter out;
    private static StringTokenizer tokenizer;

    public static void main(String[] args) throws Exception {
        fileIOMode = args.length > 0 && args[0].equals("!");
        if (fileIOMode) {
            in = new BufferedReader(new FileReader(problemName + ".in"));
            out = new PrintWriter(problemName + ".out");
        } else {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }
        tokenizer = new StringTokenizer("");

        new Thread(new A()).start();
    }

    private static String nextLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    private static String nextToken() {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    private static int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private static long nextLong() {
        return Long.parseLong(nextToken());
    }

    private static double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    private static BigInteger nextBigInteger() {
        return new BigInteger(nextToken());
    }

    private static void print(Object o) {
        if (fileIOMode) {
            System.out.print(o);
        }
        out.print(o);
    }

    private static void println(Object o) {
        if (fileIOMode) {
            System.out.println(o);
        }
        out.println(o);
    }

    private static void printf(String s, Object... o) {
        if (fileIOMode) {
            System.out.printf(s, o);
        }
        out.printf(s, o);
    }
}
