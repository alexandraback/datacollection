import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

/**
 * Author: Andriy Gusyev
 * Date: 05.05.12
 */
public class TaskR2_1 {

    static private int cases;

    static private List<Double[]> results;

    static private Case[] c;

    public static class Case {

        int contestants;

        int[] scores;

        int x = 0;

        double avg;
    }


    private static void readInput(String s, int index) {
        s = s.trim();
        String[] arr = s.split(" ");
        Case cas = new Case();
        cas.contestants = Integer.parseInt(arr[0]);
        cas.scores = new int[cas.contestants];
        for (int i = 0; i < cas.contestants; i++) {
            cas.scores[i] = Integer.parseInt(arr[i + 1]);
            cas.x += cas.scores[i];
        }
        cas.avg = 2.0 * cas.x / cas.contestants;
        c[index] = cas;
    }


    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(new File("d:/codejam/r2/1/small"), "UTF-8");
        cases = Integer.parseInt(sc.nextLine());
        results = new ArrayList<Double[]>();
        c = new Case[cases];
        for (int i = 0; i < cases; i++) {
            readInput(sc.nextLine(), i);
            results.add(proceed(c[i]));
        }
        System.out.print(results);
        Locale.setDefault(Locale.US);
        FileWriter fw = new FileWriter(new File("d:/codejam/r2/1/small_out"));
        int k = 0;
        for (Double[] arr : results) {
            k++;
            fw.write(String.format("Case #%s:", String.valueOf(k)));
            for (Double d : arr) {
                fw.write(String.format(" %.6f", d.doubleValue()));
            }
            fw.write("\n");
        }
        fw.close();
    }

    private static Double[] proceed(Case aCase) {
        Double[] result = new Double[aCase.contestants];
        int altContentants = aCase.contestants;
        double altX = aCase.x;
        int i = 0;
        for (int score : aCase.scores) {
            if (score >= aCase.avg) {
                altContentants--;
                altX -= score;
            }
        }
       if (altX < 0) {altX = 0;}
        i = 0;
        for (int score : aCase.scores) {
            if (score >= aCase.avg) {
                result[i++] = 0.0;
                continue;
            } else {
                double tmp = (aCase.x + altX) / (altContentants * aCase.x)  - (double) score / aCase.x;
                if (tmp < 0) {
                    tmp = 0.0;
                } else if (tmp > 1.0) {
                    tmp = 1.0;
                }
                result[i++] = tmp * 100.0;
                continue;

            }
        }
        return result;

    }
}