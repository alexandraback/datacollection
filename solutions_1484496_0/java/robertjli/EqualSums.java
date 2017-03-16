package equalsums;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;



public class EqualSums {

    static SimpleReader reader;
    static SimpleWriter writer;
    
    static int size;
    static int[] elements;
    static Map<Integer, Set<Integer>> sums;
    static Set<Integer> set1;
    static Set<Integer> set2;

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
            int[] read = reader.readIntArray();
            size = read[0];
            elements = new int[size];
            for (int j = 1; j <= size; j++) {
                elements[j - 1] = read[j];
            }
            
            solve(i + 1);
            System.out.println("Case " + (i + 1) + " done");
        }
        writer.flush();
        System.out.println("Done");
    }
    
    private static void solve(int caseNo) {
        sortAscending(elements);
        sums = new HashMap<>();
        boolean[] switches = new boolean[size];
        for (int i = 0; i < size; i++) {
            switches[i] = false;
        }
        boolean found = findAllSubsets(switches, 0);
        if (found) {
            writer.writeLine("Case #" + caseNo + ": ");
            writer.writeLine(printSet(set1));
            writer.writeLine(printSet(set2));
        } else {
            writer.writeLine("Case #" + caseNo + ": Impossible");
        }
    }
    
    private static boolean findAllSubsets(boolean[] switches, int index) {
        if (index == size) {
            HashSet<Integer> set = new HashSet<>();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                if (switches[i]) {
                    set.add(elements[i]);
                    sum += elements[i];
                }
            }
            if (!set.isEmpty()) {
                if (sums.containsKey(sum)) {
                    set1 = set;
                    set2 = sums.get(sum);
                    return true;
                } else {
                    sums.put(sum, set);
                    return false;
                }
            } else {
                return false;
            }
        }
        
        switches[index] = false;
        if (findAllSubsets(switches, index + 1)) {
            return true;
        }
        switches[index] = true;
        return findAllSubsets(switches, index + 1);
    }

    private static String printSet(Set<Integer> set) {
        String ret = "";
        for (int i : set) {
            ret += i + " ";
        }
        return ret;
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
}
