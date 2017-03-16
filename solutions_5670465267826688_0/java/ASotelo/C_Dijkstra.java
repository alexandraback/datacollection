// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class C_Dijkstra {
  // --------------------------------------------------------------------------------
  private static String ID="C";
  private static String NAME="small-attempt0";
  private static String STAGE="qualification";
  private static boolean STANDARD_OUTPUT=false;
  // --------------------------------------------------------------------------------
  private static BufferedReader reader=null;
  private static PrintStream output=null;
  // --------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    try (BufferedReader bufferedReader=reader=new BufferedReader(new FileReader(new File("data/"+STAGE+"/"+ID+"-"+NAME+".in")))) {
      try (PrintStream printStream=output=STANDARD_OUTPUT?System.out:new PrintStream(new File("data/"+STAGE+"/"+ID+"-"+NAME+".out"))) {
        process();
      }
    }
  }
  // --------------------------------------------------------------------------------
  private static void process() throws Throwable {
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      StringTokenizer st=new StringTokenizer(reader.readLine());
      int L=Integer.parseInt(st.nextToken()),X=Integer.parseInt(st.nextToken());
      X=Math.min(X,12+X%4);
      int LX=L*X;
      char pattern[]=reader.readLine().toCharArray();
      char string[]=new char[LX];
      for (int x=0; x<X; x++) {
        System.arraycopy(pattern,0,string,L*x,L);
      }
      // 1=1 i=2 j=3 k=4
      int[] accum=new int[LX+1];
      accum[0]=1;
      for (int k=1; k<=LX; k++) {
        accum[k]=mul(accum[k-1],f(string[k-1]));
      }
      // i j
      // xxxxxxyyyyyyzzzzzzz
      boolean answer=false;
      int q2=accum[LX];
      loop: for (int i=0; i<LX; i++) {
        int q0=accum[i+1],rI=q0;
        if (rI!=2) continue loop;
        for (int j=i+2; j<LX; j++) {
          int q1=accum[j];
          int rJ=mul(inv(q0),q1);
          int rK=mul(inv(q1),q2);
          // System.out.println(s.substring(0,i+1)+"-"+s.substring(i+1,j)+"-"+s.substring(j)+" : "+g(rI)+":"+g(rJ)+":"+g(rK));
          if (rJ==3&&rK==4) {
            answer=true;
            break loop;
          }
        }
      }
      output.println("Case #"+c+": "+(answer?"YES":"NO"));
    }
  }
  private static int f(char ch) {
    return ch=='i'?2:(ch=='j'?3:(ch=='k'?4:1));
  }
  @SuppressWarnings("unused")
  private static String g(int v) {
    return (v<0?"-":"")+" 1ijk".charAt(Math.abs(v));
  }
  private static int inv(int v) {
    return v==1?1:-v;
  }
  private static int mul(int v1, int v2) {
    int sgn=v1<0?(v2<0?+1:-1):(v2<0?-1:+1);
    int w1=Math.abs(v1),w2=Math.abs(v2),sum=w1+w2;
    int w=w1==1?w2:(w2==1?w1:w1==w2?-1:(sum==5?(w1==2?4:-4):(sum==6?(w1==2?-3:3):(w1==3?2:-2))));
    return sgn<0?-w:w;
  }
}
