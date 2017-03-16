import java.util.Scanner;
import java.io.*;

public class ProbARound1B {
  public static void main(String[] args) throws IOException{
    Scanner in = new Scanner(new File("D:/A-small-attempt1-1B.in"));
    PrintStream out = new PrintStream(new File("D:/outputA-1B.txt"));
    
    int caseAmount = in.nextInt();
    
    for (int m = 1; m <= caseAmount; m++) {
      int n = in.nextInt();
      int[] a = new int[n];
      double[]frac = new double[n];
      int[] check = new int[n];
      int sum = 0;
      int count=0;
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();
        sum+=a[i];
      }
      
      out.print("Case #" + m + ":");
      
      double k = 2/(double)(n);
      
      while(true) {
        for (int i = 0; i < n; i++) {
          if (check[i] == 0) {
            frac[i] = k - a[i] / (double) sum;
          }
          if (frac[i] < 0) {
            frac[i] = 0;
            check[i]++;
            count++;
          }        
        }
    
        if(count==0){
          for (int i = 0; i < n; i++) {
            out.print(" " + 100 * frac[i]);
          }
          break;
        }

        else {
          k = 2/(double)(n-count);
          for (int i = 0; i < n; i++) {
            if (check[i] != 0) {
              k -= a[i] / (double)((n - count) * sum);
            }
          }
          count = 0;
        }
      }

      out.println();

    }
    
    in.close();
    out.close();
   
  }
}

