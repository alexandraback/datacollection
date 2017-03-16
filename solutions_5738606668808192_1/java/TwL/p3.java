import java.util.*;
import java.math.*;

public class p3
{
    private static BigInteger TWO = new BigInteger("2");

    public static BigInteger getDecimal(boolean[] bits, BigInteger base)
    {
        BigInteger sum = BigInteger.ZERO;
        BigInteger weight = BigInteger.ONE;

        for (int i = 0; i < bits.length; i++)
        {
            if (bits[i])
                sum = sum.add(weight);

            weight = weight.multiply(base);
        }

        return sum;
    }

    public static void setBits(boolean[] bits, BigInteger num)
    {
        for (int i = 1; i < bits.length - 1; i++)
        {
            if (num.compareTo(BigInteger.ZERO) > 0)
            {
                bits[i] = num.mod(TWO).equals(BigInteger.ONE);
                num = num.divide(TWO);
            }
            else
            {
                bits[i] = false;
            }
        }
    }

    public static void printBits(boolean[] bits)
    {
        for (int i = bits.length - 1; i >= 0; i--)
            System.out.print(bits[i] == true ? "1" : "0");
    }

    public static BigInteger[] findDivisors(boolean[] bits)
    {
        BigInteger[] result = new BigInteger[11];
        result[0] = BigInteger.ONE;
    
        for (int base = 2; base <= 10; base++)
        {
            BigInteger baseBig = new BigInteger(Integer.toString(base));
            BigInteger num = getDecimal(bits, baseBig);
            BigInteger divisor = TWO;

            BigInteger cutoff = new BigInteger("100000");
            if (cutoff.compareTo(num) > 0) cutoff = num;
            while (divisor.compareTo(cutoff) < 0)
            {
                if (num.mod(divisor).equals(BigInteger.ZERO))
                    break;
                else
                    divisor = divisor.add(BigInteger.ONE);
            }

            if (divisor.compareTo(cutoff) >= 0)
            {
                result[0] = BigInteger.ZERO;
                return result;
            }
            else
            {
                result[base] = divisor;
            }
        }

        return result;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int N = sc.nextInt();
        int J = sc.nextInt();

        System.out.println("Case #1:");

        boolean[] bits = new boolean[N];
        bits[0] = true;
        bits[N - 1] = true;

        BigInteger max = TWO.pow(N - 2);

        for (BigInteger i = BigInteger.ZERO; i.compareTo(max) < 0; i = i.add(BigInteger.ONE))
        {
            if (J <= 0) break;

            setBits(bits, i);

            BigInteger[] divisors = findDivisors(bits);
            if (divisors[0].equals(BigInteger.ZERO))
                continue;

            J--;
            printBits(bits);            

            for (int base = 2; base <= 10; base++)
                System.out.printf(" %s", divisors[base].toString(10));
            System.out.println();
        }
    }
}
