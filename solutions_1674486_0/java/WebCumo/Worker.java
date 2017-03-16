package net.webcumo.codejam.c1.a;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Cumo
 */
public class Worker {

    public static String calculate(int n, String[] nRows) throws RuntimeException {
        //собираем
        int [][] classes = new int[n][];
        for (int i = 0 ; i < n ; i++) {
            String[] inherits = nRows[i].split(" ");
            int count = Integer.parseInt(inherits[0]);
            classes[i] = new int[count];
            for (int z = 0 ; z < count ; z++) {
                classes[i][z] = Integer.parseInt(inherits[z + 1]);
            }
        }

        //ищем:
        for (int i = 0 ; i < n ; i++) {
            if (classes[i].length > 1) {
                if (findCrossingWays(classes, i))
                    return "Yes";
            }
        }
        return "No";
    }

    private static boolean findCrossingWays (int[][] classes, int currentClass) {
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
                if (resultsOnWays.get(i).size() > 10000)
                    flag = false;
            }
        }
        return false;
    }
}
