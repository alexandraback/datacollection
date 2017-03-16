package ProblemB;

import java.io.File;
import java.util.Scanner;

/**
 *
 * @author Brenton
 */
public class ProblemB {

    public static void main(String[] args) {

        String INPUT = args[0];
        int caseNumber = 1;
        int cases;

        try {
            Scanner readIn = new Scanner(new File(INPUT));
            // Read in the number of cases
            cases = readIn.nextInt();
            readIn.nextLine();

            while (caseNumber <= cases) {

                // Read in the variables
                int K = readIn.nextInt();
                int L = readIn.nextInt();
                int S = readIn.nextInt();

                readIn.nextLine();
                String keyboard = readIn.next();
                String target = readIn.next();

                // Solve the problem
                double result = solve(keyboard, target, S);

                //print result
                System.out.println("Case #" + caseNumber + ": " + result);
                caseNumber++;
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    static int OFFSET = 'A';

    public static String[] getAllLists(String[] elements, int lengthOfList) {


        //initialize our returned list with the number of elements calculated above
        String[] allLists = new String[(int) Math.pow(elements.length, lengthOfList)];

        //lists of length 1 are just the original elements
        if (lengthOfList == 1) {
            return elements;
        } else {
            //the recursion--get all lists of length 3, length 2, all the way up to 1
            String[] allSublists = getAllLists(elements, lengthOfList - 1);

            //append the sublists to each element
            int arrayIndex = 0;

            for (int i = 0; i < elements.length; i++) {
                for (int j = 0; j < allSublists.length; j++) {
                    //add the newly appended combination to the list
                    allLists[arrayIndex] = elements[i] + allSublists[j];
                    arrayIndex++;
                }
            }

            return allLists;
        }
    }

    public static double solve(String keyboard, String target, int S) {
        // Work out the probability of each letter in the TARGET
        // being struck


        // Generate all possible combinations of the keys
        String[] e = new String[keyboard.length()];
        for (int i = 0; i < keyboard.length(); i++) {
            e[i] = keyboard.charAt(i) + "";
        }
        String[] combos = getAllLists(e, S);



        int[] correctWords = new int[8];

        int count = 0;

        // Search the combinations and count the
        // number of times the target appears in each one
        for (int i = 0; i < combos.length; i++) {
            int thisCount = 0;
            int index = combos[i].indexOf(target);
            while (index >= 0) {
                thisCount++;
                index = combos[i].indexOf(target, index + 1);
            }
            correctWords[thisCount]++;
            count += thisCount;
        }

        double maxBananas = 0;
        // Find the max number of bananas
        for (int i = 0; i < correctWords.length; i++) {
            if (correctWords[i] > 0) {
                maxBananas = i;
            }
        }

        double expectedNumberOfCorrectWords = (double) count / (double) combos.length;
        double result = maxBananas - expectedNumberOfCorrectWords;

        return result;
    }
}
