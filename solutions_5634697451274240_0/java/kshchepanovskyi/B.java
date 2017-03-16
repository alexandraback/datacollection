import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;

/**
 * @author Kostiantyn Shchepanovskyi
 */
public class B {


    private final FastScanner sc;
    private final PrintWriter pw;

    public B(String f) throws FileNotFoundException {
        sc = new FastScanner(new FileInputStream("src/main/resources/" + f + ".in"));
        pw = new PrintWriter("src/main/resources/" + f + ".out");


    }

    public static void main(String[] args) throws FileNotFoundException {
        B a = new B("B-small-attempt0");
        a.solve();
        a.flush();
    }

    private static long solution(char s[]) {
        boolean flipRequired = s[0] == '-';
        if (flipRequired) {
            return solution1(s) + 1;
        }
        return solution1(s);
    }

    private static long solution1(char s[]) {
        int n = s.length;
        int i = 1;
        while (i < n && s[i] == s[i-1]) {
            i++;
        }
        if (i == n) {
            return 0;
        } else {
            char s1[] = Arrays.copyOfRange(s, i, n);
            reverse(s1);
            return 1 + solution1(s1);
        }
    }

    char inverse(char c) {
        if (c == '-') {
            return '+';
        } else {
            return '-';
        }
    }

    void solve() {

        int tests = sc.nextInt();
        for (int test = 0; test < tests; test++) {
            String s = sc.next();
            char[] array = s.toCharArray();
            reverse(array);
            printResult(test, solution(array));
        }
    }

    static void reverse(char[] a) {
        for (int i = 0; i*2 < a.length; i++) {
            int j = a.length - 1 - i;
            char tmp = a[i];
            a[i] = a [j];
            a[j] = tmp;
        }
    }

    void flush() {
        pw.close();
    }

    void printResult(int testCase, long result) {
        pw.printf("Case #%d: %d\n", testCase + 1, result);
    }

}
