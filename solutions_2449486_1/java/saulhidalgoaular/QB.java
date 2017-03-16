import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class QB {

  static boolean equals(int [][] a, int [][] b){
    boolean ans = true;
    for (int i = 0; i < a.length; i++) {
      ans &=  Arrays.equals(a[i],b[i]);
    }
    return ans;
  }

  public static void main(String[] args) {
    final String PREFIX = "/home/saul/IdeaProjects/CodeJam/src/";

    try {
      Scanner sc = new Scanner(new File(PREFIX + "B-large.in"));
      PrintWriter out = new PrintWriter(new File(PREFIX + "QB.out"));
      //PrintWriter out = new PrintWriter(System.out);
      int n = sc.nextInt();
      for (int iCases = 0; iCases < n; iCases++) {
        int h = sc.nextInt() , w = sc.nextInt();
        int [][] grass = new int[h][w];
        for (int i = 0; i < grass.length; i++) {
          for (int j = 0; j < grass[i].length; j++) {
            grass[i][j] = sc.nextInt();
          }
        }
        int [][] original = new int[h][w];
        for (int i = 0; i < original.length; i++) {
          Arrays.fill(original[i],100);
        }
        for (int i = 0; i < grass.length; i++) {
          int max = 0;
          for (int j = 0; j < grass[i].length; j++) {
            max = Math.max(max , grass[i][j]);
          }
          for (int j = 0; j < original[i].length; j++) {
            original[i][j] = Math.min(max , original[i][j]);
          }
        }
        for (int j = 0; j < grass[0].length; j++) {
          int max = 0;
          for (int i = 0; i < grass.length; i++) {
            max = Math.max(grass[i][j], max);
          }
          for (int i = 0; i < original.length; i++) {
            original[i][j] = Math.min(max, original[i][j]);
          }
        }
        out.println("Case #" + (iCases+1) +": " + (equals(original , grass) ? "YES" : "NO"));
      }
      out.close();
    }catch (Exception ex){
      ex.printStackTrace();
    }
  }
}
