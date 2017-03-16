import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class kingdom {
	public static void main (String [] args) throws IOException {
	    BufferedReader f = new BufferedReader(new FileReader("B-small-attempt1.in"));
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-small-attempt1.out")));
	    StringTokenizer st = new StringTokenizer(f.readLine());

	    int caseCt = Integer.parseInt(st.nextToken());

	    int levels;
	    
	    for(int i = 0; i < caseCt; i++){
	    	st = new StringTokenizer(f.readLine());
	    	
	    	levels = Integer.parseInt(st.nextToken());
	    	int[] oneReq = new int[levels];
	    	int[] twoReq = new int[levels];
	    	boolean[] oneTraveled = new boolean[levels];
	    	boolean[] twoTraveled = new boolean[levels];
	    	
	    	int steps = 0;
	    	int twoStarsFinished = 0;
	    	int currentPower = 0;
	    	
	    	for(int j = 0; j < levels; j++){
	    		st = new StringTokenizer(f.readLine());
	    		oneReq[j] = Integer.parseInt(st.nextToken());
	    		twoReq[j] = Integer.parseInt(st.nextToken());
	    	}
	    	
	    	boolean foundOneLastTime = true;
	    	//find least 2
	    	while(twoStarsFinished < levels){
    			//grab all the twos available
	    		boolean foundTwo = false;
	    		for(int j = 0; j < levels; j++){
	    			if(!twoTraveled[j]){
	    				if(currentPower >= twoReq[j]){
	    					twoTraveled[j] = true;
	    					twoStarsFinished++;
	    					foundTwo = true;
	    					if(oneTraveled[j]){
	    						currentPower += 1;
	    						steps++;
	    					} else {
	    						oneTraveled[j] = true;
	    						currentPower += 2;
	    						steps++;
	    					}
	    				}
	    			}
	    		}
	    		
	    		if(foundTwo){
	    			continue;
	    		} else {
	    			if(!foundOneLastTime){
	    				break;
	    			}
	    		}
	    		
	    		boolean foundOne = false;
	    		
	    		
	    		//find the greatest two from suitable ones
	    		int currentTwo = 0;
	    		int index = -1;
	    		
	    		for(int j = 0; j < levels; j++){
	    			if(!oneTraveled[j]){
	    				if(currentPower >= oneReq[j]){
	    					foundOne = true;
	    					if(twoReq[j] > currentTwo){
	    						currentTwo = twoReq[j];
	    						index = j;
	    					}
	    				}
	    			}
	    		}

	    		if(foundOne){
					currentPower += 1;
					steps++;
					oneTraveled[index] = true;
	    			foundOneLastTime = true;
	    		} else {
	    			foundOneLastTime = false;
	    		}
	    	}
	    	
	    	if(twoStarsFinished == levels){
	    		out.print("Case #" + (i+1) + ": " + steps);
	    	} else {
	    		out.print("Case #" + (i+1) + ": " + "Too Bad");
	    	}
	    	
	    	out.println();
	    }
	    
	    out.close();
	    System.exit(0);
	}
}
