package r1a2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
   public static void main(String[] args) throws Exception {
      String input = "B-small-attempt2.in";
      String output = "B-small-attempt2.out";

      Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
      PrintWriter pw = new PrintWriter(new BufferedWriter(
            new FileWriter(output)));

      int T = Integer.parseInt(scan.nextLine());
      for (int t = 1; t <= T; t++) {
         // System.out.println("##### " + t + " #####");
         int N = Integer.parseInt(scan.nextLine());
         Level[] ls = new Level[N];
         for (int i = 0; i < N; i++) {
            String[] info = scan.nextLine().split(" ");
            ls[i] = new Level(Integer.parseInt(info[0]),
                  Integer.parseInt(info[1]));
         }
         Arrays.sort(ls);
         // for (int i = 0; i < N; i++)
         // System.out.println("[" + i + "] " + ls[i].ai + " " + ls[i].bi);

         int cstar = 0, c2 = 0, done = 0;
         while (c2 < N) {
            boolean found = true;
            while (found) {
               found = false;
               for (int i = N - 1; cstar < ls[c2].bi && i >= c2; i--)
                  if (cstar >= ls[i].ai) {
                     // System.out.println("do ai[" + i + "]");
                     done++;
                     cstar++;
                     ls[i].ai = Integer.MAX_VALUE;
                     found = true;
                  }
            }
            if (ls[c2].bi <= cstar) {
               // System.out.println("do bi[" + c2 + "]");
               ls[c2].bi = Integer.MAX_VALUE;
               cstar++;
               if (ls[c2].ai != Integer.MAX_VALUE)
                  cstar++;
               c2++;
               done++;
            }
            else
               break;
         }

         if (c2 == N) {
            pw.println("Case #" + t + ": " + done);
            // System.out.println("Case #" + t + ": " + done);
         }
         else {
            pw.println("Case #" + t + ": Too Bad");
            // System.out.println("Case #" + t + ": Too Bad");
         }
      }

      scan.close();
      pw.close();
   }
}

class Level implements Comparable<Object> {
   int ai, bi;

   public Level(int ai, int bi) {
      super();
      this.ai = ai;
      this.bi = bi;// System.out.println(ai + " " + bi);
   }

   public int compareTo(Object arg0) {
      Level l = (Level) arg0;
      if (bi != l.bi)
         return bi - l.bi;
      return l.ai - ai;
   }
}
