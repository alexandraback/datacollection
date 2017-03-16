package gcj.v2016;

/**
 * Created by vbhavsar on 4/15/16.
 */

import java.util.*;

public class BFFs {

    private static boolean debug = false;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        for (int _t = 1; _t <= t; _t++) {

            int n = sc.nextInt(); sc.nextLine();
            String line = sc.nextLine();

            int result = doit(line);
            System.out.printf("Case #%d: %d%n", _t, result);
        }
    }

    private static int doit(String line) {

        Map<Integer, Integer> map = new HashMap<>();
        Map<Integer, List<Integer>> out = new HashMap<>();
        Map<Integer, List<Integer>> in = new HashMap<>();
        String[] arr = line.split(" ");
        int n = arr.length;
        for (int i=0; i< arr.length; i++) {
            map.put(i+1, Integer.parseInt(arr[i]));
        }

        // build out map
        for (int i=1; i<=n; i++) {
            Integer ikey = i;
            List<Integer> ilist = new ArrayList<>();
            Set<Integer> iset = new HashSet<>();
            while (map.containsKey(ikey) && !iset.contains(map.get(ikey))) {
                ilist.add(map.get(ikey));
                iset.add(ikey);
                ikey = map.get(ikey);
            }
            out.put(i, ilist);
        }
        debug("out: "+out.toString());

        // build in map
        for (int i=1; i<=n; i++) {
            Integer key = map.get(i);

            if (in.containsKey(key)) {
                in.get(key).add(i);
            } else {
                List<Integer> ilist = new ArrayList<>();
                ilist.add(i);
                in.put(key, ilist);
            }
        }
        debug("in: "+in.toString());

        Map<Integer, Set<Integer>> chain = new HashMap<>();
        Set<Integer> seen = new HashSet<>();
        for (int i=1; i<=n; i++) {
            if (!seen.contains(i)) {

                if (out.containsKey(i)) {

                    Set<Integer> ichain = new HashSet<>();

                    List<Integer> itail = out.get(i);

                    ichain.add(i);
                    ichain.addAll(itail);
                    seen.addAll(ichain);

                    for (int iin : in.get(itail.get(itail.size()-1))) {
                        if (!ichain.contains(iin)) {
                            ichain.add(iin);
                            break;
                        }
                    }

                    chain.put(i, ichain);
                }

            }
        }

        debug("chain: "+chain.toString());

        int max = 1;
        for (Map.Entry<Integer, Set<Integer>> e : chain.entrySet()) {
            if (e.getValue().size() > max) {
                max = e.getValue().size();
            }
        }

        return max;
    }

    private static void debug(String str) {
        if (debug) {
            System.out.println(str);
        }
    }
}