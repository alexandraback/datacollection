package com.fg.codejam.qualification;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

import com.fg.codejam.util.IOUtils;

public class Treasure {

    private static final class Chest {
        private final int keyType;
        private final int[] keysInside;
        private boolean opened;
        public String toString() {
            return keyType + " - " + keysInside.length + " keys inside";
        }
        private Chest(int keyType, int[] keysInside) {
            this.keyType = keyType;
            this.keysInside = keysInside;
        }
    }

    private static final class Stage {
        private final boolean[] opened;
        private final int[] keys;
        private final int hashCode;
        public int hashCode() {
            return hashCode;
        }
        public boolean equals(Object obj) {
            if(obj == null || !(obj instanceof Stage)) {
                return false;
            }
            Stage o = (Stage) obj;
            return Arrays.equals(this.opened, o.opened) && Arrays.equals(this.keys, o.keys);
        }
        private Stage(int[] keys, boolean[] opened, int hashCode) {
            this.keys = keys;
            this.opened = opened;
            this.hashCode = hashCode;
        }
        private static final Stage createByClone(Chest[] chests, int[] keys) {
            int h = 31;
            int[] newKeys = new int[keys.length];
            boolean[] newOpened = new boolean[chests.length];
            for(int i = 0; i < keys.length; i++) {
                if(keys[i] > 0) {
                    newKeys[i] = keys[i];
                    h = h * ( (10000 * (i + 1)) + keys[i] );
                }
            }
            for(int i = 0; i < chests.length; i++) {
                if(chests[i].opened) {
                    h = h * ( (31 * (i + 1)) );
                    newOpened[i] = true;
                }
            }
            //System.out.println(h);
            return new Stage(newKeys, newOpened, h);
        }
    }

    public static final boolean compute(
        Chest[] chests
        , int[] keys
        , Set<Stage> stages
        , StringBuffer ret
    ) {
        int x;
        //Stage stage = Stage.createByClone(chests, keys);
        int retOrigLength = ret.length();

        // DEBUG
        if(retOrigLength == 0) {
            x = 0;
        } else if(retOrigLength == 2) {
            x = 2;
        } else if(retOrigLength == 4) {
            x = 4;
        } else {
            x = 6;
        }
        if(x < 0) {
            System.out.println(x);
        }
        // DEBUG END

        boolean allOpened = true;
        for(int i = 0; i < chests.length; i++) {
            Chest chest = chests[i];
            if(!chest.opened) {
                allOpened = false;
                if(keys[chest.keyType] > 0) {
                    // Try to open it and solve the problem
                    chest.opened = true;
                    keys[chest.keyType]--;
                    for(int ki = 0; ki < chest.keysInside.length; ki++) {
                        keys[chest.keysInside[ki]]++;
                    }
                    Stage newStage = Stage.createByClone(chests, keys);
                    if(!stages.contains(newStage)) {
                        stages.add(newStage);
                        ret.append(" ").append(i + 1);
                        if(compute(chests, keys, stages, ret)) {
                            return true;
                        } else {
                            ret.setLength(retOrigLength);
                        }
                    }
                    // Failed, we should not open it now
                    chest.opened = false;
                    keys[chest.keyType]++;
                    for(int ki = 0; ki < chest.keysInside.length; ki++) {
                        keys[chest.keysInside[ki]]--;
                    }
                }
            }
        }
        return allOpened;
    }

    public static final void computeFile(InputStream is, OutputStream out)
    throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(is));
        try {
            Set<Stage> stagesReuse = new HashSet<Stage>(100000);
            StringBuffer resultReuse = new StringBuffer(1000);
            int caseIndex = 1;
            String line;
            line = br.readLine(); // number of test cases
            while( (line = br.readLine()) != null ) {
                String[] KN = line.split(" ");
                int keyCount = Integer.parseInt(KN[0]);
                String[] keysArray = br.readLine().split(" ");
                int[] keys = new int[20];
                for(int i = 0; i < keyCount; i++) {
                    Integer keyType = new Integer(keysArray[i]) - 1;
                    keys[keyType.intValue()]++;
                }

                int chestCount = Integer.parseInt(KN[1]);
                Chest[] chests = new Chest[chestCount];
                for(int i = 0; i < chestCount; i++) {
                    String[] chestArray = br.readLine().split(" ");
                    int ci = 0;
                    int keyType = Integer.parseInt(chestArray[ci++]) - 1;
                    int keysInsideCount = Integer.parseInt(chestArray[ci++]);
                    int[] keysInside = new int[keysInsideCount];
                    for(int ki = 0; ki < keysInsideCount; ki++) {
                        keysInside[ki] = Integer.parseInt(chestArray[ci++]) - 1;
                    }
                    chests[i] = new Chest(keyType, keysInside);
                }
                stagesReuse.clear();
                resultReuse.setLength(0);
                boolean success = compute(chests, keys, stagesReuse, resultReuse);
                if(success && resultReuse.charAt(0) == ' ') {
                    resultReuse.delete(0, 1);
                }
                out.write( ("Case #" + caseIndex + ": " + (success ? resultReuse.toString() : "IMPOSSIBLE")  + "\n").getBytes() );
                caseIndex++;
            }
        } finally {
            IOUtils.close(br);
        }
    }

    public static void main(String[] args) throws Exception {
        InputStream in = new FileInputStream("c:\\work\\java\\GoogleCodeJam2003\\20130403-Qualification\\input\\Treasure\\D-small-attempt1.in");
        OutputStream out = new FileOutputStream("c:\\work\\java\\GoogleCodeJam2003\\20130403-Qualification\\input\\Treasure\\D-small-attempt1.out");
        try {
            computeFile(in, out);
        } finally {
            IOUtils.close(in);
            IOUtils.close(out);
        }
    }

}
