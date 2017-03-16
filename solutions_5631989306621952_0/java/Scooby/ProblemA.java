package ProblemA;

import java.io.File;
import java.util.Scanner;

/**
 *
 * @author Brenton
 */
public class ProblemA {

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
                String S = readIn.next();
                readIn.nextLine();

                // Solve the problem
                String result = "";
                result = solve(S);

                //print result
                System.out.println("Case #" + caseNumber + ": " + result);
                caseNumber++;
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static String solve(String S) {
        String result = S.substring(0, 1);


        for (int i = 1; i < S.length(); i++) {
            if (S.charAt(i) >= result.charAt(0)) {
                result = S.charAt(i) + result;
            } else {
                result = result + S.charAt(i);
            }
        }

        return result;
    }
}
