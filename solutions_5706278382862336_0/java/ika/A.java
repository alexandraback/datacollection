import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

    public void run() {
        long startTime = System.nanoTime();

        int cases = nextInt();
        for (int tc = 1; tc <= cases; tc++) {

            String s = nextToken();
            long p = Long.parseLong(s.split("/")[0]);
            long q = Long.parseLong(s.split("/")[1]);
            long d = gcd(p, q);
            p /= d;
            q /= d;
            if ((q & -q) != q) {
                printf("case #%d: %s\n", tc, "impossible");
            } else {
                p <<= 1;
                printf("case #%d: %s\n", tc, 1 + Long.numberOfTrailingZeros(q / Long.highestOneBit(p)));
            }

        }


        if (fileIOMode) {
            System.out.println((System.nanoTime() - startTime) / 1e9);
        }
        out.close();
    }

    public static long gcd(long n, long m) {
        long big, little;
        if (n < m) {
            big = m;
            little = n;
        } else {
            big = n;
            little = m;
        }
        while (little != 0) {
            long temp = little;
            little = big % little;
            big = temp;
        }
        return big;
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
