package google.codejam_2015;

import java.util.Scanner;

public class Omino {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        for (int i = 0; i < t; i++) {
            int omino = s.nextInt();
            int x = s.nextInt();
            int y = s.nextInt();

            System.out.printf("Case #%d: %s%n", i + 1, b2s(solve(omino, x, y)));
        }
    }

    private static boolean solve(int omino, int x, int y) {
        if (x * y % omino != 0) {
            return false;
        }
        if (omino > 6) {
            return false;
        }
        if (omino > Math.max(x, y)) {
            return false;
        }
        if (omino > 2 * Math.min(x, y)) {
            return false;
        }
        if (omino == 4 && Math.min(x, y) == 2) {
            return false;
        }
        return true;

    }

    static String b2s(boolean b) {
        return b ? "GABRIEL" : "RICHARD";
    }
}
