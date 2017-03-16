import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.StringJoiner;

/**
 * @author Kostiantyn Shchepanovskyi
 */
public class D {

    private final FastScanner sc;
    private final PrintWriter pw;

    public D(String f) throws FileNotFoundException {
        sc = new FastScanner(new FileInputStream("src/main/resources/" + f + ".in"));
        pw = new PrintWriter("src/main/resources/" + f + ".out");


    }

    public static void main(String[] args) throws FileNotFoundException {
//        D a = new D("test");
        D a = new D("D-small-attempt1");
        a.solve();
        a.flush();
    }

    private List<String> solution(int k, int c, int s) {
        List<String> result = new ArrayList<>();
//        for(int i=0; i<(1<<k); i++) {
//            String f = toFractal(i, k);
//            System.out.println(f + " --> " + iter(f, c-1));
//        }
//        if (c == 1) {
            if (s < k) {
                result.add("IMPOSSIBLE");
            } else {
                for (int i = 0; i < k; i++) {
                    result.add(String.valueOf(i+1));
                }
            }
//        } else {
//            if (s < k || s < k - 1) {
//                result.add("IMPOSSIBLE");
//            } else {
//                for (int i = 1; i < k; i++) {
//                    result.add(String.valueOf(i + 1));
//                }
//            }
//        }
        return result;
    }

    private String iter(String f, int c) {
        if (c == 0) {
            return f;
        }
        if (c == 1) {
            return iter(f);
        } else {
            return iter(iter(f, c-1));
        }
    }

    private String iter(String f) {
        StringBuilder sb = new StringBuilder();
        for (char c : f.toCharArray()) {
            if (c == 'L') {
                sb.append(f);
            } else {
                for (int i = 0; i < f.length(); i++) {
                    sb.append('G');
                }
            }
        }

        return sb.toString();
    }

    private String toFractal(int i, int k) {
        char f[] = new char[k];
        for (int j = 0; j < k; j++) {
            f[j] = toPlate(i%2);
            i = i / 2;
        }
        return new String(f);
    }

    private char toPlate(int i) {
        if (i == 0) {
            return 'L';
        } else {
            return 'G';
        }
    }

    void solve() {

        int tests = sc.nextInt();
        for (int test = 0; test < tests; test++) {
            int k = sc.nextInt();
            int c = sc.nextInt();
            int s = sc.nextInt();
            printResult(test, solution(k, c, s));
        }
    }

    void flush() {
        pw.close();
    }

    void printResult(int testCase, List<String> result) {
        pw.printf("Case #%d: %s\n", testCase + 1, String.join(" ", result));

    }

}
