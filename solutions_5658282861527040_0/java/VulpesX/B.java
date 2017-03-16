import java.util.*;

public class B
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);

        int T = scan.nextInt();
        for(int ca=1;ca <= T;ca++)
        {
            int a = scan.nextInt();
            int b = scan.nextInt();
            int k = scan.nextInt();

            int ans = 0;
            for(int i=0;i < a;i++)
            for(int j=0;j < b;j++)
            {
                if((i & j) < k)
                    ans++;
            }

            System.out.println("Case #" + ca +": " + ans);
        }
    }
}