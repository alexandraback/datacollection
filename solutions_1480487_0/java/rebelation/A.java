import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class A{
    public static void main(String[] args) throws Exception{
        new A().run();
    }


    int n, sum;
    void solve(int[] s, int t){
        double l = 0, r = 1.0, m=0;
        for(int e = 0; e < 200; e++){
            m = (l+r)/2.0;
            double total = s[t] + m*sum;
            double rest = 1-m;
            for(int i = 0; i < n; i++){
                if(t==i)continue;
                if(total<=s[i])continue;
                double y = (total - s[i])/sum;
                rest-=y;
            }
            if(rest<0)r = m;
            else l = m;
        }
        System.out.printf(" %.9f", m*100);
        //return m;
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available
        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            n = sc.nextInt();
            sum = 0;
            int[] s = new int[n];
            for(int i = 0; i < n; i++){
                s[i] = sc.nextInt();
                sum += s[i];
            }
            System.out.printf("Case #%d:", o);
            for(int i = 0; i < n; i++)
                solve(s, i);
            System.out.println();
        }
    }
}
