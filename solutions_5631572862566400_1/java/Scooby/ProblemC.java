package ProblemC;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Brenton
 */
public class ProblemC {

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
                int N = readIn.nextInt();
                int[] friend = new int[N];
                readIn.nextLine();

                for (int i = 0; i < N; i++) {
                    friend[i] = readIn.nextInt();
                }
                readIn.nextLine();

                // Solve the problem
                String result = "";
                result = solve(N, friend);

                //print result
                System.out.println("Case #" + caseNumber + ": " + result);
                caseNumber++;
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static String solve(int N, int[] friend) {

        String result = "";

        boolean[] paired = new boolean[N];
        int[] pairCounts = new int[N];

        // find pairs
        for (int i = 0; i < N; i++) {
            // if my bff's bff is me
            if (friend[friend[i] - 1] - 1 == i) {
                paired[i] = true;
            }
        }

        // find the longest chain ending with each item of the pair
        int maxCount = 0;
        int maxLoop = 0;
        // Start with person 1
        for (int initialPerson = 0; initialPerson < N; initialPerson++) {
            int count = 0;
            int currentPerson = initialPerson;
            boolean visited[] = new boolean[N];
            while (!visited[currentPerson] || currentPerson==initialPerson) {
                count++;
                visited[currentPerson] = true;

                // stop if currentPerson is the initialPerson or a paired Number

                if (paired[currentPerson]) {
                    pairCounts[currentPerson] = Math.max(pairCounts[currentPerson], count);
                    break;
                } else if (initialPerson == currentPerson&&count!=1) {
                    // it's a loop.
                    maxLoop = Math.max(count-1, maxLoop);
                    break;
                } 

                currentPerson = friend[currentPerson] - 1;

            }
        }


        // add together all independent pair.
        int pairSum = 0;
        for (int i : pairCounts) {
            pairSum += i;
        }
        // compare total from pairs to largest loop available.
        result = Math.max(maxLoop, pairSum) + "";

        return result;
    }
}
