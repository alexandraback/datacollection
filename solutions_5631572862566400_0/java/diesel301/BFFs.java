import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by russinko on 4/15/16.
 */
public class BFFs {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("C-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new File("output.txt"));
        int caseCount = sc.nextInt();
        for(int i = 0; i < caseCount; i++) {
            int len = sc.nextInt();
            Map<Integer, Integer> map = new HashMap<Integer, Integer>();
            for(int j = 0; j < len; j++) {
                int buddy = sc.nextInt() - 1;
                map.put(j, buddy);
            }
            pw.printf("Case #%d: %d\n", i + 1, best(new ArrayList<Integer>(), new ArrayList<Integer>(map.keySet()), map));

        }
        pw.close();
    }

    static int best(List<Integer> assigned,  List<Integer> free, Map<Integer, Integer> map) {
        int b = 0;
        if(check(assigned, map)) {
            b = assigned.size();
        }
        for(int buddy : free) {
            List<Integer> newAssigned = new ArrayList<Integer>(assigned);
            newAssigned.add(buddy);
            List<Integer> newFree = new ArrayList<Integer>();
            for(int h : free) {
                if(h != buddy) newFree.add(h);
            }
            int val = best(newAssigned, newFree, map);
            if(val > b) {
                b = val;
            }
        }
        return b;
    }

    static boolean check(List<Integer> list, Map<Integer, Integer> map) {
        if(list.size() < 2) return true;
        for(int i = 0; i < list.size(); i++) {
            int buddy = list.get(i);
            int next = list.get((list.size() + i + 1) % list.size());
            int prev = list.get((list.size() + i - 1) % list.size());
            if((next != map.get(buddy)) && prev != map.get(buddy)) {
                return false;
            }
        }
        return true;
    }

}
