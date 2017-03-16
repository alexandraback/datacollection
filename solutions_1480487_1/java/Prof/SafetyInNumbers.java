import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class SafetyInNumbers {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(new File("A-large.in")));
    String line = br.readLine();
    int t = Integer.parseInt(line);
    for (int i = 0; i < t; i++) {
      line = br.readLine();
      String[] split = line.split(" ");
      int n = Integer.parseInt(split[0]);
      int[] judge = new int[n];
      int X = 0;
      for (int j = 0; j < n; j++) {
        int s = Integer.parseInt(split[j+1]);
        judge[j]=s;
        X+=s;
      }
      int[] judgeCopy = new int[n];
      System.arraycopy(judge, 0, judgeCopy, 0, n);
      
      Arrays.sort(judgeCopy);
      
      double partlyAverage = 0.0;
      for (int j = n; j > 0; j--) {
        partlyAverage = computeAverage(judgeCopy, j, X);
        if(partlyAverage>=judgeCopy[j-1]) {
          break;
        }
      }
      
      double[] ans = new double[n];
      for (int j = 0; j < ans.length; j++) {
        ans[j]=(partlyAverage-judge[j])*100.0/X;
      }
      System.out.print("Case #" + (i + 1) + ":");
      for (double d : ans) {
        if(d<0) d = 0.0;
        System.out.print(" " + d);
      }
      System.out.println();
    }
  }

  private static double computeAverage(int[] judgeCopy, int j, int x) {
    int acc=2*x;
    for (int i = j; i < judgeCopy.length; i++) {
      acc-=judgeCopy[i];
    }
    return 1.0*acc/j;
  }

}
