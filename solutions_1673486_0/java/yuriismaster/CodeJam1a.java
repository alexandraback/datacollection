import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by IntelliJ IDEA.
 * User: nickg
 * Date: 4/13/12
 * Time: 9:57 PM
 * To change this template use File | Settings | File Templates.
 */
public class CodeJam1a {

    public static void main(String[] args) {

        double result = doAsBackspace(new double[]{1.0, .9, .1}, 3, 4, 1);

        Scanner scanner = new Scanner(System.in);
        int numTrials = scanner.nextInt();
        for(int i = 0; i < numTrials; i++){
            System.out.println("Case #" + (i+1) + ": " + doSomething(scanner));
        }
    }

    private static String doSomething(Scanner scanner) {
        int charsSoFar = scanner.nextInt();
        int charsTotal = scanner.nextInt();

        double[] rightProb = new double[charsSoFar];
        for (int j = 0, rightProbLength = rightProb.length; j < rightProbLength; j++) {
            rightProb[j] = scanner.nextDouble();
        }

        double keep = doAsKeep(rightProb, charsSoFar, charsTotal);
        double enter = Math.min(keep, doAsEnter(rightProb, charsSoFar, charsTotal));
        for(int i = 1; i <= charsSoFar; i++){
            enter= Math.min(enter, doAsBackspace(rightProb, charsSoFar, charsTotal, i));
        }

        return String.format("%06f", enter);
    }

    private static double doAsBackspace(double[] rightProb, int charsSoFar, int charsTotal, int numberOfBackspaces) {
        double totalProbIveMadeIt = 1.0;
        for(int i = 0; i < (charsSoFar - numberOfBackspaces); i++){
            totalProbIveMadeIt *= rightProb[i];
        }

        int totalToFinish = (2 * numberOfBackspaces) + 1 + (charsTotal - charsSoFar);
        return (totalProbIveMadeIt * totalToFinish) + (1.0 - totalProbIveMadeIt) * (totalToFinish + 1 + charsTotal);
    }

    private static double doAsEnter(double[] rightProb, int charsSoFar, int charsTotal) {
        return charsTotal + 2;
    }

    private static double doAsKeep(double[] rightProb, int charsSoFar, int charsTotal) {
        double total = 1.0;
        for(int i = 0; i < charsSoFar; i++){
            total*= rightProb[i];
        }
        return total * (charsTotal - charsSoFar + 1) + (charsTotal + (charsTotal - charsSoFar) + 2) * (1 - total);
    }
}
