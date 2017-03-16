package net.webcumo.codejam.c1.c;

import java.util.ArrayList;

/**
 * @author Cumo
 */
public class Worker {

    public static String calculate(int boxesCount, int toysCount, long[] boxes, int[] boxesTypes, long[] toys, int[] toysTypes) throws RuntimeException {
        long maxCount = 0;
        for (int i = 0 ; i < boxesCount ; i++) {
            int curType = boxesTypes[i];
            long count = 0;
            for (int t = 0 ; t < toysCount ; t++)
                if (toysTypes[t] == curType) {
                    count += Math.min(boxes[i], toys[t]);
                    for (int b = i + 1 ; b < boxesCount ; b++) {
                        curType = boxesTypes[b];
                        for (; t < toysCount ; t++)
                            if (toysTypes[t] == curType) {
                                count += Math.min(boxes[b], toys[t]);
                            }
                    }
                }
            maxCount = Math.max(maxCount, count);
        }

        return "" + maxCount;
    }

    private static boolean calcu (int[][] classes, int currentClass) {
        int waysCount = classes[currentClass].length;
        ArrayList<ArrayList<Integer>> resultsOnWays = new ArrayList<ArrayList<Integer>>();
        ArrayList<ArrayList<Integer>> nextSteps = new ArrayList<ArrayList<Integer>>(waysCount);
        for (int i = 0 ; i < waysCount ; i++) {
            resultsOnWays.add(new ArrayList<Integer>());
            nextSteps.add(new ArrayList<Integer>());
            nextSteps.get(i).add(classes[currentClass][i]);
        }
        boolean flag = true;
        while (flag) {
            for (int i = 0 ; i < waysCount ; i++) {
                for (int k = 0 ; k < nextSteps.get(i).size() ; k++) {
                    int c = nextSteps.get(i).get(k);
                    resultsOnWays.get(i).add(c);
                    for (int d: classes[c - 1]) {
                        for (int ii = 0 ; ii < waysCount ; ii++) {
                            if (ii != i && resultsOnWays.get(ii).contains(d))
                                return true;
                        }
                        nextSteps.get(i).add(d);
                    }
                }
                if (resultsOnWays.get(i).size() > 2000)
                    flag = false;
            }
        }
        return false;
    }
}
