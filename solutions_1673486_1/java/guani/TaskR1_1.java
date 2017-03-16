import java.io.File;
import java.io.FileWriter;
import java.util.Locale;
import java.util.Scanner;

/**
 * Author: Andriy Gusyev
 * Date: 27.04.12
 */
public class TaskR1_1 {

    static private int cases;

    static private double[] results;

    static private Case[] passwords;

    public static class Case {
        private int typed;
        private int total;
        private double[] probabilities;

        public double calcIfKeepTyping() {
            double probCorrect = 1.0;
            for (int i = 0; i < typed; i++) {
                probCorrect = probCorrect * probabilities[i];
            }
            double probIncorrect = 1.0 - probCorrect;
            double numCorrect = total - typed + 1.0;
            double numIncorrect = numCorrect + total + 1.0;
            double res = probCorrect * numCorrect + probIncorrect * numIncorrect;
            return res;
        }

        public double calcIfPressEnter() {
            double res = 2.0 + total;
            return res;
        }

        public double calcIfHitBackSpace() {
            double bestResult = 10000000.0;
            double probCorrect = 1.0;
            for (int i = 0; i < typed; i++) {
                probCorrect = probCorrect * probabilities[i];
            }
            for (int i = 1; i < typed; i++) {
                if (2 * i - typed > 1) {
                    return bestResult;
                }
                probCorrect = probCorrect / probabilities[typed - i];
                double numCorrect = total - typed + 1 + 2 * i;
                double probIncorrect = 1.0 - probCorrect;
                double numIncorrect = numCorrect + total + 1;
                double resCand = probCorrect * numCorrect + probIncorrect * numIncorrect;
                if (resCand < bestResult) {
                    bestResult = resCand;
                }
            }
            return bestResult;
        }

        public double getBest() {
            double res = Math.min(calcIfKeepTyping(), calcIfPressEnter());
            res = Math.min(res, calcIfHitBackSpace());
            return res;
        }
    }


    private static void readInput(String s, int index) {
        s = s.trim();
        String[] arr = s.split(" ");
        Case cas = new Case();
        cas.typed = Integer.parseInt(arr[0]);
        cas.total = Integer.parseInt(arr[1]);
        passwords[index] = cas;
    }

    private static void readInput2(String s, int index) {
        Case cas = passwords[index];
        s = s.trim();
        String[] arr = s.split(" ");
        cas.probabilities = new double[cas.typed];
        for (int i = 0; i < cas.typed; i++) {
            cas.probabilities[i] = Double.parseDouble(arr[i]);
            if (cas.probabilities[i] > 1.0) {
                cas.probabilities[i] = 1.0;
            }
            if (cas.probabilities[i] < 0.0) {
                cas.probabilities[i] = 0.0;
            }
        }
    }

    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(new File("d:/codejam/r1/1/large"), "UTF-8");
        cases = Integer.parseInt(sc.nextLine());
        results = new double[cases];
        passwords = new Case[cases];
        for (int i = 0; i < cases; i++) {
            readInput(sc.nextLine(), i);
            readInput2(sc.nextLine(), i);
            results[i] = passwords[i].getBest();
        }
        System.out.print(results);
        Locale.setDefault(Locale.US);
        FileWriter fw = new FileWriter(new File("d:/codejam/r1/1/large_out"));
        int k = 0;
        for (double i : results) {
            k++;
            fw.write(String.format("Case #%s: %.6f\n", String.valueOf(k), i));
        }
        fw.close();
    }

}
