
import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {

    static BufferedReader in;
    static StringTokenizer stk;
    static int T, N, M, K;
    static PrintWriter out;

    public static void main(String[] args) throws Exception {
        backupPreviousOutputs("out.txt");

        out = new PrintWriter("out.txt");
        in = new BufferedReader(new FileReader("src/in.txt"));

        // Start of User Code

        T = ni();

        for (int i = 0; i < T; i++) {
            printf("Case #%d: %s\n", i + 1, proc());
        }

        // End of User Code
        out.flush();
        out.close();
        in.close();
    }

    static String proc() throws Exception {
        int a = ni();
        int b = ni();
        int c = ni();
        return get(a - 1, b - 1, c - 1).toString();
        //throw new Exception("NOT IMPLEMENTED YET");

    }
    static HashMap<BigInteger, BigInteger> cache = new HashMap<BigInteger, BigInteger>();

    static BigInteger get(int a, int b, int c) {
        if(a == 0){
            return BigInteger.valueOf(b + 1);
        }else if(b == 0){
            return BigInteger.valueOf(a + 1);
        }
//        if (a == 0 || b == 0 || c == 0) {
//            return BigInteger.ONE;
//        }
        BigInteger key = BigInteger.valueOf(a);
        key = key.multiply(BigInteger.valueOf(1000000001)).add(BigInteger.valueOf(b));
        key = key.multiply(BigInteger.valueOf(1000000001)).add(BigInteger.valueOf(c));

        if (cache.containsKey(key)) {
            return cache.get(key);
        }

        
        BigInteger x1 = c > 0 ? get((a - 1) / 2, (b - 1) / 2, (c - 1) / 2) : BigInteger.ZERO;
        BigInteger x2 = get(a / 2, b / 2, c / 2);
        BigInteger x3 = get((a) / 2, (b - 1) / 2, (c) / 2);
        BigInteger x4 = get((a - 1) / 2, (b) / 2, (c) / 2);

        BigInteger res = x1.add(x2).add(x3).add(x4);
        cache.put(key, res);
        return res;
    }

    static long modPow(long n, long pow, long mod) {
        return BigInteger.valueOf(n).modPow(BigInteger.valueOf(pow), BigInteger.valueOf(mod)).longValue();
    }

    static long modInv(long n, long mod, boolean isPrimeModuli) {
        if (isPrimeModuli) {
            return modPow(n, mod - 2, mod);
        }
        return BigInteger.valueOf(n).modInverse(BigInteger.valueOf(mod)).longValue();
    }
    // calc factorials
    static long[] fact;

    static void calcFactorials(int n) {
        fact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }

    static void calcFactorialsModM(int n, long M) {
        fact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            fact[i] %= M;
        }
    }

    static long ncr(int n, int r) {
        return fact[n] / (fact[n - r] * fact[r]);
    }

    static long ncrModM(int n, int r, long MOD, boolean isPrimeModuli) {
        return fact[n] * modInv(fact[n - r], MOD, isPrimeModuli) * modInv(fact[r], MOD, isPrimeModuli);
    }

    static long toL(String s) {
        return Long.parseLong(s);
    }

    static long toL(BigInteger n) {
        return n.longValue();
    }

    static int toI(String s) {
        return Integer.parseInt(s);
    }

    static double toD(String s) {
        return Double.parseDouble(s);
    }

    static void printf(String format, Object... args) {
        out.printf(format, args);
        System.out.printf(format, args);
    }

    static void println(String str) {
        out.println(str);
        System.out.println(str);
    }

    static int ni() throws Exception {
        while (stk == null || !stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(stk.nextToken());
    }

    static long nl() throws Exception {
        while (stk == null || !stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Long.parseLong(stk.nextToken());
    }

    static double nd() throws Exception {
        while (stk == null || !stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Double.parseDouble(stk.nextToken());
    }

    static String ns() throws Exception {
        while (stk == null || !stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return stk.nextToken();
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static long min(long a, long b) {
        return a < b ? a : b;
    }

    static long max(long a, long b) {
        return a > b ? a : b;
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static void backupPreviousOutputs(String name) throws Exception {
        File f = new File(name);
        if (f.exists()) {
            f.renameTo(new File("out [" + new Date(f.lastModified()).toLocaleString() + "].txt"));
        }
    }
}
