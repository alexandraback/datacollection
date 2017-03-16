package codejam.y2013.q;

import info.olteanu.utils.StringTools;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.text.DecimalFormat;
import java.text.FieldPosition;
import java.util.Arrays;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class P4 {

  public static final int MAX_KEYS = 201;

  public static void main(String[] args) throws Exception {
    BufferedReader inputFile = new BufferedReader(new InputStreamReader(
        new FileInputStream(args[0])));
    int cases = Integer.parseInt(inputFile.readLine());

    PrintStream outFile = new PrintStream(new FileOutputStream(args[1]));
    for (int inputNo = 1; inputNo <= cases; inputNo++) {
      String[] kn = tokenize(inputFile.readLine());
      int n = Integer.parseInt(kn[1]);
      //System.err.println("Processing #" + inputNo + " " + kn[0] + "/" + kn[1]);

      int[] initialKeys = new int[MAX_KEYS];
      String[] initialKeysStr = tokenize(inputFile.readLine());
      for (String kstr : initialKeysStr) {
        initialKeys[Integer.parseInt(kstr)]++;
      }
//      System.err.println(" Initial keys: "
//          + StringTools.untokenize(initialKeysStr));

      int[] chestInKey = new int[n];
      int[][] chestOutKeys = new int[n][];
      int totalKeys = 0;
      for (int i = 0; i < n; i++) {
        String[] keysStr = tokenize(inputFile.readLine());
        chestInKey[i] = Integer.parseInt(keysStr[0]);
        int nOutKeys = Integer.parseInt(keysStr[1]);
        chestOutKeys[i] = new int[nOutKeys];
        for (int j = 0; j < nOutKeys; j++) {
          chestOutKeys[i][j] = Integer.parseInt(keysStr[j + 2]);
          totalKeys++;
        }
        Arrays.sort(chestOutKeys[i]);
//        System.err.println("  " + keysStr[0] + " -> "
//            + StringTools.untokenize(StringTools.cutFirst(keysStr, 2)));
      }

      //System.err.println("Total keys: " + totalKeys);

      // static analysis - dependency - if one chest has the same demands as a previous one but
      // generates same or less keys, then it needs to wait for the previous one to be opened
      int[] dependency = new int[n];
      for (int i = 0; i < dependency.length; i++) {
        dependency[i] = -1;

        for (int j = i - 1; j >= 0; j--) {
          if (chestInKey[i] == chestInKey[j]) {
            if (allIn(chestOutKeys[i] , chestOutKeys[j])) {
              dependency[i] = j;
              break;
            }
          }
        }
      }

      // in/out analysis
      int[] selfKeys = new int[n];
      int[][] chestOutKeysDedup = new int[n][];
      //TreeSet<Integer>[] outPerChest = new TreeSet[n];
      for (int i = 0; i < chestOutKeys.length; i++) {
        TreeSet<Integer> k = new TreeSet<Integer>();
        for (int j = 0; j < chestOutKeys[i].length; j++) {
          if (chestInKey[i] == chestOutKeys[i][j])
            selfKeys[i]++;
          k.add(chestOutKeys[i][j]);
        }
        //outPerChest[i] = k;

        chestOutKeysDedup[i] = new int[k.size()];
        int j = 0;
        for (Integer x : k) {
          chestOutKeysDedup[i][j++] = x;
        }

        //System.err.println(" Self #" + i + ": " + selfKeys[i] + "; dependency: " + dependency[i]);
      }


      String out = "IMPOSSIBLE";

      try {
        int[] solution = new int[n];
        boolean[] selected = new boolean[n];
        searchForSolution(solution, selected, 0, selfKeys, initialKeys.clone(),
            chestInKey, chestOutKeys, chestOutKeysDedup, dependency);
        out = "IMPOSSIBLE";
      } catch (Finish t) {
        StringBuilder sb = new StringBuilder();
        for (int c : t.solution) {
          sb.append(' ');
          sb.append(c + 1);
        }
        out = sb.toString().trim();
      }
      //System.err.println("Solution: " + out);

      outFile.println("Case #" + inputNo + ": " + out);
    }
    outFile.close();
    inputFile.close();
  }

  // all from small are in big; they are sorted
  private static boolean allIn(int[] small, int[] big) {
    int idxBig = -1;
    for (int v : small) {
      idxBig = firstIndexOf(v, big, idxBig);
      if (idxBig == -1)
        return false;
    }
    return true;
  }

  private static int firstIndexOf(int v, int[] big, int start) {
    for (int i = start + 1; i < big.length; i++) {
      if (v == big[i])
        return i;
    }
    return -1;
  }

  // selfKeys - how many keys of the type input is present in output for each chest
  private static void searchForSolution(int[] solution, boolean[] selected,
      int nSelected, int selfKeys[], int[] availableKeys, int[] chestInKey, int[][] chestOutKeys, int[][] chestOutKeysDedup,
      int[] dependency)
      throws Finish {

    if (nSelected == selected.length)
      throw new Finish(solution);

    if (!enoughAvailableKeys(selected, selfKeys, availableKeys, chestInKey, chestOutKeys, chestOutKeysDedup))
      return;

    for (int i = 0; i < selected.length; i++) {
      if (!selected[i] && availableKeys[chestInKey[i]] > 0) {
        // can't select it now - wait to select the dependency first
        if (dependency[i] != -1 && !selected[dependency[i]])
          continue;

        selected[i] = true;
        solution[nSelected] = i;
        availableKeys[chestInKey[i]]--;
        for (int j = 0; j < chestOutKeys[i].length; j++) {
          availableKeys[chestOutKeys[i][j]]++;
        }

        searchForSolution(solution, selected, nSelected + 1, selfKeys, availableKeys,
            chestInKey, chestOutKeys, chestOutKeysDedup, dependency);

        // undo
        selected[i] = false;
        solution[nSelected] = -1;
        availableKeys[chestInKey[i]]++;
        for (int j = 0; j < chestOutKeys[i].length; j++) {
          availableKeys[chestOutKeys[i][j]]--;
        }
      }
    }

  }

  private static final int[] _totalKeys = new int[MAX_KEYS];
  private static final int[] _demandedKeys = new int[MAX_KEYS];
  private static final int[] _cntChestsWithKey = new int[MAX_KEYS];
  // returns false if by there are not enough keys to cover the demand
  private static boolean enoughAvailableKeys(boolean[] selected, int[] selfKeys,
      int[] availableKeys, int[] chestInKey, int[][] chestOutKeys, int[][] chestOutKeysDedup) {
    int[] totalKeys = _totalKeys;
    int[] demandedKeys = _demandedKeys;
    int[] cntChestsWithKey = _cntChestsWithKey;
    for (int i = 0; i < MAX_KEYS; i++) {
      totalKeys[i] = availableKeys[i];
      demandedKeys[i] = 0;
      cntChestsWithKey[i] = 0;
    }

    for (int i = 0; i < chestOutKeys.length; i++) {
      if (!selected[i]) {
        for (int j = 0; j < chestOutKeys[i].length; j++) {
          totalKeys[chestOutKeys[i][j]]++;
        }

        for (int j = 0; j < chestOutKeysDedup[i].length; j++) {
          cntChestsWithKey[chestOutKeysDedup[i][j]]++;
        }
      }
    }



    for (int i = 0; i < chestInKey.length; i++) {
      if (!selected[i]) {
        demandedKeys[chestInKey[i]]++;
      }
    }

    // check overall
    for (int i = 0; i < MAX_KEYS; i++)
      if (demandedKeys[i] > totalKeys[i])
        return false;

    // now check per chest
    for (int i = 0; i < chestOutKeys.length; i++) {
      int k = chestInKey[i];
      if (cntChestsWithKey[k] == 1 && totalKeys[k] == selfKeys[i])
        return false;
    }

    return true;
  }

  private static class Finish extends Throwable {
    private static final long serialVersionUID = -3469391319530628728L;

    public Finish(int[] solution) {
      this.solution = solution;
    }

    public final int[] solution;
  }

  public static String[] tokenize(String input) {
    StringTokenizer st = new StringTokenizer(input);
    String[] k = new String[st.countTokens()];
    for (int i = 0; i < k.length; i++)
      k[i] = st.nextToken();
    return k;
  }

  public static String[] tokenize(String input, String sep) {
    StringTokenizer st = new StringTokenizer(input, sep);
    String[] k = new String[st.countTokens()];
    for (int i = 0; i < k.length; i++)
      k[i] = st.nextToken();
    return k;
  }

  public static String formatDouble(double myDouble, String format) {
    DecimalFormat dfFormat = new DecimalFormat(format);
    FieldPosition f = new FieldPosition(0);
    StringBuffer s = new StringBuffer();
    dfFormat.format(myDouble, s, f);
    return s.toString();
  }
}
