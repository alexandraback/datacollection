package r1a2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
   public static void main(String[] args) throws Exception {
      String input = "A-large.in";
      String output = "A-large.out";

      Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
      PrintWriter pw = new PrintWriter(new BufferedWriter(
            new FileWriter(output)));

      int T = Integer.parseInt(scan.nextLine());
      for (int t = 1; t <= T; t++) {
         String[] info = scan.nextLine().split(" ");
         int A = Integer.parseInt(info[0]);
         int B = Integer.parseInt(info[1]);
         double[] P = new double[A];
         info = scan.nextLine().split(" ");
         for (int i = 0; i < A; i++)
            P[i] = Double.parseDouble(info[i]);

         double min = B + 2;

         double[] p = new double[A + 1];
         p[0] = 1;
         for (int i = 1; i <= A; i++)
            p[i] = p[i - 1] * P[i - 1];

         double[] CI = new double[A + 1];
         for (int i = 0; i <= A; i++) {
            CI[i] = p[i] * (A - i + B - i + 1) + (1 - p[i])
                  * (A - i + B - i + 1 + B + 1);
            min = Math.min(min, CI[i]);
         }

         pw.println("Case #" + t + ": " + min);
      }

      scan.close();
      pw.close();
   }
}