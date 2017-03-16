package codejamprep;

import java.util.*;
import java.io.*;

public class Sheep
{
    private static Scanner in;

    public static void main(String[] args) throws FileNotFoundException
    {
        final File file = new File(args[0]);

        in = new Scanner(file);

        int t = in.nextInt();

        
        for (int i = 0; i < t; i++) {
            final int m = in.nextInt();
            final int result = findFirst(m);
            System.out.println("Case #" + (i + 1) + ": " + (result == 0 ? "INSOMNIA" : result));
        }
    }

    private static int findFirst(final int N)
    {
        if ( N == 0)
            return 0;

        int n = 0;
        final List<Integer> found = new ArrayList<>();
        for (int i = 0; i < 100000; i++)
        {
            n += N;
            //System.out.println("N: " + n);
            int m = n;
            while (m != 0)
            {
                int r = m % 10;
                m = m / 10;
                if (!found.contains(r))
                    found.add(r);
            }
            //System.out.println(found);
            if (found.size() == 10)
                return n;
        }
        return 0;
    }
}