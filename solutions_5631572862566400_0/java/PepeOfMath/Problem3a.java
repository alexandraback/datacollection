// Code by PepeOfMath
//
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class Problem3a {
    public static void main(String[] args) throws FileNotFoundException {
    	
        //hard code the file location
        //open file
        //get number of test cases
        File f = new File("C-small-attempt1.in");
        Scanner s = new Scanner(f);
        String line = s.nextLine();
        int T = Integer.parseInt(line);
        
        //open output file
        File f2 = new File("smalloutput.txt");
        PrintWriter p = new PrintWriter(f2);
        
        
        for ( int j = 1; j <= T; j++) {
        	int n = s.nextInt();
        	int[] ff = new int[n];
        	for (int i = 0 ; i < n; i++) {
        		ff[i] = s.nextInt()-1;
        	}
        	
        	//small solution
        	int mm = 0;
        	for (int i = 0; i < n; i++) {
        		//build a solution
				HashSet<Integer> sol = new HashSet<Integer>();
				sol.add(i);
				int prev = -1;
				int last = i;
				int max = buildSolution(i, sol, prev, last, ff);
        		if (max > mm) mm = max;
        	
        	}
        	
			p.println("Case #" + j + ": " + mm);
		   	
        
        }
        
        p.close();
        s.close();
    }
    
    public static int buildSolution(int start, HashSet<Integer> sol, int prev, int last, int[] f) {
    	if(!sol.contains(f[last])) {
    		sol.add(f[last]);
    		prev = last;
    		last = f[last];
    		return buildSolution(start, new HashSet<Integer>(sol), prev, last, f);
    	} else if (f[last] == prev) {
    		//closed chain, need to keep going
    		int max = sol.size();
    		for(int i = 0; i < f.length; i++) {
    			if(!sol.contains(i)) {
 	   				HashSet<Integer> tmp = new HashSet<Integer>(sol);
 	   				tmp.add(i);
 	   				int pp = last;
 	   				int ll = i;
    				max = Math.max(max, buildSolution(start, tmp, pp, ll, f));
    			}
    		}
    		return max;
   		} else if (f[last] == start) {
    		//loop
    		return sol.size();
    	} else {
    		return 0;
    	}
    
    }
    
}
