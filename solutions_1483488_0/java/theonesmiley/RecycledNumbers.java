import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class RecycledNumbers {
    public static BufferedReader BR;

    public static String readLine() {
        try {
            return BR.readLine();
        } catch(Exception E) {
            System.err.println(E.toString());
            return null;
        }
    }


    // ****** MAIN ******

    public static void main(String [] args) throws Exception {
        BR = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(readLine());
        for (int t = 1; t <= testcases; t++) {
            RecycledNumbers instance = new RecycledNumbers();
            instance.solve(t);
        }

    }

    // ****** GLOBAL VARIABLES ******



    public RecycledNumbers() {
    }

    public boolean solve(int caseNumber) {
    	StringTokenizer st = new StringTokenizer(readLine());
    	int a = Integer.parseInt(st.nextToken());
    	int b = Integer.parseInt(st.nextToken());
    	int n = Integer.toString(a).length();
    	long result = 0;
    	for (int i = a; i <= b; ++i) {
    		String s = Integer.toString(i);
    		Set<Integer> seen = new HashSet<Integer>();
    		for (int j = 1; j < n; ++j) {
    			int rotated = Integer.parseInt(s.substring(j) + s.substring(0,j));
    			if (i < rotated && rotated <= b && !seen.contains(rotated)) {
    				seen.add(rotated);
    				++result;
    			}
    		}
    	}
      System.out.println("Case #" + caseNumber + ": " + result);
			return false;
    }


}
