package es.gmail.jdominguezdetena;

import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

public class Main {
	
	public static int getPos(String s){
		 char[] ch  = s.toCharArray();
		        int temp = (int) ch[0];
		        int temp_integer = 64; //for upper case
		        if(temp<=90 & temp>=65)
		        	return temp-temp_integer;
		        else
		        	return -1;
	}

	
	public static void main(String[] args){
		InputUtils.readInput();
		DecimalFormat df = new DecimalFormat("###.#");
		List<String> solutionList = new ArrayList<String>();
		int T = InputUtils.inputs.length;

		System.out.println("COMPUTING...");
		for (int nCase = 1; nCase <= T; nCase ++) {
		      String S = InputUtils.inputs[nCase-1];
		      String caseString = "";
		      //System.out.println(K+" - "+C+" - "+S);
		      
		      // CODE STARTS HERE //
		      String buildString = S.charAt(0)+"";
		      for(int i = 1; i < S.length(); i++){
		    	String firstCharacter = buildString.charAt(0)+"";
		    	String character = S.charAt(i)+"";
		    	if(getPos(character) < 0) continue;
		    	if(getPos(character) >= getPos(firstCharacter)){
		    		buildString = character + buildString;
		    	}else{
		    		buildString = buildString + character;
		    	}
		      }
		      
		      caseString = buildString;
		      System.out.println("Case #"+nCase+": "+caseString);
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

