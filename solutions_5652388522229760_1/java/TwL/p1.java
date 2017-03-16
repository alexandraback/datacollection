import java.util.*;

public class p1
{
    private static void visit(long num, boolean[] seen)
    {
        while (num > 0)
        {
            seen[(int)(num % 10)] = true;
            num /= 10;
        }
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();

        for (int c = 1; c <= cases; c++)
        {
            System.out.printf("Case #%d: ", c);
            long N = sc.nextInt();

            if (N == 0)
            {
                System.out.print("INSOMNIA\n");
                continue;
            }

            long result = N;
            boolean[] seen = new boolean[10];

            while (true)
            {
                visit(result, seen);

                boolean success = true;
                for (boolean b : seen)
                {
                    if (!b)
                    {
                        success = false;
                        break;
                    }
                }

                if (success)
                {
                    System.out.printf("%d\n", result);
                    break;
                }
                else
                    result += N;
            }
        }
    }
}
