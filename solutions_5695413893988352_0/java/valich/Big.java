package B;

import org.junit.Assert;

import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Big {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            final int T = in.nextInt();
            for (int i = 0; i < T; i++) {
                final String a = in.next();
                final String b = in.next();
                Assert.assertEquals(solveDull(a, b), solve(a, b));
                System.out.printf("Case #%d: %s\n", i + 1, solve(a, b));
            }
        }
    }
    
    private static String solveDull(String first, String second) {
        final int len = first.length();
        final int max = (int)Math.pow(10, len);

        String best = "00000 99999";
        
        for (int i = 0; i < max; i++) {
            for (int j = 0; j < max; j++) {
                String a = "000" + String.valueOf(i);
                String b = "000" + String.valueOf(j);
                a = a.substring(a.length() - len);
                b = b.substring(b.length() - len);
                
                
                StringBuilder s1 = new StringBuilder(first);
                StringBuilder s2 = new StringBuilder(second);
                for (int k = 0; k < len; k++) {
                    if (s1.charAt(k) == '?') s1.setCharAt(k, a.charAt(k));
                    if (s2.charAt(k) == '?') s2.setCharAt(k, b.charAt(k));
                }
                
                best = getBest(best, s1 + " " + s2);
            }
        }
        return best;
    }

    private static String solve(String first, String second) {
        final StringBuilder s1 = new StringBuilder(first);
        final StringBuilder s2 = new StringBuilder(second);

        Assert.assertEquals(s1.length(), s2.length());

        String best = null;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) == '?' && s2.charAt(i) == '?') {
                s1.setCharAt(i, '1');
                s2.setCharAt(i, '0');
                best = getBest(best, solveWithDiff(s1.toString(), s2.toString(), 1));

                s1.setCharAt(i, '0');
                s2.setCharAt(i, '1');
                best = getBest(best, solveWithDiff(s1.toString(), s2.toString(), -1));
                        
                s1.setCharAt(i, '0');
                s2.setCharAt(i, '0');
            }
            else if (s1.charAt(i) != '?' && s2.charAt(i) != '?') {
                int seenDiff = s1.charAt(i) - s2.charAt(i);
                if (seenDiff != 0) {
                    best = getBest(best, solveWithDiff(s1.toString(), s2.toString(), seenDiff));
                    return best;
                }
            }
            else if (s1.charAt(i) == '?') {
                if (s2.charAt(i) != '9') {
                    s1.setCharAt(i, (char)(s2.charAt(i) + 1));
                    best = getBest(best, solveWithDiff(s1.toString(), s2.toString(), 1));
                }
                if (s2.charAt(i) != '0') {
                    s1.setCharAt(i, (char)(s2.charAt(i) - 1));
                    best = getBest(best, solveWithDiff(s1.toString(), s2.toString(), -1));
                }
                s1.setCharAt(i, s2.charAt(i));
            }
            else if (s2.charAt(i) == '?') {
                if (s1.charAt(i) != '9') {
                    s2.setCharAt(i, (char)(s1.charAt(i) + 1));
                    best = getBest(best, solveWithDiff(s1.toString(), s2.toString(), -1));
                }
                if (s1.charAt(i) != '0') {
                    s2.setCharAt(i, (char)(s1.charAt(i) - 1));
                    best = getBest(best, solveWithDiff(s1.toString(), s2.toString(), 1));
                }
                s2.setCharAt(i, s1.charAt(i));
            }
            else {
                throw new IllegalStateException("?");
            }
        }

        return getBest(best, s1 + " " + s2);
    }
    
    private static String solveWithDiff(String first, String second, int seenDiff) {
        final StringBuilder s1 = new StringBuilder(first);
        final StringBuilder s2 = new StringBuilder(second);

        Assert.assertEquals(s1.length(), s2.length());

        

        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) == '?') {
                s1.setCharAt(i, seenDiff < 0 ? '9' : '0');
            }
            if (s2.charAt(i) == '?') {
                s2.setCharAt(i, seenDiff > 0 ? '9' : '0');
            }
        }
        return s1 + " " + s2;
    }
    
    private static String getBest(String s1, String s2) {
        if (s1 == null) {
            return s2;
        }
        
        long d1 = getDiff(s1);
        long d2 = getDiff(s2);
        if (d1 < d2 || d1 == d2 && s1.compareTo(s2) < 0) {
            return s1;
        }
        else {
            return s2;
        }
    }

    private static long getDiff(String s1) {
        StringTokenizer st = new StringTokenizer(s1);
        return new BigInteger(st.nextToken()).subtract(new BigInteger(st.nextToken())).abs().longValue();
    }

}
