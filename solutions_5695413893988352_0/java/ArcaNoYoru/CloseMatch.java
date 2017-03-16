import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static util.FileHandler.*;

/*
That's a super ugly brute force solution...
And the code is super ugly too
 */
public class CloseMatch {

    public static void main(String[] args) {
        start();

        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        scanner.nextLine();
        for (int i = 1; i <= N; i++) {
            OUT.println(String.format("Case #%s: %s", i, solve(scanner.nextLine())));
        }

        end();
    }

    private static String solve(String s) {
        String[] split = s.split(" ");
        String a = split[0];
        String b = split[1];

        List<String> aList = new ArrayList<>();
        List<String> bList = new ArrayList<>();
        aList.add(a);
        bList.add(b);

        int diffMin = Integer.MAX_VALUE;
        int minA = Integer.MAX_VALUE;
        int minB = Integer.MAX_VALUE;

        List<String> possibleA = computeAllPossible(aList);
        List<String> possibleB = computeAllPossible(bList);

        for (String a2 : possibleA) {
            for (String b2 : possibleB) {
                int abs = Math.abs(Integer.valueOf(a2) - Integer.valueOf(b2));

                if (abs < diffMin) {
                    diffMin = abs;
                    minA = Integer.valueOf(a2);
                    minB = Integer.valueOf(b2);
                } else if (abs == diffMin) {
                    if (Integer.valueOf(a2) < minA) {
                        minA = Integer.valueOf(a2);
                        minB = Integer.valueOf(b2);
                    } else if (Integer.valueOf(b2) < minB) {
                        minB = Integer.valueOf(b2);
                    }
                }
            }
        }

        return prepend(minA, a.length()) + " " + prepend(minB, b.length());
    }

    private static String prepend(int minA, int n) {
        String val = String.valueOf(minA);

        while (val.length() < n) {
            val = "0" + val;
        }

        return val;
    }

    private static List<String> computeAllPossible(List<String> strings) {
        List<String> all = new ArrayList<>();
        for (String string : strings) {
            if (string.contains("?")) {
                for (int i = 0; i < 10; i++) {
                    all.add(string.replaceFirst("\\?", String.valueOf(i)));
                }
            } else {
                return strings;
            }
        }

        return computeAllPossible(all);

    }

}
