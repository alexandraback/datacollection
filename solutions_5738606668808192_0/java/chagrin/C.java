import java.math.BigInteger;
import java.util.*;

public class C {

    private static Random RANDOM_GENERATOR = new Random();
    private static final long TIMEOUT_AFTER = 5;

    public static List<BigInteger> findDivisors(String checkNumber) {
        long timeout = System.currentTimeMillis() + TIMEOUT_AFTER;
        List<BigInteger> divisors = new LinkedList<BigInteger>();
        for (int radix = 2; radix <= 10; radix++) {
            BigInteger testNumber = new BigInteger(checkNumber, radix);
            BigInteger divisor = BigInteger.valueOf(2);
            while (divisor.compareTo(testNumber) < 0 && System.currentTimeMillis() < timeout) {
                if (testNumber.mod(divisor).equals(BigInteger.ZERO)) {
                    break;
                }
                divisor = divisor.add(BigInteger.ONE);
            }
            if (!testNumber.mod(divisor).equals(BigInteger.ZERO)) {
                return null;
            }
            divisors.add(divisor);
        }
        return divisors;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int casesCount = scanner.nextInt();
        for (int i = 1; i <= casesCount; i++) {
            System.out.format("Case #%d:\n", i);
            int size = scanner.nextInt();
            int numbersCount = scanner.nextInt();
            Set<String> foundNumbers = new HashSet<String>(numbersCount);
            long bound = 2L << size - 3;
            while (foundNumbers.size() < numbersCount) {
                long randomNumber = Math.abs(RANDOM_GENERATOR.nextLong()) % bound;
                String checkNumber = Long.toBinaryString((bound + randomNumber << 1) + 1L);
                if (!foundNumbers.contains(checkNumber)) {
                    List<BigInteger> divisors = findDivisors(checkNumber);
                    if (divisors != null) {
                        foundNumbers.add(checkNumber);
                        System.out.print(checkNumber);
                        for (BigInteger divisor : divisors) {
                            System.out.print(" " + divisor);
                        }
                        System.out.println();
                    }
                }
            }
        }
    }
}
