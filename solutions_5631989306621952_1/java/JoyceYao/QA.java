package googleCodeJamRound1;

import java.util.*;
import java.io.*;

public class QA {
	private static Reader in;
	private static PrintWriter out;
	public static final String NAME = ".\\codeJamRound1\\A-large";

	public static void main(String[] args) throws IOException {	
		
		out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
		File file = new File(NAME+".in");
		
		try (BufferedReader br = new BufferedReader(new FileReader(file))) {
		    int T = Integer.parseInt(br.readLine());
		    String line;

		    
		    for(int i=0; i<T; i++){
		    	line = br.readLine();
		    	StringBuilder sb = new StringBuilder();
		    	int first = 0;
		    	int thisV = 0;
		    	for(int j=0; j<line.length(); j++){
		    		thisV = line.charAt(j)-'A';  
		    		if(thisV < first){
		    			sb.append(line.charAt(j)); 	
		    		}else{
		    			sb.insert(0, line.charAt(j));
		    			first = thisV;
		    		}
		    	}
		    	out.println("Case #" + (i+1) + ": " + sb.toString());
		    }
		    
		}
		
		out.close();
	    System.exit(0);
		
	}
}

