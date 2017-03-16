import com.google.common.collect.HashMultimap;
import com.google.common.collect.SetMultimap;
import qualification.FastScanner;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;

/**
 * @author Kostiantyn Shchepanovskyi
 */
public class C {


    private final FastScanner sc;
    private final PrintWriter pw;

    public C(String f) throws FileNotFoundException {
        sc = new FastScanner(new FileInputStream("src/main/resources/" + f + ".in"));
        pw = new PrintWriter("src/main/resources/" + f + ".out");
    }

    public static void main(String[] args) throws FileNotFoundException {
        C a = new C("C-small-attempt0");
        a.solve();
        a.flush();
    }

    void solve() {

        int tests = sc.nextInt();
        for (int test = 0; test < tests; test++) {
            int n = sc.nextInt();
            List<Pair> data = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String a = sc.next();
                String b = sc.next();
                data.add(new Pair(a, b));
            }
            printResult(test,  solution(data));
        }
    }

    class Pair {
        String a;
        String b;


        public Pair(String a, String b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public String toString() {
            final StringBuilder sb = new StringBuilder("Res{");
            sb.append("a='").append(a).append('\'');
            sb.append(", b='").append(b).append('\'');
            sb.append('}');
            return sb.toString();
        }
    }

    private int solution(List<Pair> data) {
        int n = data.size();
        SetMultimap<String, String> a = HashMultimap.create();
        SetMultimap<String, String> b = HashMultimap.create();
        for (Pair pair : data) {
            a.put(pair.a, pair.b);
            b.put(pair.b, pair.a);
        }
        int count = 0;
        while (true) {
            boolean removed = false;
            loop: for (String s : a.keySet()) {
                Set<String> refs = a.get(s);
                if (refs.size() == 1) {
                    continue;
                }
                for (String ref : refs) {
                    Set<String> inverse = b.get(ref);
                    if (inverse.size() > 1) {
                        // safe to remove
                        a.remove(s, ref);
                        b.remove(ref, s);
                        removed = true;
                        count++;
                        break loop;
                    }
                }
            }
            if (!removed) {
                break;
            }
        }
        return count;
    }


    void flush() {
        pw.close();
    }

    void printResult(int testCase, int result) {
        pw.printf("Case #%d: %d\n", testCase + 1, result);
    }

}
