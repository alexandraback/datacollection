import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Treasure {
    static Scanner sc = new Scanner(System.in);
    private static int MAX_KEY = 201;

    // Needs DP.

    static HashMap<SubProblem, String> memo;

    public static void main(String[] args) {
        int T = sc.nextInt();

        for (int i = 1; i <= T; i++) {
            int[] keys = new int[MAX_KEY];
            int K = sc.nextInt(), N = sc.nextInt();
            for (int j = 0; j < K; j++) {
                keys[sc.nextInt()]++;
            }

            Chest[] chests = new Chest[N];
            for (int j = 0; j < N; j++) {
                memo = new HashMap<SubProblem, String>();
                int keyType = sc.nextInt();
                int numKeys = sc.nextInt();
                int[] keysInside = new int[MAX_KEY];
                for (int k = 0; k < numKeys; k++) {
                    keysInside[sc.nextInt()]++;
                }
                chests[j] = new Chest(keyType, keysInside);
            }

            System.out.println("Case #" + i + ":" + getAllTreasure(keys, chests, 0, ""));
        }
    }

    private static String getAllTreasure(int[] keys, Chest[] chests, int taken, String solution) {
        if(taken == (1 << (chests.length)) - 1)
            return solution;

        SubProblem key = new SubProblem(taken, keys);
        if(memo.containsKey(key))
            return memo.get(key);

        for (int i = 0; i < chests.length; i++) {
            if((taken & (1 << i)) == 0) { // chest not taken
                if(keys[chests[i].keyType] > 0) { // we have the key
                    int[] newKeys = keys.clone();
                    newKeys[chests[i].keyType]--; // remove used key
                    for (int j = 0; j < MAX_KEY; j++) {
                        newKeys[j] += chests[i].containedKeys[j];
                    }
                    String result = getAllTreasure(newKeys, chests, taken | 1 << i, solution + " " + (i+1));
                    memo.put(key, result);
                    if(!result.equals(" IMPOSSIBLE")) {
                        return result;
                    }
                }
            }
        }

        return " IMPOSSIBLE";
    }

    static class SubProblem {
        int taken;

        SubProblem(int taken, int[] keys) {
            this.taken = taken;
            this.keys = keys;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            SubProblem that = (SubProblem) o;

            if (taken != that.taken) return false;
            if (!Arrays.equals(keys, that.keys)) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = taken;
            result = 31 * result + Arrays.hashCode(keys);
            return result;
        }

        int[] keys;
    }

    static class Chest {
        int keyType;
        int[] containedKeys;

        Chest(int keyType, int[] containedKeys) {
            this.keyType = keyType;
            this.containedKeys = containedKeys;
        }
    }
}
