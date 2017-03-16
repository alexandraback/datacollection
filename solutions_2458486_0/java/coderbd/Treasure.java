import java.io.*;
import java.util.*;

public class Treasure {

  public BufferedReader br;
  public int k, n, t;
  public int[] keys, kin;
  public boolean[] b, visited;
  public Chest[] chests;
  public List<Integer> list;

  public static class Chest {
    public int openKey;
    public int[] insideKeys;
    public Chest(int openKey, int[] insideKeys) {
      this.openKey = openKey;
      this.insideKeys = insideKeys;
    }
  }

  public int s2i(boolean[] state) {
    int ret = 0;
    for (int i = 0; i < state.length; i++)
      if (state[i])
        ret |= (1 << i);
    return ret;
  }

  public boolean isSolvable(boolean[] opened, int[] keysInHand) {
    int stateNum = 1 << n;
    visited = new boolean[stateNum];
    Arrays.fill(visited, false);
    DFS(opened, keysInHand);
    return visited[stateNum-1];
  }

  public void DFS(boolean[] opened, int[] keysInHand) {
    int stateNum = s2i(opened);
    visited[stateNum] = true;
    for (int i = 0; i < n; i++)
      if (!opened[i] && keysInHand[chests[i].openKey] > 0) {
        opened[i] = true;
        keysInHand[chests[i].openKey]--;
        for (int moreKey : chests[i].insideKeys)
          keysInHand[moreKey]++;
        int nextStateNum = s2i(opened);
        if (!visited[nextStateNum])
          DFS(opened, keysInHand);
        opened[i] = false;
        keysInHand[chests[i].openKey]++;
        for (int lessKey : chests[i].insideKeys)
          keysInHand[lessKey]--;
      }
  }

  public void go() throws Throwable {
    br = new BufferedReader(new InputStreamReader(System.in));
    t = Integer.parseInt(br.readLine());
    for (int caseNo = 1; caseNo <= t; caseNo++) {
      String[] ss = br.readLine().split(" +");
      k = Integer.parseInt(ss[0]);
      n = Integer.parseInt(ss[1]);
      ss = br.readLine().split(" +");
      chests = new Chest[n];
      kin = new int[k];
      for (int i = 0; i < k; i++)
        kin[i] = Integer.parseInt(ss[i]) - 1;
      for (int i = 0; i < n; i++) {
        ss = br.readLine().split(" +");
        int openKey = Integer.parseInt(ss[0]) - 1;
        int keyNum = Integer.parseInt(ss[1]);
        int[] insideKeys = new int[keyNum];
        for (int j = 0; j < keyNum; j++)
          insideKeys[j] = Integer.parseInt(ss[j+2]) - 1;
        chests[i] = new Chest(openKey, insideKeys);
      }
      keys = new int[200];
      Arrays.fill(keys, 0);
      for (int key : kin)
        keys[key]++;
      list = new ArrayList<Integer>();
      b = new boolean[n];
      Arrays.fill(b, false);

      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (!b[j] && keys[chests[j].openKey] > 0) {
            boolean[] bb = new boolean[n];
            for (int ii = 0; ii < n; ii++)
              bb[ii] = b[ii];
            bb[j] = true;
            int[] kk = new int[200];
            for (int ii = 0; ii < 200; ii++)
              kk[ii] = keys[ii];
            kk[chests[j].openKey]--;
            for (int moreKey : chests[j].insideKeys)
              kk[moreKey]++;
            if (isSolvable(bb, kk)) {
              b[j] = true;
              keys[chests[j].openKey]--;
              for (int moreKey : chests[j].insideKeys)
                keys[moreKey]++;
              list.add(j + 1);
              break;
            }
          }

      System.out.print("Case #" + caseNo + ":");
      if (list.size() == 0)
        System.out.print(" IMPOSSIBLE");
      else for (int id : list)
        System.out.print(" " + id);
      System.out.println();
    }
  }

  public static void main(String[] args) throws Throwable {
    new Treasure().go();
  }

}
