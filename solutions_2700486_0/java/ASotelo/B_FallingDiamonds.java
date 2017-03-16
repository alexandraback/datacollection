// Author: Alejandro Sotelo Arevalo
package round2;

import java.io.*;
import java.util.*;

public class B_FallingDiamonds {
  // --------------------------------------------------------------------------------
  private static String ID="B";
  private static String NAME="small-attempt2";
  private static String STAGE="round2";
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
    //int M=15000; // even
    int M=200; // even
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      String line[]=reader.readLine().split(" ");
      int N=Integer.parseInt(line[0]),X=Integer.parseInt(line[1]),Y=Integer.parseInt(line[2]);
//int N=9,X=10,Y=10;    
      if ((X&1)==1) Y--;
      int diamonds[]=new int[M*2+1],count=0,options=0;
//Set<String> set=new HashSet<>();      
      for (int r=0,t=1<<N; r<t; r++) {
        Arrays.fill(diamonds,-1);
        boolean possible=true;
        for (int i=0; i<N&&possible; i++) {
          boolean toRight=((r>>>i)&1)==1,toLeft=!toRight;
          if ((M%2==0&&diamonds[M]==-1)||(diamonds[M-1]==diamonds[M+1]&&diamonds[M]==diamonds[M-1])) {
            if (toRight) {
              diamonds[M]+=2;
            }
            else {
              possible=false;
            }
          }
          else {
            if ((toRight&&diamonds[M+1]<=diamonds[M-1])||(toLeft&&diamonds[M+1]>=diamonds[M-1])) {
              for (int delta=toRight?1:-1,k=M+delta; k>=0&&k<diamonds.length; k+=delta) {
                if ((k%2==0&&diamonds[k]==-1)||(diamonds[k-1]==diamonds[k+1]/*&&diamonds[k]==diamonds[k-1]*/)) {
                  diamonds[k]+=2;
                  break;
                }
              }
            }
            else {
              possible=false;
            }
          }
        }
        if (possible) {
          //set.add(Arrays.toString(Arrays.copyOfRange(diamonds,M-4,M+5)));
          //System.out.println(Arrays.toString(Arrays.copyOfRange(diamonds,M-4,M+5))+";"+Integer.toString(r,2));          
          options++;
          if (X+M<diamonds.length&&X+M>=0&&Y<=diamonds[X+M]) count++;
        }
      }
      //for (String s:set) System.out.println(s);
      output.println("Case #"+c+": "+(options==0?0.0:(1.0*count/options)));
    }
  }
}
