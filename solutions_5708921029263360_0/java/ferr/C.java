import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class C {
    static PrintWriter pw;
    static Scanner sc;

    public static void main(String[] args) {
        pw = new PrintWriter(System.out);
        sc = new Scanner(System.in);

        new C().run();
        pw.flush();
    }

    private void run() {
        int T = sc.nextInt();
        for (int t = 0; t < T; ++t) {
            System.err.printf("Case %d of %d\n", t + 1, T);
            pw.printf("Case #%d: %s\n", t + 1, nextCase(t));
        }
    }

    final int MAXQ = 11;

    int J, P, S, K;

    int[] JP = new int[MAXQ * MAXQ];
    int[] PS = new int[MAXQ * MAXQ];
    int[] JS = new int[MAXQ * MAXQ];

    ArrayList<Integer> ans = new ArrayList<>();
    int bestAns;
    String strAns = null;

    void saveAns(int d) {
        StringBuilder res = new StringBuilder();
        res.append(d);
        res.append('\n');
        for (int a : ans) {
            res.append(a / (MAXQ * MAXQ) + 1);
            res.append(' ');
            res.append(a / MAXQ % MAXQ + 1);
            res.append(' ');
            res.append(a % MAXQ + 1);
            res.append('\n');
        }
        strAns = res.toString().trim();
    }

    List<Integer> alts;

    void go(int id, int d) {
        if (d > bestAns) {
            bestAns = d;
            saveAns(d);
        }
        if (d + (alts.size() - id) < bestAns) {
            return;
        }
        for (int idn = id; idn < alts.size(); ++idn) {
            int an = alts.get(idn);
            int sn = an % MAXQ, pn = an / MAXQ % MAXQ, jn = an / (MAXQ * MAXQ);
            if (sn < S && pn < P && jn < J) {
                if (JP[jn * MAXQ + pn] < K && PS[pn * MAXQ + sn] < K && JS[jn * MAXQ + sn] < K) {
                    JP[jn * MAXQ + pn]++;
                    PS[pn * MAXQ + sn]++;
                    JS[jn * MAXQ + sn]++;
                    ans.add(an);
                    go(idn + 1, d + 1);
                    ans.remove(ans.size() - 1);
                    JS[jn * MAXQ + sn]--;
                    PS[pn * MAXQ + sn]--;
                    JP[jn * MAXQ + pn]--;
                }
            }
        }
    }

    private String nextCase(int caseNum) {
        J = sc.nextInt();
        P = sc.nextInt();
        S = sc.nextInt();
        K = sc.nextInt();
        strAns = null;
        bestAns = 0;
        alts = new ArrayList<>();
        for (int an = 0; an < MAXQ * MAXQ * MAXQ; ++an) {
            int sn = an % MAXQ, pn = an / MAXQ % MAXQ, jn = an / (MAXQ * MAXQ);
            if (sn < S && pn < P && jn < J) {
                alts.add(an);
            }
        }
        go(0, 0);
        return strAns;
    }
}