import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class ProblemA {
	private static final String SIGN = "/";
	private static final String SPACE = " ";
	private static final String SEMICOLON = ": ";
	private static final String CASE = "Case #";
	private static final String IMPOSSIBLE = "impossible";
	
	public static void main(String[] args) throws IOException{
		
	    BufferedReader br = new BufferedReader(new FileReader("resources/A-large.in"));
	    try {
	        StringBuilder sb = new StringBuilder();
	        String line = br.readLine();

	        if (line != null) {
	        	int numberOfCases = Integer.parseInt(line);
	        	for(long i = 0; i<numberOfCases; i++){
	        		line = br.readLine();
	        		String[] np = line.split(SIGN);
	        		long upper = Long.parseLong(np[0]);
	        		long down = Long.parseLong(np[1]);
	        		
	        		String outputString = howMany(upper, down);

        			sb.append(CASE + (i+1) + SEMICOLON + outputString);
	        		sb.append(System.lineSeparator());
	        	}
	        }
	        String output = sb.toString();
	        FileWriter fw = new FileWriter(new File("resources/A-large.out"));
	        fw.write(output);
	        fw.close();
	        
	    } finally {
	        br.close();
	    }
	    
	}

	private static String howMany(long upper, long down) {
		long globalCounter = 0;
		long counter = 0; 
		long rest = upper;
		long lastRest = upper;
		long multiCounter = 0;
		
		while(1==1){
			if(multiCounter > 60){
				return IMPOSSIBLE;
			}
			while(rest/down < 1){
				rest = rest *2;
				counter++;
			}
			long newRest = rest%down;
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
	
}
