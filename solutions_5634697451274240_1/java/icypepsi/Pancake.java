package codejam2016.pancakes;

import java.util.Scanner;

public class Pancake {

    private static int minManeuver(String s) {
        int maneuvers = 0, n = s.length();
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i) != s.charAt(i - 1))
                maneuvers++;
        }
        if (s.charAt(n - 1) == '-') maneuvers++;
        return maneuvers;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < t; ++i) {
            String s = sc.nextLine();
            System.out.printf("Case #%d: %d\n", i + 1, minManeuver(s));
        }
    }
}
