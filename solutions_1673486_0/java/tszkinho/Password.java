/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package password;

import java.util.Scanner;

/**
 *
 * @author kin
 */
public class Password {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int a, b, t;
        Scanner scanner = new Scanner(System.in);
        t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            double[] p = new double[a];
            for (int j = 0; j < a; j++) {
                p[j] = scanner.nextDouble();
            }
            double min = b + 2;
            double p1 = 1;
            for (int j = 0; j < a; j++) {
                p1 = p1 * p[j];
            }
            double average;
            average = ((b - a + 1) * p1 + (1 - p1) * (b - a + 2 + b));
            if (average < min) {
                min = average;
            }
            p1 = 1;
            for (int j = 0; j < a - 1; j++) {
                p1 = p1 * p[j];
            }
            average = ((b - a + 3) * p1 + (1 - p1) * (b - a + 3 + b + 1));
            if (average < min) {
                min = average;
            }
            p1 = 1;
            for (int j = 0; j < a - 2; j++) {
                p1 = p1 * p[j];
            }
            average = ((b - a + 5) * p1 + (1 - p1) * (b - a + 5 + b + 1));
            if (average < min) {
                min = average;
            }
            System.out.print("Case #"+(i+1)+": ");
            System.out.printf("%.6f",min);
            System.out.println();
        }

    }
}
