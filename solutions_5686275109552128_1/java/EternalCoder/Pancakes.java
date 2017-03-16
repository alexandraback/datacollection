package gcj15;

import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.math.*;

public class Pancakes {
	static File file = new File("A-small-attempt0.in");
    static final String FILENAME = "A-large";
    static final String IN       = FILENAME + ".in";
    static final String OUT      = FILENAME + ".out";
    static PrintStream         out      = System.out;

	
	public static void main(String [] args) throws Exception {
		run();
	}
	
    private static void run() throws Exception {
         Scanner  sc   = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine());
        for (int i = 1; i <= t; i++) {
       	 int dinerCount = Integer.parseInt((sc.nextLine()));
       	 String s[] = sc.nextLine().split(" ");
       	ArrayList<Integer> al = new ArrayList<>();
       	 for(int aa = 0;aa<s.length;aa++){
       		al.add(Integer.parseInt(s[aa]));
       	 }
            solve(i, dinerCount,al );
        }
        sc.close();
        out.close();
    }
    
    public static void solve(int caseN, int dinnerCount, ArrayList<Integer> plates ){
    		        Collections.sort(plates, Collections.reverseOrder());
    		        int maxRound = plates.get(0);
    		        int minTime = Integer.MAX_VALUE;
    		        for(double r = 1;r< maxRound + 1;r++){
    		            int moveRound = 0;
    		            for (int plate : plates){
    		                if( plate <= r)
    		                    break;
    		                moveRound += (Math.ceil((plate / r) - 1));
    		            }
    		            if ( moveRound + r < minTime)
    		                minTime = (int) (moveRound + r);
    		        }
    		        System.out.println("Case #"+caseN+": "+minTime );
    }
}
