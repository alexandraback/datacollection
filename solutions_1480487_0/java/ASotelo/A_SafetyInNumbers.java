// Author: Alejandro Sotelo Arevalo
package round1b;

import java.io.*;

public class A_SafetyInNumbers {
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
      int N=Integer.parseInt(w[0]),s[]=new int[N],X=0;
      for (int i=0; i<N; i++) {
        s[i]=Integer.parseInt(w[i+1]);
        X+=s[i];
      }
      java.text.DecimalFormat df=new java.text.DecimalFormat("0.00000000");
      System.out.print("Case #"+c+":");
      for (int i=0; i<N; i++) {
        double result=check(N,s,X,i,0.0)?0.0:binarySearch(N,s,X,i,0.0,1.0)*100;
        System.out.print(" "+df.format(result).replace(',','.'));
      }
      System.out.println();
    }
    if (!STANDARD_OUTPUT) System.out.close();
    reader.close();
  }
  private static double binarySearch(int N, int[] s, int X, int i, double p1, double p2) {
    if (p2-p1<1e-10) return (p1+p2)/2;
    double pm=(p1+p2)/2;
    if (check(N,s,X,i,pm)) {
      return binarySearch(N,s,X,i,p1,pm);
    }
    else {
      return binarySearch(N,s,X,i,pm,p2);
    }
  }
  private static boolean check(int N, int[] s, int X, int i, double p) {
    double score=s[i]+X*p;
    double q=1.0-p;
    for (int j=0; j<N; j++) if (i!=j&&s[j]<score) {
      // s[j]+X*r=score
      double r=(score-s[j])/X;
      if (r>q) return true;
      q-=r;
    }
    return false;
  }
}
