import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class B{
    public static void main(String[] args) throws Exception{
        new B().run();
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available
        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            int n = sc.nextInt();
            int s = sc.nextInt();
            int p = sc.nextInt();
            int ans = 0;
            for(; n > 0; n--){
                int t = sc.nextInt();
                if(t >= p*3){
                    ans++;
                    continue;
                }
                int d = t / 3;
                if(t%3>0)d++;
                if(d >= p){
                    ans++;
                }else if(s > 0){
                    boolean  ok = false;
                    loop:
                    for(int i = 0; i <= t; i++)
                        for(int j = i; j <= t; j++)
                            for(int k = j; k <= t; k++)
                                if(i+j+k==t){
                                    int mn = min(i, min(j, k));
                                    int mx = max(i, max(j, k));
                                    if(mx >= p && mx - mn <= 2){
                                        ok = true;
                                        break loop;
                                    }
                                }
                    if(ok){
                        ans++;
                        s--;
                    }
                }
            }
            System.out.printf("Case #%d: %d\n", o, ans);
        }
   }
}
