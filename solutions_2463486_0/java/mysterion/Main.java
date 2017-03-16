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
            int A = sc.nextInt();
            int B = sc.nextInt();
            for (int i = A; i <= B; ++i) {
                if (isFairAnfSquare(i)) {
                    ++ret;
                }
            }
            out.println("Case #" + t + ": " + ret);
            out.flush();
        }
        out.close();
    }

    private static boolean isFairAnfSquare(int i) {
        String s = String.valueOf(i);
        int x = (int) Math.sqrt(i);
        if (x * x == i && isPalindrome(s) && isPalindrome(String.valueOf(x))) {
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
