import java.util.*;

public class Main {
    
    static int N;
    static boolean[] used;
    static int[] needKey;
    static int[][] containKey;
    
    static String search(int[] key, int index, int count) {
        if (key[needKey[index]] == 0) {
            return null;
        }
        key[needKey[index]]--;
        for (int i = 0; i < 41; i++) {
            key[i] += containKey[index][i];
        }
        count++;
        if (count == N) {
            return Integer.toString(index + 1);
        }
        String res = null;
        used[index] = true;
        for (int i = 0; i < N; i++) {
            if (used[i]) {
                continue;
            }
            String temp = search(key, i, count);
            if (temp != null) {
                res = Integer.toString(index + 1) + " " + temp;
                break;
            }
        }
        used[index] = false;
        return res;
    }
    
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        int taskCount = scan.nextInt();
        scan.nextLine();
        for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
            int K = scan.nextInt();
            N = scan.nextInt();
            needKey = new int[N];
            used = new boolean[N];
            containKey = new int[N][41];
            int[] key = new int[41];
            for (int i = 0; i < K; i++) {
                key[scan.nextInt()]++;
            }
            for (int i = 0; i < N; i++) {
                needKey[i] = scan.nextInt();
                int keyNum = scan.nextInt();
                for (int j = 0; j < keyNum; j++) {
                    containKey[i][scan.nextInt()]++;
                }
            }
            String res = null;
            for (int i = 0; i < N; i++) {
                Arrays.fill(used, false);
                res = search(Arrays.copyOf(key, key.length), i, 0);
                if (res != null) {
                    break;
                }
            }
            System.out.println(String.format("Case #%d: %s", taskIndex, res == null ? "IMPOSSIBLE" : res));
        }
    }
}
