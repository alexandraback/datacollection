import java.util.Scanner;

public class A
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for(int i = 0; i < T; i++)
        {
            String S = sc.next();

            String res = ""+S.charAt(0);
            for(int j = 1; j < S.length(); j++)
            {
                if(S.charAt(j) >= res.charAt(0)) res = S.charAt(j)+res;
                else res = res + S.charAt(j);
            }

            System.out.println("Case #"+(i+1)+": "+res);
        }
    }
}
