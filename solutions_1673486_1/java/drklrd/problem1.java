import java.util.*;
import java.io.*;


public class problem1
{
    private final Scanner sc;
    private static final boolean debug = true;

    static void debug(Object ... objects)
    {
        if(debug)
            System.err.println(Arrays.toString(objects));        
    }

    problem1()
    {
        sc = new Scanner(new BufferedInputStream(System.in));
    }

    public static void main(String [] args)
    {
        (new problem1()).solve();
    }
    
    
    void solve()
    {
        int T = sc.nextInt();
        int cs = 0;
        while(cs < T)
        {
            cs++;
            int A = sc.nextInt(), B = sc.nextInt();
            double p[] = new double[A];
            for(int i=0;i<p.length;i++)
                p[i] = sc.nextDouble();

            double minVal = B+2;
            for(int back=0;back<=A;back++)
            {
                double prob=1.0;
                for(int i=0;i<A-back;i++)
                    prob*=p[i];
                double nprob = 1.0 - prob;
                double val = B-A+1+2*back+(B+1)*nprob;
                minVal = Math.min(minVal,val);
            }


            System.out.printf("Case #%d: %.6f\n",cs,minVal);
        }

    }
}
