package google.codejam_2015;

import java.util.Scanner;

public class Dijkstra1 {

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
            System.out.printf("Case #%d: %s%n", i + 1, b2s(solve(pattern, x)));

        }
    }

    private static boolean solve(String patternString, long reps) {
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

        boolean patternFound = false;
        int breakPoint = 30 * pattern.length;
        int idx = 0;
        while (idx < chain) {
            int c = pattern[(int) (idx % pattern.length)];

            if (idx > breakPoint) {
                return false;
            }

            idx++;
            current = multiply(current, c);
            if (current == lookingFor) {
                lookingFor++;
                current = 1;
                if (lookingFor == 5) {
                    patternFound = true;
                    break;
                }
            }
        }

        boolean result;
        if (patternFound) {
            // looking for identity
            while (idx % pattern.length != 0) {
                int c = pattern[(int) (idx % pattern.length)];
                current = multiply(current, c);
                idx++;
            }
            long remainingPower = (chain - idx) / pattern.length;
            int reduced = reducePattern(pattern);
            result = 1 == multiply(current, power(reduced, remainingPower));
        } else {
            result = false;
        }

        return result;
    }

    static String b2s(boolean b) {
        return b ? "YES" : "NO";
    }

    static int reducePattern(int[] pattern) {
        int current = 1;
        for (int i : pattern) {
            current = multiply(current, i);
        }
        return current;
    }

    static int power(int number, long power) {
        if (number == 1) {
            return 1;
        }
        int mod = (int) (power % 4);
        if (number == -1) {
            if (mod == 1 || mod == 3) {
                return -1;
            } else {
                return 1;
            }
        }
        if (mod == 0) {
            return 1;
        } else if (mod == 1) {
            return number;
        } else if (mod == 2) {
            return -1;
        } else {
            return -number;
        }
    }

    private static int multiply(int c1, int c2) {
        boolean sgn = (c1 * c2) > 0;
        int mul = multTable[Math.abs(c1) - 1][Math.abs(c2) - 1];
        if (!sgn) {
            mul *= -1;
        }
        return mul;
    }
}
