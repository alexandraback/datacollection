// @gilesgardam
import java.util.*;
import static java.lang.Math.*;

public class ProblemC {

    long[] fas;
    long LIMIT = 100000000000000L;

    void run() {
        Scanner sc = new Scanner(System.in);
        cache();
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            long A = sc.nextLong();
            long B = sc.nextLong();
            int i = 0;
            int j = fas.length-1;
            while (fas[i] < A) {
                ++i;
            }
            while (fas[j] > B) {
                --j;
            }
            System.out.printf("Case #%d: %d\n", caseNum, j - i + 1);
        }
    }

    void cache() {
        List<Long> fasl = new ArrayList<Long>();
        for (long y = 1; y * y < LIMIT; ++y) {
            if (is_palindrome(y) && is_palindrome(y*y)) {
                fasl.add(y*y);
            }
        }
        int n = fasl.size();
        fas = new long[n];
        for (int i = 0; i < n; ++i) {
            fas[i] = fasl.get(i);
        }
    }

    String rev(String s) {
        int n = s.length();
        char[] c = new char[n];
        for (int i = 0; i < n; ++i) {
            c[i] = s.charAt(n-1-i);
        }
        return new String(c);
    }

    boolean is_palindrome(long x) {
        String s = "" + x;
        int n = s.length();
        for (int i = 0; i < n/2; ++i) {
            if (s.charAt(i) != s.charAt(n-1-i)) {
                return false;
            }
        }
        return true;
    }

    boolean debug = false;
    void p(String f, Object...params) {
        System.out.printf(f, params);
    }
    void d(Object...params) {
        if (debug) {
            p("DEBUG: %s\n", Arrays.deepToString(params));
        }
    }
    void die() {
        throw new RuntimeException();
    }
    public ProblemC(String[] args) {
        if (args.length > 0 && args[0].equals("debug")) {
            debug = true;
        }
    }
    public static void main(String[] args) {
        new ProblemC(args).run();
    }
}
