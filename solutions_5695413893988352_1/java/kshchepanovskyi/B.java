import qualification.FastScanner;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

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
        B a = new B("B-large");
        a.solve();
        a.flush();
    }

    void solve() {

        int tests = sc.nextInt();
        for (int test = 0; test < tests; test++) {
            String a = sc.next();
            String b = sc.next();
            printResult(test,  solution(a, b));
        }
    }

    class Res {
        String a;
        String b;

        long diff;

        public Res(String a, String b) {
            this.a = a;
            this.b = b;
            long x = Long.valueOf(a);
            long y = Long.valueOf(b);
            diff = x-y;
            if (diff < 0) {
                diff = -diff;
            }
        }

        @Override
        public String toString() {
            final StringBuilder sb = new StringBuilder("Res{");
            sb.append("a='").append(a).append('\'');
            sb.append(", b='").append(b).append('\'');
            sb.append(", diff=").append(diff);
            sb.append('}');
            return sb.toString();
        }
    }
    private Res solution(String a, String b) {
        char aa = a.charAt(0);
        char bb = b.charAt(0);
        boolean av = false;
        boolean bv = false;
        if (aa == '?' && bb == '?') {
            aa = '0';
            bb = '0';
            av = true;
            bv = true;
        } else if (aa == '?') {
            aa = bb;
            av = true;
        } else if (bb == '?') {
            bb = aa;
            bv = true;
        }
        if (a.length() == 1) {
            return new Res(String.valueOf(aa), String.valueOf(bb));
        }
        String aRest = a.substring(1);
        String bRest = b.substring(1);
        if (aa < bb) {
            return new Res(aa + max(aRest), bb + min(bRest));
        }
        if (aa > bb) {
            return new Res(aa + min(aRest), bb + max(bRest));
        }
        Res sub = solution(aRest, bRest);
        List<Res> res = new ArrayList<>();
        res.add(new Res(aa + sub.a, bb + sub.b));
        if (av) {
            if (aa < '9') {
                res.add(new Res((char)(aa+1) + min(aRest), bb + max(bRest)));
            }
            if (aa > '0') {
                res.add(new Res((char)(aa-1) + max(aRest), bb + min(bRest)));
            }
        }
        if (bv) {
            if (bb < '9') {
                res.add(new Res(aa + max(aRest), (char)(bb+1) + min(bRest)));
            }
            if (bb > '0') {
                res.add(new Res(aa + min(aRest), (char)(bb-1) + max(bRest)));
            }
        }
        Res min = res.get(0);
        for (Res r : res) {
            if (r.diff < min.diff) {
                min = r;
            }
            if (r.diff == min.diff) {
                if (r.a.compareTo(min.a) < 0) {
                    min = r;
                }
                if (r.a.compareTo(min.a) == 0) {
                    if (r.b.compareTo(min.b) < 0) {
                        min = r;
                    }
                }
            }
        }
        return min;
    }

    String min(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '?') {
                sb.append('0');
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }

    String max(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '?') {
                sb.append('9');
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }

    private int id(char c) {
        return c-'A';
    }


    void flush() {
        pw.close();
    }

    void printResult(int testCase, Res result) {
        pw.printf("Case #%d: %s %s\n", testCase + 1, result.a, result.b);
    }

}
