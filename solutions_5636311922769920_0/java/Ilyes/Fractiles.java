package codejamprep;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Fractiles
{
    private static Scanner in;

    public static void main(String[] args) throws FileNotFoundException
    {
        final File file = new File(args[0]);

        in = new Scanner(file);

        int t = in.nextInt();
        in.nextLine();

        for (int i = 0; i < t; i++) {
            int k = in.nextInt();
            int c = in.nextInt();
            int s = in.nextInt();

            final long[] result = getTiles(k, c, s);
            System.out.println("Case #" + (i + 1) + ": " + toString(result));
        }
    }

    private static long[] getTiles(final int k, final int c, final int s)
    {
        assert k == s;
        final long[] tiles = new long[k];
        final long multiplier = BigInteger.valueOf(k).pow(c - 1).longValueExact();
        for (int i = 0; i < k; i++)
        {
            BigInteger b;
            tiles[i] = i*multiplier + 1;
        }
        return tiles;
    }

    private static String toString(final long[] tiles)
    {
        String s = Long.toString(tiles[0]);
        for (int i = 1; i < tiles.length; i++)
            s += " " + tiles[i];
        return s;
    }
}