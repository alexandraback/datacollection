package round1;

import java.math.BigInteger;
import java.util.*;

/**
 * Created by ninghou on 4/15/16.
 */
public class P2 {
    String nhou(int[][] m) {
        HashMap<Integer, Integer> count = new HashMap<>();
        for (int[] arr : m) {
            for (int x : arr) {
                if (count.containsKey(x)) {
                    count.put(x, count.get(x) + 1);
                } else {
                    count.put(x, 1);
                }
            }
        }

        List<Integer> found = new ArrayList<>();
        for (int x : count.keySet()) {
            if (count.get(x) % 2 == 1) {
                found.add(x);
            }
        }

        Collections.sort(found);
        StringBuilder sb = new StringBuilder();
        for (int x : found) {
            sb.append(Integer.toString(x));
            sb.append(" ");
        }
        return sb.toString();
    }
}
