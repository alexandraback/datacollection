package codejam;

import java.io.File;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Treasure {

  private static class KeyList {
    int[] keyCount = new int[201];// max key types

    public KeyList(KeyList list) {
      for (int i = 0; i < list.keyCount.length; i++) {
        this.keyCount[i] = list.keyCount[i];
      }
    }

    public KeyList() {

    }

    public void remove(int key) {
      keyCount[key]--;
    }

    public boolean contains(int key) {
      return keyCount[key] != 0;
    }

    public void add(int key) {
      keyCount[key]++;
    }

    public void addAll(int[] keys) {
      if (keys == null) return;
      for (int key : keys) {
        add(key);
      }
    }

    public boolean containAll(KeyList kList) {
      for (int i = 1; i < keyCount.length; i++) {
        if (keyCount[i] < kList.keyCount[i]) return false;
      }
      return true;
    }
  }

  private static class Status {
    public Status(int totalChest) {
      this.totalChest = totalChest;
      chestKeys = new int[totalChest + 1][];
      chestOpenKey = new int[totalChest + 1];
      chestStatus = new int[totalChest + 1];
    }

    int totalChest;
    List<Integer> result = new LinkedList<Integer>();;
    int[][] chestKeys;
    int chestOpenKey[];
    int chestStatus[];// a[i]=0,closed. a[i]=1,opened
    KeyList curKeys = new KeyList();

    // dependency graph
    List<Integer> curKeyReach;

    Map<Integer, List<Integer>> depGraph;

    private boolean connected() {
      updateCurKeysReach();

      int[] visited = new int[totalChest + 1];
      Deque<Integer> queue = new LinkedList<Integer>();
      queue.addAll(curKeyReach);
      while (queue.size() != 0) {
        int v = queue.poll();
        visited[v] = 1;
        for (Integer i : depGraph.get(v)) {
          if (chestStatus[i] == 0 && visited[i] == 0) {// closed chest
            queue.add(i);
          }
        }
      }
      for (int chest = 1; chest <= totalChest; chest++) {
        if (visited[chest] == 0 && chestStatus[chest] == 0) {
          return false;// unreachable
        }
      }
      return true;
    }

    private void initDepGraph() {
      depGraph = new HashMap<Integer, List<Integer>>();
      for (int chest = 1; chest <= totalChest; chest++) {
        depGraph.put(chest, new LinkedList<Integer>());
      }
      for (int chest = 1; chest <= totalChest; chest++) {
        int openkey = chestOpenKey[chest];
        for (int c = 1; c <= totalChest; c++) {
          if (c != chest) {
            for (int key : chestKeys[c]) {
              if (key == openkey) {
                depGraph.get(c).add(chest);// c-->chest
              }
            }
          }
        }
      }
    }

    private void updateCurKeysReach() {
      curKeyReach = new LinkedList<Integer>();
      for (int chest = 1; chest <= totalChest; chest++) {
        int openkey = chestOpenKey[chest];
        if (chestStatus[chest] == 0 && curKeys.contains(openkey)) {
          curKeyReach.add(chest);
        }
      }
    }

    private boolean hopeful() {
      KeyList possibleKeys = new KeyList(curKeys);
      KeyList neededKeys = new KeyList();
      for (int i = 1; i <= totalChest; i++) {
        if (chestStatus[i] == 0) {
          neededKeys.add(chestOpenKey[i]);
          possibleKeys.addAll(chestKeys[i]);
        }
      }

      if (possibleKeys.containAll(neededKeys)) return true;
      else return false;
    }

    private void closeChest(int chest) {
      chestStatus[chest] = 0;
      curKeys.add(chestOpenKey[chest]);
      int[] keys = chestKeys[chest];
      if (keys != null) {
        for (int key : keys) {
          curKeys.remove(key);
        }
      }
    }

    private void openChest(int chest) {
      chestStatus[chest] = 1;
      curKeys.remove(chestOpenKey[chest]);
      curKeys.addAll(chestKeys[chest]);
    }

    private boolean openable(int chest) {
      return curKeys.contains(chestOpenKey[chest]);
    }

    private boolean search(int chest) {
      if (!openable(chest)) return false;
      this.openChest(chest);
      result.add(chest);
//      System.out.println(Arrays.toString(result.toArray(new Integer[0])));
      if (result.size() == totalChest) {
        return true;
      }
      if (hopeful() && connected()) {
        for (int i = 1; i <= totalChest; i++) {
          if (chestStatus[i] == 0) {
            if (true == search(i)) {
              return true;
            }
          }
        }

      }
//      else {
//        System.out.println("branch out");
//      }
      this.closeChest(chest);
      result.remove(new Integer(chest));
      return false;
    }
  }

  private static String getResultString(int caseNum, List<Integer> list) {
    StringBuilder sb = new StringBuilder("Case #" + caseNum + ":");
    for (int chest : list) {
      sb.append(" " + chest);
    }
    return sb.toString();
  }

  public static void main(String[] args) throws Exception {
    String file = "D:\\D-large.in";
    Scanner cin = new Scanner(new File(file));
    Writer writer = new FileWriter(new File("D:\\d-out2.dat"));
    int n = Integer.parseInt(cin.nextLine());
    nextcase: for (int caseNum = 1; caseNum <= n; caseNum++) {
//      System.out.println("CASE===============" + caseNum);
      int startKeys = cin.nextInt(), totalChest = cin.nextInt();

//      System.out.println("startKeys=" + startKeys + " totalChest=" + totalChest);
      Status status = new Status(totalChest);
      for (int i = 0; i < startKeys; i++) {
        status.curKeys.add(cin.nextInt());// initial keys
      }
      for (int chest = 1; chest <= totalChest; chest++) {
        status.chestOpenKey[chest] = cin.nextInt();
        int chestKeys = cin.nextInt();
        int[] keys = new int[chestKeys];
        for (int i = 0; i < chestKeys; i++) {
          keys[i] = cin.nextInt();
        }
        status.chestKeys[chest] = keys;
      }
      // read for this case finished.
      status.initDepGraph();
//      System.out.println("depGraph init finish");
      for (int i = 1; i <= totalChest; i++) {
        if (true == status.search(i)) {
          writer.append(getResultString(caseNum, status.result) + "\n");
          continue nextcase;
        }
//        System.out.println();
      }
      writer.append("Case #" + caseNum + ": IMPOSSIBLE" + "\n");

    }
    writer.close();
    cin.close();
    System.out.println("Finished.");

  }
}
