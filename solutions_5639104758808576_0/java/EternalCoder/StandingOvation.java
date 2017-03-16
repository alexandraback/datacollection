package gcj15;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class StandingOvation {
	static File file = new File("A-small-attempt0.in");
    static final String FILENAME = "A-large";
    static final String IN       = FILENAME + ".in";
    static final String OUT      = FILENAME + ".out";
    static PrintStream         out      = System.out;

	
	public static void main(String [] args) throws Exception {
		run();
	}
	
    private static void run() throws Exception {
         Scanner             sc       = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine());
        for (int i = 1; i <= t; i++) {
            solve(i, sc.nextLine());
        }
        sc.close();
        out.close();
    }
	
	public static void solve(int caseN, String total){		
	    int shyness =0, ans = 0;
	    
	    String [] array = total.split(" ");
	    int shynessMax = Integer.parseInt(array[0]);
	    
	    String a = array[1];
	    int audienceCount = 0, friends = 0;
	    for(int shyCount = 0;shyCount< (shynessMax + 1);shyCount++){
	                int aud = Character.getNumericValue(a.charAt(shyCount));
	                if (aud != 0){
	                    if(audienceCount < shyCount){
	                        friends += shyCount - audienceCount;
	                        audienceCount = shyCount;
	                    }
	                    audienceCount += aud;
	                }
	    }
        System.out.println("Case #"+caseN+": "+ friends);

	    
	}
}
