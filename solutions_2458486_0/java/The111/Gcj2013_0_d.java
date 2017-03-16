package Gcj2013_0;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Gcj2013_0_d {
    public static PrintWriter pw;
    public static boolean allOpen;
    public static Set<Set<Integer>> triedPaths;
    
    final static String WORK_DIR = "C:\\eclipse\\workspace\\GoogleCodeJam\\IO\\2013_0\\";

    void solve(Scanner sc) {
        int K = sc.nextInt();
        int N = sc.nextInt();
        List<Integer> keys = new ArrayList<Integer>();
        Chest[] chests = new Chest[N];
        List<Integer> path = new ArrayList<Integer>();
        for (int i = 0; i < K; i++) {
            keys.add(sc.nextInt());
        }
        for (int i = 0; i < N; i++) {
            chests[i] = new Chest();
            chests[i].lock = sc.nextInt();
            int k = sc.nextInt();
            chests[i].treasure = new int[k];
            for (int j = 0; j < k; j++) {
                chests[i].treasure[j] = sc.nextInt();
            }
        }
        
        allOpen = false;
        triedPaths = new HashSet<Set<Integer>>();
        openChests(keys, chests, path);
        
        if (!allOpen) { 
            pw.println("IMPOSSIBLE");
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "D-small-attempt4.in"));
        pw = new PrintWriter(new FileWriter(WORK_DIR + "D-small-attempt4.out"));
        int T = sc.nextInt();
        long start = System.currentTimeMillis();
        for (int t=0; t<T; t++) {
            System.out.println("Processing test case " + (t + 1) + " of " + T);
            pw.print("Case #" + (t+1) + ": ");
            new Gcj2013_0_d().solve(sc);
        }
        long end = System.currentTimeMillis();
        System.out.println("Took " + (end - start) + "ms.");
        pw.flush();
        pw.close();
        sc.close();
    }
    
    public class Chest {
        int lock;
        int[] treasure;
    }
    
    public class TriedTreasure {
        List<Integer> contents;
        int lock;
    }
    
    public void openChests(List<Integer> keys, Chest[] chests, List<Integer> path) {
        // see if a permutation of this path has already been tried
        Set<Integer> pathSet = new HashSet<Integer>(path);
        if (!triedPaths.add(pathSet)) {
            //System.out.println("TRIED: " + triedPaths);
            //System.out.println("ABORTING: " + pathSet + "\n");
            return; // backtrack
        }
        
        if (allOpen) {
            return; // solved, no more digging needed
        }
        
        boolean test = true;
        for (int m = 0; m < chests.length; m++) {
            if (chests[m] != null) {
                test = false;
                break;
            }
        }
        if (test) {
            allOpen = true;
            for (int i = 0; i < path.size(); i++) {
                pw.print(path.get(i));
                if (i < path.size() - 1) {
                    pw.print(" ");
                }
            }
            pw.println();
            return; // solved!
        }
        //boolean triedSomething = false;
        List<TriedTreasure> triedTreasures = new ArrayList<TriedTreasure>();
        for (int j = 0; j < chests.length; j++) {
            if (chests[j] != null && keys.contains(chests[j].lock)) {

                // see if this treasure's contents have already been obtained in the same level of recursion
                // using the same type of key
                // but at an earlier lexographic position
                // if so, no need to recurse down that path
                TriedTreasure tryTreasure = new TriedTreasure();
                tryTreasure.lock = chests[j].lock;
                tryTreasure.contents = new ArrayList<Integer>();
                for (int n = 0; n < chests[j].treasure.length; n++) {
                    tryTreasure.contents.add(chests[j].treasure[n]);
                }
                boolean skip = false;
                for (TriedTreasure triedTreasure : triedTreasures) {
                    List<Integer> l1 = new ArrayList<Integer>(triedTreasure.contents);
                    List<Integer> l2 = new ArrayList<Integer>(tryTreasure.contents);
                    if (includesAll(l1, l2) && (triedTreasure.lock == tryTreasure.lock)) {
                        /*System.out.print("SKIPPING BECAUSE: ");
                        System.out.println(triedTreasure.contents + " with lock type " + triedTreasure.lock);
                        System.out.print("INCLUDES ALL OF ");
                        System.out.println(tryTreasure.contents + " with lock type " + tryTreasure.lock + "\n");*/
                        skip = true;
                        break;
                    }
                }
                
                if (!skip) {
                    triedTreasures.add(tryTreasure);
                    List<Integer> keys2 = new ArrayList<Integer>(keys);
                    keys2.remove(keys2.indexOf(chests[j].lock));
                    for (int n = 0; n < chests[j].treasure.length; n++) {
                        keys2.add(chests[j].treasure[n]);
                    }
                    Chest[] chests2 = Arrays.copyOf(chests, chests.length);
                    chests2[j] = null;
                    List<Integer> path2 = new ArrayList<Integer>(path);
                    path2.add(j + 1);
                    openChests(keys2, chests2, path2);
                }
            }
        }
    }
    
    public static boolean includesAll(List<Integer> list1, List<Integer> list2) {
        if (list1.size() == 0 && list2.size() > 0) {
            return false;
        } else if (list1.size() > 0 && list2.size() == 0) {
            return true;
        } else if (list1.size() == 0 && list2.size() == 0) {
            return true;
        }
        
        int i = list2.get(0);
        if (!list1.contains(i)) {
            return false;
        } else {
            list2.remove(0);
            list1.remove(list1.indexOf(i));
            return includesAll(list1, list2);
        }
    }
}
