//Uses Java 8

import java.io.*;
import java.util.*;
import java.text.*;

public class GCJ161BB {

    static Scanner sc = new Scanner(System.in);

    public void run(int Case) {
        String A = sc.next();
        String B = sc.next();
        DecimalFormat format;

        switch (A.length()) {
        case 1:
            format = new DecimalFormat("#0");
            break;
        case 2:
            format = new DecimalFormat("#00");
            break;
        default:
            format = new DecimalFormat("#000");
            break;
        }

        String bestA = A;
        String bestB = B;
        int bestDif = Integer.MAX_VALUE / 2;
        for (int i = 0; i < Math.pow(10, A.length()); i++) {
            String thisA = format.format(i);
            boolean success = true;
            for (int j = 0; j < A.length(); j++) {
                if (!((A.charAt(j) == '?' || (A.charAt(j) == thisA.charAt(j))))) {
                    success = false;
                }
            }
            if (!success) {
                continue;
            }
            for (int j = 0; j < Math.pow(10, A.length()); j++) {
                String thisB = format.format(j);
                boolean success2 = true;
                for (int k = 0; k < A.length(); k++) {
                    if (!(B.charAt(k) == '?' || (B.charAt(k) == thisB.charAt(k)))) {
                        success2 = false;
                    }
                }
                if (!success2) {
                    continue;
                }
                int diff = Math.abs(Integer.valueOf(thisB)-Integer.valueOf(thisA));
                if(diff<bestDif) {
                    bestA = thisA;
                    bestB = thisB;
                    bestDif = diff;
                }

            }
        }

        String answer = "Case #" + Case + ": " + bestA+" "+bestB;
        System.out.println(answer);
    }

    public static void main(String[] args) throws FileNotFoundException {
        //Generates output file, can be removed to get everything from default output
        System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream("C://Users/s142589/Desktop/output.txt")), true));

        int runs = sc.nextInt();
        for (int i = 0; i < runs; i++) {
            new GCJ161BB().run(i + 1);
        }
    }
}
