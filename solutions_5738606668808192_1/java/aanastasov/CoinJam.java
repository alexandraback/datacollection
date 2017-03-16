import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class CoinJam {
    public static void main(String[] args) {
        new CoinJam().solve(32, 500);
    }

    int[] getAllBinary(int num, int digitsCount) {
        int[] digits = new int[digitsCount];
        for (int digitAt = digitsCount - 2; digitAt > 0; --digitAt) {
            digits[digitAt] = num % 2;
            num /= 2;
        }
        digits[0] = 1;
        digits[digitsCount - 1] = 1;
        return digits;
    }

    long getDivisor(int[] digits, int base) {
        BigInteger number = BigInteger.ZERO;
        BigInteger baseBigInteger = BigInteger.valueOf(base);
        for (int i = 0; i < digits.length; ++i) {
            number = number.multiply(baseBigInteger).add(BigInteger.valueOf(digits[i]));
        }
        for (int div = 2; div < 10000; ++div)
            if (number.mod(BigInteger.valueOf(div)).equals(BigInteger.ZERO)) {
                return (long) div;
            }
        return -1;
    }

    public void solve(final int digitsCount, int desiredCount) {
        System.out.println("Case #1:");
        final int variableDigitsCount = digitsCount - 2;
        for (int digitsSet = 0; digitsSet < (1 << variableDigitsCount); ++digitsSet) {
            int[] binaryDigits = getAllBinary(digitsSet, digitsCount);
            boolean ok = true;
            List<Integer> divisors = new ArrayList<>();
            for (int base = 2; ok && base <= 10; ++base) {
                long div = getDivisor(binaryDigits, base);
                if (div < 0) {
                    ok = false;
                } else {
                    divisors.add((int)div);
                }
            }
            if (ok) {
                for (int i = 0; i < binaryDigits.length; ++i)
                    System.out.print(binaryDigits[i]);
                for (long div : divisors) {
                    System.out.print(" " + div);
                }
                System.out.println();
                desiredCount--;
                if (desiredCount == 0) {
                    break;
                }
            }
        }
    }
}
