import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class CoinJam {
    PrintWriter out;
    BigInteger get(long mask, int b) {
        if (mask == 0) return BigInteger.ZERO;
        return get(mask / 2, b).multiply(BigInteger.valueOf(b)).add(BigInteger.valueOf(mask % 2));
    }
    Random rnd = new Random(239);
    BigInteger factorize(BigInteger n) {
        BigInteger x = BigInteger.valueOf(rnd.nextInt() % 10 + 1);
        x = x.mod(n);
        BigInteger y = x;
        BigInteger d = BigInteger.ONE;
        BigInteger c = BigInteger.valueOf(rnd.nextInt() % 21 - 10);
        long cnt2 = 0;
        long sq = (long)1e4;
        while (d.equals(BigInteger.ONE) && cnt2 < sq) {
            cnt2++;
            x = x.multiply(x).add(c).mod(n);
            y = y.multiply(y).add(c).mod(n);
            y = y.multiply(y).add(c).mod(n);
            d = (x.subtract(y)).gcd(n);
        }
        if (!(d.equals(n) || d.equals(BigInteger.ONE))) {
            return d;
        }

        return BigInteger.ZERO;
    }
    ArrayList<BigInteger> get_coin(long x) {
        ArrayList<BigInteger> ans = new ArrayList<>();
        for (int b = 2; b <= 10; b++) {
            BigInteger res = get(x, b);
            if (res.isProbablePrime(100)) {
                return ans;
            }
        }
        //System.err.println("!");
        for (int b = 2; b <= 10; b++) {
            BigInteger res = get(x, b);
            BigInteger f = factorize(res);
            if (f.equals(BigInteger.ZERO)) {
                return ans;
            }
            ans.add(f);
        }
        return ans;
    }
    void solve(int n, int j) {
        for (long i = 1; i < (long)1 << (n - 2) && j > 0; i++) {
            long i1 = i * 2 + 1 + ((long)1 << (n - 1));
            ArrayList<BigInteger> res = get_coin(i1);
            if (res.size() == 10 - 2 + 1) {
                System.err.println(j);
                out.print(Long.toBinaryString(i1));
                for (BigInteger x : res) {
                    out.print(" " + x);
                }
                out.println();
                j--;
            }
        }
    }
    CoinJam() throws IOException {
        out = new PrintWriter(new File("a.out"));
        //out = new PrintWriter(System.out);
        out.println("Case #1:");
        solve(32, 500);
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new CoinJam();
    }
}
