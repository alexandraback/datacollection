

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

// Using the Google Guava library.
public class C {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/C-small-0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
		    int c = in.nextInt();
		    int d = in.nextInt();
		    int v = in.nextInt();
		    List<Integer> coins = new ArrayList<>();
		    for (int i = 0; i < d; i++) {
		        coins.add(in.nextInt());
		    }
		    
		    ArrayDeque<List<Integer>> q = new ArrayDeque<>();
		    q.add(coins);
		    List<Integer> solution = null;
		    Set<List<Integer>> seen = new HashSet<>();
		    while (solution == null) {
		        List<Integer> cur = q.remove();
		        int reach = reach(cur);
		        if (reach >= v) {
		            solution = cur;
		            break;
		        }
		        for (int i = 1; i <= reach+1; i++) {
		            if (!cur.contains(i)) {
		                List<Integer> next = new ArrayList<>(cur);
		                next.add(i);
		                Collections.sort(next);
		                if (!seen.contains(next)) {
		                    q.add(next);
		                }
		            }
		        }
		    }
		    
			String ans = "Case #"+cs+": "+(solution.size() - d);
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		in.close();
	}
	
	static int reach(List<Integer> coins) {
	    int reach = 0;
	    for (int c : coins) {
	        if (c > reach + 1) {
	            break;
	        }
	        reach += c;
	    }
	    return reach;
	}
}
