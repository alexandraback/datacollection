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
      String input = "C-small-attempt0.in";
      String output = "C-small-attempt0.out";

      Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
      PrintWriter pw = new PrintWriter(new BufferedWriter(
            new FileWriter(output)));

      int T = Integer.parseInt(scan.nextLine());
      for (int t = 1; t <= T; t++) {
         String[] info = scan.nextLine().split(" ");
         int A = Integer.parseInt(info[0]);
         int B = Integer.parseInt(info[1]);
         long count = 0;
         for (int i = A; i <= B; i++) {
            char[] num = String.valueOf(i).toCharArray();
            HashSet<Integer> set = new HashSet<Integer>();
            for (int j = 1; j < num.length; j++) {
               String n = "";
               for (int k = j, m = 0; m < num.length; m++, k = (k + 1)
                     % num.length)
                  n += num[k];
               int s = Integer.parseInt(n);
               if (s > i && s <= B)
                  set.add(s);
            }
            count += set.size();
         }
         pw.println("Case #" + t + ": " + count);
      }

      scan.close();
      pw.close();
   }
}