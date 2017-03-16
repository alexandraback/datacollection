import java.util.*;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

/**
 *
 * CodeJam 2013 Round 1C
 */
public class B {
    public static void main(String[] args) {
         try {
             Scanner scanner = (new Scanner(new File("c:/codejam/src/input.txt")));


             FileOutputStream out = new FileOutputStream("c:/codejam/src/output.txt");

             int numberOfCases;
             numberOfCases = scanner.nextInt();

             PrintWriter wr = new PrintWriter(out);
             for (int i = 0; i < numberOfCases; i++) {
                 doCase(i + 1, scanner, wr);
             }
             wr.close();
             out.close();

         } catch (IOException e) {
             System.out.println("Error: " + e);
         }
     }

    private static void doCase(int caseNumber, Scanner scanner, PrintWriter wr) {

        int x = scanner.nextInt();
        int y = scanner.nextInt();

        int x0 = x;
        if (x < 0) x0 = -x;
        int y0 = y;
        if (y < 0) y0 = -y;
        String result = "";
        for (int i = 0; i < x0; i++) {
            if (x > 0) {
                result += "WE";
            } else {
                result += "EW";
            }
        }
        for (int i = 0; i < y0; i++) {
            if (y > 0) {
                result += "SN";
            } else {
                result += "NS";
            }
        }

        wr.println("Case #" + caseNumber + ": " + result);
        System.out.println("Case #" + caseNumber + ": "  + result);
        // ...
    }


}