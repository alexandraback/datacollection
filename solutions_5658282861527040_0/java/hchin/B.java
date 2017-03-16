import java.util.*;

public class B
{
    public static int no_test =0;
    public static long A,B,K,soln;

    public static void solve()
    {
        soln=0;
        for(long a=0; a<A; a++)
        for(long b=0; b<B; b++)
        if((a&b) <K) soln++;
    }
    public static void main (String [] args)
    {
        Scanner sc = new Scanner(System.in);
        no_test = sc.nextInt();

        for(int test=1; test<=no_test; test++)
        {
            A = sc.nextLong(); B=sc.nextLong(); K=sc.nextLong();
            solve();
            System.out.printf("Case #%d: %d\n",test, soln);
        }

    }
}
