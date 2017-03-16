import java.io.*;
import java.util.*;

public class Bff {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    int N;
    int[] F;
    List<Integer>[] rev;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        N = scan.nextInt();
        line = in.readLine();
        scan = new Scanner(line);
        F = new int[N];
        rev = new List[N];
        for (int i = 0; i < N; i++) {
            rev[i] = new ArrayList<>();
        }
        for (int i = 0; i < N; i++) {
            F[i] = scan.nextInt() - 1;
            rev[F[i]].add(i);
        }
        System.out.println(best());
    }
    
    int best() {
        int best = 0;
        BitSet unusedAll = new BitSet(N);
        for (int i = 0; i < N; i++) {
            unusedAll.set(i);
        }
        for (int i = 0; i < N; i++) {
            List<Integer> sofar = new ArrayList<>();
            BitSet unused = (BitSet)unusedAll.clone();
            sofar.add(i);
            unused.clear(i);
            sofar.add(F[i]);
            unused.clear(F[i]);
            int len = best(sofar, unused);
            if (len > best) best = len;
        }
        return best;
    }
    
    int best(List<Integer> sofar, BitSet unused) {
        int lensofar = sofar.size();
        int last = sofar.get(lensofar - 1);
        int beforeLast = sofar.get(lensofar - 2);
        if (F[last] != beforeLast) {
            if (F[last] == sofar.get(0)) return sofar.size();
            if (!unused.get(F[last])) return 0;
            sofar.add(F[last]);
            unused.clear(F[last]);
            return best(sofar, unused);
        }
        // sofar is good
        int best = sofar.size();
        List<Integer> candidates = new ArrayList<>();
        for (Integer revFriend : rev[last]) {
            if (unused.get(revFriend)) {
                candidates.add(revFriend);
                unused.clear(revFriend); // use it now or never;
            }
        }
        if (candidates.size() > 0) {
            for (Integer revFriend : candidates) {
                List<Integer> sofarClone = (ArrayList<Integer>)((ArrayList<Integer>)sofar).clone();
                sofarClone.add(revFriend);
                int len = best(sofarClone, (BitSet)unused.clone());
                if (len > best) best = len;
            }
            return best;
        } else {
            unused.stream().forEach(i -> candidates.add(i));
            for (Integer candidate : candidates) {
                if (unused.get(F[candidate])) {
                    BitSet unusedClone = (BitSet) unused.clone();
                    List<Integer> sofarClone = (ArrayList<Integer>)((ArrayList<Integer>)sofar).clone();
                    unusedClone.clear(candidate);
                    unusedClone.clear(F[candidate]);
                    sofarClone.add(candidate);
                    sofarClone.add(F[candidate]);
                    int len = best(sofarClone, unusedClone);
                    if (len > best) best = len;
                }
            }
            return best;
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
        new Bff().run();
    }

}
