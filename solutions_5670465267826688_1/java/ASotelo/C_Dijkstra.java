// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class C_Dijkstra {
  // --------------------------------------------------------------------------------
  private static String ID="C";
  private static String NAME="large";
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
    class Solver {
      int L,X;
      char pattern[];
      boolean answer=false;
      Solver(int L, int X, char[] pattern) {
        this.L=L;
        this.X=X;
        this.pattern=pattern;
      }
      public void solve() {
        int LX=L*X;
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
        int q2=accum[LX];
        loop1: for (int i=0; i<LX; i++) {
          int q0=accum[i+1],rI=q0;
          if (rI!=2) continue loop1;
          loop2: for (int j=i+2; j<LX; j++) {
            int q1=accum[j];
            // int rJ=mul(inv(q0),q1);
            int rJ=q0==1?q1:mul(-q0,q1);
            if (rJ!=3) continue loop2;
            // int rK=mul(inv(q1),q2);
            int rK=q1==1?q2:mul(-q1,q2);
            if (rK!=4) continue loop2;
            // System.out.println(s.substring(0,i+1)+"-"+s.substring(i+1,j)+"-"+s.substring(j)+" : "+g(rI)+":"+g(rJ)+":"+g(rK));
            answer=true;
            break loop1;
          }
        }
      }
    }
    final int T=Integer.parseInt(reader.readLine());
    final Solver[] solvers=new Solver[T];
    for (int c=1; c<=T; c++) {
      StringTokenizer st=new StringTokenizer(reader.readLine());
      long L=Long.parseLong(st.nextToken()),X=Long.parseLong(st.nextToken());
      X=Math.min(X,12+X%4);
      if (X==15) X=11;
      char pattern[]=reader.readLine().toCharArray();
      solvers[c-1]=new Solver((int)L,(int)X,pattern);
    }
    final int div=5;
    Thread[] globalThreads=new Thread[div];
    for (int k=0; k<div; k++) {
      final int offset=k;
      globalThreads[k]=new Thread() {
        @Override
        public void run() {
          for (int i=offset; i<T; i+=div) {
            System.err.println("STARTING: "+i);
            solvers[i].solve();
            System.err.println("ENDING: "+i);
          }
        }
      };
      globalThreads[k].start();
    }
    for (int k=0; k<div; k++) {
      globalThreads[k].join();
    }
    for (int c=1; c<=T; c++) {
      output.println("Case #"+c+": "+(solvers[c-1].answer?"YES":"NO"));
    }
  }
  private static int f(char ch) {
    return ch=='i'?2:(ch=='j'?3:(ch=='k'?4:1));
  }
  @SuppressWarnings("unused")
  private static String g(int v) {
    return (v<0?"-":"")+" 1ijk".charAt(Math.abs(v));
  }
  @SuppressWarnings("unused")
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
