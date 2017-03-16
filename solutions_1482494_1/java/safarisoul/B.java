package r1a2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class B {
   public static void main(String[] args) throws Exception {
      String input = "B-large.in";
      String output = "B-large.out";
      // String com = "out";
      // Scanner scan0 = new Scanner(new BufferedReader(new FileReader(com)));

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

         // Arrays.sort(ls, Level.another);
         // for (int i = 0; i < N; i++)
         // System.out.println("[" + i + "] " + ls[i].ai + " " + ls[i].bi);
         Arrays.sort(ls, Level.one);
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
            // int goal = ls[c2].bi;
            // Arrays.sort(ls, Level.another);
            // for(int i=0; cstar<goal && i<N && ls[i].ai<=cstar; i++)
            // if(ls[i].bi!=Integer.MAX_VALUE){
            // done++;
            // cstar++;System.out.println("do ai[" + ls[i].ai + "][" + ls[i].bi
            // + "]");
            // ls[i].ai = Integer.MAX_VALUE;
            // }
            // Arrays.sort(ls,Level.one);
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

//         String line = scan0.nextLine();

         if (c2 == N) {
            pw.println("Case #" + t + ": " + done);
            System.out.println("Case #" + t + ": " + done);
//            System.out.println(line);
//            System.out.println();
         }
         else {
            pw.println("Case #" + t + ": Too Bad");
            System.out.println("Case #" + t + ": Too Bad");
//            System.out.println(line);
//            System.out.println();
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

   static final Comparator<Level> one = new Comparator<Level>() {
      public int compare(Level arg0, Level arg1) {
         if (arg0.bi != arg1.bi)
            return arg0.bi - arg1.bi;
         return arg1.ai - arg0.ai;
      }
   };

   static final Comparator<Level> another = new Comparator<Level>() {
      public int compare(Level arg0, Level arg1) {
         if (arg0.ai != arg1.ai)
            return arg0.ai - arg1.ai;
         else
            return arg1.bi - arg0.bi;
      }
   };
}
