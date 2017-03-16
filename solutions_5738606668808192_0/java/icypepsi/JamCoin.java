package codejam2016.coin_jam;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class JamCoin {

    // generating the jam coins with pattern
    //          (a + 1) * (c0*1 + c1*a^2 + c2*a^4 + ...ck*a^2k + ck+1*a^2(k+1))
    // a is the base
    // a + 1 is the non nontrivial divisor
    // it can generate 2^k = 2^(n/2-2) jam coins.
    private static String buildCoin(int n, int x) {
        int k = n / 2 - 2;
        String binary = Integer.toBinaryString(x);
        int zeros = k - binary.length();
        if (zeros > 0)
            binary = String.format("%0" + zeros + "d%s", 0, binary);
        // replacing 0 with 00, 1 with 11
        return "11" +binary.replace("0", "00").replace("1", "11") + "11";
    }

    private static void generateJamCoin(int n, int j, PrintWriter pw) {
        int k = n / 2 - 2;
        int maxCoins = 1 << k;
        if (n % 2 == 1 || j > maxCoins)
            throw new IllegalArgumentException();

        StringBuilder divisors = new StringBuilder();
        for (int a = 2; a <= 10; ++a)
            divisors.append(" ").append(a + 1);

        for (int i = 0; i < j; ++i) {
            String jamCoin = buildCoin(n, i);
            pw.print(jamCoin);
            pw.println(divisors);
        }
    }

    private static void run(Scanner sc, PrintWriter pw) {
        int t = sc.nextInt();
        for (int i = 0; i < t; ++i) {
            int n = sc.nextInt();
            int j = sc.nextInt();
            pw.printf("Case #%d:\n", i + 1);
            generateJamCoin(n, j, pw);
        }
    }

    public static void main(String[] args) {
        try {
            String in = args[0];
            String out = args[1];

            Scanner sc = new Scanner(new FileReader(in));
            PrintWriter pw = new PrintWriter(out);
            run(sc, pw);
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
