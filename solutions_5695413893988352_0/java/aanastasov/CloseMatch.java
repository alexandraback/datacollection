import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class CloseMatch {
    public static int pow(int a, int b) {
        int res = 1;
        for (int i = 0; i < b; ++i) {
            res *= a;
        }
        return res;
    }

    public static boolean matches(String s, int number) {
        List<Integer> digits = new ArrayList<>();
        while (number > 0) {
            digits.add(number % 10);
            number /= 10;
        }
        while (digits.size() < s.length()) {
            digits.add(0);
        }
        Collections.reverse(digits);
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '?') continue;
            if (s.charAt(i) - '0' != digits.get(i)) return false;
        }
        return true;
    }

    public static String print(int number, int length) {
        List<Integer> digits = new ArrayList<>();
        while (number > 0) {
            digits.add(number % 10);
            number /= 10;
        }
        while (digits.size() < length) {
            digits.add(0);
        }
        Collections.reverse(digits);
        String res = "";
        for (int x : digits) res += (char)('0' + x);
        return res;
    }

    public static void main(String[] args) throws FileNotFoundException {
        final Scanner reader = new Scanner(new File(args[0] + ".in"));
        final PrintWriter writer = new PrintWriter(new File(args[0] + ".out"));
        final int testsCount = reader.nextInt();
        for (int test = 0; test < testsCount; ++test) {
            String a = reader.next();
            String b = reader.next();
            int bestDelta = 1000000000;
            int bestA = 10000;
            int bestB = 10000;
            for (int va = 0; va < pow(10, a.length()); ++va)
                for (int vb = 0; vb < pow(10, b.length()); ++vb) {
                    if (matches(a, va) && matches(b, vb)) {
                        if (Math.abs(va - vb) < bestDelta) {
                            bestDelta = Math.abs(va - vb);
                            bestA = va;
                            bestB = vb;
                        }
                    }
                }
            writer.write(String.format("Case #%d: %s %s\n", test + 1, print(bestA, a.length()),
                    print(bestB, b.length())));
        }
        reader.close();
        writer.close();
    }
}
