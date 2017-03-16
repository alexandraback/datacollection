/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.StringTokenizer;
import sun.security.util.BigInt;

/**
 *
 * @author ndkoval
 */
public class CodeJam {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter("output.txt");

        int nTest = Integer.parseInt(br.readLine());
        for (int t = 1; t <= nTest; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());

            int count = 0;

            for (long i = (long) (Math.sqrt(a) + 0.99999999); i * i <= b; i++) {
                String s1 = String.valueOf(i);
                String s2 = String.valueOf(i * i);
                boolean bool = true;
                for (int j = 0; j < s1.length(); j++) {
                    if (s1.charAt(j) != s1.charAt(s1.length() - j - 1)) {
                        bool = false;
                        break;
                    }
                }
                if (bool) {
                    for (int j = 0; j < s2.length(); j++) {
                        if (s2.charAt(j) != s2.charAt(s2.length() - j - 1)) {
                            bool = false;
                            break;
                        }
                    }
                }
                if (bool) {
                    count++;
                }
            }

            pw.println("Case #" + t + ": " + count);
        }

        /*BigInteger max = new BigInteger("222222222222222222222222222222222222222222222222", 3);
         for (BigInteger i = BigInteger.ONE; !i.equals(max); i = i.add(BigInteger.ONE)) {
         String s1 = i.toString(3);
         String s2 = new BigInteger(s1).pow(2).toString();
         boolean b = true;
         for (int j = 0; j < s1.length(); j++) {
         if (s1.charAt(j) != s1.charAt(s1.length() - j - 1)) {
         b = false;
         break;
         }
         }
         if (b) {
         for (int j = 0; j < s2.length(); j++) {
         if (s2.charAt(j) != s2.charAt(s2.length() - j - 1)) {
         b = false;
         break;
         }
         }
         }
         if (b) {
         System.out.println(s1 + " * " + s1 + " = " + s2);
         }
         }*/

        pw.close();
        br.close();
    }
}
