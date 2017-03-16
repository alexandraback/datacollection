import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;

/**
 *
 *
 */
public class A {
    public static void main(String[] args) {
         try {
             Scanner scanner = (new Scanner(new File("c:/users/rafal/ideaprojects/src/Ain.txt")));


             FileOutputStream out = new FileOutputStream("c:/users/rafal/ideaprojects/src/Aout.txt");

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
        String num = scanner.next();

        long result = solve(num);
//		String result = "";
        wr.println("Case #" + caseNumber + ": " + result);
        System.out.println("Case #" + caseNumber + ": " + result);
        // ...

    }

    private static long solve(String num) {
        if (num.length() == 1) {
            return Integer.parseInt(num);
        }
        if (num.equals("10")) {
            return 10;
        }

        if (num.startsWith("1") && onlyZeros(num.substring(1))) {
            return solve(concat("9", num.length() - 1)) + 1;
        }

        // split in half
        String upperHalf = num.substring(0, num.length() / 2);
        String lowerHalf = num.substring(num.length() / 2);

        if (onlyZeros(lowerHalf)) {
            Long l = Long.parseLong(num);
            return solve("" + (l-1)) + 1;
        } else {

            if (upperHalf.equals("1" + concat("0", upperHalf.length() - 1))) {
                long lowerValue = Long.parseLong(removeLeadingZeros(lowerHalf));
                return solve("1" + concat("0", num.length() - 1)) + lowerValue;
            }
            upperHalf = reverse(upperHalf);
            long upperValue = Long.parseLong(removeLeadingZeros(upperHalf));

            long lowerValue = Long.parseLong(removeLeadingZeros(lowerHalf)) - 1;
            return solve("1" + concat("0", num.length() - 1)) + upperValue + 1 + lowerValue;
        }


    }

    private static String removeLeadingZeros(String lowerHalf) {
        for (int i = 0; i < lowerHalf.length(); i++) {
            if (lowerHalf.charAt(i) != '0') {
                return lowerHalf.substring(i);
            }
        }
        return "0";
    }

    private static String reverse(String upperHalf) {
        StringBuffer b = new StringBuffer();
        for (int i = upperHalf.length() - 1; i >= 0; i--) {
            b.append(upperHalf.charAt(i));
        }
        return b.toString();
    }

    private static String concat(String s, int times) {
        StringBuffer b  = new StringBuffer();
        for (int i = 0; i < times; i++) {
            b.append(s);
        }
        return b.toString();
    }

    private static boolean onlyZeros(String substring) {
        for (int i = 0; i < substring.length(); i++) {
            if (substring.charAt(i) != '0') {
                return false;
            }
        }
        return true;
    }


}