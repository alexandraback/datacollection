import java.util.*;

public class D {
    public static void main(String [] argv) {
        Kattio io = new Kattio(System.in, System.out);
        int tests = io.getInt();
        for (int test = 0; test<tests; test++) {
            int K = io.getInt(); // keys you have
            int N = io.getInt(); // chests you have to open
            int [] haveKeys = new int [201];
            for (int i=0; i<K; i++) {
                int k = io.getInt();
                haveKeys[k]++;
            }
            int [] keysToOpen = new int [200+1];
            List<List<Integer>> keys = new ArrayList<List<Integer>>(N+1);

            keys.add(new ArrayList<Integer>()); // 0:th element

            for (int i=1; i<= N; i++) {
                keysToOpen[i] = io.getInt();
                int Ki = io.getInt(); // number of keys inside
                keys.add(new ArrayList<Integer>());
                for (int j=0; j<Ki; j++)
                    keys.get(i).add(io.getInt());
            }

            Treasure t = new Treasure(keys, haveKeys, keysToOpen);

            SortedSet<Integer> locked = new TreeSet<Integer>();
            for (int i=1; i<= N; i++)
                locked.add(i);

            if (!t.isPossibleQ(haveKeys, locked)) {
                System.out.println("Case #" + (test+1) + ": IMPOSSIBLE");
                System.err.println("||| " +  t.timesCalled);
                continue;
            }

            List<Integer> orderUnlock = t.solve(haveKeys, locked);

            System.out.print("Case #" + (test+1) + ": ");
            for (int i=0; i<orderUnlock.size()-1; i++)
                System.out.print(orderUnlock.get(i) + " ");
            System.out.println(orderUnlock.get(orderUnlock.size()-1));
            System.err.println("||| " + t.timesCalled);

        }
        io.close();
    }
}
