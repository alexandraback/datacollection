import java.util.*;
import java.math.*;

public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        for (int thisNum = 1; thisNum <= numCases; thisNum++) {
            System.out.format("Case #%d:\n", thisNum);
            int N = in.nextInt();
            int J = in.nextInt();
            int found = 0;
            String endStr = "";
            for (int i = 0; i < N - 2; i++)
                endStr += "1";
            int end = Integer.parseInt(endStr, 2);
            for (int current = 0; current <= end; current++) {
                boolean valid = true;
                String factors = "";
                String test = "1" + pad(Integer.toBinaryString(current), N - 2) + "1";
                for (int base = 2; base <= 10; base++) {
                    BigInteger testInt = new BigInteger(test, base);
                    if (testInt.isProbablePrime(1)) {
                        valid = false;
                        break;
                    }
                    BigInteger factor = easyFactor(testInt);
                    if (factor.compareTo(testInt) != 0)
                        factors += factor + " ";
                    else
                        valid = false;
                }
                if (valid) {
                    System.out.println(test + " " + factors.trim());
                    found++;
                }
                if (found >= J)
                    break;

            }
        }
    }

    public static String pad(String num, int length) {
        StringBuilder retVal = new StringBuilder(length);
        for (int i = 0; i < length - num.length(); i++)
            retVal.append("0");
        retVal.append(num);
        return retVal.toString();
    }

    public static BigInteger easyFactor(BigInteger num) {
        if (num.mod(new BigInteger("2")).compareTo(BigInteger.ZERO) == 0)
            return new BigInteger("2");
        if (num.mod(new BigInteger("3")).compareTo(BigInteger.ZERO) == 0)
            return new BigInteger("3");
        if (num.mod(new BigInteger("5")).compareTo(BigInteger.ZERO) == 0)
            return new BigInteger("5");
        if (num.mod(new BigInteger("7")).compareTo(BigInteger.ZERO) == 0)
            return new BigInteger("7");
        if (num.mod(new BigInteger("11")).compareTo(BigInteger.ZERO) == 0)
            return new BigInteger("11");
        if (num.mod(new BigInteger("13")).compareTo(BigInteger.ZERO) == 0)
            return new BigInteger("13");
        if (num.mod(new BigInteger("17")).compareTo(BigInteger.ZERO) == 0)
            return new BigInteger("17");
        if (num.mod(new BigInteger("19")).compareTo(BigInteger.ZERO) == 0)
            return new BigInteger("19");
        if (num.mod(new BigInteger("23")).compareTo(BigInteger.ZERO) == 0)
            return new BigInteger("23");
        if (num.mod(new BigInteger("29")).compareTo(BigInteger.ZERO) == 0)
            return new BigInteger("29");
        if (num.mod(new BigInteger("31")).compareTo(BigInteger.ZERO) == 0)
            return new BigInteger("31");
        if (num.mod(new BigInteger("37")).compareTo(BigInteger.ZERO) == 0)
            return new BigInteger("37");

        return num;
    }
}
