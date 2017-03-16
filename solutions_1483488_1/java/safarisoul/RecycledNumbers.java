package q2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class RecycledNumbers {
   public static void main(String[] args) throws Exception {
      long start = System.currentTimeMillis();
      String input = "C-large.in";
      String output = "C-large.out";

      Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
      PrintWriter pw = new PrintWriter(new BufferedWriter(
            new FileWriter(output)));

      int T = Integer.parseInt(scan.nextLine());
      for (int t = 1; t <= T; t++) {
         String[] info = scan.nextLine().split(" ");
         int A = Integer.parseInt(info[0]);
         int B = Integer.parseInt(info[1]);
         HashSet<Integer> set = new HashSet<Integer>();
         long count = 0;
         for (int i = A; i <= B; i++) {
            String num = String.valueOf(i);
            int len = num.length();
            set.clear();
            for (int j = 1; j < len; j++) {
               String n = num.substring(j) + num.substring(0, j);
               int s = Integer.parseInt(n);
               if (s > i && s <= B)
                  set.add(s);
            }
            count += set.size();
         }
         System.out.println("Case #" + t + ": " + count);
         pw.println("Case #" + t + ": " + count);
      }

      scan.close();
      pw.close();

      long end = System.currentTimeMillis();
      System.out.println((end - start) / 1000.0);
   }
}