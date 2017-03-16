package p1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {
    
    private static Set<Integer> available;
    private static Set<Integer> possibleNew;
    
    public static boolean testValue(int value, Set<Integer> remaining) {
        
        if (value < 0) {
            return false;
        } else if (value == 0) {
            return true;
        } else {
            for (int x : remaining) {
                Set<Integer> remainingNext = new HashSet<Integer>(remaining);
                remainingNext.remove(x);
                if (testValue(value - x, remainingNext)) {
                    return true;
                }
            }
        }

        return false;
    }
    
    public static boolean test(int v, int count, Set<Integer> selected) {
        
        //System.out.println("v:" + v + " count:" + count + " sel:" + selected);
        
        if (selected.size() == count) {
            
            Set<Integer> combined = new HashSet<Integer>();
            combined.addAll(available);
            combined.addAll(selected);
            
            //System.out.println("combined:" + combined);
            
            for (int i = 1; i <= v; i++) {
                if (!testValue(i, combined)) {
                    return false;
                }
            }

            return true;

        } else {
            for (int den : possibleNew) {
                if (!selected.contains(den)) {
                    Set<Integer> selectedNext = new HashSet<Integer>(selected);
                    selectedNext.add(den);
                    if (test(v, count, selectedNext)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    public static int solve(int d, int v, Integer[] dd) {
        
        available = new HashSet<Integer>();
        available.addAll(Arrays.asList(dd));
        possibleNew = new HashSet<Integer>();
        for (int i = 1; i <= v; i++) {
            possibleNew.add(i);
        }
        possibleNew.removeAll(available);
        
        for (int i = 0; i <= v; i++) {
            if (test(v, i, new HashSet<Integer>())) {
                //System.out.println("found:" + i);
                return i;
            }
        }
        
        return 0;
    }
    
    public static void main(String[] args) {
        
        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            PrintWriter writer = new PrintWriter("output.txt");
            int count = Integer.valueOf(br.readLine());
            
            for (int ii = 0; ii < count; ii++) {
                String line = br.readLine();
                String[] tmp = line.split(" ");
                Integer[] values = new Integer[tmp.length];
                for (int i = 0; i < tmp.length; i++) {
                    values[i] = Integer.valueOf(tmp[i]);
                }
                
                //int c = values[0];
                int d = values[1];
                int v = values[2];
                
                line = br.readLine();
                tmp = line.split(" ");
                values = new Integer[tmp.length];
                for (int i = 0; i < tmp.length; i++) {
                    values[i] = Integer.valueOf(tmp[i]);
                }
                
                //System.out.println("Case #" + (ii+1) + ": " + solve(d, v, values));
                writer.println("Case #" + (ii+1) + ": " + solve(d, v, values));
            }
            
            br.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }
    
}
