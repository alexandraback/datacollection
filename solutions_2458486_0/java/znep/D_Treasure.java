package contests.Qualification2013;

import contests.Util;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class D_Treasure extends Util {
    private static class Chest {
        boolean opened = false;
        int chestNum;
        int keyOpen;
        List<Integer> keysInside = new ArrayList<Integer>();
    }

    private static class Keys {
        private Map<Integer,Integer> keyMap = new HashMap<Integer,Integer>();
        private int numKeys;

        public Keys() {}

        public Keys(Keys k) {
            keyMap = new HashMap<Integer, Integer>(k.keyMap);
            numKeys = k.numKeys;
        }

        public String toString() {
            String[] keys = new String[keyMap.size()];
            int i = 0;
            for (Map.Entry e : keyMap.entrySet()) {
                keys[i++] = e.getKey() + "/" + e.getValue();
            }
            Arrays.sort(keys);
            return Arrays.toString(keys);
        }

        public int getNumKeys() {
            return numKeys;
        }
        public void add(Integer key) {
            Integer count = keyMap.get(key);
            if (count == null) count = 0;
            keyMap.put(key, ++count);
            numKeys++;
        }

        public void add(List<Integer> keys) {
            for (Integer key: keys) {
                add(key);
            }
        }

        public boolean use(Integer key) {
            Integer count = keyMap.get(key);
            if (count == null || count == 0) return false;
            else {
                keyMap.put(key, --count);
                numKeys--;
                return true;
            }
        }

        public void remove(List<Integer> keys) {
            for (Integer key: keys) {
                if (!use(key))  throw new RuntimeException("key not present to remove!?!");
            }
        }

    }

    public static void main(String args[]) throws IOException {
        String inputFileName = "src/contests/Qualification2013/D-sample.in";
        if (args.length == 1) inputFileName = args[0];

        BufferedReader in = new BufferedReader(new FileReader(inputFileName));

        int numTestCases = Integer.parseInt(in.readLine());
        debug("Processing " + numTestCases + " test cases");
        for (int testCase = 1; testCase <= numTestCases; testCase = testCase + 1) {
            debug("Starting case " + testCase);
            D_Treasure treasure = new D_Treasure();

            treasure.orderOpened = new ArrayList<Integer>();
            treasure.chests = new ArrayList<Chest>();
            treasure.keys = new Keys();

            // K = num keys start with, N = num chests
            Integer[] intLine = readIntArrayLine(in);
            treasure.chestsRemaining = intLine[1];

            // keys we start with
            intLine = readIntArrayLine(in);
            for (Integer k: intLine) treasure.keys.add(k);

            for (int i = 0; i < treasure.chestsRemaining; i++) {
                intLine = readIntArrayLine(in);
                Chest c = new Chest();
                c.chestNum = i+1;
                c.keyOpen = intLine[0];
                if (intLine[1] > 0) {
                    for (int k = 2; k < intLine.length; k++) c.keysInside.add(intLine[k]);
                }
                treasure.keysRemainingInLockedChests = treasure.keysRemainingInLockedChests + c.keysInside.size();


                treasure.chests.add(c);
            }



            if (treasure.openChests()) {
                StringBuilder sb = new StringBuilder();
                for (Integer i: treasure.orderOpened) {
                    sb.append(i).append(' ');
                }
                sb.deleteCharAt(sb.length()-1);
                System.out.println("Case #" + testCase + ": " + sb);
            } else {
                System.out.println("Case #" + testCase + ": " + "IMPOSSIBLE");

            }


        }
    }


    private int chestsRemaining;
    private Keys keys = new Keys();
    private List<Chest> chests = new ArrayList<Chest>();
    private List<Integer> orderOpened = new ArrayList<Integer>();
    private int keysRemainingInLockedChests;
    private int openChestsCount, keysRemainingShortCircuitCount, keyOpensShortCircuitCount;
    private Set<String> failedChestsKeys = new HashSet<String>();
    private int failedChestsKeysCount;


    private boolean openChests() {
        openChestsCount++;
        if (openChestsCount % 1000000 == 0) {
            debug("openChestsCount: " + openChestsCount);
            debug("keysRemainingShortCircuitCount: " + keysRemainingShortCircuitCount);
            debug("keyOpensShortCircuitCount: " + keyOpensShortCircuitCount);
            debug("failedChestsKeysCount: " + failedChestsKeysCount);
        }
        if (chestsRemaining == 0) return true;

        if (keys.getNumKeys() + keysRemainingInLockedChests < chestsRemaining) {
            keysRemainingShortCircuitCount++;
            return false;
        }

        StringBuilder chestsRemainingSb = new StringBuilder();
        for (Chest c: chests) {
            if (c.opened == false) chestsRemainingSb.append(c.chestNum).append(',');
        }
        String chestsKeys = chestsRemainingSb + " / " + keys.toString();
        if (failedChestsKeys.contains(chestsKeys)) {
            failedChestsKeysCount++;
//            debug("skipping because failed before: " + chestsKeys);
            return false;
        }
//        debug("CHESTSKEYS " + chestsKeys);


        {
            Keys testKeys = new Keys(keys);
            for (Chest c: chests) {
                if (c.opened == false) testKeys.add(c.keysInside);
            }
            for (Chest c: chests) {
                if (c.opened == false && !testKeys.use(c.keyOpen)) {
                    keyOpensShortCircuitCount++;
                    return false;
                }
            }

        }


        // try each chest in order, can't use iterator
        for (int i = 0; i < chests.size(); i++) {
            Chest c = chests.get(i);

            // see if we have already tried


            // if I know I need {...} keys to open remaining chests, and remaining chests don't have those keys


            // if num keys in hand < num chests remaining + num keys in num chests, then bail




//            debug("remaining " + chestsRemaining + ", trying " + c.chestNum);
            // not opened already
            // have a key
            if (!c.opened && keys.use(c.keyOpen)) {
                c.opened = true;
                chestsRemaining--;
                orderOpened.add(c.chestNum);
                keys.add(c.keysInside);
                keysRemainingInLockedChests = keysRemainingInLockedChests - c.keysInside.size();

                // recurse
                if (openChests()) {
                    // DONE!
                    return true;
                } else {
                    // close chest, remove keys inside, and add back key used to open
                    c.opened = false;
                    chestsRemaining++;
                    orderOpened.remove(orderOpened.size()-1);
                    keysRemainingInLockedChests = keysRemainingInLockedChests + c.keysInside.size();
                    keys.remove(c.keysInside);
                    keys.add(c.keyOpen);

                }
            }
        }

        failedChestsKeys.add(chestsKeys);
//        debug("adding failed: " + chestsKeys);
        return false;



    }

}

