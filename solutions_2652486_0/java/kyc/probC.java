
import java.util.*;
import java.io.*;
import java.math.*;

public class probC 
{
    static int[] tests;

    static int guess()
    {
        int[] f = new int[6];
        for (int test : tests)
        {
            int[] g = new int[6];
            while (test % 3 == 0)
            {
                test /= 3;
                g[3]++;
            }
            while (test % 5 == 0)
            {
                test /= 5;
                g[5]++;
            }
            if (test == 64)
                return 444;
            if (test == 32)
                return 442;
            if (test == 16 && g[3] + g[5] >= 1)
                return g[3] > 0 ? 443 : 445;
            if (test == 16)
                g[4]++;
            if (test == 8 && g[3] + g[5] >= 1)
                g[4]++;
            if (test == 4 && g[3] + g[5] >= 2)
                g[4]++;
            if (test == 2)
                g[2]++;
            for (int i = 2; i <= 5; i++)
                f[i] = Math.max(f[i], g[i]);
        }
        while (f[2] + f[3] + f[4] + f[5] < 3)
            f[2]++;

        int guess = 0;
        for (int i = 2; i <= 5; i++)
            for (int j = 0; j < f[i]; j++)
                guess = 10 * guess + i;
        return guess;
    }

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int numTrials = input.nextInt();
            input.nextInt();
            input.nextInt();
            int numTests = input.nextInt();

            System.out.println("Case #1:");
            for (int i = 0; i < numTrials; i++)
            {
                tests = new int[numTests];
                for (int j = 0; j < numTests; j++)
                    tests[j] = input.nextInt();
                System.out.println(guess());
            }
        }
    }
}

