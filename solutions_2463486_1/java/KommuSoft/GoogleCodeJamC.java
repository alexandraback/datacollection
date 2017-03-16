package googlecodejamc;

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author kommusoft
 */
public class GoogleCodeJamC {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        /*for (long v = 1; v < 1000000000L;) {
         System.out.println(v);
         v = nextPalinDrome(v);
         }*/
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int c = 1; c <= t; c++) {
            solveInstance(sc, c);
        }//*/
    }

    private static boolean isPalinDrome(BigInteger tmp) {
        String val = tmp.toString();
        int n = val.length() / 2 + 1;
        for (int lo = 0, hi = val.length() - 1; lo < n; lo++, hi--) {
            if (val.charAt(lo) != val.charAt(hi)) {
                return false;
            }
        }
        return true;
    }

    private static void solveInstance(Scanner sc, int c) {
        BigInteger bi = sc.nextBigInteger();
        BigInteger bi2 = sc.nextBigInteger();
        int lon = bi.toString().length() / 2;
        int hin = bi2.toString().length() / 2 + 1;
        //System.out.println(""+lon+" "+hin);
        long loval = pow(10, lon) + 1;
        if(lon == 0) {
            loval = 1;
        }
        long hival = pow(10, hin);
        //System.out.println(""+loval+" "+hival);
        long np = 0, npp = 0;
        BigInteger tmp;
        for (long x = loval; x < hival;) {
            //System.out.println("Palin "+x);
            tmp = BigInteger.valueOf(x);
            tmp = tmp.multiply(tmp);
            if (bi.compareTo(tmp) <= 0) {
                if (tmp.compareTo(bi2) <= 0) {
                    if(isPalinDrome(tmp)) {
                        //System.out.println(tmp);
                        np++;
                    }
                } else {
                    break;
                }
            }
            x = nextPalinDrome(x);
        }
        //System.out.println(String.format("Case #%s: %s -> %s", c,npp,np));
        System.out.println(String.format("Case #%s: %s", c,np));
    }

    private static long digit(long val, int pos) {
        return (val / pow(10, pos)) % 10;
    }

    private static long pow(long base, long pow) {
        long res = 1;
        while (pow != 0) {
            if ((pow & 1) == 1) {
                res *= base;
            }
            base *= base;
            pow >>>= 1;
        }
        return res;
    }

    private static long nextPalinDrome(long val) {
        int ndigits = (int) Math.floor(Math.log10(val)) + 1;
        int lo = (ndigits - 1) / 2;
        int hi = lo + 1 - (ndigits & 1);
        //System.out.println(String.format("[%s;%s]",lo,hi));
        while (lo >= 0 && digit(val, lo) == 9) {
            //System.out.println(String.format("Checked digit(%s,%s)=%s", val, lo, digit(val, lo)));
            val = clearDigit(val, lo);
            val = clearDigit(val, hi);
            lo--;
            hi++;
        }
        if (lo < 0) {
            //System.out.println("new rank");
            return pow(10, ndigits) + 1;
        } else {
            if (hi == lo) {
                return incDigit(val, lo);
            } else {
                val = incDigit(val, hi);
                return incDigit(val, lo);
            }
        }
    }

    private static long clearDigit(long val, int pos) {
        long pw = pow(10, pos);
        long pwn = 10 * pw;
        return (val) % pw + (val / pwn) * pwn;
    }

    private static long incDigit(long val, int pos) {
        long pw = pow(10, pos);
        return val + pw;
    }
}
