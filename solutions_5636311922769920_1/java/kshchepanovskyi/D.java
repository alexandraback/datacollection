import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;
import java.util.stream.Collectors;

/**
 * @author Kostiantyn Shchepanovskyi
 */
public class D {

    public static final char G = '0';
    public static final char L = '1';
    private final FastScanner sc;
    private final PrintWriter pw;

    public D(String f) throws FileNotFoundException {
        sc = new FastScanner(new FileInputStream("src/main/resources/" + f + ".in"));
        pw = new PrintWriter("src/main/resources/" + f + ".out");


    }

    public static void main(String[] args) throws FileNotFoundException {
        D a = new D("D-large");
//        D a = new D("D-small-attempt1");
        a.solve();
        a.flush();
    }

    private List<String> solution(int k, int c, int s) {
        List<String> result = new ArrayList<>();
        List<String> a = new ArrayList<>();
        for (int i = 1; i < (1 << k); i *= 2) {
            String f = toFractal(i, k);
            String fractal = iter(f, f, c - 1);
            a.add(fractal);
            System.out.println(f + " --> " + fractal);
        }
        List<String> solution = null;
        for (int i = 1; i <= s; i++) {
            solution = findSolution(a, i);
            if (solution != null) {
                break;
            }
        }
        if (solution == null) {
            solution = Collections.singletonList("IMPOSSIBLE");
        }
        return solution;
    }

    private List<String> findSolution(List<String> a, int s) {
        int counter[] = new int[s];
        int n = a.get(0).length();
        for (counter[0] = 0; counter[0] < n - s + 1; counter[0]++) {

            List<String> solution = findSolutionImpl(a, counter[0]);
            if (solution != null) {
                return solution;
            }
            if (s > 1) {
                for (counter[1] = counter[0] + 1; counter[1] < n - s + 2; counter[1]++) {

                    solution = findSolutionImpl(a, counter[0], counter[1]);
                    if (solution != null) {
                        return solution;
                    }
                    if (s > 2) {
                        for (counter[2] = counter[1] + 1; counter[2] < n - s + 3; counter[2]++) {
                            solution = findSolutionImpl(a, counter[0], counter[1], counter[2]);
                            if (solution != null) {
                                return solution;
                            }

                            if (s > 3) {
                                for (counter[3] = counter[2] + 1; counter[3] < n - s + 4; counter[3]++) {
                                    solution = findSolutionImpl(a, counter[0], counter[1], counter[2], counter[3]);
                                    if (solution != null) {
                                        return solution;
                                    }
                                    if (s > 4) {
                                        for (counter[4] = counter[3] + 1; counter[4] < n - s + 5; counter[4]++) {
                                            solution = findSolutionImpl(a, counter[0], counter[1], counter[2], counter[3], counter[4]);
                                            if (solution != null) {
                                                return solution;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return null;
    }

    private List<String> findSolutionImpl(List<String> a, int... i) {
        int linesSet = 0;
        for (int j = 0; j < a.size(); j++) {
            if (oneOfIsSet(a.get(j), i)) {
                linesSet++;
            }
        }
        if (linesSet == a.size()) {
            List<String> result = new ArrayList<>();
            for (int i1 : i) {
                result.add(String.valueOf(i1 + 1));
            }
            return result;
        }
        return null;
    }

    private boolean oneOfIsSet(String s, int[] i) {
        for (int i1 : i) {
            if (s.charAt(i1) == G) {
                return true;
            }
        }

        return false;
    }

    private String iter(String source, String f, int c) {
        if (c == 0) {
            return f;
        }
        if (c == 1) {
            return iter(source, f);
        } else {
            return iter(source, iter(source, f, c - 1));
        }
    }

    private String iter(String source, String f) {
        StringBuilder sb = new StringBuilder();
        for (char c : f.toCharArray()) {
            if (c == L) {
                sb.append(source);
            } else {
                for (int i = 0; i < source.length(); i++) {
                    sb.append(G);
                }
            }
        }

        return sb.toString();
    }

    private String toFractal(int i, int k) {
        char f[] = new char[k];
        for (int j = 0; j < k; j++) {
            f[j] = toPlate(i % 2);
            i = i / 2;
        }
        return new String(f);
    }

    private char toPlate(int i) {
        if (i == 0) {
            return L;
        } else {
            return G;
        }
    }

    void solve() {

        int tests = sc.nextInt();
        for (int test = 0; test < tests; test++) {
            int k = sc.nextInt();
            int c = sc.nextInt();
            int s = sc.nextInt();
//            printResult(test, solution(k, c, s));
            printResult(test, solution2(k, c, s));
        }
    }

    private List<String> solution2(int k, int c, int s) {
        int kc = k/c + (k%c > 0 ? 1 : 0);
        int minS = Math.max(kc, 1);
        if (s < minS) {
            return Collections.singletonList("IMPOSSIBLE");
        }
        List<Long> result = new ArrayList<>();
        for(int i = 0; i < minS; i++) {
            result.add(1L);
        }
        for(int i = 0; i < k; i++) {
            int pos = i/c;
            long x = result.get(pos);
            x = x + i * pow(k, i%c);
            result.set(pos, x);
        }
        HashSet<Long> dc = new HashSet<>();
        for (Long res : result) {
            dc.addAll(decomposeToSet(k, res-1, c));
        }
        if (dc.size() != k) {
            throw new IllegalStateException();
        }

        return result.stream()
                .map(String::valueOf)
                .collect(Collectors.toList());
    }

    private Set<Long> decomposeToSet(long k, long n, long c) {
        SortedSet<Long> result = new TreeSet<>();
        while (c >= 1) {
            result.add(n % k);
            n = n / k;
            c--;
        }
        return result;
    }

    long pow(long a, long n) {
        long x = 1;
        for (int i = 0; i < n; i++) {
            x *= a;
        }
        return x;
    }

    void flush() {
        pw.close();
    }

    void printResult(int testCase, List<String> result) {
        pw.printf("Case #%d: %s\n", testCase + 1, String.join(" ", result));

    }

}
