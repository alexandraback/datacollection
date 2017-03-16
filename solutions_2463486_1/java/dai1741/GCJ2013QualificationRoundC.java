import java.math.BigInteger;
import java.util.Scanner;


public class GCJ2013QualificationRoundC {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: %d%n", i, new GCJ2013QualificationRoundC()
                    .solve(sc));
        }
    }

    int getNum(BigInteger rem, int remSumCenter, int digit, int maxDigit) {
        if (digit * 2 >= maxDigit) {
            // System.out.println(rem + ", maxdigit: " + maxDigit);
            return 1;
        }
        int ret = 0;

        // go through
        if (digit > 0) ret += getNum(rem, remSumCenter, digit + 1, maxDigit);

        int palindDigit = maxDigit - digit - 1;
        for (int i = 1; i <= 3; i++) {
            if (remSumCenter - i * i * (palindDigit != digit ? 2 : 1) < 0) break;
            BigInteger nextRem = rem.subtract(BigInteger.valueOf(i).multiply(
                    BigInteger.TEN.pow(digit)));
            if (palindDigit != digit) nextRem = nextRem.subtract(BigInteger.valueOf(i)
                    .multiply(BigInteger.TEN.pow(palindDigit)));
            if (nextRem.signum() < 0) break;
            ret += getNum(nextRem, remSumCenter - i * i * (palindDigit != digit ? 2 : 1),
                    digit + 1, maxDigit);
        }

        return ret;
    }

    /** @return n桁の回文数で、二乗が回文数なやつ */
    int getNumQuick(int n) {
        if (n == 1) return 3;
        if (n == 2) return 2;
        boolean hasCenter = n % 2 == 1;
        n = n / 2 - 1;  // 真ん中と端以外の自由度
        int ret = 0;
        for (int i = 1; i <= 3; i++) {
            for (int j = 0; j <= 3; j++) {
                ret += getNumQuick2(n, 9 - i * i * 2 - j * j);
                if (!hasCenter) break;
            }
        }
        return ret;
    }

    int getNumQuick2(int n, int rem) {
        if (rem < 0) return 0;
        int ret = 0;
        for (int i = 0; i <= rem / 2; i++) {  // n個の箱に1をi個入れるのはcomb
            int ret2 = 1;
            for (int j = 0; j < i; j++) {
                ret2 = ret2 * (n - j) / (j + 1);
            }
            ret += ret2;
        }
        return rem >= 8 ? ret + n : ret;  // 4も入れられるなら適当に入れる
    }

    // a^2 is palindrome only if computation of a*a can be performed without carry
    // both a and a^2 is palindrome only if sum of square of i-th digit of a is less than 10
    // see: http://arxiv.org/abs/1210.7593

    private long solve(Scanner sc) throws Exception {
        String aS = sc.next();
        String bS = sc.next();
        BigInteger aSqrt = sqrt(aS).subtract(BigInteger.ONE);
        BigInteger bSqrt = sqrt(bS);
        if (!bSqrt.pow(2).equals(new BigInteger(bS))) bSqrt = bSqrt
                .subtract(BigInteger.ONE);

        int ret = 0;
//        System.out.println("asqrt: " + aSqrt + ", bsqrt: " + bSqrt);

        int minDiffDigit = aSqrt.toString().length();
        int maxDigit = bSqrt.toString().length();
        for (int i = minDiffDigit; i < maxDigit; i++) {
//            int method1 = getNum(bSqrt, 9, 0, i);
//            int method2 = getNumQuick(i);
//            System.out.println(i + ";;; method1: " + method1 + ", method2: " + method2);
            ret += getNumQuick(i);
        }
        ret += getNum(bSqrt, 9, 0, maxDigit);
        //        System.out.println("-----");
        if (aSqrt.signum() > 0) ret -= getNum(aSqrt, 9, 0, minDiffDigit);
        return ret;
    }

    /** @return ceil(sqrt(n)) */
    private BigInteger sqrt(String s) {
        BigInteger v = new BigInteger(s);
        BigInteger l = BigInteger.ZERO;
        BigInteger r = v;
        while (l.compareTo(r) < 0) {
            BigInteger mid = l.add(r).divide(BigInteger.valueOf(2));
            BigInteger mv = mid.pow(2);
            if (mv.compareTo(v) < 0) l = mid.add(BigInteger.ONE);
            else r = mid;
        }
        return l;
    }

}
