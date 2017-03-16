import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class CJ2014Round1CB {

  public static int MODVAL = 1000000007;
  
  public static long factorial(int x) {
    long result = 1;
    for (int i = x; i > 1; i--) {
      result = (result * i) % MODVAL;
    }
    return result;
  }
  
  public static long getAnswer(String[] trains) {
    boolean[] noMore = new boolean[26];
    int[] freeTrains = new int[26];
    boolean[] touchedFreeTrains = new boolean[26];
    int numTrains = trains.length;
    if (numTrains == 1) {
      return 1;
    }
    ArrayList<String> compactTrains = new ArrayList<String>(numTrains);
    ArrayList<String> compactTrainsReverse = new ArrayList<String>(numTrains);
    for (String k : trains) {
      char startChar = k.charAt(0);
      boolean allSame = true;
      int i;
      for (i = 1; i < k.length(); i++) {
        if (k.charAt(i) != startChar) {
          allSame = false;
          break;
        }
      }
      if (allSame) {
        freeTrains[startChar - 'a']++;
        continue;
      }
      char curChar = k.charAt(i);
      for (i = i+1; i < k.length(); i++) {
        if (curChar != k.charAt(i)) {
          if (noMore[curChar - 'a']) {
            return 0;
          }
          noMore[curChar - 'a'] = true;
          curChar = k.charAt(i);
        }
      }
      compactTrains.add(startChar + "" + curChar);
      compactTrainsReverse.add(curChar + "" + startChar);
    }
    Collections.sort(compactTrains);
    Collections.sort(compactTrainsReverse);
    long result = 1;
    int setCount = 0;
    if (compactTrains.size() > 0) {
      char firstChar = compactTrains.get(0).charAt(0);
      char lastChar = compactTrainsReverse.get(0).charAt(0);
      if (noMore[firstChar - 'a'] || noMore[lastChar - 'a']) {
        return 0;
      }
      for (int i = 1; i < compactTrains.size(); i++) {
        if (firstChar == compactTrains.get(i).charAt(0) || lastChar == compactTrainsReverse.get(i).charAt(0)) {
          return 0;
        }
        firstChar = compactTrains.get(i).charAt(0);
        lastChar = compactTrainsReverse.get(i).charAt(0);
        if (noMore[firstChar - 'a'] || noMore[lastChar - 'a']) {
          return 0;
        }
      }

      boolean[] touched = new boolean[compactTrains.size()];
      for (int i = 0; i < compactTrains.size(); i++) {
        if (touched[i]) {
          continue;
        }
        setCount++;

        result = (result * getCombinationCountForward(touched, touchedFreeTrains, freeTrains, i, i+1, compactTrains)) % MODVAL;
        result = (result * getCombinationCountBackward(touched, touchedFreeTrains, freeTrains, i, i+1, compactTrains)) % MODVAL;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (freeTrains[i] != 0 && (touchedFreeTrains[i] == false)) {
        setCount++;
        result = (result * factorial(freeTrains[i])) % MODVAL;
      }
    }
    result = (result * factorial(setCount)) % MODVAL;
    return result;
  }
  
  static long getCombinationCountForward(boolean[] touched, boolean[] touchedFreeTrains,int[] freeTrains, int curIndex, int minIndex, ArrayList<String> trains) {
    touched[curIndex] = true;
    String curTrain = trains.get(curIndex);
    char nextChar = curTrain.charAt(1);
    long retCount = 1;
    retCount = (retCount * factorial(freeTrains[nextChar - 'a'])) % MODVAL;
    if (touchedFreeTrains[nextChar - 'a']) {
      return 0;
    }
    touchedFreeTrains[nextChar - 'a'] = true;
    int nextIndex = -1;
    for (int i = minIndex; i < trains.size(); i++) {
      if (trains.get(i).charAt(0) == nextChar) {
        nextIndex = i;
        break;
      }
    }
    if (nextIndex == -1) {
      return retCount;
    }
    if (touched[nextIndex]) {
      return 0;
    }
    retCount = (retCount * getCombinationCountForward(touched, touchedFreeTrains, freeTrains, nextIndex, minIndex, trains)) % MODVAL;
    return retCount;
  }
  
  static long getCombinationCountBackward(boolean[] touched, boolean[] touchedFreeTrains, int[] freeTrains, int curIndex, int minIndex, ArrayList<String> trains) {
    touched[curIndex] = true;
    String curTrain = trains.get(curIndex);
    char nextChar = curTrain.charAt(0);
    long retCount = 1;
    retCount = (retCount * factorial(freeTrains[nextChar - 'a'])) % MODVAL;
    if (touchedFreeTrains[nextChar - 'a']) {
      return 0;
    }
    touchedFreeTrains[nextChar - 'a'] = true;
    int nextIndex = -1;
    for (int i = minIndex; i < trains.size(); i++) {
      if (trains.get(i).charAt(1) == nextChar) {
        nextIndex = i;
        break;
      }
    }
    if (nextIndex == -1) {
      return retCount;
    }
    if (touched[nextIndex]) {
      return 0;
    }
    retCount = (retCount * getCombinationCountBackward(touched, touchedFreeTrains, freeTrains, nextIndex, minIndex, trains)) % MODVAL;
    return retCount;
  }
  
  public static boolean isTest = false;
  public static boolean isSmall = true;
  public static void main(String[] args) {
    try {
      BufferedReader br = null;
      BufferedWriter bw = null;
      if (isTest) {
        br = new BufferedReader(new FileReader("test.txt"));
        bw = new BufferedWriter(new FileWriter("output.txt"));
      } else if (isSmall) {
        br = new BufferedReader(new FileReader("B-small-attempt1.in"));
        bw = new BufferedWriter(new FileWriter("B-small.out.txt"));
      } else {
        br = new BufferedReader(new FileReader("B-large.in"));
        bw = new BufferedWriter(new FileWriter("B-large.out.txt"));
      }

      String line = br.readLine().trim();
      int numOfGames = Integer.parseInt(line);
      String[] inVals;
      for(int i = 1; i<=numOfGames; i++) {
        inVals = br.readLine().trim().split("\\s+");
        inVals = br.readLine().trim().split("\\s+");
        long result = CJ2014Round1CB.getAnswer(inVals);
        System.out.println("Case #"+i+": " + result);
        bw.write("Case #"+i+": " + result + "\n");
      }
      br.close();
      bw.flush();
      bw.close();
    }
    catch (FileNotFoundException e) {
      System.out.println("ERROR: Cannot find file.");
      return;
    }
    catch (IOException e) {
    }
  }

}
