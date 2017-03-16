import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class CoinJam {
    PrintWriter out;
    BigInteger get(long mask, int b) {
        if (mask == 0) return BigInteger.ZERO;
        return get(mask / 2, b).multiply(BigInteger.valueOf(b)).add(BigInteger.valueOf(mask % 2));
    }
    boolean is_coin(long x) {
        for (int b = 2; b <= 10; b++) {
            BigInteger res = get(x, b);
            if (res.isProbablePrime(100)) {
                return false;
            }
        }
        return true;
    }
    void badBase(long x) {
        for (int b = 2; b <= 10; b++) {
            BigInteger res = get(x, b);
            for (BigInteger i = BigInteger.valueOf(2); i.multiply(i).compareTo(res) < 0; i = i.add(BigInteger.ONE)) {
                if (res.mod(i).equals(BigInteger.ZERO)) {
                    out.print(" " + i);
                    break;
                }
            }
        }
    }
    void solve(int n, int j) {
        for (long i = 1; i < (long)1 << (n - 2) && j > 0; i++) {
            long i1 = i * 2 + 1 + ((long)1 << (n - 1));
            if (is_coin(i1)) {
                out.print(Long.toBinaryString(i1));
                badBase(i1);
                out.println();
                j--;
            }
        }
    }
    CoinJam() throws IOException {
        out = new PrintWriter(new File("a.out"));
        //out = new PrintWriter(System.out);
        out.println("Case #1:");
        solve(16, 50);
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new CoinJam();
    }
}
