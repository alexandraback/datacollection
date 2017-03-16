// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class D_Treasure {
  // --------------------------------------------------------------------------------
  private static String ID="D";
  private static String NAME="small-attempt2";
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
  private static int initialKeys[],availableKeys[],potentialKeys[],requiredKeys[],chests[],chestKeys[][],answer[];
  private static boolean[] openedChests;
  private static BitSet keysBitSet,chestsBitSet;
  private static void process() throws Throwable {
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      String line[]=reader.readLine().trim().split(" ");
      initialKeys=new int[Integer.parseInt(line[0])];
      availableKeys=new int[1<<9];
      potentialKeys=new int[1<<9];
      requiredKeys=new int[1<<9];
      chests=new int[Integer.parseInt(line[1])];
      chestKeys=new int[chests.length][];
      answer=new int[chests.length];
      openedChests=new boolean[chests.length];
      keysBitSet=new BitSet(1<<9);
      chestsBitSet=new BitSet(1<<9);
      line=reader.readLine().trim().split(" ");
      for (int k=0; k<initialKeys.length; k++) {
        initialKeys[k]=Integer.parseInt(line[k]);
      }
      Arrays.sort(initialKeys);
      addKeys(availableKeys,initialKeys);
      for (int n=0; n<chests.length; n++) {
        line=reader.readLine().trim().split(" ");
        chests[n]=Integer.parseInt(line[0]);
        chestKeys[n]=new int[Integer.parseInt(line[1])];
        for (int k=0; k<chestKeys[n].length; k++) {
          chestKeys[n][k]=Integer.parseInt(line[k+2]);
        }
        Arrays.sort(chestKeys[n]);
        requiredKeys[chests[n]]++;
        addKeys(potentialKeys,chestKeys[n]);
        keysBitSet.set(chests[n]);
        chestsBitSet.set(n);
      }
      output.print("Case #"+c+":");
      if (simulate(0)) {
        for (int index:answer) {
          output.print(" "+index);
        }
        output.println();
      }
      else {
        output.println(" IMPOSSIBLE");
      }
    }
  }
  private static boolean simulate(int i) {
    if (i==chests.length) return true;
    for (int k=keysBitSet.nextSetBit(0); k>=0; k=keysBitSet.nextSetBit(k+1)) {
      if (requiredKeys[k]>availableKeys[k]+potentialKeys[k]) return false;
    }
    for (int j=chestsBitSet.nextSetBit(0),k,keys[]; j>=0; j=chestsBitSet.nextSetBit(j+1)) {
      k=chests[j];
      keys=chestKeys[j];
      if (openedChests[j]||availableKeys[k]<=0) continue;
      answer[i]=j+1;
      openedChests[j]=true;
      availableKeys[k]--;
      addKeys(availableKeys,keys);
      removeKeys(potentialKeys,keys);
      requiredKeys[k]--;
      if (requiredKeys[k]==0) keysBitSet.clear(k);
      chestsBitSet.clear(j);
      if (simulate(i+1)) return true;
      chestsBitSet.set(j);
      if (requiredKeys[k]==0) keysBitSet.set(k);
      requiredKeys[k]++;
      addKeys(potentialKeys,keys);
      removeKeys(availableKeys,keys);
      availableKeys[k]++;
      openedChests[j]=false;
      answer[i]=0;
      if (Arrays.binarySearch(keys,k)>=0) return false;
    }
    return false;
  }
  private static void addKeys(int[] availableKeys, int[] keys) {
    for (int key:keys) {
      availableKeys[key]++;
    }
  }
  private static void removeKeys(int[] availableKeys, int[] keys) {
    for (int key:keys) {
      availableKeys[key]--;
    }
  }
}
