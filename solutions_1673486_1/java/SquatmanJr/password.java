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
	    BufferedReader f = new BufferedReader(new FileReader("A-large.in"));
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-large-attempt.out")));
	    StringTokenizer st = new StringTokenizer(f.readLine());

	    int caseCt = Integer.parseInt(st.nextToken());
	    int typedChars, totalChars;
	    for(int i = 0; i < caseCt; i++){
	    	st = new StringTokenizer(f.readLine());
	    	typedChars = Integer.parseInt(st.nextToken());
	    	totalChars = Integer.parseInt(st.nextToken());
	    	
	    	st = new StringTokenizer(f.readLine());
	    	double[] percentages = new double[typedChars + 1];
	    	double[] backspaceResults = new double[typedChars];
	    	
	    	percentages[0] = 1.0;
	    	for(int j = 1; j <= typedChars; j++){
	    		percentages[j] = Double.parseDouble(st.nextToken()) * percentages[j - 1]; 
	    	}
	    	
	    	int charsLeft = totalChars - typedChars;
	    	
	    	//strategy stay
	    	Double probability = 1.0;
	    	Double keyStrokes = 0.0;
	    	Double best;
	    		probability = percentages[typedChars];

	    	
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


	    	//strategies back1 - backn
	    	for(int j = 1; j <= typedChars; j++){
	    		if(typedChars > j - 1){
			    	keyStrokes = 0.0;
			    	probability = percentages[typedChars - j];
			    	
			    	keyStrokes += probability * (charsLeft + 1 + 2*j);
			    	keyStrokes += (1-probability) * (charsLeft + 1 + 2*j + totalChars + 1);	    	
	
		    		if(best > keyStrokes){
			    		best = keyStrokes;
			    	}
		    		//System.out.println("back" + j + ": " + keyStrokes);
	    		}
	    	}
	    	
	    	DecimalFormat format = new DecimalFormat("#.000000");
	    	
	    	out.print("Case #" + (i+1) + ": " + format.format(best));
	    	out.println();
	    }
	    
	    out.close();
	    System.exit(0);
	}
}
