import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class GettingTheDigits {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int numCases = scanner.nextInt();
    for (int i = 1; i <= numCases; ++i)
      System.out.printf("Case #%d: %s\n", i, getPhoneNumber(toLetterBag(scanner.next())));
  }

  private static String getPhoneNumber(Map<Character, Integer> letters) {
    int[] counts = new int[10];

    int zeros = letters.getOrDefault('Z', 0);
    counts[0] = zeros;
    for (char c : "ZERO".toCharArray())
      removeNChars(letters, c, zeros);

    int twos = letters.getOrDefault('W', 0);
    counts[2] = twos;
    for (char c : "TWO".toCharArray())
      removeNChars(letters, c, twos);

    int sixes = letters.getOrDefault('X', 0);
    counts[6] = sixes;
    for (char c : "SIX".toCharArray())
      removeNChars(letters, c, sixes);

    int fours = letters.getOrDefault('U', 0);
    counts[4] = fours;
    for (char c : "FOUR".toCharArray())
      removeNChars(letters, c, fours);

    int ones = letters.getOrDefault('O', 0);
    counts[1] = ones;
    for (char c : "ONE".toCharArray())
      removeNChars(letters, c, ones);

    int threes = letters.getOrDefault('R', 0);
    counts[3] = threes;
    for (char c : "THREE".toCharArray())
      removeNChars(letters, c, threes);

    int fives = letters.getOrDefault('F', 0);
    counts[5] = fives;
    for (char c : "FIVE".toCharArray())
      removeNChars(letters, c, fives);

    int sevens = letters.getOrDefault('V', 0);
    counts[7] = sevens;
    for (char c : "SEVEN".toCharArray())
      removeNChars(letters, c, sevens);

    int eights = letters.getOrDefault('G', 0);
    counts[8] = eights;
    for (char c : "EIGHT".toCharArray())
      removeNChars(letters, c, eights);

    int nines = letters.getOrDefault('I', 0);
    counts[9] = nines;
    for (char c : "NINE".toCharArray())
      removeNChars(letters, c, nines);

    assert letters.isEmpty();

    StringBuilder sb = new StringBuilder();
    for (int digit = 0; digit < 10; ++digit)
      for (int i = 0; i < counts[digit]; ++i)
        sb.append(digit);
    return sb.toString();
  }

  private static Map<Character, Integer> toLetterBag(String letters) {
    Map<Character, Integer> bag = new HashMap<>();
    for (char c : letters.toCharArray())
      bag.put(c, bag.getOrDefault(c, 0) + 1);
    return bag;
  }

  private static void removeNChars(Map<Character, Integer> bag, char c, int n) {
    int newCount = bag.getOrDefault(c, 0) - n;
    assert newCount >= 0 : bag.toString() + c + n;
    if (newCount == 0)
      bag.remove(c);
    else
      bag.put(c, newCount);
  }
}
