import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;


public class RecycledNumbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		BufferedReader inFile = null;
		try {
			inFile = new BufferedReader(
				    new InputStreamReader(
				        new BufferedInputStream(new FileInputStream("C-small-attempt1.in")),
				        "UTF-8"
				    )
				);
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		int numCases = 0;
		List<Integer> recycledNumbersPerCase = new ArrayList<Integer>();
		try {
			numCases = Integer.parseInt(inFile.readLine());
			for (int caseNum = 0; caseNum < numCases; caseNum++) {	
				
				String[] words = inFile.readLine().split(" ");
				long A = Integer.parseInt(words[0]);
				long B = Integer.parseInt(words[1]);
				
				int numDigits = (int) Math.ceil(Math.log10(A+1));
				// make sure A doesn't start with leading 0
				int numDigitsB = (int) Math.ceil(Math.log10(B));
				numDigits = (numDigits > numDigitsB) ? numDigits : numDigitsB;
				
				int matchedRecycledNumbers = 0;
				
				for (long n = A; n < B-1; n++) {
					/*
					 * rotate digits and look for all the numbers
					 * bigger than original number and in given interval 
					 */
					long rotatedNum = n;
					while(true) {
						rotatedNum = rotateDigitsRight(rotatedNum, numDigits);
						if (rotatedNum == n) break;
						
						if(rotatedNum < A || B < rotatedNum) continue;
						if(rotatedNum < n) continue; // don't count twice
						
						// number is in interval
						matchedRecycledNumbers++;
					}
					
				}
				recycledNumbersPerCase.add(matchedRecycledNumbers);	
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		try {
			BufferedWriter bw = new BufferedWriter(
					new OutputStreamWriter(
							new FileOutputStream("C-small1.out.txt"), "UTF-8"
							)
					);
			
			for (int caseNum = 0; caseNum < numCases; caseNum++) {
				bw.append("Case #" + (caseNum+1) + ": " + recycledNumbersPerCase.get(caseNum));				
				bw.newLine();
			}
			bw.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	
	}

	private static long rotateDigitsRight(long number, int numDigits) {
		long biggerRightPart = number / 10;
		long transferingRightmostNum = number % 10;
		long result = (transferingRightmostNum * (int) Math.pow(10, numDigits-1)) + biggerRightPart;
		return result;
		
	}

}
