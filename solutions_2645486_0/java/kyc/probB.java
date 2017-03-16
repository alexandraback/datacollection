
import java.util.*;
import java.io.*;
import java.math.*;

public class probB 
{
    static int start, gain, numThings;
    static long[] values;

    static long find()
    {
        long[][] table = new long[numThings + 1][start + 1];
        table[0][start] = 0;
        for (int i = 0; i < numThings; i++)
            for (int j = 0; j <= start; j++)
                for (int k = 0; k <= j; k++)
                    table[i + 1][Math.min(start, j - k + gain)] = Math.max(table[i + 1][Math.min(start, j - k + gain)], table[i][j] + k * values[i]);

        long best = 0;
        for (long l : table[numThings])
            if (l > best)
                best = l;
        return best;
    }

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            start = input.nextInt();
            gain = input.nextInt();
            numThings = input.nextInt();
            values = new long[numThings];
            for (int i = 0; i < numThings; i++)
                values[i] = input.nextInt();
            System.out.println("Case #" + (n + 1) + ": " + find());
        }
    }
}

