
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

    static long solve()
    {
        int[] prevs = new int[numThings];
        int[] nexts = new int[numThings];

        for (int i = 0; i < numThings; i++)
        {
            int index = i - 1;
            while (index != -1 && values[i] >= values[index])
            {
                nexts[index] = i;
                index = prevs[index];
            }
            prevs[i] = index;
        }

        long sum = 0, energy = start;
        for (int i = 0; i < numThings; i++)
        {
            if (nexts[i] == 0)
            {
                sum += energy * values[i];
                energy = gain;
            }
            else if (energy + (nexts[i] - i) * gain >= start)
            {
                int low = Math.max(0, start - (nexts[i] - i) * gain);
                sum += values[i] * (energy - low);
                energy = Math.min(start, low + gain);
            }
            else
            {
                energy += gain;
            }
        }

        return sum;
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
            System.out.println("Case #" + (n + 1) + ": " + solve());
        }
    }
}

