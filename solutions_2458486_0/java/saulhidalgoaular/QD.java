import java.io.File;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;

public class QD {

  static class Chest{
    int keyNeeded;
    LinkedList<Integer> keyInside = new LinkedList<Integer>();

    Chest(int keyNeeded, LinkedList<Integer> keyInside) {
      this.keyNeeded = keyNeeded;
      this.keyInside = keyInside;
    }
  }

  static boolean found = false;
  static LinkedList<Integer> steps;
  static HashSet<Integer> visited;

  public static void main(String[] args) {
    final String PREFIX = "/home/saul/IdeaProjects/CodeJam/src/";

    try {
      Scanner sc = new Scanner(new File(PREFIX + "D-small-attempt2.in"));
      PrintWriter out = new PrintWriter(new File(PREFIX + "QD2.out"));
      //PrintWriter out = new PrintWriter(System.out);

      int t = sc.nextInt();
      for (int iCases = 0; iCases < t; iCases++) {
        HashMap<Integer, Integer> iHave = new HashMap<Integer, Integer>();
        int k = sc.nextInt() , n = sc.nextInt();
        for (int i = 0; i < k; i++) {
          int key = sc.nextInt();
          if ( !iHave.containsKey(key) ){
            iHave.put(key, 0);
          }
          iHave.put(key, iHave.get(key)+1);
        }
        Chest[] allChests = new Chest[n];
        for (int i = 0; i < n; i++) {
          int needed = sc.nextInt();
          if ( !iHave.containsKey(needed) ){
            iHave.put(needed, 0);
          }
          LinkedList<Integer> inside = new LinkedList<Integer>();
          int ki = sc.nextInt();
          for (int j = 0; j < ki; j++) {
            int key = sc.nextInt();
            if ( !iHave.containsKey(key) ){
              iHave.put(key , 0);
            }
            inside.add(key);
          }
          allChests[i] = new Chest(needed , inside);
        }

        found = false;
        steps = new LinkedList<Integer>();
        visited = new HashSet<Integer>();
        explore(allChests, iHave, 0);
        out.print("Case #" + (iCases+1) +": ");
        if ( found ){
          for (int i = 0; i < steps.size(); i++) {
            if ( i != 0 ){
              out.print(" ");
            }
            out.print(steps.get(i));
          }
        }else{
          out.print("IMPOSSIBLE");
        }
        out.println();
      }

      out.close();
    }catch (Exception ex){
      ex.printStackTrace();
    }
  }

  private static void explore(Chest[] allChests, HashMap<Integer, Integer> iHave, int openedQ) {
    if ( openedQ == (1 << allChests.length) - 1 ){
      found = true;
    }else if ( visited.contains(openedQ) ){
      // skip;
    }else {
      visited.add(openedQ);
      for (int i = 0; i < allChests.length; i++) {
        if ( (openedQ & 1 << i) == 0 ){
          if ( iHave.get(allChests[i].keyNeeded) > 0 ){
            steps.add(i+1);

            iHave.put(allChests[i].keyNeeded,iHave.get(allChests[i].keyNeeded) - 1 );
            for (int j = 0; j < allChests[i].keyInside.size(); j++) {
              iHave.put(allChests[i].keyInside.get(j),iHave.get(allChests[i].keyInside.get(j)) + 1);
            }
            explore(allChests, iHave, openedQ | 1 << i);

            if ( found ){
              break;
            }
            iHave.put(allChests[i].keyNeeded,iHave.get(allChests[i].keyNeeded) + 1 );
            for (int j = 0; j < allChests[i].keyInside.size(); j++) {
              iHave.put(allChests[i].keyInside.get(j),iHave.get(allChests[i].keyInside.get(j)) - 1);
            }
            steps.removeLast();
          }
        }
      }
    }
  }

}
