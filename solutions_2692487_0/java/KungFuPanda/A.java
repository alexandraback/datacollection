import java.util.*;
import java.io.*;
import java.util.Collections;


public class A {
  
  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);
    
    int T = sc.nextInt();
    int[] num;
    for(int i=1;i<=T; i++) {
      long a = sc.nextLong();
      int n = sc.nextInt();
      num = new int[n];
      
      for(int j=0;j<n;j++) {
        num[j] = sc.nextInt();
      }
    
      Arrays.sort(num);
      
      int count = solve(num,a,0,n-1);
      System.out.print("Case #"+i+": "+count);
      if(i!=T) System.out.println();
    }
  }
   private static int solve(int[] num, long sum, int p, int q) {
     
      if(sum == 1) return q-p+1;
      if(p==q) {
        if(sum > num[p]) return 0;
        return 1;
      }
      if(sum > num[p]) 
        return solve(num, sum+num[p], p+1,q);
        
      int count = 0;
      long diff = sum;
      while(diff <= num[p]) {
        diff = 2*diff -1;
        count++;
      }
   //   System.out.println("Sum :"+sum+" diff: "+diff+" c "+num[p]);
      count = count + solve(num, diff+num[p], p+1,q);
      //int count2 = 1+solve(num, sum,p+1,q); 
      return Math.min(count,q-p+1);
    }
}  