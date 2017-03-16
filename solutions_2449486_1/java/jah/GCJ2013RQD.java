package gcj;

/*
 * Problem D. Treasure
Confused? Read the quick-start guide.
Small input
20 points 
Solve D-small
You may try multiple times, with penalties for wrong submissions.
Large input
60 points 
You must solve the small input first.
You will have 8 minutes to solve 1 input file. (Judged after contest.)
Problem

Following an old map, you have stumbled upon the Dread Pirate Larry's secret treasure trove!

The treasure trove consists of N locked chests, each of which can only be opened by a key of a specific type. Furthermore, once a key is used to open a chest, it can never be used again. Inside every chest, you will of course find lots of treasure, and you might also find one or more keys that you can use to open other chests. A chest may contain multiple keys of the same type, and you may hold any number of keys.

You already have at least one key and your map says what other keys can be found inside the various chests. With all this information, can you figure out how to unlock all the chests?

For example, suppose the treasure trove consists of four chests as described below, and you began with exactly one key of type 1:

Chest Number  |  Key Type To Open Chest  |  Key Types Inside
--------------+--------------------------+------------------
1             |  1                       |  None
2             |  1                       |  1, 3
3             |  2                       |  None
4             |  3                       |  2
You can open all the chests in this example if you do them in the order 2, 1, 4, 3. If you start by opening chest #1 first, then you will have used up your only key, and you will be stuck.
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a single line containing two positive integers K and N, representing the number of keys you start with and the number of chests you need to open.

This is followed by a line containing K integers, representing the types of the keys that you start with.

After that, there will be N lines, each representing a single chest. Each line will begin with integers Ti and Ki, indicating the key type needed to open the chest and the number of keys inside the chest. These two integers will be followed by Ki more integers, indicating the types of the keys contained within the chest.

Output

For each test case, output one line containing "Case #x: C1 C2 ... CN", where x is the case number (starting from 1), and where Ci represents the index (starting from 1) of the ith chest that you should open.

If there are multiple ways of opening all the chests, choose the "lexicographically smallest" way. In order words, you should choose to make C1 as small as possible, and if there are multiple ways of making C1 as small as possible, choose the one that makes C2 as small as possible, and so on.

If there is no way to open all the chests, you should instead output one line containing "Case #x: IMPOSSIBLE".

Limits

1 ² T ² 25.
1 ² K.
All chest types and key types will be integers between 1 and 200 inclusive.
Small dataset

1 ² N ² 20.
In each test case, there will be at most 40 keys altogether.
Large dataset

1 ² N ² 200.
In each test case, there will be at most 400 keys altogether.
Sample


Input 
  
Output 
 
3
1 4
1
1 0
1 2 1 3
2 0
3 1 2
3 3
1 1 1
1 0
1 0
1 0
1 1
2
1 1 1
Case #1: 2 1 4 3
Case #2: 1 2 3
Case #3: IMPOSSIBLE

 */
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

public class GCJ2013RQD {
  public static void main(String[] args) throws Exception {
    final String FILE_DIR = "/Users/jhorwitz/Downloads/";
    File inFile = new File(FILE_DIR + "D-small-attempt0.in");
    File outFile = new File(FILE_DIR + "gcj2013-rq-D-s.txt");
    Writer w = new FileWriter(outFile);
    Scanner s = new Scanner(inFile);

    int T = s.nextInt();
    for (int t = 1; t <= T; ++t) {
      int currentKeys[] = new int[201]; // one-based ... ignore currentKeys[0]
      // init (to 0) current keyring
      for (int key = 1; key <= 200; ++key) {
        currentKeys[key] = 0;
      }

      int K = s.nextInt();
      int N = s.nextInt();

      // read in initial keyring
      for (int i = 1; i <= K; ++i) {
        (currentKeys[s.nextInt()])++;
      }

      int keyToOpen[] = new int[N+1]; // keyToOpen[i] == type of key that opens chest i

      int keysInChest[][] = new int[N+1][200+1]; // keysInChest[2][3] == how many keys of type 3 are in chest 2 (e.g.)
      int numKeysInChest[] = new int[N+1];
      for (int chest = 1; chest <= N; ++chest) {
        // init (to 0) keysInChest[chest]
        for (int key = 1; key <= 200; ++key) {
          keysInChest[chest][key] = 0;
        }

        keyToOpen[chest] = s.nextInt();

        numKeysInChest[chest] = s.nextInt();
        for (int i = 1; i <= numKeysInChest[chest]; ++i) {
          (keysInChest[chest][s.nextInt()])++;
        }
      }
      // now input is (finally!) read in

      boolean solutionFound = false;
      int potentialSolution[] = new int[N+1];
      potentialSolution[1] = 0;
      int firstPositionToIncrement = 1; // so first call to nextOrdering will set potentialSolution to (1,2,...,N)
      while (nextOrdering(firstPositionToIncrement, potentialSolution, N)) {
        firstPositionToIncrement = checkForSolution(potentialSolution, N, currentKeys, keyToOpen, numKeysInChest, keysInChest);
        if (firstPositionToIncrement == 0) {
          solutionFound = true;
          break;
        }
      }
      if (solutionFound) {
        output(w, t, makeStringOfSolution(potentialSolution, N));
      } else {
        output(w, t, "IMPOSSIBLE");
      }
    }
    s.close();
    w.close();
  }

