import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class GettingTheDigits {
    public static void main(String[] args) throws FileNotFoundException {
        final Scanner reader = new Scanner(new File(args[0] + ".in"));
        final PrintWriter writer = new PrintWriter(new File(args[0] + ".out"));
        final int testsCount = reader.nextInt();
        for (int test = 0; test < testsCount; ++test) {
            String input = reader.next();
            int[] counts = new int[26];
            for (int i = 0; i < input.length(); ++i) {
                int ch = input.charAt(i) - 'A';
                counts[ch]++;
            }
            List<Character> res = new ArrayList<>();
            String order = "ZWXGUSVROE";
            String digits = "0268475319";
            String[] names = new String[] {
                    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
            for (int i = 0; i < digits.length(); ++i) {
                int letter = order.charAt(i) - 'A';
                int digit = digits.charAt(i) - '0';
                int count = counts[letter];
                for (int j = 0; j < count; ++j) {
                    res.add(digits.charAt(i));
                    for (int k = 0; k < names[digit].length(); ++k) {
                        int ch = names[digit].charAt(k) - 'A';
                        counts[ch]--;
                    }
                }
            }
            Collections.sort(res);
            String result = "";
            for (Character ch : res) {
                result += ch;
            }
            writer.write(String.format("Case #%d: %s\n", test + 1, result));
        }
        reader.close();
        writer.close();
    }
}
