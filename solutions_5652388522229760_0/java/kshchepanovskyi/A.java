import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;

/**
 * @author Kostiantyn Shchepanovskyi
 */
public class A {


    private final FastScanner sc;
    private final PrintWriter pw;

    public static void main(String[] args) throws FileNotFoundException {
        A a = new A("A-small-attempt0");
        a.solve();
        a.flush();
    }

    public A(String f) throws FileNotFoundException {
        sc = new FastScanner(new FileInputStream("src/main/resources/" + f +".in"));
        pw = new PrintWriter("src/main/resources/" + f + ".out");


    }

    void solve() {

        int tests = sc.nextInt();
        for (int test = 0; test < tests; test++) {
            int n = sc.nextInt();
            if (n == 0) {
                printResult(test, 0);
            } else {
                printResult(test, solution(n));
            }
        }
    }

    private static long solution(int n) {
        int mask = 0;
        int i = 1;
        long t = 0;
        while(mask != ((1 << 10) - 1)) {
            t = (long)n * i;
            mask |= digitsMask(t);
            i++;
        }
        return t;
    }

    private static int digitsMask(long n) {
        int mask = 0;
        while(n > 0) {
            long digit = n%10;
            n = n / 10;
            mask = mask | 1 << digit;
        }
        return mask;
    }

    void flush() {
        pw.close();
    }

    void printResult(int testCase, long result) {
        if (result == 0) {
            pw.printf("Case #%d: INSOMNIA\n", testCase+1);
        } else {
            pw.printf("Case #%d: %d\n", testCase+1, result);
        }
    }

}
