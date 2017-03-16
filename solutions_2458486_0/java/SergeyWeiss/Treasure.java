package gcj2013.qualification;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Treasure {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

    public Treasure() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
    }

    int[] readInts() throws IOException {
        String[] strings = reader.readLine().split(" ");
        int[] ints = new int[strings.length];
        for(int i = 0; i < ints.length; i++) {
            ints[i] = Integer.parseInt(strings[i]);
        }
        return ints;
    }

    int[] tt = null;
    int tx = 0;
    int readInt() throws IOException {
        if(tt == null || tx >= tt.length) {
            tt = readInts();
            tx = 0;
        }
        return tt[tx++];
    }

    long[] readLongs() throws IOException {
        String[] strings = reader.readLine().split(" ");
        long[] ints = new long[strings.length];
        for(int i = 0; i < ints.length; i++) {
            ints[i] = Long.parseLong(strings[i]);
        }
        return ints;
    }

    long[] ttl = null;
    int txl = 0;
    long readLong() throws IOException {
        if(ttl == null || txl >= ttl.length) {
            ttl = readLongs();
            txl = 0;
        }
        return ttl[txl++];
    }

    class Box {
        int openWith;
        int[] keys;
        int[] keyCnt = new int[201];
        boolean used;
    }

    Box readBox() throws IOException {
        Box box = new Box();
        box.openWith = readInt();
        box.keys = new int[readInt()];
        for(int i = 0; i < box.keys.length; i++) {
            box.keys[i] = readInt();
            box.keyCnt[box.keys[i]]++;
        }
        return box;
    }

    Box[] boxes;
    int[] keys = new int[201];
    int[] reqKeys = new int[201];

    void useBox(Box box) {
        box.used = true;
        keys[box.openWith]--;
        reqKeys[box.openWith]--;
        for(int key : box.keys) {
            keys[key]++;
        }
    }
    void unUseBox(Box box) {
        box.used = false;
        keys[box.openWith]++;
        reqKeys[box.openWith]++;
        for(int key : box.keys) {
            keys[key]--;
        }
    }

    boolean check() {
        final List<Box> usedBoxes = new ArrayList<Box>();
        while(true) {
            boolean ok = false;
            for(int k = 0; k < boxes.length; k++) {
                final Box box = boxes[k];
                if(!box.used) {
                    int key = box.openWith;
                    if(keys[key] >= reqKeys[key]) {
                        ok = true;
                        useBox(box);
                        usedBoxes.add(box);
                    }
                    else if(keys[box.openWith] > 0) {
                        class KeyFinder {
                            boolean[] u = new boolean[boxes.length];
                            boolean findKey(int boxIndex) {
                                Box b = boxes[boxIndex];
                                u[boxIndex] = true;
                                if(b.keyCnt[box.openWith] > 0) {
                                    useBox(b);
                                    usedBoxes.add(b);
                                    return true;
                                }
                                for(int i = 0; i < boxes.length; i++) {
                                    if(boxes[i].used || u[i] || b.keyCnt[boxes[i].openWith] == 0) continue;
                                    if(findKey(i)) {
                                        useBox(b);
                                        usedBoxes.add(b);
                                        return true;
                                    }
                                }
                                return false;
                            }
                        }
                        if(new KeyFinder().findKey(k)) {
                            ok = true;
                        }
                    }
                }
            }
            if(!ok) break;
        }
        boolean usedAll = true;
        for(Box box : boxes) usedAll = usedAll && box.used;
        for(Box box : usedBoxes) unUseBox(box);
        return usedAll;
    }

    void solve(int test) throws IOException {
        writer.printf("Case #%d: ", test);
        int keysCount = readInt();
        int n = readInt();
        for(int i = 1; i <= 200; i++) {
            keys[i] = 0;
            reqKeys[i] = 0;
        }
        for(int i = 0; i < keysCount; i++) {
            keys[readInt()]++;
        }
        boxes = new Box[n];
        for(int i = 0; i < n; i++) {
            boxes[i] = readBox();
            reqKeys[boxes[i].openWith]++;
        }
        for(int k = 0; k < n; k++) {
            boolean ok = false;
            for(int i = 0; !ok && i < n; i++) {
                if(!boxes[i].used && keys[boxes[i].openWith] > 0) {
                    useBox(boxes[i]);
                    if(check()) {
                        writer.print(i + 1);
                        if(k != n - 1) writer.print(" ");
                        ok = true;
                    }
                    else {
                        unUseBox(boxes[i]);
                    }
                }
            }
            if(!ok) {
                writer.print("IMPOSSIBLE");
                break;
            }
        }
        writer.println();
        writer.flush();
    }


    void multiSolve() throws IOException {
        int n = readInts()[0];
        for(int i = 0; i < n; i++) {
            solve(i + 1);
        }
    }

    public static void main(String[] args) throws IOException{
        new Treasure().multiSolve();
    }
}
