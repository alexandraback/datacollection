import java.io.*;
import java.util.*;

public class BffLarge {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    int N;
    int[] F;
    List<Integer>[] rev;
    int[] longestRev;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        N = scan.nextInt();
        line = in.readLine();
        scan = new Scanner(line);
        F = new int[N];
        rev = new List[N];
        longestRev = new int[N];
        for (int i = 0; i < N; i++) {
            rev[i] = new ArrayList<>();
        }
        for (int i = 0; i < N; i++) {
            F[i] = scan.nextInt() - 1;
            rev[F[i]].add(i);
        }
        
        int bestCycle = 0;
        BitSet inCycle = new BitSet(N);
        for (int i = 0; i < N; i++) {
            if (inCycle.get(i)) continue;
            int lenCycle = checkCycle(i, inCycle);
            if (lenCycle > bestCycle) bestCycle = lenCycle;
        }
        
        List<int[]> pairs = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if (inCycle.get(i)) continue;
            if (F[i] > i && F[F[i]] == i) {
                pairs.add(new int[] { i, F[i] });
            }
        }
        
        if (pairs.isEmpty()) {
            System.out.println(bestCycle);
            return;
        }
        
        int bestOfPairs = 0;
        for (int[] pair : pairs) {
            bestOfPairs += longestChainEndingIn(pair[0], pair[1]);
            bestOfPairs += longestChainEndingIn(pair[1], pair[0]);
        }
        
        System.out.println(Math.max(bestCycle, bestOfPairs));
    }
    
    int longestChainEndingIn(int guy, int notThisGuy) {
        if (longestRev[guy] != 0) return longestRev[guy];
        int longest = 1;
        for (int nextGuy : rev[guy]) {
            if (nextGuy == notThisGuy) continue;
            int thisLongest = 1 + longestChainEndingIn(nextGuy, -1);
            if (thisLongest > longest) longest = thisLongest;
        }
        longestRev[guy] = longest;
        return longest;
    }

    int checkCycle(int i, BitSet inCycle) {
        BitSet thisCycle = new BitSet(N);
        thisCycle.set(i);
        int len = 1;
        int curr = i;
        while (true) {
            int next = F[curr];
            if (next == i) {
                if (len == 2) return 0;
                thisCycle.stream().forEach(j -> inCycle.set(j));
                return len;
            }
            if (thisCycle.get(next)) {
                len = checkCycle(next, inCycle);
                if (len == 0) return 0;
                thisCycle.stream().forEach(j -> inCycle.set(j));
                return len;
            }
            thisCycle.set(next);
            curr = next;
            len++;
        }
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new BffLarge().run();
    }

}
