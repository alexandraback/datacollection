import java.io.File;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by Vitaly Russinkovsky
 * Date: 5/5/12
 */
public class Main1 {


    private static boolean analyze(Map<Integer, Set<Integer>> map, int size) {


        System.out.println("MAP:" + map);

        Map<Integer, Set<Integer>> order = new HashMap<Integer, Set<Integer>>();

        for(Map.Entry<Integer, Set<Integer>> entry : map.entrySet()) {
            Set<Integer> set = new HashSet<Integer>(entry.getValue());
            order.put(entry.getKey(), set);
        }

        Queue<Integer> waitList = new LinkedList<Integer>();
        for(int i = 0; i < size; i++) {
            if(map.get(i + 1) == null) {
                waitList.add(i + 1);
            }
        }

        List<Integer> sorted = new ArrayList<Integer>();
        while (waitList.size() > 0) {
            int elem = waitList.poll();
            Set<Integer> keys = new HashSet<Integer>(map.keySet());
            for(Integer key : keys) {
                Set<Integer> set = map.get(key);
                if(set.contains(elem)) {
                    set.remove(elem);
                    if(set.size() == 0) {
                        map.remove(key);
                        waitList.add(key);
                    } else {
                        map.put(key, set);
                    }
                }

            }
            sorted.add(elem);


        }

        System.out.println("ORDER:" + order);

        for(Integer s : sorted) {
            Set<Integer> set = order.get(s);
            if(set != null) {
                for(Integer k : new HashSet<Integer>(set)) {
                    Set<Integer> ins = order.get(k);
                    if(ins != null) {
                        for(Integer el : ins) {
                            if(set.contains(el)) {
                                return true;
                            }
                            set.add(el);

                        }
                    }
                }
               order.put(s, set);
            }
        }



        System.out.println("SORTED:" + sorted);
        System.out.println("ORDER:" + order);
      return false;
    }


    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(new File("A-small-attempt2.in"));
        PrintWriter pw = new PrintWriter(new File("output.txt"));
        int ncase = sc.nextInt();
        for(int i = 0; i < ncase; i++) {

            Map<Integer, Set<Integer>> map = new HashMap<Integer, Set<Integer>>();

            int nclass = sc.nextInt();
            for(int j = 0; j < nclass; j++) {
                int child = j + 1;
                int ndepend = sc.nextInt();
                for(int k = 0; k < ndepend; k++) {
                    int parent = sc.nextInt();

                    Set<Integer> set = map.get(parent);
                    if(set == null) {
                        set= new HashSet<Integer>();
                    }
                    set.add(child);
                    map.put(parent, set);
                }
            }


            System.out.println(i);
            System.out.println(map);
            pw.print(String.format("Case #%d: %s%n", i + 1, analyze(map, nclass) ? "Yes" : "No"));

            System.out.println(map);
            System.out.println(i + 1);
        }
        sc.close();
        pw.close();

    }

}
