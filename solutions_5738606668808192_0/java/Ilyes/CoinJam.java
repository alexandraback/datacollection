package codejamprep;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class CoinJam
{
    private static Scanner in;

    public static void main(final String[] args) throws FileNotFoundException
    {
        final File file = new File(args[0]);

        in = new Scanner(file);

        final int t = in.nextInt();
        in.nextLine();

        for (int i = 0; i < t; i++)
        {
            int n = in.nextInt();
            int j = in.nextInt();

            System.out.println("Case #" + (i + 1) + ":");
            find(n, j);
        }
    }

    public static Map<Long, long[]> find(final int size, final int resultCount)
    {
        final Map<Long, long[]> map = new HashMap<>();

        final long max = (long) Math.pow(2, size) - 1;
        final int[] bases = {3, 4, 5, 6, 7, 8, 9, 10};


        outerloop:
        for (long i = (long) Math.pow(2, size - 1) + 1; i < max; i += 2)
        {
            final long[] div = new long[9];

            // base 2
            final long is2Prime = firstDivisor(BigInteger.valueOf(i));
            if (is2Prime == 1)
                continue;
            div[0] = is2Prime;

            // String
            final String rep = Long.toBinaryString(i);

            for (int b = 0; b < bases.length; b++)
            {
                final BigInteger newInt = new BigInteger(rep, bases[b]);
                final long divisor = firstDivisor(newInt);
                if (divisor == 1)
                    continue outerloop;
                else
                    div[b+1] = divisor;
            }

            System.out.println("" + Long.toBinaryString(i) + " " + toString(div));
            map.put(i, div);
            if (map.size() >= resultCount)
                break;
        }

        return map;
    }

    private static long firstDivisor(final BigInteger n)
    {
        if (n.remainder(BigInteger.valueOf((long)2)).intValue()==0) return 2;
        for(int i=3; i<100; i+=2) {
            if(n.remainder(BigInteger.valueOf((long) i)).intValue()==0)
                return i;
        }
        // it is either a prime, or it has a big dividend, but we ignore
        return 1;
    }
    
    private static String toString(final long[] vals)
    {
        String s = Long.toString(vals[0]);
        for (int i = 1; i < vals.length; i++)
            s += " " + vals[i];
        return s;
    }
}