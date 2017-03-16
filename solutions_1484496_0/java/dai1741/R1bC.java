import java.util.Scanner;


public class R1bC {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            solve(sc, i);
        }
    }
    static int as = 0;
    static int bs = 0;
    static int n = 0;
    static int[] s;
    
    static void dfs(int as, int bs, int aSum, int bSum, int cur) {
        if (aSum != 0 && aSum == bSum) {
            R1bC.as = as;
            R1bC.bs = bs;
        }
        if (R1bC.as != 0 || cur >= n) {
            return;
        }
        dfs(as, bs, aSum, bSum, cur + 1);
        dfs(as | (1 << cur), bs, aSum + s[cur], bSum, cur + 1);
        dfs(as, bs | (1 << cur), aSum, bSum + s[cur], cur + 1);
    }
    
    static void solve(Scanner sc, int t) {
        n = sc.nextInt();
        s = new int[20];
        for (int i = 0; i < n; i++) {
            s[i] = sc.nextInt();
        }
        as = bs = 0;
        dfs(0, 0, 0, 0, 0);
        StringBuilder sb = new StringBuilder("Case #"+ t + ":");
        if (as == 0) {
            sb.append(" Impossible");
        }
        sb.append("\n");
        appendEm(sb, as);
        sb.append("\n");
        appendEm(sb, bs);
        System.out.println(sb);
    }
    
    static void appendEm(StringBuilder sb, int mask) {
        boolean isFirst = true;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;
            if (isFirst) {
                isFirst = false;
            }
            else {
                sb.append(" ");
            }
            sb.append(s[i]);
        }
    }
}
