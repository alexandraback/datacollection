import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;


public class ProblemA {
	private static final String SIGN = "/";
	private static final String SPACE = " ";
	private static final String SEMICOLON = ": ";
	private static final String CASE = "Case #";
	private static final String IMPOSSIBLE = "impossible";
	
	public static void main(String[] args) throws IOException{
		
	    BufferedReader br = new BufferedReader(new FileReader("resources/A-small-attempt1.in"));
	    try {
	        StringBuilder sb = new StringBuilder();
	        String line = br.readLine();

	        if (line != null) {
	        	int numberOfCases = new Integer(line);
	        	for(int i = 0; i<numberOfCases; i++){
	        		line = br.readLine();
	        		String[] np = line.split(SIGN);
	        		int upper = Integer.parseInt(np[0]);
	        		int down = Integer.parseInt(np[1]);
	        		
	        		String outputString = howMany(upper, down);

        			sb.append(CASE + (i+1) + SEMICOLON + outputString);
	        		sb.append(System.lineSeparator());
	        	}
	        }
	        String output = sb.toString();
	        FileWriter fw = new FileWriter(new File("resources/A-small-1.out"));
	        fw.write(output);
	        fw.close();
	        
	    } finally {
	        br.close();
	    }
	    
	}

	private static String howMany(int upper, int down) {
		int globalCounter = 0;
		int counter = 0; 
		int rest = upper;
		int lastRest = upper;
		int multiCounter = 0;
		
		while(1==1){
			if(multiCounter > 60){
				return IMPOSSIBLE;
			}
			while(rest/down < 1){
				rest = rest *2;
				counter++;
			}
			int newRest = rest%down;
			if(newRest == 0 && multiCounter > 0){
				return String.valueOf(globalCounter);
			}
			if(newRest == 0 && multiCounter <= 0){
				return String.valueOf(counter);
			}
			if(newRest == lastRest && newRest == 1){
				return IMPOSSIBLE;
			}
			if(newRest == 0){
				return String.valueOf(globalCounter);
			}
			lastRest = newRest;
			rest = newRest;
			if(globalCounter == 0){
				globalCounter = counter;
			}
			multiCounter++;
		}
			
	}
	
    public static boolean prime(int n) 
    { 
            if (n>2) 
            { 
            double sq = Math.sqrt(n); 
            if(n%2==0) 
            return false; 
                    else 
                    { 
                    for(int i=3; i<=sq; i+=2) 
                            { 
                                    if(n%i==0) 
                                    { 
                                    return false; 
                                    } 
                            } 
                            return true; 
                                    } 
                                    } 
    else if (n==2) return true; 
    return false; 
                    } 

	
}
