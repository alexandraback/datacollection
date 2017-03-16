// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class B_InfiniteHouseOfPancakes {
  // --------------------------------------------------------------------------------
  private static String ID="B";
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
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      int t=Integer.parseInt(reader.readLine()),array[]=new int[t];
      StringTokenizer st=new StringTokenizer(reader.readLine());
      SortedMap<Integer,Integer> bag=new TreeMap<>();
      for (int i=0; i<t; i++) {
        array[i]=Integer.parseInt(st.nextToken());
        add(bag,array[i],+1);
      }
      // memory.clear();
      // int time=solveSlow(bag);
      int time=solveFast(array);
      output.println("Case #"+c+": "+time);
    }
  }
  // FAST VERSION
  private static int solveFast(int[] array) {
    Arrays.sort(array);
    int t=array.length,MAX=1024;
    int matrix[][]=new int[t+1][MAX];
    for (int i=0; i<=t; i++) {
      for (int max=0; max<MAX; max++) {
        if (i==0) {
          matrix[i][max]=max;
        }
        else {
          int v=array[i-1];
          int best=Integer.MAX_VALUE;
          for (int j=1; j<=v; j++) {
            int currentCuts=j-1;
            int currentMax=v/j+(v%j==0?0:1);
            best=Math.min(best,currentCuts+matrix[i-1][Math.max(max,currentMax)]);
          }
          matrix[i][max]=best;
        }
      }
    }
    return matrix[t][0];
  }
  // RECURSIVE VERSION
  @SuppressWarnings("unused")
  private static int solveRecursive(int[] array) {
    return solveRecursive(array,array.length-1,0);
  }
  private static int solveRecursive(int[] array, int i, int max) {
    if (i==-1) return max;
    int v=array[i];
    int best=Integer.MAX_VALUE;
    for (int j=1; j<=v; j++) {
      int currentCuts=j-1;
      int currentMax=v/j+(v%j==0?0:1);
      best=Math.min(best,currentCuts+solveRecursive(array,i-1,Math.max(max,currentMax)));
    }
    return best;
  }
  // SLOW VERSION
  private static Map<String,Integer> memory=new HashMap<>();
  @SuppressWarnings("unused")
  private static int solveSlow(SortedMap<Integer,Integer> bag) {
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
        best=Math.min(best,solveSlow(newBag)+1);
      }
    }
    { // Option 2
      SortedMap<Integer,Integer> newBag=new TreeMap<>();
      for (Map.Entry<Integer,Integer> entry:bag.entrySet()) {
        int key=entry.getKey(),value=entry.getValue();
        if (key>1) add(newBag,key-1,value);
      }
      best=Math.min(best,solveSlow(newBag)+1);
    }
    memory.put(bagKey,best);
    return best;
  }
  private static void add(Map<Integer,Integer> bag, int key, int delta) {
    Integer oldValue=bag.remove(key);
    int newValue=(oldValue!=null?oldValue.intValue():0)+delta;
    if (newValue>0) bag.put(key,newValue);
  }
}
