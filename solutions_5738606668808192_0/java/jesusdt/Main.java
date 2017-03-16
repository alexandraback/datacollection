package es.gmail.jdominguezdetena;

import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Main {
	
	static boolean[] primes = new boolean[1000000];
	static double[] primeNumbers = new double[1000000];
	static int primeDbSize = 0;
	
	//set up the primesieve
	public static void fillSieve() {
	    Arrays.fill(primes,true);        // assume all integers are prime.
	    primes[0]=primes[1]=false;       // we know 0 and 1 are not prime.
	    for (int i=2;i<primes.length;i++) {
	        //if the number is prime, 
	        //then go through all its multiples and make their values false.
	        if(primes[i]) {
	            for (int j=2;i*j<primes.length;j++) {
	                primes[i*j]=false;
	            }
	        }
	    }
	    int j = 0;
	    for (int i=2;i<primes.length;i++) {
	    	if(primes[i]) {
	    		primeNumbers[j] = i;
	    		j++;
	    	}
	    }
	    primeDbSize = j;
	}

	public static double isPrime(double number) {
		for(int i=0; i < primeDbSize; i++) {
	        if(number % primeNumbers[i] == 0 && number != primeNumbers[i])
	            return primeNumbers[i];
	    }
	    return 0;
	}
	
	public static void main(String[] args){
		InputUtils.readInput();
		DecimalFormat df = new DecimalFormat("###.#");
		List<String> solutionList = new ArrayList<String>();
		int T = InputUtils.inputs.length;
		solutionList.add("Case #1:");
		
		System.out.println("Getting primes...");
		fillSieve();
		System.out.println("Got em!");
		
		System.out.println("COMPUTING...");
		      int N = InputUtils.inputs[0][0];
		      int J = InputUtils.inputs[0][1];
		      
		      int howMany = 0;
		      
		      for(int i = 0; i < 99999; i++){
		    	  String padding = "00000000000000";
		    	  boolean primeAlert = false;
		    	  
		    	  String result = padding + Long.toBinaryString(i);
		    	  result = "1" + result.substring(result.length() - 14, result.length()) + "1";
		    	  String lineString = result;
		    	  
		    	  for(int base = 2; base <= 10; base++){
		    	  double number = 0;
		    	  int k = result.length() - 1;
		    	  for (char ch : result.toCharArray()) {
		    		  if(ch == '1'){
		    			  number += Math.pow(base, k);
		    		  }
		    		  k--;
		    	  }
		    	  double divisor = isPrime(number);
		    	  if(divisor > 0){
		    		  lineString = lineString + " " + df.format(divisor);
		    	  }else{
		    		  primeAlert = true;
		    		  break;
		    	  }
		    	 
		    	  }
		    	  
		    	  if(!primeAlert){
		    		  solutionList.add(lineString);
		    		  howMany++;
		    		  if(howMany >= J) break;
		    	  }
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

