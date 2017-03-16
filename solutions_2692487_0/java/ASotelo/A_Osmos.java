// Author: Alejandro Sotelo Arevalo
package round2;

import java.io.*;
import java.util.*;

public class A_Osmos { // -Xmx512M
  // --------------------------------------------------------------------------------
  private static String ID="A";
  private static String NAME="small-attempt0";
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
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      String line[]=reader.readLine().split(" ");
      int A=Integer.parseInt(line[0]),N=Integer.parseInt(line[1]);
      long motes[]=new long[N];
      line=reader.readLine().split(" ");
      for (int i=0; i<N; i++) {
        motes[i]=Long.parseLong(line[i]);
      }
      Arrays.sort(motes);
      memory.clear();
      output.println("Case #"+c+": "+function(motes,A,0));
    }
  }
  private static HashMap<Long,Integer> memory=new HashMap<>();
  private static int function(long[] motes, long size, int i) {
    if (i==motes.length) return 0;
    Long key=(size<<8)|i;
    Integer value=memory.get(key);
    if (value!=null) return value;
    if (motes[i]<size) value=function(motes,size+motes[i],i+1);
    else if (size<=1) value=function(motes,size,i+1)+1;
    else value=Math.min(function(motes,size,i+1)+1,function(motes,size+size-1,i)+1);
    memory.put(key,value);
    return value;
  }
}
