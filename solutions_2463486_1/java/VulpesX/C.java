import java.util.*;

public class C
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);

        //Precomp
        long[] a = new long[10000000];
        int k = 0;

        for(long i=1;i <= 10000000;i++)
        {
            if(!palin(i)) continue;
            long sq = i*i;
            if(!palin(sq)) continue;
            a[k++] = sq;
        }


        int T = scan.nextInt();

        for(int ca=1;ca <= T;ca++)
        {
            int i = Arrays.binarySearch(a, 0, k, scan.nextLong());
            int j = Arrays.binarySearch(a, 0, k, scan.nextLong());

            int ans = 0;
            if(i < 0)
                i = (-i) - 1;
            if(j < 0)
            {
                j = (-j) - 1;
                ans--;
            }

            ans += (j-i+1);
            System.out.println("Case #" + ca + ": " + ans);
        }
    }


    public static boolean palin(long x)
    {
        StringBuffer sb = new StringBuffer(x+"");
        return sb.reverse().toString().equals(x+"");
    }
}