  /*
   * @returns first position to increment when going to next potential solution (i.e., where things first broke); returns 0 if we found a solution! 
   */
  private static int checkForSolution(int[] potentialSolution, int N, int[] initialKeys, int[] keyToOpen, int[] numKeysInChest, int[][] keysInChest) {
    int[] currentKeys = new int[201];
    System.arraycopy(initialKeys, 0, currentKeys, 0, N+1);
    for (int i = 1; i <= N; ++i) {
      // try opening chest potentialSolution[i]
      int chestToOpenNow = potentialSolution[i];
      if ( --(currentKeys[keyToOpen[chestToOpenNow]]) < 0 ) return i; // we don't have the right key to open chestToOpenNow;

      // add newfound keys to currentKeys
      for (int key = 1; key <= 200; ++key) {
        currentKeys[key] += keysInChest[chestToOpenNow][key];
      }
    }
    return 0; // success!
  }

  private static String makeStringOfSolution(int[] potentialSolution, int N) {
    StringBuilder sb = new StringBuilder();

    for (int i = 1; i < N; ++i) {
      sb.append(potentialSolution[i] + " ");
    }
    sb.append(potentialSolution[N]);

    return sb.toString();
  }

  /*
   *  changes potentialsSolution to next permutation on (1,2,...,N) after
   *  potentialSolution where value at firstPositionToIncrement is
   *  incrementing--carrying forward as necessary, and resetting later
   *  positions to lexicographically first possible sequence
   *
   * @returns false is there were no more orderings (true otherwise)
   */
  private static boolean nextOrdering(int firstPositionToIncrement, int[] potentialSolution, int N) {
    // figure out what values from 1 to N have been used in positions 1 to firstPositionToIncrement
    boolean[] alreadyUsed = new boolean[N+1]; // init to false
    for (int pos = 1; pos < firstPositionToIncrement; ++pos) {
      alreadyUsed[potentialSolution[pos]] = true;
    }

    // increment at firstPositionToIncrement ... and if it goes over max possible value, increment the value to the left (repeating as necessary)
    ++firstPositionToIncrement; // a cheat so we can decrement immediately in the loop and end with the right value (and have a "meaningful" value (for debugging) while in the loop
    do {
      --firstPositionToIncrement;
      if (firstPositionToIncrement == 0) return false;
      while ( ++(potentialSolution[firstPositionToIncrement]) <= N && alreadyUsed[potentialSolution[firstPositionToIncrement]] ) {
      }
    } while ( potentialSolution[firstPositionToIncrement] > N );

    // now set everything after firstPositionToIncrement to lexicographically first ordering of remaining numbers

    // figure out what values from 1 to N have been used
    alreadyUsed = new boolean[N+1]; // init to false
    for (int pos = 1; pos <= firstPositionToIncrement; ++pos) {
      alreadyUsed[potentialSolution[pos]] = true;
    }

    // now fill in positions firstPositionToIncrement+1 to N
    int possiblyAvailablePosition = 1;
    for (int pos = firstPositionToIncrement+1; pos <= N; ++pos) {
      while (alreadyUsed[possiblyAvailablePosition]) ++possiblyAvailablePosition;
      potentialSolution[pos] = possiblyAvailablePosition;
      ++possiblyAvailablePosition;
    }

    return true;
  }

  public static void output(Writer w, int t, String s) throws IOException {
    w.write("Case #" + t + ": " + s + "\n");
    System.out.println("Case #" + t + ": " + s);
  }
}