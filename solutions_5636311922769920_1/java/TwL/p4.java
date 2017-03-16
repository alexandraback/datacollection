import java.util.*;

public class p4
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int c = 1; c <= cases; c++)
        {
            long K = sc.nextLong();
            long C = sc.nextLong();
            long S = sc.nextLong();

            System.out.printf("Case #%d:", c);

            if (C == 1)
            {
                if (S < K)
                    System.out.print(" IMPOSSIBLE");
                else
                {
                    for (int i = 0; i < K; i++)
                        System.out.printf(" %d", i + 1);
                }
            }
            else
            {
                if (K == 1)
                    System.out.print(" 1");
                else if (S < K - 1)
                    System.out.print(" IMPOSSIBLE");
                else
                {
                    for (long i = 1; i < K; i++)
                    {
                        long point = (i - 1) * K;
                        point += i;
                        point += 1;

                        System.out.printf(" %d", point);
                    }
                }
            }
            System.out.println();
        }
    }
}
