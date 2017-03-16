package ma;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @author fly
 */
public class Counter {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new FileInputStream(args[0]));
        try (PrintWriter out = new PrintWriter(new FileOutputStream(args[0].replaceAll("\\.in", ".out")))) {
            int nTestCases = scanner.nextInt();
            for (int i = 1; i <= nTestCases; ++i) {
                long N = scanner.nextLong();
                out.println(String.format("Case #%d: %d", i, solve(N)));
            }
        }
    }

    private static Map<String, Integer> solutions = new HashMap<>(10000);
    private static long max = 1;

    static {
        solutions.put("1", 1);
    }

    private static int solve(long N) {
        for (long i = max + 1; i <= N; ++i) {
            String s = Long.toString(i);
            Integer fromRev = solutions.get(reverse(s));
            if (fromRev == null) fromRev = Integer.MAX_VALUE;
            int prev = solutions.get(Long.toString(i - 1));
            solutions.put(s, Math.min(fromRev, prev) + 1);
        }
        if (N > max) max = N;
        return solutions.get(Long.toString(N));
    }

    private static String reverse(String cur) {
        char[] chars = cur.toCharArray();
        int length = chars.length;
        for (int i = 0; i < length / 2; ++i) {
            char c = chars[i];
            chars[i] = chars[length - i - 1];
            chars[length - i - 1] = c;
        }
        return new String(chars);
    }
}
