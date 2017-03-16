package ProblemB;

import java.io.File;
import java.util.Arrays;
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
                int N = readIn.nextInt();
                int[] individual = new int[(2 * N - 1) * N];
                readIn.nextLine();

                for (int i = 0; i < 2 * N - 1; i++) {
                    for (int j = 0; j < N; j++) {
                        int k = readIn.nextInt();
                        individual[i * N + j] = k;
                    }
                    readIn.nextLine();
                }

                // Solve the problem
                String result = "";
                result = solve(N, individual);

                //print result
                System.out.println("Case #" + caseNumber + ": " + result);
                caseNumber++;
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static String solve(int N, int[] individual) {

        String result = "";
        int count = 0;

        // Sort the list according to the first height
        Arrays.sort(individual);
        for (int i = 0; i < individual.length; i += 2) {
            // check if there is a pair
            if (i == individual.length - 1 || individual[i] != individual[i + 1]) {
                //pair doesn't exist
                result = result + individual[i] + " ";
                count++;
                i--;
            }
        }
        if (count == N) {
            return result;
        } else {
            return "FAILED";
        }

    }
}
