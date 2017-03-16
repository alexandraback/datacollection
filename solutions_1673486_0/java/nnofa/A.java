import java.io.*;
import java.util.*;
public class A{
	public static void main(String[] args){
	  try{
		String inputFile = "A-small-attempt0.in";
		String outputFile = "A-small-attempt0.out";
		Scanner sc = new Scanner(new File(inputFile));
        FileWriter fwStream = new FileWriter( outputFile );
        BufferedWriter bwStream = new BufferedWriter( fwStream );
        PrintWriter pwStream = new PrintWriter( bwStream );
		int numCase = sc.nextInt();
		for(int i = 0; i < numCase; i++){
			
			double answer = -1;
			int numTyped = sc.nextInt();
			int totalNum = sc.nextInt();
			double[] prob = new double[numTyped];
			for(int j = 0; j < numTyped; j++){
				prob[j] = sc.nextDouble();
			}
			for(int numBackspace = 0 ; numBackspace <= numTyped; numBackspace++){
				double rightProbability = 1;
				for(int j = 0; j < numTyped - numBackspace; j++){
					rightProbability *= prob[j];
				}
				double expected = (rightProbability * (totalNum - numTyped + (2*numBackspace) + 1)) + ((1-rightProbability) * (totalNum + totalNum - numTyped + (2*numBackspace) + 2));
				System.out.println("expected = " + expected);
				//2 is for enter
				if(answer == -1) answer = expected;
				else if(expected < answer) answer = expected;
			}
			
			// case if enter
			double expected = 2 + totalNum;
			if(expected < answer) answer = expected;
			pwStream.printf("Case #"+(i+1)+ ": %.6f", answer);
			pwStream.println();
		}
		pwStream.close();
		sc.close();
		}
	  catch(Exception e){e.printStackTrace();}
	}
	
}