package code_jam;

import java.io.*;
import java.util.*;

public class d {
  public static void main(String[] args) throws Exception{
    Scanner inf = new Scanner(new FileReader("D-large.in"));
   
    int nn = inf.nextInt();
    for (int ii = 0; ii < nn; ii++) {

      int n = inf.nextInt();
      double[] a = new double[n];
      double[] b = new double[n];
      for (int i=0; i<n; i++) 
        a[i] = inf.nextDouble();
      Arrays.sort(a);
      for (int i=0; i<n; i++)
        b[i] = inf.nextDouble();
      Arrays.sort(b);
      
      int ansa=0, ansb=0;
      int l=0, r=n-1;
      for (int i=n-1; i>=0; i--) {
        if (a[i]>b[r]) {
          ansa++;
          l++;
        } else r--;
      }
      
      l=0; 
      r=n-1;
      for (int i=n-1; i>=0; i--) {
        //System.out.println(b[i]+"\t"+a[r]);
        if (b[i]>a[r])
          l++;
        else {
          ansb++;
          r--;
        }
      }
      System.out.println("Case #" + (ii+1) + ": " + ansb + " " + ansa);
    }
    inf.close();
  }
}
