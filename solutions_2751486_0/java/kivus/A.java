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
             Scanner scanner = (new Scanner(new File("c:/codejam/src/input.txt")));


             FileOutputStream out = new FileOutputStream("c:/codejam/src/output.txt");

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
     //

        String name = scanner.next();
        int n = scanner.nextInt();
//        System.out.println("name: " + name + " n: " + n);

        int len = name.length();

        int lastPos = -1;
        int numCons = 0;
        long result = 0;

        for (int i = 0; i < name.length(); i++) {
            if (isVowel(name, i)) {
                numCons = 0;
            } else {
                numCons++;
                if (numCons >= n) {
                    int startPos = i - n + 1;
                    // found substring
                    int diff = startPos - lastPos;

                    int endDiff = (name.length() - startPos - n + 1);

                    result += (diff * endDiff);

                    lastPos = startPos;
                }
            }
        }

        wr.println("Case #" + caseNumber + ": " + result);
        System.out.println("Case #" + caseNumber + ": " + result);
        // ...

    }

    private static boolean isVowel(String name, int i) {
        char c = name.charAt(i);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }


}