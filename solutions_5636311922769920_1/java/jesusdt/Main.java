package es.gmail.jdominguezdetena;

import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

public class Main {
	
	public static BigInteger cPow(BigInteger i, int z){
		if(z == 0) return BigInteger.ONE;
		return cPow(i, z-1).multiply(i);
	}

	
	public static void main(String[] args){
		InputUtils.readInput();
		DecimalFormat df = new DecimalFormat("###.#");
		List<String> solutionList = new ArrayList<String>();
		int T = InputUtils.inputs.length;

		System.out.println("COMPUTING...");
		for (int nCase = 1; nCase <= T; nCase ++) {
		      int K = InputUtils.inputs[nCase-1][0];
		      int C = InputUtils.inputs[nCase-1][1];
		      int S = InputUtils.inputs[nCase-1][2];
		      String caseString = "";
		      //System.out.println(K+" - "+C+" - "+S);
		      
		      // CODE STARTS HERE //
		      int minS = (int) Math.ceil(((double) K)/((double) C));
		      if(S < minS){
		    	  //System.out.println("Case #"+nCase+": IMPOSSIBLE");
		    	  solutionList.add("Case #"+nCase+": IMPOSSIBLE");
		    	  continue;
		      }
		      
		      int i = K;
		      boolean gotEmAll = false;
		      
		      for (int nS = 0; nS < minS; nS++) {
		      //for (int nS = 0; nS < K; nS++) {
		    	 BigInteger currentS = BigInteger.ZERO;
		    	  
		    	  for(int j = 1; j <= C; j++){
		    		  if(gotEmAll || i < 1){
		    			  gotEmAll = true;
		    			  i = 1;
		    		  }
		    		  if(j == 1){
		    			  currentS = BigInteger.valueOf(i);
		    		  }else{
		    			  currentS = cPow(BigInteger.valueOf(K), j-1).multiply(BigInteger.valueOf(i-1)).add(currentS);
		    		  }  
		    		  i--;
		    	  }
		    	  //i++;
		    	  if(caseString == ""){
		    		 caseString = df.format(currentS);
		    	  }else{
		    		 caseString = caseString + " " + df.format(currentS);  
		    	  }  
		      }
		      
		      //System.out.println("Case #"+nCase+": "+caseString);
		      solutionList.add("Case #"+nCase+": "+caseString);
		      // CODE ENDS HERE //
		}
		
		System.out.println("DONE!");
		
		FileWriter writer;
		try {
			writer = new FileWriter("C://GoogleCodeJam/output.in");
			for(String str: solutionList) {
				  writer.write(str + System.getProperty("line.separator"));
				}
				writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		} 
		
	}
}

