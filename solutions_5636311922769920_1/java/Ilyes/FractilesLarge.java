package codejamprep;

import java.util.*;
import java.io.*;

public class FractilesLarge
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
        final int minimumS = (int) Math.ceil((double) k / c);
        if (s < minimumS)
            return null;

        final long[] tiles = new long[minimumS];
        for (int i = 0; i < minimumS; i++)
        {
            final int initPos = i * c;
            long pos = initPos;
            for (int j = initPos; j < Math.min(initPos + c - 1, k - 1); j++)
            {
                pos = pos * k + j + 1;
            }
            tiles[i] = pos + 1;
        }
        return tiles;
    }

    private static String toString(final long[] tiles)
    {
        if (tiles == null)
            return "IMPOSSIBLE";

        String s = Long.toString(tiles[0]);
        for (int i = 1; i < tiles.length; i++)
            s += " " + tiles[i];
        return s;
    }
}