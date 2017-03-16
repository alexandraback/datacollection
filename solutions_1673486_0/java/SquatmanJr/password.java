import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.StringTokenizer;


public class password {
	public static void main (String [] args) throws IOException {
	    BufferedReader f = new BufferedReader(new FileReader("A-small-attempt0.in"));
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt.out")));
	    StringTokenizer st = new StringTokenizer(f.readLine());

	    int caseCt = Integer.parseInt(st.nextToken());
	    int typedChars, totalChars;
	    for(int i = 0; i < caseCt; i++){
	    	st = new StringTokenizer(f.readLine());
	    	typedChars = Integer.parseInt(st.nextToken());
	    	totalChars = Integer.parseInt(st.nextToken());
	    	
	    	st = new StringTokenizer(f.readLine());
	    	double[] percentages = new double[typedChars];
	    	double[] strategyResults = new double[typedChars + 2];
	    	
	    	for(int j = 0; j < typedChars; j++){
	    		percentages[j] = Double.parseDouble(st.nextToken());
	    	}
	    	
	    	int charsLeft = totalChars - typedChars;
	    	
	    	//strategy stay
	    	Double probability = 1.0;
	    	Double keyStrokes = 0.0;
	    	Double best;
	    	for(int j = 0; j < typedChars; j++){
	    		probability *= percentages[j];
	    	}
	    	
	    		//E(k) correct
	    		keyStrokes += probability * (charsLeft + 1);
	    		//E[k) incorrect
	    		keyStrokes += (1 - probability) * (charsLeft + 1 + totalChars + 1);
	    		
	    	best = keyStrokes;
	    	//System.out.println("stay: " + keyStrokes);
	    	
	    	//strategy fold
	    	
	    	keyStrokes = 1.0 + totalChars + 1.0;
	    	
	    	if(best > keyStrokes){
	    		best = keyStrokes;
	    	}
	    	//System.out.println("fold: " + keyStrokes);
	    	
	    	//strategy back1
	    	keyStrokes = 0.0;
	    	probability = 1.0;
	    	
	    	for(int j = 0; j < typedChars - 1; j++){
	    		probability *= percentages[j];
	    	}
	    		//E(k) correct
	    		//System.out.println(probability + ": " + (charsLeft + 3));
	    		keyStrokes += probability * (charsLeft + 1 + 2);
	    		//E(k) incorrect
	    		keyStrokes += (1 - probability) * (charsLeft + 1 + 2 + totalChars + 1);
		    	
	    		if(best > keyStrokes){
		    		best = keyStrokes;
		    	}
	    		//System.out.println("back1: " + keyStrokes);
	    	
	    	//strategy back2
	    	if(typedChars > 1){
	    		keyStrokes = 0.0;
	    		probability = 1.0;
	    		for(int j = 0; j < typedChars - 2; j++){
	    			probability *= percentages[j];
	    		}
	    		
	    		//E(k) correct
	    		keyStrokes += probability * (charsLeft + 1 + 4);
	    		//E(k) incorrect
	    		keyStrokes += (1 - probability) * (charsLeft + 1 + 4 + totalChars + 1);
	    		
		    	if(best > keyStrokes){
		    		best = keyStrokes;
		    	}
	    		//System.out.println("back2: " + keyStrokes);
	    	}
	    		
	    	//strategy back3
	    	if(typedChars > 2){
	    		keyStrokes = 0.0;
	    		probability = 1.0;
	    		for(int j = 0; j < typedChars - 3; j++){
	    			probability *= percentages[j];
	    		}
	    		
	    		//E(k) correct
	    		keyStrokes += probability * (charsLeft + 1 + 6);
	    		//E(k) incorrect
	    		keyStrokes += (1 - probability) * (charsLeft + 1 + 6 + totalChars + 1);
	    		
		    	if(best > keyStrokes){
		    		best = keyStrokes;
		    	}
	    		//System.out.println("back3: " + keyStrokes);
	    	}
	    	
	    	DecimalFormat format = new DecimalFormat("#.000000");
	    	
	    	out.print("Case #" + (i+1) + ": " + format.format(best));
	    	out.println();
	    }
	    
	    out.close();
	    System.exit(0);
	}
}
