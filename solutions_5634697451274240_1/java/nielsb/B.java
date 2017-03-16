package codejam;

import java.util.*;

public class B {

    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        scanner.nextLine();
        for (int t = 1; t <= T; t++) {
            String solution = solve(scanner);
            System.out.println("Case #" + t + ": " + solution);
        }
    }

    private static String solve(Scanner scanner) {
        String S = scanner.nextLine();

        int flips = 0;
        char flipChar = '-';

        for (int i = S.length() - 1; i >= 0; i--) {
            if (S.charAt(i) == flipChar) {
                flipChar = (flipChar == '+') ? '-' : '+';
                flips++;
            }
        }

        return flips + "";
    }

}
