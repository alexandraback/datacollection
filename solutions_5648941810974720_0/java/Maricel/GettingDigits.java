import java.io.*;
import java.util.*;

public class GettingDigits {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("getting_digits_in.txt"));
        PrintStream out = new PrintStream(new File("getting_digits_out.txt"));

        GettingDigits program = new GettingDigits();

        int tests = in.nextInt();
        for (int test = 1; test <= tests; test++) {
            String s = in.next();

            String number = program.solve(s);
            System.out.println(number);
            out.println("Case #" + test + ": " + number);
        }

        in.close();
        out.close();
    }

    private String solve(String s) {
        int[] count = new int[10];

        Map<Character, Integer> charCount = new HashMap<>();
        for (char c : s.toCharArray()) {
            charCount.computeIfPresent(c, (k, v) -> v + 1);
            charCount.putIfAbsent(c, 1);
        }

        count[0] = charCount.getOrDefault('Z', 0);
        charCount.computeIfPresent('Z', (k, v) -> v - count[0]);
        charCount.computeIfPresent('E', (k, v) -> v - count[0]);
        charCount.computeIfPresent('R', (k, v) -> v - count[0]);
        charCount.computeIfPresent('O', (k, v) -> v - count[0]);

        count[6] = charCount.getOrDefault('X', 0);
        charCount.computeIfPresent('S', (k, v) -> v - count[6]);
        charCount.computeIfPresent('I', (k, v) -> v - count[6]);
        charCount.computeIfPresent('X', (k, v) -> v - count[6]);

        count[8] = charCount.getOrDefault('G', 0);
        charCount.computeIfPresent('E', (k, v) -> v - count[8]);
        charCount.computeIfPresent('I', (k, v) -> v - count[8]);
        charCount.computeIfPresent('G', (k, v) -> v - count[8]);
        charCount.computeIfPresent('H', (k, v) -> v - count[8]);
        charCount.computeIfPresent('T', (k, v) -> v - count[8]);

        count[2] = charCount.getOrDefault('W', 0);
        charCount.computeIfPresent('T', (k, v) -> v - count[2]);
        charCount.computeIfPresent('W', (k, v) -> v - count[2]);
        charCount.computeIfPresent('O', (k, v) -> v - count[2]);

        count[3] = charCount.getOrDefault('H', 0);
        charCount.computeIfPresent('T', (k, v) -> v - count[3]);
        charCount.computeIfPresent('H', (k, v) -> v - count[3]);
        charCount.computeIfPresent('R', (k, v) -> v - count[3]);
        charCount.computeIfPresent('E', (k, v) -> v - count[3]);
        charCount.computeIfPresent('E', (k, v) -> v - count[3]);

        count[4] = charCount.getOrDefault('U', 0);
        charCount.computeIfPresent('F', (k, v) -> v - count[4]);
        charCount.computeIfPresent('O', (k, v) -> v - count[4]);
        charCount.computeIfPresent('U', (k, v) -> v - count[4]);
        charCount.computeIfPresent('R', (k, v) -> v - count[4]);

        count[5] = charCount.getOrDefault('F', 0);
        charCount.computeIfPresent('F', (k, v) -> v - count[5]);
        charCount.computeIfPresent('I', (k, v) -> v - count[5]);
        charCount.computeIfPresent('V', (k, v) -> v - count[5]);
        charCount.computeIfPresent('E', (k, v) -> v - count[5]);

        count[7] = charCount.getOrDefault('V', 0);
        charCount.computeIfPresent('S', (k, v) -> v - count[7]);
        charCount.computeIfPresent('E', (k, v) -> v - count[7]);
        charCount.computeIfPresent('V', (k, v) -> v - count[7]);
        charCount.computeIfPresent('E', (k, v) -> v - count[7]);
        charCount.computeIfPresent('N', (k, v) -> v - count[7]);

        count[9] = charCount.getOrDefault('I', 0);
        charCount.computeIfPresent('N', (k, v) -> v - count[9]);
        charCount.computeIfPresent('I', (k, v) -> v - count[9]);
        charCount.computeIfPresent('N', (k, v) -> v - count[9]);
        charCount.computeIfPresent('E', (k, v) -> v - count[9]);

        count[1] = charCount.getOrDefault('O', 0);
        charCount.computeIfPresent('O', (k, v) -> v - count[1]);
        charCount.computeIfPresent('N', (k, v) -> v - count[1]);
        charCount.computeIfPresent('E', (k, v) -> v - count[1]);


        String result = "";
        for (int digit = 0; digit < 10; digit++) {
            for (int i = 0; i < count[digit]; i++) {
                result += digit;
            }
        }

        return result;
    }
}