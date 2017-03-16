import java.util.*;

public class B
{
    static double C, F, X;

    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();

        for(int ca=1;ca <= T;ca++)
        {
            C = scan.nextDouble();
            F = scan.nextDouble();
            X = scan.nextDouble();

            int lo = 0;
            int hi = 1000000;
            while(lo < hi - 3)
            {
                int mid1 = lo + (hi-lo)/3;
                int mid2 = lo + 2*(hi-lo)/3;
                if(ans(mid1) < ans(mid2))
                    hi = mid2;
                else
                    lo = mid1;
            }
            double ans = ans(lo);
            for(int i=lo+1;i <= hi;i++)
                ans = Math.min(ans, ans(i));
            
            System.out.printf("Case #%d: %.7f\n", ca, ans);
        }
    }

    public static double ans(int i)
    {
        // Try it with i farms
        double rate = 2;
        double ans = 0;
        for(int j=0;j < i;j++)
        {
            double t = C / rate;
            ans += t;
            rate += F;
        }

        double t = X / rate;
        ans += t;

        return ans;
    }
}