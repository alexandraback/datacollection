import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {
    private static final String inFile = "C-small-attempt0 (1).in";
    private static final String outFile = "C-out.txt";

    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(new FileReader(inFile));
        int T = scanner.nextInt();
        FileWriter fw = new FileWriter(outFile);

        for (int t = 1; t <= T; ++t) {
            int c = scanner.nextInt();
            int n = scanner.nextInt();
            int v = scanner.nextInt();
            int[] d = new int[n];
            for (int i = 0; i < n; ++i) {
                d[i] = scanner.nextInt();
            }
            fw.write(String.format("Case #%d: %s\n", t, solve(c, v, d)));
        }
        fw.close();
    }

    static int[] D = new int[5];
    static int[] sol = null;

    static int C, V;

    private static void brute(int idx) {
        if (idx == D.length) {
            if (good(C, V, D) == 1 && sol == null) {
                sol = new int[D.length];
                for (int i = 0; i < D.length; ++i) {
                    sol[i] = D[i];
                }
            }
        }
        else {
            Set<Integer> s = new HashSet<Integer>();
            for (int i = 0; i < idx; ++i) s.add(D[i]);
            for (int i = 1; i <= V; ++i) {
                if (s.contains(i)) continue;
                D[idx] = i;
                brute(idx + 1);
            }
        }
    }

    private static int good(int c, int v, int[] d) {
        boolean[] a = new boolean[v + 1];
        boolean[] na = new boolean[v + 1];
        a[0] = true;
        for (int i = 0; i < d.length; ++i) {
            for (int j = 1; j <= c; ++j) {
                for (int k = 0; k <= v; ++k) {
                    na[k] = false;
                }
                for (int k = 0; k <= v; ++k) {
                    int nk = k + d[i] * j;
                    if (a[k] && nk <= v) na[nk] = true;
                }
                for (int k = 0; k <= v; ++k) {
                    if (na[k]) a[k] = true;
                }
            }
        }
        boolean good = true;
        for (int i = 0; i <= v; ++i)
            good &= a[i];
        return good ? 1 : 0;
    }

    private static int solve(int c, int v, int[] d) {
        C = c;
        V = v;
        int n = d.length;
        for (int i = 0; i < 10; ++i) {
            D = new int[n + i];
            for (int j = 0; j < n; ++j) {
                D[j] = d[j];
            }
            sol = null;
            brute(n);
            if (sol != null) {
                return i;
            }
        }
        return -1;
    }
}
