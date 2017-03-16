package b1;

import java.io.FileInputStream;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.*;

/**
 * Created by IntelliJ IDEA.
 * User: Yuri
 * Date: 05.05.12
 * Time: 20:27
 * To change this template use File | Settings | File Templates.
 */
public class Task3 {

    public static Set<Set<Integer>> powerSet(Set<Integer> originalSet) {
        Set<Set<Integer>> sets = new HashSet<Set<Integer>>();
        if (originalSet.isEmpty()) {
            sets.add(new HashSet<Integer>());
            return sets;
        }
        List<Integer> list = new ArrayList<Integer>(originalSet);
        Integer head = list.get(0);
        Set<Integer> rest = new HashSet<Integer>(list.subList(1, list.size()));
        for (Set<Integer> set : powerSet(rest)) {
            Set<Integer> newSet = new HashSet<Integer>();
            newSet.add(head);
            newSet.addAll(set);
            sets.add(newSet);
            sets.add(set);
        }
        return sets;
    }

public static <T> List<List<T>> powerset(Collection<T> list) {
  List<List<T>> ps = new ArrayList<List<T>>();
  ps.add(new ArrayList<T>());   // add the empty set

  // for every item in the original list
  for (T item : list) {
    List<List<T>> newPs = new ArrayList<List<T>>();

    for (List<T> subset : ps) {
      // copy all of the current powerset's subsets
      newPs.add(subset);

      // plus the subsets appended with the current item
      List<T> newSubset = new ArrayList<T>(subset);
      newSubset.add(item);
      newPs.add(newSubset);
    }

    // powerset is now powerset of list.subList(0, list.indexOf(item)+1)
    ps = newPs;
  }
  return ps;
}
    public static boolean check(List<Integer> a, List<Integer> b) {
        for (Integer x : a) {
            if (b.contains(x)) {
                return false;
            }
        }
        return true;
    }

       public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new FileInputStream("1b_task3.txt"));
        scanner.useLocale(Locale.US);
        int T = scanner.nextInt();
        for (int i = 0; i < T; i++) {
            int N = scanner.nextInt();
            HashSet<Integer> set = new HashSet<Integer>();
            for (int j = 0; j < N; j++) {
                set.add(scanner.nextInt());
            }
            List<List<Integer>> ps = powerset(set);
            int sum[] = new int[ps.size()];
            int j = 0;
            for (List<Integer> subset : ps) {
                sum[j] = 0;
                for (int el : subset) {
                    sum[j] += el;
                }
                j++;
            }
            int k = 0;
            boolean flag = false;
            for (j = 0; j < sum.length; j++) {
                for (k = j + 1; k < sum.length; k++) {
                    if (sum[j] == sum[k]) {
                        if (check(ps.get(j), ps.get(k))) {
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) {
                    break;
                }
            }
            System.out.println("Case #" + (i + 1) + ":");
            if (flag) {
                for (Integer x : ps.get(j)) {
                    System.out.print("" + x + " ");
                }
                System.out.println();
                for (Integer x : ps.get(k)) {
                    System.out.print("" + x + " ");
                }
                System.out.println();
            } else {
                System.out.println("Impossible");
            }
        }
    }

}
