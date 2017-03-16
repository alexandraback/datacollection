package es.gmail.jdominguezdetena;

import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
	
	public static Character plus = new Character('+');
	public static Character minus = new Character('-');
	
	public static String ltrim(String s) {
	    int i = 0;
	    while (i < s.length() && s.charAt(i) == plus) {
	        i++;
	    }
	    return s.substring(i);
	}
	
	public static String rtrim(String s) {
	    int i = s.length()-1;
	    while (i >= 0 && s.charAt(i) == plus) {
	        i--;
	    }
	    return s.substring(0,i+1);
	}
	
	public static String stringOfSize(int size, char ch)
	{
	    final char[] array = new char[size];
	    Arrays.fill(array, ch);
	    return new String(array);
	}

	
	public static void main(String[] args){
		InputUtils.readInput();
		List<String> solutionList = new ArrayList<String>();
		int T = InputUtils.inputs.length;

		System.out.println("COMPUTING...");
		for (int nCase = 1; nCase <= T; nCase ++) {
		      String S = InputUtils.inputs[nCase-1];

		      // CODE STARTS HERE //
		      int j = 0;
		      for(int i = 0; i < 10; i++){
		    	  //System.out.println(S);
		    	  S = rtrim(S);
		    	  if(S.length() < 1) break;
		    	  if(S.startsWith("-")){
		    		  S = S.replace("-", "1").replace("+", "0").replace("1", "+").replace("0", "-");
		    		  S = new StringBuilder(S).reverse().toString();
		    	  }else{
		    		  int antes = S.length();
		    		  S = ltrim(S);
		    		  int n = antes - S.length();
		    		  S =  stringOfSize(n, '-') + S;
		    	  }
		    	  j++;
		      }
		      
		      //System.out.println("Case #"+nCase+": "+j);
		      solutionList.add("Case #"+nCase+": "+j);
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

