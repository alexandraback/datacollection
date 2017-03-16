import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;

public class ProblemC {
    
    private static int brute_force(int start, int end, int[] bffs, Set<Integer> closed) {
        LinkedList<Integer> result = new LinkedList<Integer>();
        for (int i = 0; i < bffs.length; i++) {
            if (!closed.contains(i)) {
                if (bffs[i] - 1 == start) {
                    Set<Integer> newSet = new HashSet<Integer>(closed);
                    newSet.add(i);
                    result.add(1+brute_force(i, end, bffs, newSet));
                } else if(bffs[i]-1 == end) {
                    Set<Integer> newSet = new HashSet<Integer>(closed);
                    newSet.add(i);
                    result.add(1+brute_force(start, i, bffs, newSet));
                }
            }
        }
        if (result.isEmpty()) {
            return 0;
        } else {
            Collections.sort(result);
            return result.getLast();
        }
        
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        
        for (int i = 1; i <= numCases; i++) {
            int N = input.nextInt();
            int[] bffs = new int[N];
            for (int k = 0; k < N; k++) {
                bffs[k] = input.nextInt();
            }
            int max = 0;
            for (int j = 0; j < N; j++) {
                HashSet<Integer> closed = new HashSet<Integer>();
                int start = j;
                closed.add(j);
                int current = j;
                while (true) {
                    int next = bffs[current] - 1;
                    if (next != start && closed.contains(next)) {
                        if (bffs[next]-1 == current) {
                                           
                            max = Math.max(max, closed.size()+brute_force(start, current, bffs, closed));
                            break;
                        }
                        break;
                    } else if (next == start) {
                        max = Math.max(max, closed.size());
                        break;
                    } else {
                        closed.add(next);
                        current = next;
                    }
                }
            }
            System.out.println(String.format("Case #%d: %d", i, max));
        }
        
        input.close();
    }
}
