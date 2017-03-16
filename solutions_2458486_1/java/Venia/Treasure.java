import java.util.*;

public class Treasure {

    int N;
    int [] keyToOpen;
    List<List<Integer>> keysInside; // keys.get(k) - keys inside chest 'k'

    public static boolean DEBUG = false;



    // don't care about order:
    // take a chest if the key is not needed for opening anything else
    // or if the key you need is contained inside.
    // If that's not possible, take the one that contains most keys
    int timesCalled = 0;
    static final int PROBABLY_IMPOSSIBLE = 2<<21;
    boolean isPossibleQ(int [] haveKeys, Set<Integer> locked) {
        timesCalled++;
        if (timesCalled > PROBABLY_IMPOSSIBLE)
            return false;
        if (DEBUG) {
            System.out.println("isPossibleQ: " + locked);
            for (int t=0; t<haveKeys.length; t++)
                if (haveKeys[t] > 0)
                    System.out.println(haveKeys[t] + " of key " + t);

            for (int j: locked) {
                System.out.println("You need key " + keyToOpen[j] + " to open " + j);
                System.out.println("When you open " + j + " you will get keys " + keysInside.get(j));
            }
        }

        if (locked.isEmpty()) return true;
        Set<Integer> canOpen = new TreeSet<Integer>();
        for (int i: locked)
            if (haveKeys[keyToOpen[i]] > 0) canOpen.add(i);

        Set<Integer> freeToOpen = new TreeSet<Integer>();

        for (int i: canOpen) {
            // check if the key you need is inside:
            if (keysInside.get(i).contains(keyToOpen[i])) {
                freeToOpen.add(i);
                if (DEBUG)
                    System.out.println("isPossibleQ: " + locked + " Added " + i + " because the key (" + keyToOpen[i] + ") to open it is inside!");
            }
            else {
                int theKey = keyToOpen[i];
                int numOfTheKey = haveKeys[theKey];
                int neededOfTheKey = 0;
                for (int j: locked)
                    if (keyToOpen[j] == theKey)
                        neededOfTheKey ++;
                if (neededOfTheKey <= numOfTheKey) freeToOpen.add(i);
            }
        }

        if (!freeToOpen.isEmpty()) {
            if (DEBUG)
                System.out.println("isPossibleQ: " + locked + " the chests " + freeToOpen + " are free to open!");
            locked.removeAll(freeToOpen);
            for (int i: freeToOpen) {
                haveKeys[keyToOpen[i]]--;
                for (int keys: keysInside.get(i)) haveKeys[keys]++;
            }
            boolean ret =  isPossibleQ(haveKeys, locked);

            locked.addAll(freeToOpen);
            for (int i: freeToOpen) {
                haveKeys[keyToOpen[i]]++;
                for (int keys: keysInside.get(i)) haveKeys[keys]--;
            }
            return ret;
        }

        else{
            if (DEBUG)
                System.out.println("isPossibleQ: " + locked + " nothing free to open...");
            // otherwise, take the one that unlocks most locked chests:
            int [] unlocks = new int [N+1];
            for (int i: canOpen) {
                for (int lc: locked)
                    if (!canOpen.contains(lc))
                        if (keysInside.get(i).contains(keyToOpen[lc]))
                            unlocks[i]++;
            }
            // Try them in sorted order
            List<Pair<Integer, Integer>> byUnlocks = new ArrayList<Pair<Integer, Integer>>();
            for (int i=1; i<= N; i++)
                if (canOpen.contains(i))
                    byUnlocks.add(new Pair<Integer, Integer> (unlocks[i], i));


            Collections.sort(byUnlocks);
            for (Pair<Integer, Integer> p: byUnlocks) {
                locked.remove(p.y);
                haveKeys[keyToOpen[p.y]]--;
                for (int keys: keysInside.get(p.y)) haveKeys[keys]++;
                boolean ret =  isPossibleQ(haveKeys, locked);

                locked.add(p.y);
                haveKeys[keyToOpen[p.y]]++;
                for (int keys: keysInside.get(p.y)) haveKeys[keys]--;
                if (ret) return true;
            }
        }
        return false;
    }

    List<Integer> solve(int [] haveKeys, SortedSet<Integer> locked) {
        List<Integer> ret = new ArrayList<Integer>();
        while (locked.size() != 0) {
            if (DEBUG)
                System.out.println(locked);
            boolean possible = false;
            for (int i: locked) {
                boolean OK = false;
                if (haveKeys[keyToOpen[i]] > 0) {
                    Set<Integer> st = new TreeSet<Integer>(locked);
                    st.remove(i);
                    haveKeys[keyToOpen[i]] --;
                    for (int key: keysInside.get(i))
                        haveKeys[key]++;
                    if (isPossibleQ(haveKeys, st)) {
                        if (DEBUG) {
                            System.out.println("OK to remove " + i + " if we have keys = ");
                            for (int t=0; t<haveKeys.length; t++)
                                if (haveKeys[t] > 0)
                                    System.out.println(haveKeys[t] + " of key " + t);
                            for (int j: st) {
                                System.out.println("You need key " + keyToOpen[j] + " to open " + j);
                                System.out.println("When you open " + j + " you will get keys " + keysInside.get(j));
                            }
                        }
                        ret.add(i);
                        locked.remove(i);
                        OK = true;
                        possible = true;
                        break;
                    }
                    else {
                        haveKeys[keyToOpen[i]]++;
                        for (int key: keysInside.get(i))
                            haveKeys[key]--;

                    }
                }
                if (OK) break;
            }
            if (!possible) throw new Error("This should not be possible!");
        }
        return ret;
    }

    List<Integer> dfs(int [] haveKeys, Deque<Integer> orderUnlocked, boolean [] unlocked, Set<Integer> locked) {
        if (locked.isEmpty()) {
            List<Integer> ret = new ArrayList<Integer>();
            for (int i: orderUnlocked) ret.add(i);
            return ret;
        }

        for (int i = 1; i<= N; i++) {
            if (!unlocked[i]) {
                if (haveKeys[keyToOpen[i]] > 0) {
                    orderUnlocked.addLast(i);
                    unlocked[i] = true;
                    haveKeys[keyToOpen[i]] --;
                    for (int nKey: keysInside.get(i))
                        haveKeys[nKey]++;

                    locked.remove(i);
                    if (isPossibleQ(haveKeys, locked))
                        return dfs(haveKeys, orderUnlocked, unlocked, locked);
                    else {
                        orderUnlocked.removeLast();
                        unlocked[i] = false;
                        haveKeys[keyToOpen[i]] ++;
                        for (int nKey: keysInside.get(i))
                        haveKeys[nKey]--;
                        locked.remove(i);
                    }
                }
            }
        }
        throw new Error ("Something is wrong! This should never happen!");
    }


    public Treasure(List<List<Integer>> keysInside, int [] haveKeys, int [] keyToOpen) {
        N = keysInside.size()-1;
        this.keysInside = keysInside;
        this.keyToOpen = keyToOpen;
    }


    // since you get penalties for failed attempts:
    boolean check(List<Integer> order, int [] haveKeys) {
        for (int i: order) {
            if (haveKeys[keyToOpen[i]] < 1) return false;
            haveKeys[keyToOpen[i]] --;
            for (int j: keysInside.get(i))
                haveKeys[j]++;
        }
        return true;
    }
}

