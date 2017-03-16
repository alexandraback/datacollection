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
            Scanner input = new Scanner(new File("A-large.in"));
            int cases = input.nextInt();
            input.nextLine();
            PrintWriter output = new PrintWriter("p1_out.txt", "UTF-8");

            Long P, Q, gcd;
            Long gen;
            String[] line = new String[2];
            String out = new String();

            for (int caseNum = 0; caseNum < cases; caseNum++) {

                line = input.nextLine().split("/");
                P = Long.parseLong(line[0]);
                Q = Long.parseLong(line[1]);

                gcd = gcd(P, Q);
                P /= gcd;
                Q /= gcd;

                if (Q%2 == 1 || !isPowerOfTwo(Q)) {
                    out = "impossible";
                }
                else {
                    if (P == 1) {
                        gen = (long) (Math.log(Q) / Math.log(2));
                        out = gen.toString();
                    }
                    else {
                        gen = (long) 1;
                        out = "impossible";

                        Long i = Q/2;

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

    private static Long gcd(Long n1, Long n2) {
        if(n2 == 0){
            return n1;
        }
        return gcd(n2, n1%n2);
    }

    private static boolean isPowerOfTwo(Long x) {
        return (x & (x - 1)) == 0;
    }
}
