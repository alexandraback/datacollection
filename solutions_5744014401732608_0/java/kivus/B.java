import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 *
 *
 */
public class B {
    public static void main(String[] args) {
         try {
             Scanner scanner = (new Scanner(new File("c:/users/rafal/ideaprojects/src/Bin.txt")));


             FileOutputStream out = new FileOutputStream("c:/users/rafal/ideaprojects/src/Bout.txt");

             int numberOfCases;
             numberOfCases = scanner.nextInt();
             scanner.nextLine();

             PrintWriter wr = new PrintWriter(out);
             for (int i = 0; i < numberOfCases; i++) {
                 doCase(i + 1, scanner, wr);
                 if (i < numberOfCases - 1)
                    scanner.nextLine();
             }
             wr.close();
             out.close();

         } catch (IOException e) {
             System.out.println("Error: " + e);
         }
     }

    private static void doCase(int caseNumber, Scanner scanner, PrintWriter wr) {
        int b = scanner.nextInt();
        long m = scanner.nextInt();

        long maxValue = (long)1 << (b - 2);
        if (m > maxValue) {
            String result = "IMPOSSIBLE";


            wr.println("Case #" + caseNumber + ": " + result);
            System.out.println("Case #" + caseNumber + ": " + result);
            return;
        }

        String result = "POSSIBLE";
        wr.println("Case #" + caseNumber + ": " + result);
        System.out.println("Case #" + caseNumber + ": " + result);

        StringBuffer buf = new StringBuffer();
        if (m == maxValue) {
            while (buf.length() < b) {
                buf.append("1");
            }
        } else {
            buf.append("0");
            while (m > 0) {
                if ((m & 1) != 0) {
                    buf.append("1");
                } else {
                    buf.append("0");
                }
                m >>= 1;
            }
            while (buf.length() < b) {
                buf.append("0");
            }
        }
        String last = buf.toString();

        // print array
        for (int i = 0; i < b; i++) {
            StringBuffer bb = new StringBuffer();
            for (int j = 0; j <= i; j++) {
                bb.append("0");
            }
            for (int j = i + 1; j < b - 1; j++) {
                bb.append("1");
            }
            if (i < b - 1) {
                bb.append("" + last.charAt(i));
            }
            wr.println(bb.toString());
            System.out.println(bb.toString());
        }


    }



}