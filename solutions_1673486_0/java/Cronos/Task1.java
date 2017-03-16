package codejam.y2012.r1a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Cronos
 */
public class Task1 {

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        input.useLocale(Locale.ENGLISH);
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        int A = input.nextInt();
        int B = input.nextInt();
        double[] p = new double[A];
        for (int i = 0; i < A; i++) {
            p[i] = input.nextDouble();
        }
        double[] props = new double[A+1];
        double ps = 0;
        for (int i = 0; i < A; i++) {
            double px = 1;
            for (int j = 0; j < i; j++) {
                px *= p[j];
            }
            props[i] = px * (1 - p[i]);
            ps += props[i];
        }
        props[A] = (1 - ps);
        int[] keepTyping = new int[A+1];
        int[] pressEnter = new int[A+1];
        for (int i = 0; i < A+1; i++) {
            if (i != A) keepTyping[i] = (B - A) + B + 2;
            else keepTyping[i] = (B - A) + 1;
            pressEnter[i] = B + 2;
        }
        double kta = 0;
        double pea = 0;
        for (int i = 0; i < A+1; i++) {
            kta += keepTyping[i] * props[i];
            pea += pressEnter[i] * props[i];
        }
        int[][] pressBackspace = new int[A+1][A];
        for (int i = 0; i < A+1; i++) {
            for (int j = 0; j < A; j++) {
                if (A - (j+1) <= i) pressBackspace[i][j] = 2*(j+1) + (B-A) + 1;
                else pressBackspace[i][j] = 2*(j+1) + (B-A) + B + 2;
            }
        }
        double[] pba = new double[A];
        for (int i = 0; i < A+1; i++) {
            for (int j = 0; j < A; j++) {
                pba[j] += pressBackspace[i][j] * props[i];
            }
        }
        double pbm = pba[0];
        for (int i = 1; i < A; i++) {
            pbm = Math.min(pbm, pba[i]);
        }
        double result = Math.min(kta, pea);
        result = Math.min(result, pbm);
        return String.valueOf(result);
    }


}
