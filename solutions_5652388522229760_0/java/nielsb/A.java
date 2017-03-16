package codejam;

import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

public class A {

    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        scanner.useLocale(Locale.US);
        int T = scanner.nextInt();
        for (int t = 1; t <= T; t++) {
            String solution = solve(scanner);
            System.out.println("Case #" + t + ": " + solution);
        }
    }

    private static String solve(Scanner scanner) {
        int N = scanner.nextInt();

        if (N == 0) {
            return "INSOMNIA";
        }

        Set<Integer> digits = new HashSet<>(10);
        int n = 0;

        while (digits.size() < 10) {
            n += N;

            String s = Integer.toString(n);
            for (int i = 0; i < s.length(); i++) {
                int digit = Integer.parseInt(s.charAt(i) + "");
                digits.add(digit);
            }
        }
        return n + "";
    }

}
