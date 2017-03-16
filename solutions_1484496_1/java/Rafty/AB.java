import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;


public class AB {
   
    static HashMap< Long, ArrayList< Long>> results;
    
    private static ArrayList< ArrayList<Long>> bruteforce(ArrayList<Long> input, ArrayList<Long> current, int curIndex, int size) {
        if( size == 0 ) {
            long sum = 0;
            for( int i = 0; i < current.size(); i++ ) {
                sum += current.get(i);
            }
            if( results.containsKey(sum) && !current.equals(results.get(sum))) {
                ArrayList<ArrayList<Long>> found = new ArrayList<ArrayList<Long>>();
                found.add(current);
                found.add(results.get(sum));
                return found;
            } else {
                results.put(sum, current);
                return null;
            }
        } else {
            ArrayList< ArrayList<Long>> rez = null;
            for( int i = curIndex; i < input.size() && rez == null; ++i ) {
                ArrayList<Long> next = new ArrayList<Long>();
                next.addAll(current);
                next.add(input.get(i));
                rez = bruteforce(input, next, i+1, size-1);
            }
            return rez;
        }
    }
    
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        
        int cases;
        cases = in.nextInt();
        in.nextLine();
        
        for(int i = 0; i < cases; i ++ ) {
            int inputnum = in.nextInt();
            
            results = new HashMap< Long, ArrayList< Long>>();
            
            ArrayList<Long> input = new ArrayList<Long>();
            for( int j = 0; j < inputnum; j++) {
                input.add(in.nextLong());
            }
            ArrayList<ArrayList<Long>> result = null;
            for( int m = 0; m < input.size() - 1 && result == null; m++) {
                result = bruteforce(input, new ArrayList<Long>(), 0, m);
            }
            System.out.println("Case #" + (i+1) + ":");
            if( result == null ) {
                System.out.println(" Impossible");
            } else {
                for(int u = 0; u < result.get(0).size(); u++) {
                    System.out.print(result.get(0).get(u) + " ");
                }
                System.out.println();
                for(int u = 0; u < result.get(1).size(); u++) {
                    System.out.print(result.get(1).get(u) + " ");
                }
                System.out.println();
            }
        }
    }
}
