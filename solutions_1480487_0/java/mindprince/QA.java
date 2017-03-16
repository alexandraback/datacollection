//The reason my program didn't halt on large input was that I used input stream for taking the input instead of a file.
package R1B;

import java.util.Scanner;
import java.io.*;

/**
 *
 * @author Rohit
 */
public class QA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println("File Path:");
        Scanner f = new Scanner(System.in);
        String inputfile = f.nextLine();
        f.close();
        Scanner s = null;
        try {
            s = new Scanner(new BufferedReader(new FileReader(inputfile)));
        } catch (FileNotFoundException ex) {
            System.out.println("File Not Found");
            return;
        }
        int Tcases = s.nextInt();
        s.nextLine();
        for (int i = 0; i < Tcases; i++) {
            int Ncontestants = s.nextInt();
            int[] pointByJudges = new int[Ncontestants];
            double[] percentages = new double[Ncontestants];
            int X = 0;
            int maximum = 0;
            for (int j = 0; j < Ncontestants; j++) {
                pointByJudges[j] = s.nextInt();
                X += pointByJudges[j];
                if (maximum < pointByJudges[j]) {
                    maximum = pointByJudges[j];
                }
            }
            boolean[] toCheck = new boolean[Ncontestants];
            for (int j = 0; j < Ncontestants; j++) {
                toCheck[j] = true;
            }
            //The minimum percentage is such that the final score of all contestants become same.
            double scoreToAchieve = 2 * X / Ncontestants;
            if (scoreToAchieve < maximum) {
                //System.out.println("Can't solve");
                //Those who are greater than scoreToAchieve need 0% votes.
                int remContestants = 0;
                int remX = 0;
                for (int j = 0; j < Ncontestants; j++) {
                    if (pointByJudges[j] < scoreToAchieve) {
                        remX += pointByJudges[j];
                        remContestants++;
                    } else {
                        toCheck[j] = false;
                    }
                }
                scoreToAchieve = (X+remX) / remContestants;
            }
            //printing the output
            System.out.print("Case #" + (i + 1) + ": ");
            for (int j = 0; j < Ncontestants; j++) {
                if (toCheck[j]) {
                    percentages[j] = (scoreToAchieve - pointByJudges[j]) * 100 / X;
                }
                System.out.print(percentages[j] + " ");
            }
            System.out.println("");

        }
    }
}
