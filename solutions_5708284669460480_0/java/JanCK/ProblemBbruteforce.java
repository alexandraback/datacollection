package nickname.jck.googlecodejam.cj2015.r1c.problemB;

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

public class ProblemBbruteforce {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

//		String filenameInput = "B-sample.in";
//		String filenameOutput = "B-sample.out";
		
		
//		String filenameInput = "B-sampleC.in";
//		String filenameOutput = "B-sampleC.out";
		
		// String filenameInput = "B-small-practice.in";
		// String filenameOutput = "B-small-practice.out";

		 String filenameInput = "B-small-attempt0.in";
		 String filenameOutput = "B-small-attempt0.out";

		// String filenameInput = "B-large.in";
		// String filenameOutput = "B-large.out";

		Class currentClass = ProblemB.class;
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
				int K = Integer.parseInt(inputStringArray[0]);
				int L = Integer.parseInt(inputStringArray[1]);
				int S = Integer.parseInt(inputStringArray[2]);
				String keyboard = input.readLine();
				String target = input.readLine();
				System.out.println("target : " + target);
				System.out.println("keyboard : " + keyboard);

				int maxNumberOfBananas = 0;
				double eBananasToPay = 0.0;

				int overlap = L-1;
				boolean overlapCorrect = false;
				while(!overlapCorrect && overlap > 0){
					String firstPart = target.substring(0, overlap);
					String lastPart = target.substring(L-overlap, L);
//					System.out.println("comparing for overlap size of " + overlap);
//					System.out.println(firstPart + " with");
//					System.out.println(lastPart);
					if(firstPart.equals(lastPart)){
						overlapCorrect = true;
					}else{
						overlap--;
					}
					
					
				}
				System.out.println("overlap found as : " + overlap);
				maxNumberOfBananas = (S-overlap)/(L-overlap);
				System.out.println("maxNumberOfBananas  " + maxNumberOfBananas );
				
				double[] likelyhoodOfCharByPosition = new double[L];
				for (int j = 0; j < L; j++) {
					int numberOfThisChar = 0;
					char targetChar = target.charAt(j);
					for (int k = 0; k < K; k++) {
						if(keyboard.charAt(k) == targetChar){
							numberOfThisChar ++;
						}
					}
					if(numberOfThisChar == 0){
						maxNumberOfBananas = 0;
					}
					likelyhoodOfCharByPosition[j] = ((double) numberOfThisChar) / K;
				}
				System.out.println("likelyhood of chars " + Arrays.toString(likelyhoodOfCharByPosition));
				System.out.println("maxNumberOfBananas corrected " + maxNumberOfBananas );
				
				
				ArrayList<String> allStrings = new ArrayList<String>();
				
				createStrings(0,"",allStrings,S,keyboard);
				
				System.out.println("All possible strings");
//				System.out.println(allStrings.toString());
				
				int totalCount = 0;
				for (String currentString : allStrings) {
					int howOften = howOftenIsSubstringContained(target,currentString);
					totalCount += howOften;
				}
				eBananasToPay = ((double) totalCount)/allStrings.size();
				
				double eTakingBack = maxNumberOfBananas - eBananasToPay;

				String outputString = "Case #" + (i + 1) + ": " + eTakingBack;
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

	private static int howOftenIsSubstringContained(String target,
			String currentString) {
		int count = 0;
		for(int j=0;j<=currentString.length() - target.length();j++){
//			System.out.println("comparing for j = " + j);
//			System.out.println(currentString.substring(j, j+target.length()) + " with");
//System.out.println(target);
			if(currentString.substring(j, j+target.length()).equals(target)){
				count ++;
			}
		}
			
			
			
		return count;
	}

	private static void createStrings(int currentIndex, String currentString,
			List allStrings, int maxSize, String keyboard) {
		if (currentIndex == maxSize - 1) {
			for (int j = 0; j < keyboard.length(); j++) {
				allStrings.add(currentString + keyboard.charAt(j));
			}

		} else {
			for (int j = 0; j < keyboard.length(); j++) {
				createStrings(currentIndex + 1,
						currentString + keyboard.charAt(j), allStrings,
						maxSize, keyboard);
			}
		}
	}
}
