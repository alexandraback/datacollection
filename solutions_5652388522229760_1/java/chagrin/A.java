import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {

    public static Set<Character> getDigits(BigInteger number) {
        Set<Character> characters = new HashSet<Character>(10);
        for (Character c : number.toString().toCharArray()) {
            characters.add(c);
        }
        return characters;
    }

    public static BigInteger findLastNumber(BigInteger baseNumber) {
        if (baseNumber.equals(BigInteger.ZERO)) {
            return null;
        }
        BigInteger lastNumber = baseNumber;
        Set<Character> usedDigits = getDigits(lastNumber);
        while (usedDigits.size() < 10) {
            lastNumber = lastNumber.add(baseNumber);
            usedDigits.addAll(getDigits(lastNumber));
        }
        return lastNumber;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int casesCount = scanner.nextInt();
        for (int i = 1; i <= casesCount; i++) {
            BigInteger lastNumber = findLastNumber(scanner.nextBigInteger());
            System.out.format("Case #%d: %s\n", i, lastNumber != null ? lastNumber : "INSOMNIA");
        }
    }
}
