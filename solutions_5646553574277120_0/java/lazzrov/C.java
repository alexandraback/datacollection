import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class C {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new File("C-small-attempt1.in"));
    PrintWriter out = new PrintWriter(new File("C-small-attempt1.out"));

    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      
      int c = in.nextInt();
      int d = in.nextInt();
      int v = in.nextInt();
      ds = new HashSet<Integer>();
      for (int i = 0; i < d; i++) {
        ds.add(in.nextInt());
      }
      
      sum = new int[v+1];
      sum[0] = 1;
      for (int coin : ds) {
        for (int i = sum.length - 1; i >= 0; i--) {
          int next = i + coin;
          if (next < sum.length && sum[i] == 1) {
            sum[next] = 1;
          }
        }
      }
      
      best = Integer.MAX_VALUE;
      find(sum);
      System.out.println(t);
      best -= d;
      out.println("Case #" + t + ": " + best);
    }

    out.close();
  }
  static int sum[];
  static HashSet<Integer> ds;
  
  static int best;
  

  private static void find(int sum[]) {
    if (ds.size() >= best) {
      return ;
    }
    int ok = 1;
    for (int i = 0; i < sum.length; i++) {
      if(sum[i] == 0) {
        ok = 0;
        break;
      }
    }
    if (ok == 1) {
      best = Math.min(best, ds.size());
      return ;
    }

    for (int i = 1; i < sum.length; i++) {
      if (!ds.contains(i)) {
        int newSum[] = sum.clone();
        for (int j = newSum.length - 1; j >= 0; j--) {
          if (newSum[j] == 1 && j + i < newSum.length) {
            newSum[j + i] = 1;
          }
        }
        ds.add(i);
        find(newSum);
        ds.remove(i);
      }
    }
    
  }
}
