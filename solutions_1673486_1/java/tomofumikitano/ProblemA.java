import java.util.Scanner;

public class ProblemA {

    private static final int enter = 1;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int testCases = Integer.parseInt(scanner.nextLine());

        for (int i = 1; i <= testCases; i++) {

            String[] tmp = scanner.nextLine().split(" ");

            int charsTyped = Integer.parseInt(tmp[0]);
            int passwordLength = Integer.parseInt(tmp[1]);

            tmp = scanner.nextLine().split(" ");

            double[] probs = new double[charsTyped];

            for (int j = 0; j < charsTyped; j++) {
                probs[j] = Double.parseDouble(tmp[j]);
            }

            double result = solve(charsTyped, passwordLength, probs);

            System.out.println("Case #" + i + ": " + result);
        }

    }

    private static double solve(int charsTyped, int passwordLength, double[] probs) {

        double cost1 = costForOption1(charsTyped, passwordLength, probs);
        double cost2 = costForOption2(charsTyped, passwordLength, probs);
        double cost3 = costForOption3(charsTyped, passwordLength, probs);

        return cost1 < cost2 ? Math.min(cost1, cost3) : Math.min(cost2, cost3);
    }

    private static double costForOption1(int charsTyped, int passwordLength, double[] probs) {
        double totalProbs = 1.0;
        for (int i = 0; i < probs.length; i++) {
            totalProbs = totalProbs * probs[i];
        }
        /**
         * Finish typing the password, then press "enter". I know I'll type the rest of the characters perfectly.
         * If it turns out that one of the earlier characters was wrong, I'll have to retype the whole thing
         * and hit "enter" again -- but I know I'll get it right the second time.
         */
//        System.out.println("COST1 : To complete = " + (passwordLength - charsTyped + 1));
//        System.out.println("COST1 : Probs password is wrong = " + (1 - totalProbs));
        return (passwordLength - charsTyped + 1) + (1 - totalProbs) * (passwordLength + 1);
    }

    private static double costForOption2(int charsTyped, int passwordLength, double[] probs) {
        /**
         * Hit "backspace" some number of times, deleting the last character(s) I typed, and then complete the
         * password and press "enter" as in option 1. If one of the characters I didn't delete was wrong,
         * I'll have to retype the whole thing and press "enter", knowing I'll get it right the second time.
         */
        double minCost = Double.MAX_VALUE;

        for (int i = 0; i < charsTyped; i++) {
//            System.out.println("Calculating cost when I enter backspace " + i + " times.");
            double totalProbs = 1.0;
            for (int j = 0; j < charsTyped - i; j++) {
                totalProbs = totalProbs * probs[j];
//                System.out.println("totalProbs = " + totalProbs);
            }
            double costWhenPreviousStringsAreCorrect = totalProbs * (2 * i + passwordLength - charsTyped + enter);
            double costWhenPreviousStringsAreIncorrect = (1 - totalProbs) * ((2 * i + passwordLength - charsTyped + enter) + passwordLength + enter);
            double totalCost = costWhenPreviousStringsAreCorrect + costWhenPreviousStringsAreIncorrect;
            if (totalCost < minCost) {
                minCost = totalCost;
            }
        }

        return minCost;
    }

    private static double costForOption3(int charsTyped, int passwordLength, double[] probs) {
        /**
         * Give up by pressing "enter", retyping the password from the start,
         * and pressing "enter" again. I know I'll get it right this time.
         */
        return (double) (1 + passwordLength + 1);
    }
}
