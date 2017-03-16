// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class B_InfiniteHouseOfPancakes {
  // --------------------------------------------------------------------------------
  private static String ID="B";
  private static String NAME="small-attempt1";
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
      int t=Integer.parseInt(reader.readLine()),array[]=new int[t];
      StringTokenizer st=new StringTokenizer(reader.readLine());
      SortedMap<Integer,Integer> bag=new TreeMap<>();
      for (int i=0; i<t; i++) {
        array[i]=Integer.parseInt(st.nextToken());
        add(bag,array[i],+1);
      }
      memory.clear();
      int time=solve(bag);
      output.println("Case #"+c+": "+time);
    }
  }
  private static void add(Map<Integer,Integer> bag, int key, int delta) {
    Integer oldValue=bag.remove(key);
    int newValue=(oldValue!=null?oldValue.intValue():0)+delta;
    if (newValue>0) bag.put(key,newValue);
  }
  private static Map<String,Integer> memory=new HashMap<>();
  private static int solve(SortedMap<Integer,Integer> bag) {
    if (bag.isEmpty()) {
      return 0;
    }
    String bagKey=bag.toString();
    Integer bagValue=memory.get(bagKey);
    if (bagValue!=null) return bagValue;
    int best=Integer.MAX_VALUE;
    { // Option 1
      int max=bag.lastKey();
      for (int j=1; j<=max-1; j++) {
        SortedMap<Integer,Integer> newBag=new TreeMap<>(bag);
        add(newBag,max,-1);
        add(newBag,j,+1);
        add(newBag,max-j,+1);
        best=Math.min(best,solve(newBag)+1);
      }
    }
    { // Option 2
      SortedMap<Integer,Integer> newBag=new TreeMap<>();
      for (Map.Entry<Integer,Integer> entry:bag.entrySet()) {
        int key=entry.getKey(),value=entry.getValue();
        if (key>1) add(newBag,key-1,value);
      }
      best=Math.min(best,solve(newBag)+1);
    }
    memory.put(bagKey,best);
    return best;
  }
}
