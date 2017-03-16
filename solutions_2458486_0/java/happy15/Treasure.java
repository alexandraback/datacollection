import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Treasure {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int numTests = Integer.parseInt(reader.readLine());
        for (int testId = 1; testId <= numTests; ++ testId) {
            String[] tmp = reader.readLine().split(" ");
            int numChests = Integer.parseInt(tmp[1]);
            tmp = reader.readLine().split(" ");
            int[] numKeys = new int[201];
            int[] numKeysNeedAll = new int[201];
            int[] numKeysAll = new int[201];
            Arrays.fill(numKeys, 0);
            Arrays.fill(numKeysAll, 0);
            Arrays.fill(numKeysNeedAll, 0);
            for (String s: tmp) {
                ++numKeys[Integer.parseInt(s)];
                ++numKeysAll[Integer.parseInt(s)];
            }
            int[] need = new int[numChests + 1];
            int[][] keysInChests = new int[numChests + 1][201];
            for (int i = 1; i <= numChests; ++i) {
                tmp = reader.readLine().split(" ");
                need[i] = Integer.parseInt(tmp[0]);
                ++numKeysNeedAll[need[i]];
                Arrays.fill(keysInChests[i], 0);
                keysInChests[i][0] = Integer.parseInt(tmp[1]);
                for (int j = 2; j < tmp.length; ++j) {
                    keysInChests[i][j - 1] = Integer.parseInt(tmp[j]);
                    ++numKeysAll[Integer.parseInt(tmp[j])];
                }
            }

            System.out.print("Case #" + testId + ": ");

            boolean possible = true;
            for (int i = 1; i <= 200; ++i) {
                if (numKeysAll[i] < numKeysNeedAll[i]) {
                    possible = false;
                    break;
                }
            }
            if (!possible) {
                System.out.println("IMPOSSIBLE");
                continue;
            }

            int[] order = new int[numChests + 1];
            boolean[] opened = new boolean[numChests + 1];
            Set<Integer> failed = new HashSet<Integer>();

            Arrays.fill(opened, false);
            if (find(1, numChests, opened, need, numKeys, keysInChests, order, failed)) {
                String ans = "";
                for (int i = 1; i <= numChests; ++i) {
                    ans += String.valueOf(order[i]) + " ";
                }
                System.out.println(ans);
            } else {
                System.out.println("IMPOSSIBLE");
            }
        }
    }

    private static boolean find(int step, int numChests, boolean[] opened, int[] need, int[] numKeys, int[][] keysInChests, int[] order, Set<Integer> failed) {
        if (step > numChests) {
            return true;
        }
        int status = toStatus(opened);
        if (failed.contains(status)) {
            return false;
        }
        for (int i = 1; i <= numChests; ++i) {
            if (!opened[i] && numKeys[need[i]] > 0) {
                order[step] = i;
                opened[i] = true;
                --numKeys[need[i]];
                for (int j = 1; j <= keysInChests[i][0]; ++j) {
                    ++numKeys[keysInChests[i][j]];
                }
                if (find(step + 1, numChests, opened, need, numKeys, keysInChests, order, failed)) {
                    return true;
                }
                for (int j = 1; j <= keysInChests[i][0]; ++j) {
                    --numKeys[keysInChests[i][j]];
                }
                ++numKeys[need[i]];
                opened[i] = false;
            }
        }
        failed.add(status);
        return false;
    }

    private static int toStatus(boolean[] opened) {
        int ans = 0;
        int pow2 = 1;
        for (boolean x: opened) {
            ans += pow2 * (x ? 1 : 0);
            pow2 += pow2;
        }
        return ans;
    }
}
