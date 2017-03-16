
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;

/**
 *
 * @author peterboyen
 */
public class PasswordProblem {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("/Users/peterboyen/Downloads/A-large.in"));

        String line = br.readLine();

        int testCases = Integer.parseInt(line);

        PrintStream ps = new PrintStream("/Users/peterboyen/Downloads/A-large.out");
        for (int i = 1; i <= testCases; i++) {
            String[] amountOfChars = br.readLine().split(" ");
            String[] prob = br.readLine().split(" ");

            int A = Integer.parseInt(amountOfChars[0]);
            int B = Integer.parseInt(amountOfChars[1]);
            double[] probabilities = new double[A];
            for (int p = 0; p < probabilities.length; p++) {
                probabilities[p] = Double.parseDouble(prob[p]);
            }

            ps.println("Case #" + i + ": " + solve(A, B, probabilities));
        }

        br.close();
        ps.close();
    }

    private static double solve(int A, int B, double[] probabilities) {
        if (A == 0) {
            return B + 1; // type the whole password + enter
        }

        double[] chanceOfCorrectUpTo = new double[probabilities.length];
        chanceOfCorrectUpTo[0] = probabilities[0];

        double[] keyStrokesIfCorrect = new double[probabilities.length];
        keyStrokesIfCorrect[0] = B + probabilities.length - 1;


        for (int i = 1; i < chanceOfCorrectUpTo.length; i++) {
            chanceOfCorrectUpTo[i] = chanceOfCorrectUpTo[i - 1] * probabilities[i];
            keyStrokesIfCorrect[i] = keyStrokesIfCorrect[i - 1] - 2;
        }

        double min = B + 2; // keyStrokesIfEnter

        for (int i = 0; i < probabilities.length; i++) {
            // chanceCorrect * keystrokesCorrect + chanceIncorrect * keystrokesIncorrect
            min = Math.min(min, chanceOfCorrectUpTo[i] * keyStrokesIfCorrect[i] + (1.0 - chanceOfCorrectUpTo[i]) * (keyStrokesIfCorrect[i] + B + 1));
        }

        return min;
    }
}
