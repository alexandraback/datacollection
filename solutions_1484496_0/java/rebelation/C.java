import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class C{
    public static void main(String[] args) throws Exception{
        new C().run();
    }

    int n;
    int[] a;
    int[] sum;
    int[] dp;
    ArrayList<Integer>[] tbl;

    int dfs(int target, int state){
        if(dp[state] != 0)return dp[state];
        if(sum[state] == target)return state;
        if(sum[state] < target)return -1;
        for(int i = 0; i < n; i++)
            if(((state>>i)&1)==1){
                int ret = dfs(target, state^(1<<i));
                if(ret >= 0)return dp[state] = ret;
            }
        return dp[state] = -1;
    }

    void print(ArrayList<Integer> a){
        boolean first = true;
        for(int v : a){
            if(!first)System.out.print(" ");
            first = false;
            System.out.print(v);
        }
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available
        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            n = sc.nextInt();
            a = new int[n];
            for(int i = 0; i < n; i++)
                a[i] = sc.nextInt();
            Arrays.sort(a);
            int lim = 1<<n;
            sum = new int[lim];
            for(int i = 0; i < lim; i++){
                int s = 0;
                for(int j = 0; j < n; j++)
                    if(((i>>j)&1)==1)s+=a[j];
                sum[i] = s;
            }
            tbl = new ArrayList[lim];
            for(int i = 0; i < lim; i++)tbl[i] = new ArrayList<Integer>();
            for(int i = 0; i < lim; i++)
                tbl[sum[i]].add(i);
            int mask = lim-1;
            boolean found = false;
            System.out.printf("Case #%d:\n", o);
            for(int i = 1; i < lim-1 && !found; i++){
                int rev = mask^i;
                for(int j = 0; j < tbl[sum[i]].size(); j++){
                    int state = tbl[sum[i]].get(j);
                    if((rev&state) == state){
                        found = true;
                        ArrayList<Integer> ans = new ArrayList<Integer>();
                        for(int b = 0; b < n; b++)
                            if(((i>>b)&1)==1)ans.add(a[b]);
                        print(ans);
                        System.out.println();
                        ans.clear();
                        for(int b = 0; b < n; b++)
                            if(((state>>b)&1)==1)ans.add(a[b]);
                        print(ans);
                        System.out.println();
                        break;
                    }
                }
            }
            if(!found)
                System.out.println("Impossible");
        }
    }
}
