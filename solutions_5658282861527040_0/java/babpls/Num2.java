import java.util.*;

public class Num2
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for(int x = 1; x <= t; ++x)
        {
            String out = "Case #" + x + ": ";
            int a = scan.nextInt();
            int b = scan.nextInt();
            int k = scan.nextInt();
            int ans = 0;
            for(int i = 0; i < a; ++i)
            {
                for(int j = 0; j < b; ++j)
                {
                    if((i&j) < k)
                    {
                        ans++;
                    }
                }
            }
            System.out.println(out + ans);
        }
    }
}
