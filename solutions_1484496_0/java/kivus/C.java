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
public class C {
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

        int n = scanner.nextInt();

        int s[] = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }

        int num = (1 << n);
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        boolean found = false;
        String result1 = null, result2 = null;
        for (int i = 1; i < num; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    sum += s[j];
                }
            }
            if (map.containsKey(sum)) {
                // we found the match!!!
                result1 = printResult(map.get(sum), s, n);
                result2 = printResult(i, s, n);
                found = true;
                break;
            }
            map.put(sum, i);
        }
        wr.println("Case #" + caseNumber + ":");
        System.out.println("Case #" + caseNumber + ":");
        if (found) {
            wr.println(result1);
            wr.println(result2);
            System.out.println(result1);
            System.out.println(result2);
        } else {
            wr.println("Impossible");
            System.out.println("Impossible");
        }
    }

    private static String printResult(int bits, int[] s, int n) {
        StringBuffer b = new StringBuffer();
        for (int j = 0; j < n; j++) {
            if ((bits & (1 << j)) != 0) {
                if (b.length() > 0) {
                    b.append(' ');
                }
                b.append(s[j]);
            }
        }
        return b.toString();
    }

/*
    private static void doCase(int caseNumber, Scanner scanner, PrintWriter wr) {
        Map<Integer, Map<Integer, Integer>> map = new HashMap<Integer, Map<Integer, Integer>>();

        int n = scanner.nextInt();
        int l = scanner.nextInt();
        int h = scanner.nextInt();

        int freq[] = new int[n];

        for (int i = 0; i < n; i++) {
            freq[i] = scanner.nextInt();
        }

        int result = -1;
        for (int i = l; i <= h; i++) {
            boolean ok = true;
            for (int j = 0; j < n; j++) {
                int f1 = i;
                int f2 = freq[j];
                if (f1 == f2) {
                    // ok
                } else if (f1 < f2) {
                    if (f2 != ((f2 / f1) * f1)) {
                        ok = false;
                        break;
                    }
                } else {
                    if (f1 != ((f1/f2)*f2)) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                result = i;
                break;
            }
        }

        String res;
        if (result == -1) {
            res = "NO";
        } else {
            res = ""+result;
        }
        wr.println("Case #" + caseNumber + ": " + res);
        System.out.println("Case #" + caseNumber + ": " + res);
        // ...
    }
*/


}