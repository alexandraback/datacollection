import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class Treasure {
    static Scanner sc;
    static PrintStream out;

    public static void main(String[] args) throws Exception {
        sc = new Scanner(new FileReader("D-small-attempt0.in"));
        out = new PrintStream(new FileOutputStream("D-small-attempt0.out"));

        int testCases = sc.nextInt();
        for (int index = 1; index <= testCases; index++) {
            out.println(String.format("Case #%s: %s", index, solveCase()));
        }
    }
    
    public static String solveCase() {
        int keys = sc.nextInt(), chests = sc.nextInt();
        int[] start = new int[200];
        for(int index = 0; index < keys; index++) {
            start[sc.nextInt()-1]++;
        }
        
        chestContents = new int[chests][];
        chestType = new int[chests];
        for(int index = 0; index < chests; index++) {
            chestType[index] = sc.nextInt() - 1;
            chestContents[index] = new int[sc.nextInt()];
            for(int i = 0; i< chestContents[index].length; i++) {
                chestContents[index][i] = sc.nextInt() - 1;
            }
        }
        
        memo = new int[1<<chests];
        Arrays.fill(memo, -1);
        memo[(1<<chests) -1 ] = 1000;
        
        if (solve(0, start) == IMPOSSIBLE)
            return "IMPOSSIBLE";
        
        int open = 0; String res = "";
        while (true) {
            int next = solve(open, start);
            if (res.length() == 0)
                res = "" + (next+1);
            else
                res += " " + (next+1);
            open |= 1<<next;
            if (Integer.bitCount(open) == chests)
                break;
            update(start, next, +1);
        }
        return res;
        
        
    }
    static int[] memo, chestType;
    static int[][] chestContents;
    static final int IMPOSSIBLE = -2;
    static int solve(int open, int[] keys) {
        if (memo[open] == -1) {
            int res = IMPOSSIBLE;
            for(int index = 0; index < chestType.length; index++) {
                if ((open >> index & 1) == 0 && keys[chestType[index]] > 0) {
                    update(keys, index, +1);
                    int next = solve(open | 1<<index, keys);
                    update(keys, index, -1);
                    
                    if (next != IMPOSSIBLE) {
                        res = index;
                        break;
                    }
                }
            }
            memo[open] = res;
        }
        return memo[open];
    }
    
    static void update(int[] keys, int index, int factor) {
        keys[chestType[index]] -= factor;
        for(int key: chestContents[index])
            keys[key] += factor;
    }

}
