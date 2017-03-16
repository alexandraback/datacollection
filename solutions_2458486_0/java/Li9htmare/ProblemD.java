
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Stack;

/**
 *
 * @author Li9htmare
 */
public class ProblemD {

    public static int n;
    public static Chest[] chestArray;
    public static boolean[] unlockedChest;
    public static Stack<Integer> result = new Stack<Integer>();
    public static int[] keysInHand;
    public static int[] keysInChest;
    public static int remainChest;

    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader fileReader = new FileReader("D-small-attempt0.in");
        BufferedReader in = new BufferedReader(fileReader);
        StringBuilder resultBuilder = new StringBuilder();

        int T = Integer.parseInt(in.readLine());

        for (int t = 1; t <= T; t++) {
            String[] tokens = in.readLine().split(" ");
            int keyMax = 0;
            int k = Integer.parseInt(tokens[0]);
            remainChest = n = Integer.parseInt(tokens[1]);
            keysInHand = new int[201];
            keysInChest = new int[201];
            int[] minimumKeyArray = new int[201];
            tokens = in.readLine().split(" ");
            for (int i = 0; i < k; i++) {
                int key = Integer.parseInt(tokens[i]);
                if (keyMax < key) {
                    keyMax = key;
                }
                keysInHand[key]++;
            }
            chestArray = new Chest[n + 1];
            unlockedChest = new boolean[n + 1];
            for (int i = 1; i <= n; i++) {
                tokens = in.readLine().split(" ");
                int keyType = Integer.parseInt(tokens[0]);
                minimumKeyArray[keyType]++;
                HashMap<Integer, Integer> keys = new HashMap<Integer, Integer>();
                int keyNum = Integer.parseInt(tokens[1]);
                for (int j = 0; j < keyNum; j++) {
                    int key = Integer.parseInt(tokens[2 + j]);
                    keysInChest[key]++;
                    if (keyMax < key) {
                        keyMax = key;
                    }
                    if (keys.containsKey(key)) {
                        keys.put(key, keys.get(key) + 1);
                    } else {
                        keys.put(key, 1);
                    }
                }
                chestArray[i] = new Chest(keyType, keys);
            }
            keysInHand = Arrays.copyOfRange(keysInHand, 0, keyMax+1);
            keysInChest = Arrays.copyOfRange(keysInChest, 0, keyMax+1);
            boolean isPossible = true;
            for (int i = 1; i <= keyMax && isPossible; i++) {
                if (keysInChest[i] + keysInHand[i] < minimumKeyArray[i]) {
                    isPossible = false;
                }
            }
            result = new Stack<Integer>();
            resultBuilder.append("Case #").append(t).append(": ");
            if (isPossible && tryChest()) {
                while (!result.isEmpty()) {
                    resultBuilder.append(result.pop()).append(' ');
                }
                resultBuilder.deleteCharAt(resultBuilder.length() - 1).append("\n");
            } else {
                resultBuilder.append("IMPOSSIBLE\n");
            }
        }
        in.close();
        resultBuilder.deleteCharAt(resultBuilder.length() - 1);
        System.out.println(resultBuilder.toString());
        writeFile(resultBuilder.toString());
    }

    private static boolean tryChest() {
        if (remainChest == 0) {
            return true;
        }
        if (!isStillPossible()) {
            return false;
        }

        for (int i = 1; i <= n; i++) {
            if (!unlockedChest[i] && keysInHand[chestArray[i].lockType] > 0) {
                unlockedChest[i] = true;
                remainChest--;
                chestArray[i].unlock();
                if (tryChest()) {
                    result.push(i);
                    return true;
                } else {
                    unlockedChest[i] = false;
                    remainChest++;
                    chestArray[i].lock();
                }
            }
        }
        return false;
    }
    
    private static boolean isStillPossible() {
        for (int i = 1; i <= n; i++) {
            if (!unlockedChest[i] 
                    && keysInHand[chestArray[i].lockType] == 0 
                    && keysInChest[chestArray[i].lockType] == chestArray[i].getKeyNum(chestArray[i].lockType)){
                return false;
            }
        }
        return true;
    }

    public static class Chest {

        int lockType;
        HashMap<Integer, Integer> keys;

        public Chest(int lockType, HashMap<Integer, Integer> keys) {
            this.lockType = lockType;
            this.keys = keys;
        }
        
        public int getKeyNum(int key){
            if (keys.containsKey(key)) {
                return keys.get(key);
            } else {
                return 0;
            }
        }

        public void lock() {
            keysInHand[lockType]++;
            for (Entry<Integer, Integer> entry : keys.entrySet()) {
                keysInHand[entry.getKey()] -= entry.getValue();
                keysInChest[entry.getKey()] += entry.getValue();
            }
        }

        public int[] unlock() {
            keysInHand[lockType]--;
            for (Entry<Integer, Integer> entry : keys.entrySet()) {
                keysInHand[entry.getKey()] += entry.getValue();
                keysInChest[entry.getKey()] -= entry.getValue();
            }
            return keysInHand;
        }
    }

    private static void writeFile(String s) throws IOException {
        FileWriter output = new FileWriter("ProblemD.out");
        BufferedWriter writer = new BufferedWriter(output);
        writer.write(s);
        writer.close();
    }
}
