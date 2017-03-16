package R1A;

import java.util.Scanner;

/**
 *
 * @author Rohit
 */
public class QA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int Tcases = s.nextInt();
        s.nextLine();
        for (int i = 0; i < Tcases; i++) {
            int Atyped = s.nextInt();
            int Btotal = s.nextInt();
            double p[] = new double[Atyped];
            double product[] = new double[Atyped];

            for (int j = 0; j < Atyped; j++) {
                p[j] = s.nextDouble();
            }
            //product[k] = p[0] * p[1] * ... * p[k]
            product[0] = p[0];
            for (int j = 1; j < Atyped; j++) {
                product[j] = product[j-1] *  p[j];
            }
            double expected;

            //keep typing
            expected = (Btotal - Atyped + 1) + (Btotal + 1) * (1-product[Atyped-1]);

            //delete some characters
            for (int k = 1; k < Atyped; k++) {
                expected = Math.min(expected, (Btotal - Atyped + 2*k + 1) + (Btotal+1)*(1-product[Atyped-1 - k]));
            }

            //press enter
            expected = Math.min(expected, 1 + Btotal + 1);

            //printing the output
            System.out.println("Case #" + (i + 1) + ": " + expected);
        }
    }
}
