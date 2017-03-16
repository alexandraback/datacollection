package p1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Chris
 */
public class P1 {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            Scanner input = new Scanner(new File("A-small-attempt0.in"));
            int cases = input.nextInt();
            input.nextLine();
            PrintWriter output = new PrintWriter("p1_out.txt", "UTF-8");

            int P, Q, gcd;
            Integer gen;
            String[] line = new String[2];
            String out = new String();

            for (int caseNum = 0; caseNum < cases; caseNum++) {

                line = input.nextLine().split("/");
                P = Integer.parseInt(line[0]);
                Q = Integer.parseInt(line[1]);

                gcd = gcd(P, Q);
                P /= gcd;
                Q /= gcd;

                if (Q%2 == 1 || !isPowerOfTwo(Q)) {
                    out = "impossible";
                }
                else {
                    if (P == 1) {
                        gen = (int) (Math.log(Q) / Math.log(2));
                        out = gen.toString();
                    }
                    else {
                        gen = 1;
                        out = "impossible";

                        int i = Q/2;

                        while (i > 0) {
                            if (i <= P) {
                                out = gen.toString();
                                break;
                            }
                            else {
                                gen++;
                                i /= 2;
                            }
                        }
                    }
                }

                //Output
                output.println("Case #" + (caseNum + 1) + ": " + out);
            }
            output.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(P1.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(P1.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static int gcd(int n1, int n2) {
        if(n2 == 0){
            return n1;
        }
        return gcd(n2, n1%n2);
    }

    private static boolean isPowerOfTwo(int x) {
        return (x & (x - 1)) == 0;
    }
}
