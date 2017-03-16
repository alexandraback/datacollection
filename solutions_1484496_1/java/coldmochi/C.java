package codejam2012.round1b;

import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class C {

    Scanner             sc       = new Scanner(getClass().getResourceAsStream(IN));
    static final String FILENAME = "C";
    static final String IN       = FILENAME + ".in";
    static final String OUT      = FILENAME + ".out";
    PrintStream         out      = System.out;
    boolean writeToFile = true;

//    2
//    20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
//    20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600
    private void solve() {
        int n = sc.nextInt();
        // Contains the original list of numbers
        List<BigInteger> original = new LinkedList<BigInteger>();
        // Contains the next set of sums mapped to the index to which they should start next in the original list
        Map<BigInteger, Integer> sums = new LinkedHashMap<BigInteger, Integer>();
        // Contains the sum mapped to the indices in the original list that add to that sum
        Map<BigInteger, List<Integer>> sumToIndices = new HashMap<BigInteger, List<Integer>>();
        
        for (int i = 0; i < n; i++) {
        	original.add(new BigInteger(sc.next()));
        }
        
        // Sets up sums initially
        for (int i = 0; i < original.size(); i++) {
        	sums.put(original.get(i), i+1);
        	sumToIndices.put(original.get(i), Arrays.asList(i));
        }
        
        boolean done = false;
        while(!done) {
        	
        	Map<BigInteger, Integer> newSums = new LinkedHashMap<BigInteger, Integer>();
        	for (Map.Entry<BigInteger, Integer> e : sums.entrySet()) {
        		BigInteger currentSum = e.getKey();
        		int nextIndex = e.getValue();
        		for (int j = nextIndex; j < original.size(); j++) {
        			BigInteger sum = currentSum.add(original.get(j));
        			newSums.put(sum, j+1);
        			List<Integer> currentIndices = sumToIndices.get(currentSum);
        			List<Integer> newIndices = new LinkedList<Integer>(currentIndices);
        			newIndices.add(j);
        			if (sumToIndices.containsKey(sum)) {
        				out.println();
        				for (int k : newIndices) {
        					out.print(original.get(k) + " ");
        				}
        				out.println();
        				for (int k : sumToIndices.get(sum)) {
        					out.print(original.get(k) + " ");
        				}
        				out.println();
        				done = true;
        				break;
        			} else {
        				sumToIndices.put(sum, newIndices);
        			}
        		}
        		if (done) {
        			break;
        		}
        	}
        	sums = newSums;
        }
    }

    private void run() throws Exception {
        if (writeToFile) {
            out = new PrintStream(new FileOutputStream(OUT));
        }
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            out.print("Case #" + i + ": ");
            solve();
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new C().run();
    }
}