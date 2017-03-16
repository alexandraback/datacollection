/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcjc;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Me
 */
public class Main {

    public static Scanner s = new Scanner(System.in);

    public static void main(String[] args) {
        long t = s.nextLong();
        for (long i = 1; i <= t; i++) {
            System.out.println("Case #" + i + ": ");
            start();
        }

    }

    private static void start() {

        double distance = s.nextDouble();
        int checkpoints = s.nextInt();
        int speeds = s.nextInt();
        double[] sp = new double[speeds];
        double[][] data = new double[checkpoints][2];
        for (int i = 0; i < checkpoints; i++) {
            data[i][0] = s.nextDouble();
            data[i][1] = s.nextDouble();
        }
        for (int i = 0; i < speeds; i++) {
            sp[i] = s.nextDouble();
        }

        double[][] del = new double[checkpoints][speeds];

        for (int i = 1; i < checkpoints; i++) {
            for (int j = 0; j < speeds; j++) {
                del[i][j] = data[i][0] - Math.sqrt(2 * data[i][1] / sp[j]);
            }
        }

        for (int j = 0; j < speeds; j++) {
            double maxD = 0;
            for (int i = 1; i < checkpoints; i++) {
                maxD = Math.max(maxD, del[i][j]);
            }
            System.out.println(Math.sqrt(2*distance/sp[j])+maxD);
        }
        //System.out.println(Arrays.deepToString(data));
        //System.out.println(Arrays.deepToString(r));
        //for (int i = 0; i < speeds; i++) {
            //System.out.println([checkpoints - 1][i]);
        //}
    }
}
