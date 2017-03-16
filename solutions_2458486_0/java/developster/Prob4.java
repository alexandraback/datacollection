package codejam.y2013.q;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Prob4 {
    
    static int c; // case
    
    static int n; // number of chests
    static int k; // number of keys I have
    
    static int[] mykeys;
    static int[] chestKeyType;
    static List<Integer>[] keysInChest;
    
    static boolean[] used;
    static int[] sol;
    
//    static int maxkey;
//    static boolean[][] usedKeyWithReturn = new boolean[20][201];
    
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("/Users/octavian/codejam/D-small-attempt2.in.txt"));
        FileWriter writer = new FileWriter(new File("/Users/octavian/codejam/D-small-attempt2.out.txt"));
        
        int cn = scanner.nextInt();
        for (c = 0; c < cn; c++) {
            
            k = scanner.nextInt();
            n = scanner.nextInt();
            
//            maxkey = 1;
            mykeys = new int[201];
            for (int i = 0; i < k; i++) {
                int mykey = scanner.nextInt();
                mykeys[mykey]++;
//                maxkey = Math.max(maxkey, mykey);
            }
            chestKeyType = new int[n];
            keysInChest = new List[n];
            for (int i = 0; i < n; i++) {
                chestKeyType[i] = scanner.nextInt();
//                maxkey = Math.max(maxkey, chestKeyType[i]);
                int kicCnt = scanner.nextInt();
                keysInChest[i] = new ArrayList<Integer>();
                for (int j = 0; j < kicCnt; j++) {
                    int kic = scanner.nextInt();
                    keysInChest[i].add(kic);
//                    maxkey = Math.max(maxkey, kic);
                }
            }
            
            used = new boolean[n];
            sol = new int[n];
            
            boolean canBeSolved;
            if (enoughKeys()) {
                canBeSolved = rec(0);
            } else {
                canBeSolved = false;
            }
            
            writer.write("Case #" + (c+1) + ":");
            if (canBeSolved) {
                for (int i = 0; i < n; i++) {
                    writer.write(" " + (sol[i] + 1));
                }
            } else {
                writer.write(" IMPOSSIBLE");
            }
            writer.write("\n");
            writer.flush();
        }
        writer.close();
        scanner.close();
    }
    
    private static boolean enoughKeys() {
        for (int k = 1; k <= 200; k++) {
            int c = mykeys[k];
            for (int i = 0; i < n; i++) {
                for (int j : keysInChest[i]) {
                    if (k == j) c++;
                }
                if (chestKeyType[i] == k) {
                    c--;
                }
            }
            if (c < 0) {
                return false;
            }
        }
        return true;
    }

    private static boolean rec(int depth) {
        if (depth < n && k == 0) {
            return false; // lost all keys and 
        } else if (depth == n) {
            return true; // reached desired depth
        } else if (selfLocked()) {
            return false;
        } else {
//            for (int i = 1; i <= maxkey; i++) {
//                usedKeyWithReturn[depth][i] = false;
//            }
            
            for (int i = 0; i < n; i++) {
                if (!used[i] && mykeys[chestKeyType[i]] > 0) {
                    
//                    if (usedKeyWithReturn[depth][chestKeyType[i]] && keysInChest[i].size() == 0) {
//                        continue;
//                    }
                    
                    used[i] = true;
                    for (int j : keysInChest[i]) {
                        mykeys[j]++;
                        k++;
                    }
                    mykeys[chestKeyType[i]]--;
                    k--;
//                    if (keysInChest[i].size() > 0) {
//                        usedKeyWithReturn[depth][chestKeyType[i]] = true;
//                    }
                    
                    sol[depth] = i;
                    boolean canBeSolved = rec(depth + 1);
                    if (canBeSolved) {
                        return true;
                    }
                    sol[depth] = 0;
                    
                    used[i] = false;
                    for (int j : keysInChest[i]) {
                        mykeys[j]--;
                        k--;
                    }
                    mykeys[chestKeyType[i]]++;
                    k++;
                }
            }
            return false;
        }
    }
    
    private static boolean selfLocked() {
//        return false;
        for (int i = 0; i < n; i++) {
            if (!used[i] && mykeys[chestKeyType[i]] == 0) {
                for (int i2 = 0; i2 < n; i2++) {
                    if (!used[i2] && i != i2) {
                        for (int j : keysInChest[i2]) {
                            if (j == chestKeyType[i]) {
                                return false;
                            }
                        }
                    }
                }
                return true;
            }
        }
        return false;
    }
}
