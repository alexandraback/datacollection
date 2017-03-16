
import java.io.File;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;

public class D {
    static Map<String,String> solutions = new HashMap<>();
    static int[] keys;
    static Chest[] chests;
    static char[] unopenedChests;

    public static void main(String[] args) throws Exception {
        System.setOut(new PrintStream("/home/floris/temp/dev/codejam2013/in/out.txt"));
        Scanner sc = new Scanner(new File("/home/floris/temp/dev/codejam2013/in/D-small-attempt0.in"));
        for (int count = sc.nextInt(), current = 1; count > 0; count--, current++) {
            int keyCount = sc.nextInt();
            int chestCount = sc.nextInt();
            solutions.clear();
            keys = new int[400];
            chests = new Chest[chestCount];
            unopenedChests = new char[chestCount];
            Arrays.fill(unopenedChests, '0');
            solutions.put(new String(unopenedChests), "");
            Arrays.fill(unopenedChests, '1');
            for (int i = 0; i < keyCount; i++) keys[sc.nextInt()]++;
            for (int i = 0; i < chestCount; i++) {
                chests[i] = new Chest();
                chests[i].key = sc.nextInt();
                keyCount = sc.nextInt();
                chests[i].keys = new int[keyCount];
                for (int j = 0; j < keyCount; j++) chests[i].keys[j] = sc.nextInt();
            }
            String s = solve();
            if (s==null) s = "IMPOSSIBLE";
            System.out.printf("Case #%d: %s%n", current, s.trim());
        }
    }

    public static String solve() {
        String ss = new String(unopenedChests);
        if (solutions.containsKey(ss)) return solutions.get(ss);

        for (int i = 0; i < chests.length; i++) {
            if (unopenedChests[i] == '1' && keys[chests[i].key] > 0) {
                keys[chests[i].key]--;
                for (int j = 0; j < chests[i].keys.length; j++) keys[chests[i].keys[j]]++;
                unopenedChests[i] = '0';
                String s = solve();
                unopenedChests[i] = '1';
                keys[chests[i].key]++;
                for (int j = 0; j < chests[i].keys.length; j++) keys[chests[i].keys[j]]--;
                if (s != null) {
                    solutions.put(ss, (i+1)+" "+s);
                    return (i+1)+" "+s;
                }
            }
        }
        solutions.put(ss, null);
        return null;
    }
    static class Chest {
        int key;
        int[] keys;
    }
}
