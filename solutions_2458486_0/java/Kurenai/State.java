package googlecodejam.treasure;

import java.util.ArrayList;
import java.util.HashSet;

public class State {

    ChestOpener context;
    State father;
    boolean visited;
    ArrayList<Integer> closedChests;
    ArrayList<Integer> openedChests;
    ArrayList<Integer> keys;
    ArrayList<Integer> openableChests;

    public State(State father, ChestOpener context, ArrayList<Integer> closedChests, ArrayList<Integer> keys, ArrayList<Integer> openedChests) {
        this.father = father;
        this.context = context;
        this.closedChests = closedChests;
        this.openedChests = openedChests;
        this.keys = keys;
    }

    public State getNextState() {
        if (isSolutionReachable() && isSolutionReachible2()) {
       // if (isSolutionReachible2()) {
            for (Integer chest : getOpenableChests()) {
                openableChests.remove(chest);
                return new State(this, context, getNewClosed(chest), getNewKeys(chest), getNewOpened(chest));
            }
        }
        if (father != null) {
            return father.getNextState();
        }
        return null;

    }

    public ArrayList<Integer> getOpenableChests() {
        if (openableChests == null) {
            openableChests = new ArrayList<Integer>();
            for (Integer closed : closedChests) {
                Chest closedChest = context.chests.get(closed);
                if (keys.contains(closedChest.openKey)) {
                    openableChests.add(closed);
                }
            }
        }
        return openableChests;
    }

    public int getNumOfKeys(ArrayList<Integer> keys, int key) {
        int num = 0;
        for (int i : keys) {
            if (i == key) {
                num++;
            }
        }
        return num;
    }

    public ArrayList<Integer> sortChests(ArrayList<Integer> chests, ArrayList<Integer> keys) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        ArrayList<Integer> usedKeys = new ArrayList<Integer>();
        for (int chest : chests) {
            Integer key = context.chests.get(chest).openKey;
            if (usedKeys.contains(key)) {
                continue;
            }
            ArrayList<Integer> chestsOpenableWithKey = new ArrayList<Integer>();
            chestsOpenableWithKey.add(chest);
            for (int chest2 : chests) {
                if (context.chests.get(chest2).openKey == key) {
                    int i = 0;
                    while (i < chestsOpenableWithKey.size()
                            && context.chests.get(chestsOpenableWithKey.get(i)).providedKeys.size() >= context.chests.get(chest2).providedKeys.size()) {
                        i++;
                    }
                    if (i == chestsOpenableWithKey.size()) {
                        chestsOpenableWithKey.add(chest2);
                    } else {
                        chestsOpenableWithKey.set(i, chest2);

                    }
                }
            }
            result.addAll(chestsOpenableWithKey);
            usedKeys.add(key);
        }
        return result;


    }

    private ArrayList<Integer> getNewClosed(Integer opened) {
        ArrayList<Integer> newClosed = new ArrayList<Integer>(closedChests);
        newClosed.remove(newClosed.indexOf(opened));
        return newClosed;
    }

    private ArrayList<Integer> getNewOpened(Integer opened) {
        ArrayList<Integer> newOpened = new ArrayList<Integer>(openedChests);
        newOpened.add(opened);
        return newOpened;
    }

    private ArrayList<Integer> getNewKeys(Integer opened) {
        ArrayList<Integer> newKeys = new ArrayList<Integer>(keys);
        Integer usedKey = context.chests.get(opened).openKey;
        newKeys.remove(usedKey);
        for (Integer i : context.chests.get(opened).providedKeys) {
            newKeys.add(i);
        }
        return newKeys;
    }

    public boolean isSolution() {
        return closedChests.isEmpty();
    }

    public boolean isSolutionReachible2() {

        HashSet<Integer> keyTypes = new HashSet<Integer>();
        for (Integer closed : closedChests) {
            Chest chest = context.chests.get(closed);
            keyTypes.add(chest.openKey);
        }
        for (Integer key : keyTypes) {
            int numberKeysIHave = getNumOfKeys(keys, key);
            int numberKeysINeed = 0;
            for (Integer closed : closedChests) {
                Chest chest = context.chests.get(closed);
                numberKeysIHave += getNumOfKeys(chest.providedKeys, key);
                if (chest.openKey == key) {
                    numberKeysINeed++;
                }
            }
            if (numberKeysIHave < numberKeysINeed) {
                return false;
            }
        }
        return true;

    }

    public boolean isSolutionReachable() {
        HashSet<Integer> reachables = new HashSet<Integer>();
        HashSet<Integer> keyTypes = new HashSet<Integer>();
        for (Integer closed : closedChests) {
            Chest chest = context.chests.get(closed);
            keyTypes.add(chest.openKey);
        }
        for (int key : keys) {
            if (!reachables.contains(key)) {
                reachables.add(key);
            }
        }

        HashSet<Integer> reachabled = new HashSet<Integer>();
        Integer key = null;
        while (!reachabled.containsAll(reachables)) {
            for (Integer i : reachables) {
                if (!reachabled.contains(i)) {
                    key = i;
                    reachabled.add(i);
                    break;
                }
            }
            for (Integer closed : closedChests) {
                Chest chest = context.chests.get(closed);
                keyTypes.add(chest.openKey);
                if (chest.openKey == key.intValue()) {
                    reachables.addAll(chest.providedKeys);
                }
            }
        }
        return reachables.containsAll(keyTypes);
    }
}
