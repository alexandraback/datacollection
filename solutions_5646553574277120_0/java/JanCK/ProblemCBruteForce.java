package nickname.jck.googlecodejam.cj2015.r1c.problemC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ProblemCBruteForce {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

//		String filenameInput = "C-sampleBruteForce.in";
//		String filenameOutput = "C-sampleBruteForce.out";

//		 String filenameInput = "C-small-attempt1.in";
//		 String filenameOutput = "C-small-attempt1.out";
//
		 String filenameInput = "C-small-attempt2.in";
		 String filenameOutput = "C-small-attempt2.out";
//		 
//		 String filenameInput = "C-large.in";
//		 String filenameOutput = "C-large.out";

		Class currentClass = ProblemC.class;
		try {

			String path = "src/"
					+ currentClass.getPackage().getName().replace(".", "/");
			BufferedReader input = new BufferedReader(new FileReader(new File(
					path + "/" + filenameInput)));
			BufferedWriter output = new BufferedWriter(new FileWriter(new File(
					path + "/" + filenameOutput)));
			int numOfTestcases = Integer.parseInt(input.readLine());
			// System.out.println("Number of Testcases: " + numOfTestcases);
			for (int i = 0; i < numOfTestcases; i++) {
				System.out.println("Testnumber : " + i);
				String[] inputStringArray = input.readLine().split(" ");
				int C = Integer.parseInt(inputStringArray[0]);
				int D = Integer.parseInt(inputStringArray[1]);
				int V = Integer.parseInt(inputStringArray[2]);
				
				System.out.println("C" + C + " D " + D + " V  " + V);
				
				String currentString = input.readLine();
				String[] inputStringDenominationsArray = currentString.split(" ");
				int[] denominations = new int[D];
				for(int j =0;j<D;j++){
					denominations[j] = Integer.parseInt(inputStringDenominationsArray [j]);
				}
				
				Arrays.sort(denominations);
				System.out.println(Arrays.toString(denominations));
				int denomsCreated = 0;
				int currentReachableMax = 0;
				List<Integer> additionalDenominations = new ArrayList<Integer>();
				
				
				
				
				int checkWhetherPossible = 1;
				int indexWithinExistingDenominations = 0;
				
				
				while(checkWhetherPossible <= V){
					System.out.println("checkWhetherPossible " + checkWhetherPossible );
					if(indexWithinExistingDenominations<D && denominations[indexWithinExistingDenominations] ==checkWhetherPossible){
						currentReachableMax += denominations[indexWithinExistingDenominations];
						System.out.println("I add the extisting of value " + denominations[indexWithinExistingDenominations]);
						indexWithinExistingDenominations++;
						System.out.println("currentReachableMax " + currentReachableMax);
						checkWhetherPossible ++;
					}else{
						if(currentReachableMax >=checkWhetherPossible ){
							checkWhetherPossible ++;
						}else{
							System.out.println("I add a denom at value " + checkWhetherPossible);
							denomsCreated++;
							currentReachableMax += checkWhetherPossible ;
							System.out.println("currentReachableMax " + currentReachableMax + " denoms added till here "  + denomsCreated);
							checkWhetherPossible ++;
						}
					}
					
				}
				String outputString = "Case #" + (i + 1) + ": " + denomsCreated;
				System.out.println(outputString);
				


				if (i + 1 != numOfTestcases) {
					outputString += "\n";
				}
				output.write(outputString);

			}

			output.flush();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
