import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;


public class Main {
	
	
	public static void main (String[] args) {
		
		BufferedReader br;
		try {
			File outputFile = new File("src/outputSmall2.txt");
			// if file doesnt exists, then create it
			if (!outputFile.exists()) {
				outputFile.createNewFile();
			}
			FileWriter fw = new FileWriter(outputFile.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			br = new BufferedReader(new FileReader("src/A-small-attempt2.in"));

			String line = br.readLine();
			
			int numberOfTestCase = Integer.parseInt(line);
			for (int i = 0; i < numberOfTestCase; i++) {
				int numberOfSteps = 0;
				boolean notEnd = true;
				
				System.out.println("Round " + i);
				String line1 = br.readLine();
				String motesLine = br.readLine();
				
				ArrayList<Integer> motes = new ArrayList<Integer>();
				
				int A = Integer.parseInt(line1.split(" ")[0]);
				int N = Integer.parseInt(line1.split(" ")[1]);
				int worstCase = N;
				
				for (int j = 0; j < N; j++) {
					motes.add(Integer.parseInt(motesLine.split(" ")[j]));
				}

				
				while (motes.size() > 0 && notEnd) {
				
					int smallest = findSmallest(motes);
					if (A > smallest) {
						A += smallest;
						motes.remove(new Integer(smallest));
						System.out.println(motes.size());
					} else {
						if (motes.size() == 1) {
							numberOfSteps++;
							break;
						}
						int lessThanA= A - 1;
						A += lessThanA;
						numberOfSteps++;
						if (numberOfSteps == worstCase) {
							break;
						}
//						// compare the number of elements left and number of steps to add
//						
//						// number of elements left
//						int numberOfMotesLeft = motes.size();
//						int temp = smallest;
//						for (int j = 0; j < numberOfMotesLeft - 1; j++) {
//							if (temp % 2 != 0) { // odd
//								temp = (temp + 1)/2;
//							} else { // even
//								temp = (temp + 2)/2;
//							}
//						}
//						if (temp > A) {
//							numberOfSteps += motes.size();
//							break;
//						}

					}
					
				}

//				System.out.println("smallest: " + smallest);
//				System.out.println(motes.size());
				
				
				
				
				int caseNumber = i + 1;
				bw.write("Case #" + caseNumber + ": " + numberOfSteps);
				bw.newLine();
			}
			bw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static int findSmallest (ArrayList<Integer> motes) {
		int i = 0;
	    int min = Integer.MAX_VALUE;

	    while (i < motes.size()) {
	    	if (motes.get(i) < min) {
	    		min = motes.get(i);
	    	}
	    	i++;
	    }

	    return min;
	}
}
