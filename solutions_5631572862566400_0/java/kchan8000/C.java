import java.util.*;
import java.io.*;
import java.math.*;

public class C {
  
  public static void main(String cmdArgs[]) throws Exception {
    long time = System.currentTimeMillis();

    String filename = cmdArgs[0];

    BufferedWriter writer =
      new BufferedWriter(new PrintWriter(filename + "-output.txt", "UTF-8"));
    BufferedReader reader = new BufferedReader(new FileReader(filename));

    String nextLine;
    nextLine = reader.readLine(); // ignore count
    int caseNum = 1;
    while ((nextLine = reader.readLine()) != null) {
      nextLine = reader.readLine(); // ignore children count
      String[] children = nextLine.split(" ");
      writer.write("Case #" + caseNum + ": ");
      alg(writer, children);
      caseNum++;
      writer.newLine();
    }
    writer.close();
    long elapsed = System.currentTimeMillis() - time;
    System.out.println("millis elapsed: " + elapsed);
  }

  public static void alg(BufferedWriter writer, String[] children)
    throws Exception {
    int count = children.length;
    int[] bffs = new int[count];
    int[] inverseBffs = new int[count];
    for (int i = 0; i < count; i++) {
      bffs[i] = Integer.valueOf(children[i]) - 1; // off by 1
      inverseBffs[bffs[i]] = i;
    }

    // each child's max chain length
    int[] maxChainLengths = new int[count];

    // key = pair cycle terminus node
    // value = max chain length (not including pair)
    int[] maxChainWhichTerminatesAt = new int[count];

    // compute maxChainLength for each kid
    for (int kid = 0; kid < count; kid++) {
      if (maxChainLengths[kid] > 0) {
        // we already know this kid's in a cycle length. save our time.
        continue;
      }
      List<Integer> kidsInChain = new ArrayList<>();
      kidsInChain.add(kid);
      int chainLength = 1;
      int currentKid = kid;
      while (true) {
        int bff = bffs[currentKid];
        if (kidsInChain.contains(bff)) {
          // bff is already in the chain, cycle found!
          int kidsNotInCycle = 0;
          boolean foundBff = false;
          for (Integer kidInChain: kidsInChain) {
            if (bff == kidInChain) {
              foundBff = true;
            }
            if (!foundBff) {
              kidsNotInCycle++;
            } else {
              maxChainLengths[kidInChain] = chainLength - kidsNotInCycle;
            }
            if (maxChainLengths[kidInChain] == 2) {
              // pair cycle;
              if (kidsNotInCycle > maxChainWhichTerminatesAt[bff]) {
                maxChainWhichTerminatesAt[bff] = kidsNotInCycle;
              }
            }
          }
          break;
        } else {
          kidsInChain.add(bff);
          chainLength++;
          currentKid = bff;
        }
      }
    }
    int maxCycle = maximum(maxChainLengths);
    int sumPairChains = 0;
    boolean[] seen = new boolean[count];
    for (int kid = 0; kid < count; kid++) {
      int bff = bffs[kid];
      if (maxChainWhichTerminatesAt[kid] > 0 && !seen[kid]) {
        int chainSum = maxChainWhichTerminatesAt[kid] + maxChainWhichTerminatesAt[bff] + 2;
        sumPairChains += chainSum;
        seen[bff] = true;
      }
    }
    int max = maxCycle > sumPairChains ? maxCycle : sumPairChains;
    writer.write("" + max);
  }

  public static int maximum(int[] arr) {
    int max = -1;
    for (int i : arr) {
      if (i > max) {
        max = i;
      }
    }
    return max;
  }
}
