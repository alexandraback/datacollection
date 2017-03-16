import java.io.File;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Alexander Gulko
 */
public class ProblemC2 {

    private String best;

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

        String file = "C-small-attempt0";

        String inFile = file + ".in";
        System.setOut(new PrintStream(file + ".out"));

        Scanner scan = new Scanner(new File(inFile));

        ProblemC2 problem = new ProblemC2();

        int tests = scan.nextInt();
        for (int test = 1; test <= tests; ++test) {
            problem.solve(test, scan);
        }

        scan.close();
    }

    private int n;
    private int l;
    private boolean[][] ma;
    private Set<Integer>[] adj;
    private int[] zip;
    private boolean[] visited;

    void solve(int test, Scanner scan) {
        n = scan.nextInt();
        int m = scan.nextInt();


        visited = new boolean[n + 1];
        adj = new Set[n + 1];
        zip = new int[n + 1];
        ma = new boolean[n + 1][n + 1];

        for (int i = 1; i <= n; ++i) {
            zip[i] = scan.nextInt();
        }
        for (int i = 1; i <= n; ++i) {
            adj[i] = new HashSet<Integer>();
        }

        for (int i = 0; i < m; ++i) {
            int v1 = scan.nextInt();
            int v2 = scan.nextInt();

            adj[v1].add(v2);
            adj[v2].add(v1);
            ma[v1][v2] = ma[v2][v1] = true;
        }

        int[] perm = new int[n];
        for (int i = 0; i < n; ++i) {
            perm[i] = i + 1;
        }

        best = null;
        do {
            if (check(perm)) {
                String dist = calc(perm);
                if (best == null || dist.compareTo(best) < 0) {
                    best = dist;
                }
            }
        } while (next(perm));

        System.out.printf("Case #%s: %s\n", test, best);
    }

    boolean next(int[] perm) {
        if (perm.length < 2) {
            return false;
        }

        int i = perm.length - 2;
        while (i >= 0 && perm[i] > perm[i + 1]) {
            --i;
        }

        if (i < 0) {
            i = 0;
        }
        if (i == 0 && perm[i] > perm[i + 1]) {
            return false;
        }

        int k = perm.length - 1;
        while (k > i && perm[k] < perm[i]) {
            --k;
        }

        swap(perm, i, k);

        int start = i + 1;
        int end = perm.length - (perm.length - start) / 2;
        for (i = start; i < end; ++i) {
            swap(perm, i, perm.length - 1 - (i - start));
        }
        return true;
    }

    void swap(int[] a, int i, int k) {
        int t = a[i];
        a[i] = a[k];
        a[k] = t;
    }

    boolean check(int[] perm) {
        for (int i = 1; i < perm.length; ++i) {
            int v = perm[i];
            boolean can = false;
            for (int k = i; k >= 0; --k) {
                int v2 = perm[k];
                if (ma[v][v2]) {
                    can = true;
                    break;
                }
            }
            if (!can) {
                return false;
            }
        }
        return true;
    }

    String calc(int[] perm) {
        StringBuilder r = new StringBuilder();
        for (int v : perm) {
            r.append(zip[v]);
        }
        return r.toString();
    }
}
