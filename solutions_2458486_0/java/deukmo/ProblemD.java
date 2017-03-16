package com.google.codejam.deukmo;
 
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
 
public class ProblemD {
    private static final String INPUT_FILENAME = "D-small-attempt0.in";
    private static final String OUTPUT_FILENAME = "D-small-attempt0.out";
    
    public static void main(String[] args)  throws Exception {
		System.out.println("Start!");
		
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        int totalKeys;
        int totalChests;
        ArrayList<Integer> myKeys = new ArrayList<Integer>();
        int[] keyTypes;
        boolean[] isOpened;
        HashMap<Integer, ArrayList<Integer>> innerKeys = new HashMap<Integer, ArrayList<Integer>>();
        int innerKeyCount;
        ArrayList<Integer> solution = new ArrayList<Integer>();
        boolean open;
        int startIndex;
        int lastIndex;
        ArrayList<Integer> getKeys;
        
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
            // START
        	totalKeys = input.nextInt();
        	totalChests = input.nextInt();
        	
        	myKeys.clear();
        	for (int i=0; i<totalKeys; i++) {
        		myKeys.add(input.nextInt());
        	}
        	
        	keyTypes = new int[totalChests];
        	isOpened = new boolean[totalChests];
        	innerKeys.clear();
        	for (int i=0; i<totalChests; i++) {
        		keyTypes[i] = input.nextInt();
        		isOpened[i] = false;
        		innerKeyCount = input.nextInt();
        		ArrayList<Integer> keys = new ArrayList<Integer>();
        		for (int j=0; j<innerKeyCount; j++) {
        			keys.add(input.nextInt());
        		}
        		innerKeys.put(i, keys);
        	}
        	
        	solution.clear();
        	open = true;
        	startIndex = 0;
        	while (!myKeys.isEmpty() && open) {
        		open = false;
        		for (int i=startIndex; i<totalChests; i++) {
        			if (!isOpened[i] && myKeys.contains(keyTypes[i])) {
        				isOpened[i] = true;
        				myKeys.remove((Integer)keyTypes[i]);
        				getKeys = innerKeys.get(i);
        				if (getKeys != null) {
        					myKeys.addAll(getKeys);
        				}
        				solution.add(i);
        				open = true;
        				startIndex = 0;
        				break;
        			}
        		}
        		
        		if (!open || open && myKeys.isEmpty() && solution.size() != totalChests) {
        			if (solution.isEmpty()) break;
        			
        			lastIndex = solution.remove(solution.size() - 1);
        			if (lastIndex >= totalChests - 1) break;
        			
        			isOpened[lastIndex] = false;
    				myKeys.add(keyTypes[lastIndex]);
    				getKeys = innerKeys.get(lastIndex);
    				for (int key : getKeys) {
    					myKeys.remove((Integer)key);
    				}
    				open = true;
    				startIndex = lastIndex + 1;
        		}
        	}
        	
        	output.format("Case #%d:", caseNum);
        	if (solution.size() == totalChests) {
        		for (int chest : solution) {
        			output.format(" %d", chest + 1);
        		}
        	} else {
        		output.format(" IMPOSSIBLE");
        	}
        	output.format("\n");
            // END
        }
        
        input.close();
        output.close();
        
		System.out.println("Done!");
    }
}
