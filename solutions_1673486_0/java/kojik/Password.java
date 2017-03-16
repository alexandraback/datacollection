import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Iterator;


public class Password {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		long time = System.currentTimeMillis();
		File iFile = new File("A-large-practice.in");
		BufferedReader in= new BufferedReader(new FileReader(iFile));
		
		File oFile = new File("A-large-practice.out");
		FileOutputStream fos = new FileOutputStream(oFile);
		BufferedOutputStream bos = new BufferedOutputStream(fos);
		PrintStream out = new PrintStream(bos);
		
		int numTest = Integer.parseInt(in.readLine());
		
		for(int testNo=1; testNo<=numTest; testNo++){
			String[] numCharStrings = in.readLine().split(" ");
			
			int lengthTyped = Integer.parseInt(numCharStrings[0]);
			int lengthPass = Integer.parseInt(numCharStrings[1]);
			
			String[] probabRightStrings = in.readLine().split(" ");
			double[] probabRight = new double[lengthTyped];
			for(int i=0; i<lengthTyped; i++){
				probabRight[i] = Double.parseDouble(probabRightStrings[i]);
			}
			
			/*
			 * options are:  
			 * 0) enter, and retype
			 * 1) backspace 0 time (i.e. keep typing  
			 * 2) backspace 1 time
			 * 3) backspace 2 times
			 * ...
			 * 1+lengthTyped) backspace lengthTyped times
			 */
			double[] expectedStrokes = new double[2+lengthTyped];
			
			//if i enter and retype
			expectedStrokes[0] = 1+lengthPass+1;
			
			//if i backspace...
			for(int numBackspace = 0; numBackspace <= lengthTyped; numBackspace++){
				expectedStrokes[1+numBackspace] = 0;
				for(int numWrong=0; numWrong<=(lengthTyped-numBackspace); numWrong++){
					String[] perms = getPossiblePermutations(numWrong, (lengthTyped-numBackspace));
					
					for(String perm: perms){
						double thisProb = 1;
						for(int charIndex=0; charIndex<(lengthTyped-numBackspace); charIndex++){
							if(perm.charAt(charIndex)=='1'){
								thisProb *= (1-probabRight[charIndex]);
							}else{
								thisProb *= probabRight[charIndex];
							}
						}
						
						double thisNumNeeded = numBackspace*2 + lengthPass - lengthTyped +1;
						if(numWrong!=0){
							thisNumNeeded += lengthPass + 1;
						}
						
						expectedStrokes[1+numBackspace] += thisProb*thisNumNeeded;
					}
				}
			}
			
			double minExpected = Double.MAX_VALUE;
			for(double expected: expectedStrokes){
				if(expected < minExpected){
					minExpected = expected;
				}
			}
			
			System.out.println("Case #"+testNo+": "+ minExpected);
			out.println("Case #"+testNo+": "+ minExpected);
		}
			
		
		
		long duration = System.currentTimeMillis() - time;
		System.out.println(duration+"ms taken");
		out.close();
	}
	
	
	private static String[] getPossiblePermutations(int numWrong, int length){
		if(numWrong==0){
			String onlyAnswer = "";
			for(int i=0; i<length; i++){
				onlyAnswer += "0";
			}
			return new String[]{onlyAnswer};
		}
		
		if(numWrong > length){
			return null;
		}
		
		//if the first one is 0.
		String[] result0 = getPossiblePermutations(numWrong, length-1);
		if(result0 != null){
			for(int i=0; i<result0.length; i++){
				result0[i] = "0"+result0[i];
			}
		}
		//if the first one is 1.
		String[] result1 = getPossiblePermutations(numWrong-1, length-1);
		for(int i=0; i<result1.length; i++){
			result1[i] = "1"+result1[i];
		}
		
		String[] result;
		if(result0 != null){
			result = new String[result0.length+result1.length];
			for(int i=0; i<result0.length; i++){
				result[i] = result0[i];
			}
			for(int i=result0.length; i<result.length; i++){
				result[i] = result1[i-result0.length];
			}
		}else{
			result = new String[result1.length];
			for(int i=0; i<result1.length; i++){
				result[i] = result1[i];
			}
		}
		return result;
	}
	
}
