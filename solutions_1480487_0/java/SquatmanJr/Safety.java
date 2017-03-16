import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.StringTokenizer;


public class Safety {
	public static void main (String [] args) throws IOException {
	    BufferedReader f = new BufferedReader(new FileReader("A-small-attempt0.in"));
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt.out")));
	    StringTokenizer st = new StringTokenizer(f.readLine());

	    int caseCt = Integer.parseInt(st.nextToken());
	    int contestantCt;
 
	    for(int i = 0; i < caseCt; i++){
	    	st = new StringTokenizer(f.readLine());
	    	contestantCt = Integer.parseInt(st.nextToken());

	    	double actualTotal = 0.0;
		    double currentTotal = 0.0;
		    double atRisk = contestantCt;
		    int scores[] = new int[contestantCt];
		    double needed[] = new double[contestantCt];
		    
	    	for(int j = 0; j < contestantCt; j++){
	    		scores[j] = Integer.parseInt(st.nextToken());
	    		actualTotal += scores[j];
	    		currentTotal += scores[j] * 2;
	    		needed[j] = -1;
	    	}
	    	
	    	double currentAvg = currentTotal/contestantCt;
	    	
	    	boolean foundZero = false;
	    	for(int j = 0; j < contestantCt; j++){
	    		if(scores[j] >= currentAvg && needed[j] == -1){
	    			needed[j] = 0;
	    			currentTotal -= scores[j];
	    			atRisk -= 1;
	    			foundZero = true;
	    		}
	    	}

	    	while(foundZero){
	    		currentAvg = currentTotal/atRisk;
	    		foundZero = false;
	    		for(int j = 0; j < contestantCt; j++){
		    		if(scores[j] >= currentAvg && needed[j] == -1 && currentAvg > 0){
		    			needed[j] = 0;
		    			currentTotal -= scores[j];
		    			atRisk -= 1;
		    			foundZero = true;
		    		}
		    	}
	    	}

	    	double currentNeeded = 0;
	    	for(int j = 0; j < contestantCt; j++){
	    		if(needed[j] == -1){
	    			needed[j] = currentAvg - scores[j];
	    		}
	    	}
	    	
	    	DecimalFormat format = new DecimalFormat("0.000000");
	    	
	    	out.print("Case #" + (i+1) + ": ");
	    	for(int j = 0; j < contestantCt; j++){
	    		out.print(format.format(needed[j]*100/actualTotal));
	    		if(j != contestantCt - 1){
	    			out.print(" ");
	    		} else {
	    			out.println();
	    		}
	    	}
	    	//System.out.println();


	    }
	    
	    out.close();
	    System.exit(0);
	}
}
