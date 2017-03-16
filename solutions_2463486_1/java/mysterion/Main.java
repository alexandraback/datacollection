package topcoder;

import java.io.PrintWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int T = sc.nextInt();
        for (int t = 1; t <= T; ++t) {
            int ret = 0;
            long A = sc.nextLong();
            long B = sc.nextLong();
            long sA = (long) Math.sqrt(A);
            long sB = (long) Math.sqrt(B);
            for (long i = sA; i <= sB; ++i) {
                if (i * i >= A && i * i <= B && isFairAndSquare(i)) {
                    ++ret;
                }
            }
            out.println("Case #" + t + ": " + ret);
            out.flush();
        }
        out.close();
    }

    private static boolean isFairAndSquare(long i) {
        String s = String.valueOf(i);
        long x = i * i;
        if (isPalindrome(s) && isPalindrome(String.valueOf(x))) {
            return true;
        }
        return false;
    }

    private static boolean isPalindrome(String s) {
        int i;
        int n = s.length();
        for (i = 0; i < n / 2 && s.charAt(i) == s.charAt(n - i - 1); ++i);
        if (i == n / 2) {
            return true;
        }
        return false;
    }
}
