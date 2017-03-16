package round1;

import java.io.*;

/**
 * @author Anton Tychyna
 */
public class Consonants {
    public static void main(String[] args) throws IOException {
        Problem p = new Problem('a', true, 0);
        LineNumberReader r = new LineNumberReader(new FileReader("/Users/ant/Downloads/" + inputFile(p)));
        PrintWriter w = new PrintWriter(new FileWriter("/Users/ant/google/" + outputFile(p)));
        int n = Integer.parseInt(r.readLine());
        for (int i = 0; i < n; i++) {
            String[] s = r.readLine().split(" ");
            String str = s[0];
            int t = Integer.parseInt(s[1]);
            w.println("Case #" + (i + 1) + ": " + solve(str, t));
        }
        r.close();
        w.close();
    }

    private static int solve(String s, int t) {
        int n = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j <= s.length(); j++) {
                if (hasAtLeast(s.substring(i, j), t)) {
                    n++;
                }
            }
        }
        return n;
    }

    private static boolean hasAtLeast(String s, int t) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!isVowel(s.charAt(i))) {
                count++;
            } else {
                count = 0;
            }
            if (count >= t) {
                return true;
            }
        }
        return false;
    }

    private static boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    // helper methods, not related to problem being solved
    private static String inputFile(Problem p) {
        if (p.small) {
            return p.c + "-small-attempt" + p.attempt + ".in";
        } else {
            return p.c + "-large-" + ".in";
        }
    }

    private static String outputFile(Problem p) {
        if (p.small) {
            return p.c + "-small.out";
        } else {
            return p.c + "-large.out";
        }
    }

    private static class Problem {
        char c;
        boolean small;
        int attempt;

        private Problem(char c, boolean small, int attempt) {
            this.c = Character.toUpperCase(c);
            this.small = small;
            this.attempt = attempt;
        }
    }
}
