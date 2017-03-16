package net.purevirtual.googlejam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;
import org.apache.commons.lang.StringUtils;

/**
 * Treasure
 *
 */
public class App {
    private static class Treasure {
        Chest[] chests;
        int K;
        int N;
        int keys[];
        BitSet opened = new BitSet(200);
        Set<BitSet> failed = new HashSet<BitSet>();
        public Treasure(Scanner scanner) {
            K = scanner.nextInt();
            N = scanner.nextInt();
            scanner.nextLine();
            
            keys = new int[200];
            for(int k=0;k<K;k++) {
                int type = scanner.nextInt();
                keys[type]++; 
            }
            scanner.nextLine();
            
            chests = new Chest[N];
            for(int n=0;n<N;n++) {
                //System.out.println("chest "+n);
                chests[n] = new Chest(scanner,n);
            }
            
            for(int n1=0;n1<N;n1++) {
                for(int n2=0;n2<N;n2++) {
                    if (n1==n2) continue;
                    if (chests[n1].equalOrBetterThan(chests[n2])) {
                        chests[n1].betterThan.set(n2);
                    }
                }
                //System.out.println("chest "+n1+" better or eq  "+StringUtils.join(chests[n1].betterThan, " "));
            }
        }
        
        public List<Integer> solve(int left) {
            if (left ==0) {
                return new ArrayList();
            }
            if(failed.contains(opened)) {
                return null;
            }
            BitSet ignore = new BitSet(200);
            for(int n=0;n<N;n++) {
                if (ignore.get(n)) {
                    //continue;
                }
                if (!opened.get(n) && chests[n].canOpen(keys)) {
                    opened.set(n);
                    chests[n].open(keys, left);
                    List<Integer> tmp = solve(left-1);
                    if(tmp != null) {
                        tmp.add(n);
                        return tmp;
                    }
                    chests[n].close(keys, left);
                    opened.clear(n);
                    //if (chests[n].great) {
                    //    return null;
                    //}
                    ignore.or(chests[n].betterThan);
                }
            }
            failed.add((BitSet) opened.clone());
            return null;
        }

        private List<Integer> solve() {
            return solve(N);
        }
        
    }
    private static class Chest {
        //boolean open= false;
        int keyType;
        Map<Integer,Integer> loot;
        int no;
        boolean great = false;
        BitSet betterThan = new BitSet(200);
        public Chest(Scanner scanner, int no) {
            this.no = no;
            keyType = scanner.nextInt();
            int ki = scanner.nextInt();
            loot = new HashMap<Integer, Integer>(400);
            for (int i = 0; i < ki; i++) {
                int lootKeyType = scanner.nextInt();
                Integer val = loot.get(lootKeyType);
                if (val == null) {
                    loot.put(lootKeyType, 1);
                } else {
                    loot.put(lootKeyType, val + 1);
                }
                if (lootKeyType == keyType) {
                    great = true;
                }
            }
            scanner.nextLine();
        }

        private boolean canOpen(int[] keys) {
            return keys[keyType] > 0;
        }

        private void open(int[] keys, int left) {
            //System.out.println(StringUtils.leftPad("open  "+no, (40-left)));
            for (Entry<Integer, Integer> entry : loot.entrySet()) {
                keys[entry.getKey()] = keys[entry.getKey()] + entry.getValue();
            }
            keys[keyType]--;
            //open = true;
        }

        private void close(int[] keys, int left) {
            //System.out.println(StringUtils.leftPad("close "+no, (40-left)));
            for (Entry<Integer, Integer> entry : loot.entrySet()) {
                keys[entry.getKey()] = keys[entry.getKey()] - entry.getValue();
            }
            keys[keyType]++;
            //open = false;
        }
        
        public boolean equalOrBetterThan(Chest other) {
            for (Entry<Integer, Integer> entry : other.loot.entrySet()) {
                if ((!loot.containsKey(entry.getKey())) || loot.get(entry.getKey()) < entry.getValue()) {
                    return false;
                }
            }
            return true;
        }
    }
        
    public static void main(String[] args) throws FileNotFoundException, IOException {
        PrintWriter writer = new PrintWriter(new FileWriter("output"));
        Scanner scanner = new Scanner(new FileReader("input"));
        int tests = scanner.nextInt();
        scanner.nextLine();
        for(int t=0;t<tests;t++) {
            Treasure treasure = new Treasure(scanner);
            List<Integer> solve = treasure.solve();
            String message = "";
            if (solve != null) {
                Collections.reverse(solve);
                for(Integer i:solve) {
                    message = message +(i+1)+" ";
                }
                message = message.substring(0, message.length()-1);
            } else {
                message = "IMPOSSIBLE";
            }
            String msg = "Case #"+(t+1)+": "+message;
            System.out.println(msg);
            writer.println(msg);
        }
        writer.close();
    }
    
}
