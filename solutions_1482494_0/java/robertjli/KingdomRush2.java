package kingdomrush;

import java.util.ArrayList;


public class KingdomRush2 {

    static SimpleReader reader;
    static SimpleWriter writer;
    
    static int levels;
    static int[] hard;
    static int[] easy;
    static int[] starsGained;

    public static void main(String[] args) {
        if (args.length != 1) {
            reader = new SimpleReader();
            writer = new SimpleWriter();
        } else {
            reader = new SimpleReader(args[0]);
            writer = new SimpleWriter(args[1]);
        }
        int cases = reader.readInt();
        for (int i = 0; i < cases; i++) {
            levels = reader.readInt();
            hard = new int[levels];
            easy = new int[levels];
            starsGained = new int[levels];
            int[] read;
            for (int j = 0; j < levels; j++) {
                read = reader.readIntArray();
                easy[j] = read[0];
                hard[j] = read[1];
                starsGained[j] = 0;
            }
            
            solve(i + 1);
            System.out.println("Case " + (i + 1) + " done");
        }
        writer.flush();
        System.out.println("Done");
    }
    
    private static void solve(int caseNo) {
        int stars = 0;
        int played = 0;
        while (notDone()) {
            System.out.println(stars);
            System.out.println(played);
            printArray(easy);
            printArray(hard);
            ArrayList<Integer> easyLevels = getAllEasy(stars);
            ArrayList<Integer> hardLevels = getAllHard(stars);
            if (easyLevels.size() == 0 && hardLevels.size() == 0) {
                writer.writeLine("Case #" + caseNo + ": Too Bad");
                return;
            }
            if (hardLevels.size() == 0) { // doing an easy one
                // find the easy level with a corresponding hard that's highest
                int max = -1;
                int maxLevel = -1;
                for (Integer level : easyLevels) {
                    if (hard[level] > max) {
                        max = hard[level];
                        maxLevel = level;
                    }
                }
                stars += 1;
                played += 1;
                starsGained[maxLevel] += 1;
                easy[maxLevel] = Integer.MAX_VALUE;
            } else {
                // find the hard level with 2 stars available
                boolean found = false;
                for (Integer level : hardLevels) {
                    if (starsGained[level] == 0) {
                        stars += 2;
                        played += 1;
                        starsGained[level] = 2;
                        found = true;
                        easy[level] = Integer.MAX_VALUE;
                        hard[level] = Integer.MAX_VALUE;
                        break;
                    }
                }
                if (!found) {
                    int level = hardLevels.get(0);
                    stars += 1;
                    played += 1;
                    starsGained[level] = 2;
                    easy[level] = Integer.MAX_VALUE;
                    hard[level] = Integer.MAX_VALUE;
                }
            }
        }
        
        writer.writeLine("Case #" + caseNo + ": " + played);
    }
    
    private static ArrayList<Integer> getAllHard(int stars) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < levels; i++) {
            if (hard[i] <= stars) {
                list.add(i);
            }
        }
        return list;
    }

    private static ArrayList<Integer> getAllEasy(int stars) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < levels; i++) {
            if (easy[i] <= stars) {
                list.add(i);
            }
        }
        return list;
    }

    private static void printArray(int[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println("]");
    }
    
    private static void sortAscending(int[] array) {
        if (array == null) {
            return;
        }
        int a = array.length;
        int value;
        for (int outer = 1; outer < a; outer++) {
            value = array[outer] % 10000;
            for (int inner = outer - 1; inner >= 0; inner--) {
                if (value < array[inner] % 10000) {
                    swap(array, inner, inner + 1);
                }
            }
        }
    }
    
    private static void sortDescending(int[] array) {
        if (array == null) {
            return;
        }
        int a = array.length;
        int value;
        for (int outer = 1; outer < a; outer++) {
            value = array[outer] % 10000;
            for (int inner = outer - 1; inner >= 0; inner--) {
                if (value > array[inner] % 10000) {
                    swap(array, inner, inner + 1);
                }
            }
        }
    }
    
    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    private static boolean notDone() {
        for (int i = 0; i < levels; i++) {
            if (hard[i] != Integer.MAX_VALUE) {
                return true;
            }
        }
        return false;
    }
}
