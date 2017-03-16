import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Q1 {

    public static String solve(String s) {

        List<Integer> res = new ArrayList<>();

        Map<Character, Integer> m = new HashMap<>();
        for (char c : s.toCharArray()) {
            Integer i = m.get(c);
            if (i == null) {
                m.put(c, 1);
            } else {
                m.put(c, i + 1);
            }
        }

        int[] seq = {0, 4, 8, 6, 5, 3, 2, 1, 7, 9};
        String[] digits = {"ZERO", "FOUR", "EIGHT", "SIX", "FIVE", "THREE", "TWO", "ONE", "SEVEN", "NINE"};
        for (int i = 0; i < digits.length; i++) {
            String digit = digits[i];
            boolean hasMore = true;
            for (char c : digit.toCharArray()) {
                if (m.get(c) == null || m.get(c) == 0) {
                    hasMore = false;
                }
                if ((digit.equals("THREE") || digit.equals("SEVEN"))
                        && c == 'E' && (m.get(c) == null || m.get(c) <= 1)) {
                    hasMore = false;
                }
                if ((digit.equals("NINE"))
                        && c == 'N' && (m.get(c) == null || m.get(c) <= 1)) {
                    hasMore = false;
                }
            }
            if (hasMore) {
                res.add(seq[i]);
                for (char c : digit.toCharArray()) {
                    m.put(c, m.get(c) - 1);
                }
                i--;
            }
        }

        Collections.sort(res);
        StringBuilder sb = new StringBuilder();
        for (Integer i : res) {
            sb.append(i);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
        in.nextLine();
        for (int i = 1; i <= t; ++i) {
            String s = in.nextLine();
            System.out.println("Case #" + i + ": " + solve(s));
        }
    }

}
