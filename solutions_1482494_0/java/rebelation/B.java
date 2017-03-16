import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class B{
    public static void main(String[] args) throws Exception{
        new B().run();
    }

    int n;
    int[] a;
    int[] b;
    L[] tbl;
    int[][] dp;
    private static final int INF = 1<<20;

    int dfs(int cur, int star){
        if(cur == n)return 0;
        if(dp[cur][star] != INF)return dp[cur][star];
        if(star < tbl[cur].a)return -1;
        int ret = INF;
        if(star >= tbl[cur].b){
            int r = dfs(cur+1, star+2);
            if(r >= 0)ret = min(ret, r+1);
        }
        if(star >= tbl[cur].a){
            int s = star + 1;
            if(s >= tbl[cur].b){
                int r = dfs(cur+1, star+3);
                if(r >= 0)ret = min(ret, r+2);
            }
        }
        if(ret == INF)ret = -1;
        return dp[cur][star] = ret;
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available

        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            n = sc.nextInt();
            a = new int[n]; b = new int[n];
            tbl = new L[n];
            for(int i = 0; i < n; i++){
                a[i] = sc.nextInt(); b[i] = sc.nextInt();
                tbl[i] = new L(a[i], b[i]);
            }
            dp = new int[n][3*n+1];
            for(int i = 0; i < dp.length; i++)Arrays.fill(dp[i], INF);
            Arrays.sort(tbl);
            int ans = dfs(0, 0);
            if(ans < 0)
                System.out.printf("Case #%d: Too Bad\n", o);
            else
                System.out.printf("Case #%d: %d\n", o, ans);
        }
    }
}

class L implements Comparable<L>{
    int a, b;
    L(int _a, int _b){
        a = _a;
        b = _b;
    }
    public int compareTo(L l){
        if(b != l.b)return b - l.b;
        return a-l.a;
    }
}
