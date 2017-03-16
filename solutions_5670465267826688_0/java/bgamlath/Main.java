
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer stk;
    static boolean[] isPrime = new boolean[5000];

    static int[][] mult = new int[200][200];

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new InputStreamReader(System.in));
        in = new BufferedReader(new FileReader("input.txt"));
        out = new PrintWriter(new FileWriter("output.txt"));
        stk = new StringTokenizer(in.readLine());
        // Start of User Code
        mult[1][1] = 1;
        mult[1]['i'] = 'i';
        mult[1]['j'] = 'j';
        mult[1]['k'] = 'k';

        mult['i'][1] = 'i';
        mult['i']['i'] = -1;
        mult['i']['j'] = 'k';
        mult['i']['k'] = -'j';

        mult['j'][1] = 'j';
        mult['j']['i'] = -'k';
        mult['j']['j'] = -1;
        mult['j']['k'] = 'i';

        mult['k'][1] = 'k';
        mult['k']['i'] = 'j';
        mult['k']['j'] = -'i';
        mult['k']['k'] = -1;

        int T = ni();
        for (int t = 1; t <= T; t++) {
            out.printf("Case #%d: %s\n", t, proc());
        }

        // End of User Code
        out.close();
        in.close();
    }

    static int getMult(int a, int b) {
        int signa = a / Math.abs(a);
        a = Math.abs(a);
        int signb = b / Math.abs(b);
        b = Math.abs(b);
        return signa * signb * mult[a][b];
    }

    static String proc() throws Exception {
        int L = ni();
        long X = nl();
        String s = ns();
        String t = new StringBuilder(s).reverse().toString();
        int[] st = new int[4 * L + 1];
        int[] en = new int[4 * L + 1];
        long totalLen = L * X;
        st[0] = 1;
        en[0] = 1;
        for (int i = 1; i < st.length; i++) {
            st[i] = getMult(st[i - 1], s.charAt((i - 1) % L));
            en[i] = getMult(t.charAt((i - 1) % L), en[i - 1]);
        }

        int Y = (int) (X % 4);
        int res = 1;
        for (int i = 0; i < Y; i++) {
            res = getMult(res, st[L]);
        }
        if(res != -1) return "NO";


        for(int i = 0; i < st.length; i++){
            if(st[i] == 'i'){
                for(int j = 0; j < en.length; j++){
                    if(en[j] == 'k'){
                        if(totalLen > (i + j)){
                            return "YES";
                        }
                        break;
                    }
                }
                break;
            }
        }

        return "NO";
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
        System.out.printf(format, args);
    }

    static int ni() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(stk.nextToken());
    }

    static long nl() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Long.parseLong(stk.nextToken());
    }

    static double nd() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Double.parseDouble(stk.nextToken());
    }

    static String ns() throws Exception {
        while (!stk.hasMoreTokens()) {
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
}