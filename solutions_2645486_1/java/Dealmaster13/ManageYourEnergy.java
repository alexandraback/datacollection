package round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class ManageYourEnergy {

	private static BufferedReader br;
	private static BufferedWriter bw;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			// Open input file.
			br = new BufferedReader(new FileReader("input.in"));
			
			// Open output file.
			bw = new BufferedWriter(new FileWriter("output.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		} catch (IOException e) {
			e.printStackTrace();
		}

		try {
			// Initialise input and read number of cases.
			int testCases = Integer.parseInt(br.readLine());

			// For each test case.
			analyseTestCases(testCases);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		finally {
			try {
				br.close();
				bw.flush();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	private static void analyseTestCases(int testCases) throws IOException {
		for (int i = 1; i <= testCases; i++) {
			String input = br.readLine();
			
			String[] inputValues = input.split(" ");

			long maxE = Integer.parseInt(inputValues[0]);
			long e = maxE;
			long r = Integer.parseInt(inputValues[1]);
			//long n = Integer.parseInt(inputValues[2]);
			
			long[] activityValues = HelperFunctions.stringToLongArray(br.readLine().split(" "));
			
			long gain = 0;
			
			int index = 0;
			
			while (index < activityValues.length) {
				//long timeToMaxE = (maxE - e + r) / r;
				long timeToMaxE = (maxE + r) / r;
				
				int nextIndex = index;
				
				int j = index + 1;

				//while ((j < index + timeToMaxE) && (j < activityValues.length)) {
				while ((j <= index + timeToMaxE) && (j < activityValues.length)) {
					if (activityValues[j] > activityValues[nextIndex]) {
						nextIndex = j;
						
						break;
					}
					
					j ++;
				}
				
				long steps = nextIndex - index;
				
				long energyToSpend;
				
				if (nextIndex == index) {
					energyToSpend = e;
					
					nextIndex ++;
					steps ++;
				}
				else {
					energyToSpend = Math.min(e, Math.max(0, (e + steps * r) - maxE));
				}
				
				e -= energyToSpend;
				gain += activityValues[index] * energyToSpend;
				
				e = Math.min(maxE, e + r);
				
				index ++;
			}
			
			write("Case #" + i + ": " + gain + "\n");
		}
	}
	
	private static void write(String s) {
		try {
			bw.write(s);
			System.out.print(s);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
