import java.math.BigInteger;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

public class D {

    public static Set<BigInteger> findTestNumbers(int baseSize, int complexity, int numbersCount) {
        int actualNumbersCount = (int) Math.ceil((double) baseSize / complexity);
        if (actualNumbersCount > numbersCount) {
            return null;
        }
        Set<BigInteger> testNumbers = new HashSet<BigInteger>(actualNumbersCount);
        int checkGoldIndex = 0;
        for (int i = 0; i < actualNumbersCount; i++) {
            BigInteger number = BigInteger.ZERO;
            for (int digit = 0; digit < complexity; digit++) {
                if (checkGoldIndex < baseSize) {
                    number = number.multiply(BigInteger.valueOf(baseSize)).add(BigInteger.valueOf(checkGoldIndex++));
                }
            }
            testNumbers.add(number.add(BigInteger.ONE));
        }
        return testNumbers;
    }

    public static String formatAnswer(Set<BigInteger> numbers) {
        if (numbers == null) {
            return "IMPOSSIBLE";
        }
        StringBuilder result = new StringBuilder();
        Iterator<BigInteger> iterator = numbers.iterator();
        result.append(iterator.next());
        while (iterator.hasNext()) {
            result.append(" ").append(iterator.next());
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int casesCount = scanner.nextInt();
        for (int i = 1; i <= casesCount; i++) {
            int baseSize = scanner.nextInt();
            int complexity = scanner.nextInt();
            int numbersCount = scanner.nextInt();
            Set<BigInteger> numbers = findTestNumbers(baseSize, complexity, numbersCount);
            System.out.format("Case #%d: %s\n", i, formatAnswer(numbers));
        }
    }
}
