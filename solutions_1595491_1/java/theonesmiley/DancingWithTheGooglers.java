import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class DancingWithTheGooglers {
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
            DancingWithTheGooglers instance = new DancingWithTheGooglers();
            instance.solve(t);
        }

    }

    // ****** GLOBAL VARIABLES ******



    public DancingWithTheGooglers() {
    }

    public boolean solve(int caseNumber) {
    	StringTokenizer st = new StringTokenizer(readLine());
    	int n = Integer.parseInt(st.nextToken());
    	int s = Integer.parseInt(st.nextToken());
    	int p = Integer.parseInt(st.nextToken());
    	int[] totals = new int[n];
    	for (int i = 0; i < n; ++i) {
    		totals[i] = Integer.parseInt(st.nextToken());
    	}
    	int result = 0;
    	for (int i = 0; i < n; ++i) {
    		if ((totals[i]+2) / 3 >= p) {
    			++result;
    		} else if (s > 0 && totals[i] >= 2 && (totals[i]-2)/3 + 2 >= p) {
    			++result;
    			--s;
    		}
    	}
      System.out.println("Case #" + caseNumber + ": " + result);
      return false;
    }


}
