import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class B{
    public static void main(String[] args) throws Exception{
        new B().run();
    }

    int E, R, n;
    int[][] dp;
    int[] vs;
    int calc(int day, int rest){
        if(day >= n)return 0;
        if(dp[day][rest] >= 0)return dp[day][rest];
        int ret = 0;
        for(int i = 0; i <= rest; i++)
            ret = max(ret, i*vs[day] + calc(day+1, min(E, rest-i+R)));
        return dp[day][rest] = ret;
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available

        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            System.out.printf("Case #%d: ", o);
            E = sc.nextInt();
            R = sc.nextInt();
            n = sc.nextInt();
            dp = new int[n][E+1];
            for(int i = 0; i < n; i++)Arrays.fill(dp[i], -1);
            vs = new int[n];
            for(int i = 0; i < n; i++)vs[i] = sc.nextInt();
            System.out.println(calc(0, E));
        }
        
    }
}
