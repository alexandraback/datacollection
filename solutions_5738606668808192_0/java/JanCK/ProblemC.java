package jck.codejam.cj2016.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Arrays;
import java.util.Locale;

public class ProblemC {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// String filenameInput = "C-sample.in";
		// String filenameOutput = "C-sample.out";
		//String filenameInput = "C-small-attempt1.in";
		String filenameOutput = "C-small-attempt1.out";
		int lengthOfCoinJam = 16;
		int J = 50;
		//		 String filenameInput = "C-large.in";
//		int length = 32;
//		int J = 500;
		//		 String filenameOutput = "C-large.out";

		Class currentClass = ProblemC.class;
		try {

			String path = "src/"
					+ currentClass.getPackage().getName().replace(".", "/");
			BufferedWriter output = new BufferedWriter(new FileWriter(new File(
					path + "/" + filenameOutput)));
			int numOfTestcases = 1;
			System.out.println("Number of Testcases: " + numOfTestcases);
			
			int found = 0;
			int maximumTries = 50000;
			int counterOfTries = 0;
			long innerNMinus2Digits = 0;
			boolean[] coinJamCandidate = new boolean[lengthOfCoinJam];
			String additionalOutput = "";
			String currentNumberToBaseTen = "";
			while(found < J && counterOfTries < maximumTries ){
				System.out.println("counterOfTries" + counterOfTries);
				counterOfTries++;
				coinJamCandidate[0] = true;
				coinJamCandidate[lengthOfCoinJam-1] = true;
				
			    for (int i = lengthOfCoinJam-3; i >= 0; i--) {
			    	coinJamCandidate[i+1] = (innerNMinus2Digits & (1 << i)) != 0;
			    }
				
			    System.out.println("current array of booleans " + Arrays.toString(coinJamCandidate));
			    boolean isDivisbleInAllBases = true;
			  
			    long[] divisor = new long[9];
			    for(int base = 2;base<=10 && isDivisbleInAllBases ;base++){
			    	long numberForThisBase = 0;
			    	long baseToThePowerDigit = 1L;
			    	for(int digit = 0;digit<lengthOfCoinJam;digit++){
			    		if(coinJamCandidate[digit]){
			    			numberForThisBase += baseToThePowerDigit;
			    		}
			    		baseToThePowerDigit *= base; 
			    	}
			    	System.out.println("base is " + base + " number is " + numberForThisBase);
			    	divisor[base-2] = getDivisor(numberForThisBase);
			    	if(divisor[base-2] == 0){
			    		isDivisbleInAllBases = false;
			    	}else{
			    		if(base == 10){
			    			currentNumberToBaseTen = ""+numberForThisBase;
			    		}
			    	}
			    }
			    if(isDivisbleInAllBases){
			    	//found a coinJam
			    	found++;
			    	System.out.println("found coinjam "+ found + " it is: " + Arrays.toString(coinJamCandidate));
			    	additionalOutput += currentNumberToBaseTen;
			    	for(int base = 2;base<=10 && isDivisbleInAllBases ;base++){
			    		additionalOutput += " " + divisor[base-2];
			    	}
			    	additionalOutput  += "\n";
			    	
			    }

			    
				innerNMinus2Digits++;

			}

				String outputString = "Case #" + (1) + ":\n" + additionalOutput;
				System.out.println(outputString);

				output.write(outputString);

			

			output.flush();
			output.close();
		}catch(

	FileNotFoundException e)
	{
		// TODO Auto-generated catch block
		e.printStackTrace();
	}catch(
	IOException e)
	{
		// TODO Auto-generated catch block
		e.printStackTrace();
	}

	}

	private static long getDivisor(long num) {
        if (num < 2) return 0;
        if (num == 2) return 0;
        if (num % 2 == 0) return 2;
        for (long i = 3; i * i <= num; i += 2)
            if (num % i == 0) return i;
        return 0;
}
}
