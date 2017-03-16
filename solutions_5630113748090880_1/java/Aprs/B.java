package edu.utdallas;

import java.util.*;

/**
 * Created by sycheng on 4/15/16.
 */
public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        int c = m;
        while (m-- != 0) {
            List<Integer> list = new ArrayList<>(m);
            int n = in.nextInt();
            Set<Integer> set = new TreeSet<>();

            for (int i = 0; i < n * (2*n-1); i++) {
                int k = in.nextInt();
                if (set.contains(k)){
                    set.remove(k);
                }
                else {
                    set.add(k);
                }
            }
            Iterator<Integer> it = set.iterator();
            System.out.print("Case #" + (c-m) + ": ");
            for (; it.hasNext();) {
                System.out.print(it.next() + " ");
            }
            System.out.println();
        }
    }
}
