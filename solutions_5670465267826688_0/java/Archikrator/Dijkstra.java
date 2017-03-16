package google.codejam_2015;

import java.util.Scanner;

public class Dijkstra {

    static int[][] multTable = {
        {1, 2, 3, 4},
        {2, -1, 4, -3},
        {3, -4, -1, 2},
        {4, 3, -2, -1}
    };

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        for (int i = 0; i < t; i++) {
            int l = s.nextInt();
            long x = s.nextLong();
            String pattern = s.next();
            System.out.printf("Case #%d: %s%n", i + 1, solve(pattern, x));

        }
    }

    private static String solve(String patternString, long reps) {
        int[] pattern = new int[patternString.length()];
        char[] patternChars = patternString.toCharArray();
        for (int i = 0; i < patternChars.length; i++) {
            char c = patternChars[i];
            if (c == 'i') {
                pattern[i] = 2;
            } else if (c == 'j') {
                pattern[i] = 3;
            } else if (c == 'k') {
                pattern[i] = 4;
            }
        }
        long chain = reps * pattern.length;
//        
        int current = 1;
        int lookingFor = 2;

        for (int idx = 0; idx < chain; idx++) {
            int c = pattern[(int) (idx % pattern.length)];
            current = multiply(current, c);
            if (current == lookingFor && lookingFor != 1) {
                lookingFor++;
                current = 1;
                if (lookingFor == 5) {
                    lookingFor = 1;
                }
            }
        }
        boolean result = lookingFor == 1 && current == 1;


        return result ? "YES" : "NO";
    }

    private static int multiply(int c1, int c2) {
        boolean sgn = (c1 * c2) > 0;
        int mul = multTable[Math.abs(c1)-1][Math.abs(c2)-1];
        if (!sgn) {
            mul *= -1;
        }
        return mul;
    }
}
