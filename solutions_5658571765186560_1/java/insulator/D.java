package Qualification2015;

import java.util.Scanner;

public class D {
    private static boolean solve(int x, int r, int c) {
        if (r < c)
            return solve(x, c, r);
        if ((r * c) % x != 0)
            return true;
        if (x > r)
            return true;
        if (x >= 7)
            return true;
        if (x >= 2 * c + 1)
            return true;
        if (r == c && x >= (c + 1))
            return true;
        if (c == 1) {
            if (x == 1 || x == 2)
                return false;
            return true;
        }
        if (c == 2) {
            if (x >= 4)
                return true;
            return false;
        }
        if (c == 3) {
            if (x >= 6)
                return true;
            return false;
        }
        if (c == 4) {
            if (x >= 8)
                return true;
            return false;
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int testCase = 1; testCase <= T; ++testCase) {
            int x = sc.nextInt();
            int r = sc.nextInt();
            int c = sc.nextInt();
            System.out.printf("Case #%d: ", testCase);
            if (solve(x, r, c))
                System.out.println("RICHARD");
            else
                System.out.println("GABRIEL");
        }
    }
}