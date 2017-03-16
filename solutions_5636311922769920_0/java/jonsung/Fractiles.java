import java.util.*;
import java.io.*;

public class Fractiles {
  public static void main(String[] args) throws Exception {
    Scanner scan = new Scanner(new File("D-small-attempt0.in"));
    PrintWriter pw = new PrintWriter(new File("D.out"));
   // Scanner scan = new Scanner(System.in);
    //PrintWriter pw = new PrintWriter(System.out);
    
    int t = scan.nextInt();
    
    for(int i=0; i<t; i++) {
      int K = scan.nextInt();
      int C = scan.nextInt();
      int S = scan.nextInt();
      
      // impossible case
      if (C*S < K) {
        pw.println("Case #" + (i+1) + ": IMPOSSIBLE");
      }
      
      // otherwise, find the positions which are needed
      else {
        pw.print("Case #" + (i+1)+ ": ");
        int cur = 1;
        
        while(cur <= K) {
          pw.print(findPosition(cur, C, K) + " ");
          cur += C;
        }
        
        pw.println();
      }
    }
    

    pw.close();  
    
  }
  
  // for original length K, finds a position which is G if any of {start, start+1, ... , start+C} are G in the 
  // original sequence.
  public static long findPosition(int start, int C, int K) {
    long value = 0;
    int cur = start;
    while(C>1) {
      if (cur <=K) value += (cur - 1);
      value *= K;
      C--;
      cur++;
    }
    if(cur <= K)
      value += cur;
    else value += 1;
    
    return value;
  }
}