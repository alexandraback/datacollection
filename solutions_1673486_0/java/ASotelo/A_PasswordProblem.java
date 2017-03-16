// Author: Alejandro Sotelo Arevalo
package round1a;

import java.io.*;
import java.util.*;

public class A_PasswordProblem {
  //--------------------------------------------------------------------------------
  private static String ID="A";
  private static String NAME="small-attempt0";
  private static boolean STANDARD_OUTPUT=false;
  //--------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    BufferedReader reader=new BufferedReader(new FileReader(new File("data/"+ID+"-"+NAME+".in")));
    if (!STANDARD_OUTPUT) System.setOut(new PrintStream(new File("data/"+ID+"-"+NAME+".out")));
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      String w[]=reader.readLine().trim().split(" +");
      int A=Integer.parseInt(w[0]),B=Integer.parseInt(w[1]);
      w=reader.readLine().trim().split(" +");
      double p[]=new double[A];
      for (int i=0; i<A; i++) {
        p[i]=Double.parseDouble(w[i].replace(',','.'));
      }
      double min=function(A,B,p);
      java.text.DecimalFormat df=new java.text.DecimalFormat("0.00000000");
      System.out.println("Case #"+c+": "+df.format(min).replace(',','.'));
    }
    if (!STANDARD_OUTPUT) System.out.close();
    reader.close();
  }
  private static double function(int A, int B, double[] p) {
    double accum=1.0,R[]=new double[A+2];
    Arrays.fill(R,0.0);
    for (int k=0; k<A; k++) {
      double q=accum*(1.0-p[k]);
      // Keep typing
      int RK=(B-A)+1+B+1;
      R[0]+=RK*q;
      // Press backspace
      for (int z=1; z<=A; z++) {
        int RB=z+(B-A+z)+1;
        if (z<A-k) RB+=B+1;
        R[z]+=RB*q;
      }
      // Press enter right away
      int RE=1+B+1;
      R[A+1]+=RE*q;
      accum*=p[k];
    }
    // Without errors
    {
      double q=accum;
      // Keep typing
      int RK=(B-A)+1;
      R[0]+=RK*q;
      // Press backspace
      for (int z=1; z<=A; z++) {
        int RB=z+(B-A+z)+1;
        R[z]+=RB*q;
      }
      // Press enter right away
      int RE=1+B+1;
      R[A+1]+=RE*q;
    }
    double min=Double.POSITIVE_INFINITY;
    for (int i=0; i<R.length; i++) {
      min=Math.min(min,R[i]);
    }
    return min;
  }
}
