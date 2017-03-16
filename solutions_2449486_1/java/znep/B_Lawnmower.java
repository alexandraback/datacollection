package contests.Qualification2013;

import contests.Util;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class B_Lawnmower extends Util {

    public static void main(String args[]) throws IOException {
        String inputFileName = "src/contests/Qualification2013/B-sample.in";
        if (args.length == 1) inputFileName = args[0];

        BufferedReader in = new BufferedReader(new FileReader(inputFileName));

        int numTestCases = Integer.parseInt(in.readLine());
        debug("Processing " + numTestCases + " test cases");
        for (int testCase = 1; testCase <= numTestCases; testCase = testCase + 1) {
            debug("Starting case " + testCase);
            Integer[] sizeArray = readIntArrayLine(in);
            int nSize = sizeArray[0];
            int mSize = sizeArray[1];
            debug("processing array of " + nSize + " by " + mSize);
            int[][] desiredHeights = new int[nSize][mSize];
            int[] maxForN = new int[nSize];
            int[] maxForM = new int[mSize];

            for (int n = 0; n < nSize; n++) {
                Integer[] line = readIntArrayLine(in);
                for (int m = 0; m < mSize; m++) {
                    desiredHeights[n][m] = line[m];
                }
                debug("got line " + Arrays.toString(desiredHeights[n]));
            }



            for (int n = 0; n < nSize; n++) {
                for (int m = 0; m < mSize; m++) {
                    if (desiredHeights[n][m] > maxForN[n]) {
                        maxForN[n] = desiredHeights[n][m];
                    }
                }
            }


            for (int m = 0; m < mSize; m++) {
                for (int n = 0; n < nSize; n++) {
                    if (desiredHeights[n][m] > maxForM[m]) {
                        maxForM[m] = desiredHeights[n][m];
                    }
                }
            }


            boolean success = true;
            loop: for (int n = 0; n < nSize; n++) {
                for (int m = 0; m < mSize; m++) {
                    int goal = desiredHeights[n][m];
//                    debug("goal for " + n + "," + m + ": " +goal);
//                    debug("maxForM " + maxForM[m]);
//                    debug("maxForN " + maxForN[n]);
                    if (maxForM[m] != goal && maxForN[n] != goal) {
                        success = false;
                        break loop;
                    }
                }
            }


            System.out.println("Case #" + testCase + ": " + (success ? "YES" : "NO"));
            debug(success ? "YES" : "NO");
        }

    }


}
