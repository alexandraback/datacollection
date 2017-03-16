import java.util.Scanner;


public class GCJ2015R1C_B {

    private static final double EPS = 1e-12;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: %.10f%n", i, new GCJ2015R1C_B().solve(sc));
        }
    }

    /**
     * http://www.prefield.com/algorithm/string/knuth_morris_pratt.html
     */
    int[] buildFail(String p) {
        int m = p.length();
        int[] fail = new int[m + 1];
        int j = fail[0] = -1;
        for (int i = 1; i <= m; ++i) {
            while (j >= 0 && p.charAt(j) != p.charAt(i - 1))
                j = fail[j];
            fail[i] = ++j;
        }
        return fail;
    }
    
    int proceed(char c, String p, int[] fail, int state) {
        while (state >= 0 && p.charAt(state) != c) state = fail[state];
        state++;
        return state;
    }
    
    int match(String t, String p, int[] fail) {
        int n = t.length(), m = p.length();
        int count = 0;
        for (int i = 0, k = 0; i < n; ++i) {
          while (k >= 0 && p.charAt(k) != t.charAt(i)) k = fail[k];
          k++;
          if (k >= m) {
            ++count; // match at t[i-m+1 .. i]
            k = fail[k];
          }
        }
        return count;
      }

    private double solve(Scanner sc) throws Exception {
        int k = sc.nextInt();
        int l = sc.nextInt();
        int s = sc.nextInt();
        String keys = sc.next();
        String target = sc.next();
        double[] chooseProb = new double[256];
        for (int i = 0; i < keys.length(); i++) {
            chooseProb[keys.charAt(i)]++;
        }
        for (int i = 0; i < chooseProb.length; i++) {
            chooseProb[i] /= k;
        }
        int[] fail = buildFail(target);
        int maxBananas = 0;
        for (int i = 0, state = 0; i < s; i++) {
            if (chooseProb[target.charAt(state)] > 0) state++;
            else return 0;
            if (state >= l) {
                maxBananas++;
                state = fail[state];
            }
        }
        
        double[][][] dp = new double[maxBananas+1][s+1][l];
        // dp[i][j][k]: i本バナナ持ってて、j-1文字目まで書いて、状態がkになる確率
        dp[0][0][0] = 1;
        for (int i = 0; i <= maxBananas; i++) {
            for (int j = 0; j < s; j++) {
                for (int st = 0; st < l; st++) {
                    double curP = dp[i][j][st];
                    if (dp[i][j][st] < EPS) continue;
                    for (char c = 'A'; c <= 'Z'; c++) {
                        double p = chooseProb[c];
                        if (p == 0) continue;
                        int nextSt = proceed(c, target, fail, st);
                        int nextBanana = i;
                        if (nextSt >= l) {
                            nextBanana++;
                            nextSt = fail[nextSt];
                        }
                        dp[nextBanana][j+1][nextSt] += curP * p;
                    }
                }
            }
        }
        double e = 0;
        for (int i = 0; i <= maxBananas; i++) {
            for (int st = 0; st < l; st++) {
                e += i * dp[i][s][st];
            }
        }

        return maxBananas - e;
    }
}
