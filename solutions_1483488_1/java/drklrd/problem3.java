import java.util.*;
import java.io.*;


public class problem3
{
    private final Scanner sc;
    private static final boolean debug = true;

    static void debug(Object ... objects)
    {
        if(debug)
            System.err.println(Arrays.toString(objects));        
    }

    problem3()
    {
        sc = new Scanner(new BufferedInputStream(System.in));
    }

    public static void main(String [] args)
    {
        (new problem3()).solve();
    }

    int AA,BB;

    int rot(int b)
    {
        int p=10;
        int cnt=0;
        int maxP = 1;
        int ans = 0;
        while(b/maxP > 0) maxP*=10;
        while(b/p>0)
        {
            int c = b/p + (maxP/p)*(b%p);
            //System.out.println(b+ " " + maxP+" " + c);
            if(c==b) break;
            if(c>b&&c<=BB&&c>=AA) ans++;
            p*=10;
        }
        return ans;
    }
    
    
    void solve()
    {
        int T = sc.nextInt();
        int cs = 0;
        while(cs < T)
        {
            cs++;
            long ans = 0;
            int A = sc.nextInt(), B = sc.nextInt();
            AA=A;BB=B;

            for(int i=A;i<=B;i++)
            {
                ans+=rot(i);
            }

            System.out.println("Case #" + cs+ ": "+ans);
        }

    }
}
