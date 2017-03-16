/*
 * CONFIDENTIAL
 * Copyright 2013 Webalo, Inc.  All rights reserved.
 */

package mahfouz.google.codejam.y2014.qual;

import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * Solution of "Deceitful War" problem (Qualification 2011).
 */
public final class DeceitfulWar {

    public static void main(String[] args) throws Exception{
        Scanner s = new Scanner(new File("C:\\Users\\amahfouz\\Downloads\\cj.in"));

        int numCases = s.nextInt();

        for (int i = 0; i < numCases; i++) {
            solveCase(i + 1, s);
        }
    }

    private static void solveCase(int caseNum, Scanner s) {
        int numPieces = s.nextInt();

        ArrayList<Double> naomi = new ArrayList<Double>();
        for (int i = 0; i < numPieces; i++)
            naomi.add(s.nextDouble());

        Collections.sort(naomi);

        ArrayList<Double> ken = new ArrayList<Double>();
        for (int i = 0; i < numPieces; i++)
            ken.add(s.nextDouble());

        Collections.sort(ken);

        int optimalWar = performOptimalWar
            ((ArrayList<Double>)naomi.clone(), (ArrayList<Double>)ken.clone());

        int decitful = performDeciftful(naomi, ken);

        System.out.println("Case #" + caseNum + ": " + decitful + " " + optimalWar);
    }

    private static int performDeciftful(ArrayList<Double> naomi,
                                        ArrayList<Double> ken) {
        int naomiPoints = 0;
        while (true) {

            double minN = naomi.get(0);  // Naomi's min piece

            double minK = ken.get(0);    // Ken's min piece
            double maxK = ken.get(naomi.size() - 1); // Ken's max piece

            if (minN > maxK) {
                // all Naomi's pieces are larger than Ken's
                // Naomi wins rest of points
                naomiPoints += naomi.size();
                break;
            }
            else if (minN > minK) {

                // Naomi chooses min piece and claims a very large weight
                // Ken sacrifices his min piece

                naomiPoints++;
                naomi.remove(0);
                ken.remove(0);
            }
            else {
                // Naomi's min piece smaller than all Ken's pieces
                // she has to lost it, but she claims a weight just
                // slightly lighter than Ken's max piece so that he
                // has to use his max piece

                naomi.remove(0);
                ken.remove(ken.size() - 1);
            }

            // check if any pieces left
            if (naomi.size() == 0)
                break;
        }
        return naomiPoints;
    }

    private static int performOptimalWar(List<Double> naomi,
                                         List<Double> ken) {
        int naomiPoints = 0;
        int num = naomi.size();
        for (int i = 0; i < num; i++) {
            double first = naomi.get(i);
            int index = findJustLargerIfAny(first, ken);
            if (index == -1) {
                // if Ken can't win he wastes the smallest piece
                ken.remove(0);
                naomiPoints++;
            }
            else {
                ken.remove(index);
            }
        }
        return naomiPoints;
    }

    private static int findJustLargerIfAny(double first, List<Double> ken) {
//        int hi = ken.size() - 1;
//        int lo = 0;

        int idx = 0;
        while (idx < ken.size() && first > ken.get(idx)) {
            idx++;
        }

        return (idx == ken.size())
            ? -1
            : idx;
    }
}
