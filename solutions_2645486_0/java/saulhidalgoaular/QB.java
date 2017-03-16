import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class QB {


  static int max;
  static int maxE;

  public static void main(String[] args) {
    final String PREFIX = "/home/saul/IdeaProjects/CodeJam1A/src/";

    try {
      Scanner sc = new Scanner(new File(PREFIX + "B-small-attempt0.in"));
      PrintWriter out = new PrintWriter(new File(PREFIX + "QB.out"));
      //PrintWriter out = new PrintWriter(System.out);
      int n = sc.nextInt();
      for (int iCases = 0; iCases < n; iCases++) {
        int e = sc.nextInt() , r = sc.nextInt() , nn = sc.nextInt();
        max = 0;
        maxE = e;
        int [] values = new int[nn];
        for (int i = 0; i < values.length; i++) {
          values[i] = sc.nextInt();
        }
        go( 0, values, 0 , e , r );
        out.println("Case #" + (iCases+1) + ": " + max);
      }
      out.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  private static void go(int index, int[] values, int curVal, int e, int r) {
    if ( index == values.length ){
      max = Math.max(max , curVal);
    }else{
      for (int i = 0; i <= e; i++) {
        int nextE = Math.min(e - i + r , maxE);
        go(index+1, values, curVal + i*values[index], nextE, r);
      }
    }
  }

}
