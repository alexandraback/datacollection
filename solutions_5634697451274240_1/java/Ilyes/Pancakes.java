package codejamprep;

import java.util.*;
import java.io.*;

public class Pancakes
{
    private static Scanner in;

    public static void main(String[] args) throws FileNotFoundException
    {
        final File file = new File(args[0]);

        in = new Scanner(file);

        int t = in.nextInt();
        in.nextLine();

        for (int i = 0; i < t; i++) {
            final String pancakes = in.nextLine();
            final int result = countFlips(pancakes + 'x');
            System.out.println("Case #" + (i + 1) + ": " + result);
        }
    }

    private static int countFlips(final String pancakes)
    {
        int totalCount  = 0;
        char currentSide = pancakes.charAt(0);
        int currentSameSideCount = 1;
        for (int i = 1; i < pancakes.length(); i++)
        {
            if (pancakes.charAt(i) == currentSide)
            {
                currentSameSideCount++;
            }
            else
            {
                if (currentSide == '-')
                {
                    // this is the first group
                    if (currentSameSideCount == i)
                    {
                        totalCount++;
                    }
                    else
                    {
                        totalCount += 2;
                    }
                }
                currentSameSideCount = 1;
                currentSide = pancakes.charAt(i);
            }
        }
        return totalCount;
    }
}