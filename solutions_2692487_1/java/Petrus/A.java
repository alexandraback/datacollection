package net.axisk.codejam.round1b;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: petrusra-laptop
 * Date: 04/05/13
 * Time: 14:51
 * To change this template use File | Settings | File Templates.
 */
public class A {
    private int getMaxAchievableSize(int initialSize, int[] motes) {
        int result = initialSize;
        Arrays.sort(motes);
        for (int i=0; i < motes.length; i++) {
            if (result > motes[i])
                result+=motes[i];
            else
                break;
        }
        return result;
    }

    private int[] filterMotes(int size, int[] motes) {
        int smallIndex = 0;
        for (int mote : motes)
            if (size > mote)
                smallIndex++;
        int[] motesFiltered = new int[motes.length-smallIndex];
        System.arraycopy(motes, smallIndex, motesFiltered, 0, motesFiltered.length);
        return motesFiltered;
    }

    private int moves(int initialSize, int[]motes) {
        Arrays.sort(motes);
        int result = 0;
        int maxSize = getMaxAchievableSize(initialSize, motes);
        if (maxSize <= motes[motes.length-1])
        {
            //Filter out anything smaller than the maxInitialSize as these will have been consumed already
            motes = filterMotes(maxSize, motes);

            // Special case of 1 node left, always remove
            if (motes.length == 1) {
                result = 1;
            } else {
                // we can either remove all nodes or 'double' our size and see if we can solve it using less moves.
                int maxRemovals = motes.length;
                if (maxSize > 1) {
                    int motesAdded[] = new int[motes.length+1];
                    motesAdded[0] = maxSize-1;
                    System.arraycopy(motes, 0, motesAdded, 1, motes.length);
                    int movesFromHere = 1 + moves(maxSize, motesAdded);
                    result = Math.min(maxRemovals, movesFromHere);
                } else {
                    result = maxRemovals;
                }
            }

        }
        return result;
    }
    public void solve(Scanner sc, PrintWriter pw) {
        int tests = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < tests; i++) {
            int armin = sc.nextInt();
            int others = sc.nextInt();
            int motes[] = new int[others];
            sc.nextLine();
            for (int j=0; j < others; j++)
                motes[j] = sc.nextInt();
            int result = moves(armin, motes);
            System.out.println("Test #" + (i+1) + " = " + result );

            pw.println("Case #" + (i + 1) + ": " + result);
            pw.flush();
            if (sc.hasNext())
                sc.nextLine();
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader("C:\\Users\\petrusra-laptop\\Downloads\\A-large.in"));
        //Scanner sc = new Scanner(new FileReader("A-practice.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("A-large.out"));
        new A().solve(sc, pw);
        pw.close();
        sc.close();
    }
}
