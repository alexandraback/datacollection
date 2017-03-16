import java.util.*;

public class Luck2 {
  public static int[] temp;
  public static void main(String[] args) {
    long start = System.currentTimeMillis();
    Scanner in = new Scanner(System.in);
    int numCases = in.nextInt();
    int numRows = in.nextInt();
    int setSize = in.nextInt(); // N
    int setLimit = in.nextInt(); // M
    int numProducts = in.nextInt(); // K
      int badCount = 0;
    temp = new int[setSize];
    StringBuilder output = new StringBuilder();
    int gloCounter = 0;
    HashSet<Long> hashes = new HashSet<Long>(5000000);
    for (int caseNum = 1; caseNum <= numCases; ++caseNum) {
      output.append(String.format("Case #%d:\n", caseNum));
      long[] bestProbs = new long[numRows];
      int[][] bestSets = new int[numRows][setSize];
      int[] currentSet = new int[setSize];
      Arrays.fill(currentSet, 2);
      long[][] products = new long[numRows][numProducts];
      for (int curRow = 0; curRow < numRows; ++curRow) {
        for (int i = 0; i < numProducts; ++i) {
          products[curRow][i] = in.nextLong();
        }
      }
      int lastCheck = 0;
      do {
        if (System.currentTimeMillis() - start > 120000)
          break;
        //++gloCounter;
        if (!alreadyChecked(currentSet, hashes)) {
          setChecked(currentSet, hashes);
          /*if (gloCounter - lastCheck >= 1000) {
            System.err.printf("Reached %d after %dms\n", gloCounter, System.currentTimeMillis() - start);
            lastCheck = gloCounter;
          }*/
          // for each possible set, first, analyze its product possibilities
          // then look through each query row, determine likelihood, compare to best for that row, update accordingly.
          
          // first, we need to analyze the current set.
          // kinda want a mapping <Long --> Double>
          // going to ignore the denominator, hope it works, lol.
          HashMap<Long, Long> map = new HashMap<Long, Long>(); // map to number of times the product occurs.
          for (int mask = 0; mask < (1 << setSize); ++mask) {
            long product = 1;
            for (int bit = 1, idx = 0; bit <= mask; bit <<= 1, ++idx) {
              if ( (bit & mask) != 0) {
                product *= currentSet[idx];
              }
            }
            Long count = map.get(product);
            if (count == null) {
              map.put(product, 1L);
            } else {
              map.put(product, count+1L);
            }
          }
    OUTER:for (int curRow = 0; curRow < numRows; ++curRow) {
            long chance = 1;
            for (int curP = 0; curP < numProducts; ++curP) {
              Long count = map.get(products[curRow][curP]);
              if (count == null)
                continue OUTER; // go to next row cause this one failed.
              else
                chance *= count;
            }
            if (chance > bestProbs[curRow]) {
              bestProbs[curRow] = chance;
              System.arraycopy(currentSet, 0, bestSets[curRow], 0, setSize);
            }
          }
        }
      } while (addOne(currentSet, setLimit) != -1);
      for (int curRow = 0; curRow < numRows; ++curRow) {
        if (bestSets[curRow][0] == 0) {
          Arrays.fill(bestSets[curRow], 7);
          ++badCount;
        }
        for (int idx = 0; idx < setSize; ++idx) {
          output.append(bestSets[curRow][idx]);
        }
        output.append('\n');
      }
    }
    System.err.println(badCount);
    System.out.print(output);
  }
  
  public static boolean alreadyChecked(int[] s, HashSet<Long> set) {
    long hash = getHash(s);
    return set.contains(hash);
  }
  
  public static long getHash(int[] s) {
    System.arraycopy(s, 0, temp, 0, s.length);
    Arrays.sort(temp);
    long total = 0;
    for (int i = 0; i < temp.length; ++i) {
      total *= 10;
      total += temp[i];
    }
    return total;
  }
  
  public static void setChecked(int[] s, HashSet<Long> set) {
    long hash = getHash(s);
    set.add(hash);
  }
  
  public static int addOne(int[] set, int limit) {
    int idx = 0;
    while (idx != set.length) {
      ++set[idx];
      if (set[idx] == limit+1) {
        set[idx] = 2;
        ++idx;
      } else {
        break;
      }
    }
    if (idx == set.length) // reached the end of adding.
      return -1;
    return 0;
  }
}