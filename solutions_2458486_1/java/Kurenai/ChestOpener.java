package googlecodejam.treasure;

import java.util.ArrayList;

public final class ChestOpener {

    ArrayList<Chest> chests;
    ArrayList<Integer> keys;
    ArrayList<Integer> kindKeys;
    ArrayList<Integer> openOrder = null;

    public ChestOpener(ArrayList<Chest> chests, ArrayList<Integer> keys) {
        this.chests = chests;
        this.keys = keys;
    }

    public void openAll() {
        State initialState = getInitialState();
        for (State actual = initialState; actual != null; actual = actual.getNextState()) {
           // System.out.println(actual.openedChests);
            if (actual.isSolution()) {
                openOrder =  actual.openedChests;
                return;
            }
        }
    }

    private State getInitialState() {
        ArrayList<Integer> closed = new ArrayList<Integer>();
        for (int i = 0; i < chests.size(); i++) {
            closed.add(i);
        }
        return new State(null, this, closed, keys, new ArrayList());
    }

    public String toString() {
        if (openOrder == null) {
            return "IMPOSSIBLE";
        }
        String result = "";
        for (int i : openOrder) {
            result += (i+1) + " "; 
        }
        return result.trim();
    }
}
