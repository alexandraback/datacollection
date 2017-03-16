import java.util.*;
import java.io.*;

public class B
{
    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            double C = input.nextDouble();
            double F = input.nextDouble();
            double X = input.nextDouble();
            double ans = X / 2;
            double rate = 2;
            while (true)  // runs at most X / C times
            {
                double dans = C / rate - X / rate + X / (rate + F);
                if (dans > 0)
                    break;
                ans += dans;
                rate += F;
            }
            System.out.printf("Case #%d: %.7f\n", n + 1, ans);
        }
    }
}

