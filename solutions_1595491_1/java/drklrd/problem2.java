import java.util.*;
import java.io.*;


public class problem2
{
    private final Scanner sc;
    private static final boolean debug = true;

    static void debug(Object ... objects)
    {
        if(debug)
            System.err.println(Arrays.toString(objects));        
    }

    problem2()
    {
        sc = new Scanner(new BufferedInputStream(System.in));
    }

    public static void main(String [] args)
    {
        (new problem2()).solve();
    }
    
    
    void solve()
    {
        int T = sc.nextInt();
        int cs = 0;
        while(cs < T)
        {
            cs++;
            int n = sc.nextInt();
            int s = sc.nextInt();
            int p = sc.nextInt();

            int ans = 0;
            for(int i=0;i<n;i++)
            {
                int x = sc.nextInt();
                int maxVal = (x+2)/3;
                if(maxVal>=p)
                {
                    ans++;
                    continue;
                }
                int m = x%3;
                if(m == 1) continue;
                if(maxVal == p-1 && s>0)
                {
                    if(maxVal+1<=10&&maxVal-1>=0)
                    {
                        ans++;
                        s--;
                    }
                }
            }


            System.out.println("Case #" + cs+ ": "+ ans);
        }

    }
}
