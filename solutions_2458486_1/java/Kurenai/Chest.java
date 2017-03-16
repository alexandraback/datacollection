package googlecodejam.treasure;

import java.util.ArrayList;

public class Chest {

    int openKey;
    ArrayList<Integer> providedKeys;

    public Chest(int openKey, ArrayList<Integer> providedKeys) {
        this.openKey = openKey;
        this.providedKeys = providedKeys;
    }
}
