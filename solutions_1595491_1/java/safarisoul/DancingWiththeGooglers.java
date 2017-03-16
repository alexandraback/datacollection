package q2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class DancingWiththeGooglers {
   public static void main(String[] args) throws Exception {
      String input = "B-large.in";
      String output = "B-large.out";

      Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
      PrintWriter pw = new PrintWriter(new BufferedWriter(
            new FileWriter(output)));

      int T = Integer.parseInt(scan.nextLine());
      for (int t = 1; t <= T; t++) {
         String[] info = scan.nextLine().split(" ");
         int N = Integer.parseInt(info[0]);
         int S = Integer.parseInt(info[1]);
         int p = Integer.parseInt(info[2]);
         int[] score = new int[N];
         for (int i = 0; i < N; i++)
            score[i] = Integer.parseInt(info[3 + i]);
         int countp = 0;
         int counts = 0;
         int must = p + 2 * Math.max(0, p - 1);
         int might = p + 2 * Math.max(0, p - 2);
         for (int i = 0; i < N; i++)
            if (score[i] >= must)
               countp++;
            else if (score[i] >= might)
               counts++;
         int res = countp + Math.min(counts, S);
         pw.println("Case #" + t + ": " + res);
      }

      scan.close();
      pw.close();
   }

}
