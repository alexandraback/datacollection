package gcj2013.rd1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Osmos {
    private static String folder = "src/gcj2013/rd1b";
    private static String filename = "A-large";

    private static int findMinOps(int currMote, int[] motes) {
        if (currMote == 1) {
            return motes.length;
        }
        
        Arrays.sort(motes);
        int index = 0;
        return findMinOpsRecursive(currMote, index, motes);
    }

    private static int findMinOpsRecursive(int currMote, int index, int[] motes) {
        if (index == motes.length) {
            return 0;
        }

        if (currMote > motes[index]) {
            return findMinOpsRecursive(currMote + motes[index],
                                       index + 1,
                                       motes);
        } else {
            int numDoubleOps = 0;
            while (currMote <= motes[index]) {
                currMote = 2 * currMote - 1;
                ++numDoubleOps;
            }
            int numOps = numDoubleOps + findMinOpsRecursive(currMote + motes[index], index + 1, motes);
            return Math.min(numOps, motes.length - index);
        }
    }

    public static void main(String[] args) {
        try {
            File inputFile = new File(folder, filename + ".in");
            File outputFile = new File(folder, filename + ".out");
            BufferedReader reader = new BufferedReader(new FileReader(inputFile));
            PrintWriter pw = new PrintWriter(outputFile);
            int numTestCases = Integer.parseInt(reader.readLine());
            for (int t = 0; t < numTestCases; ++t) {
                String[] tokens = reader.readLine().trim().split(" ");
                int A = Integer.parseInt(tokens[0]);
                int N = Integer.parseInt(tokens[1]);
                int[] motes = new int[N];
                tokens = reader.readLine().trim().split(" ");
                for (int i = 0; i < N; ++i) {
                    motes[i] = Integer.parseInt(tokens[i]);
                }

                int minOps = findMinOps(A, motes);

                String result = String.format("Case #%d: %d", t + 1, minOps);
                System.out.println(result);
                pw.println(result);
            }
            reader.close();
            pw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (NumberFormatException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
