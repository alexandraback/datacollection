import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;

/**
 * 
 */

/**
 * @author Bryan
 *
 */
public class problemB {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String filePath = "/Users/Bryan/Documents/CodeJam/ProblemB/B-small-attempt0.in";
		boolean isFirstLine = true;
		int counter = 1;
		StringBuffer resultString = new StringBuffer();
		
		try {
			// Open the file that is the first
			// command line parameter
			FileInputStream fstream = new FileInputStream(filePath);
			// Get the object of DataInputStream
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			// Read File Line By Line
			while ((strLine = br.readLine()) != null) {
				if (isFirstLine){
					isFirstLine = false;
					continue;
				}
				int maxNoGoogler = 0;
				
				resultString.append("Case #" + counter + ": ");
				String[] numberList = strLine.split(" ");
				int noOfGoogler = Integer.parseInt(numberList[0]);
				int noOfSuprise = Integer.parseInt(numberList[1]);
				int individualTarget = Integer.parseInt(numberList[2]);
//				ArrayList<Integer> totalScoreList = new ArrayList<Integer>();
				for ( int a = 3; a < numberList.length; a++){
//					totalScoreList.add(Integer.parseInt(numberList[a]));
					if ( Integer.parseInt(numberList[a]) >= miniTotal(noOfGoogler, individualTarget) ){
						maxNoGoogler++;
					}else if ( noOfSuprise > 0 && Integer.parseInt(numberList[a]) >= miniTotalWithSuprise(noOfGoogler, individualTarget) ){
						noOfSuprise--;
						maxNoGoogler++;
					}
				}
				
				resultString.append(maxNoGoogler);
				resultString.append("\n");
				counter++;
			}
			// Close the input stream
			in.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
		
		writeStringToFile(resultString.toString());


	}
	
	private static int miniTotalWithSuprise(int noOfGoogler, int individualTarget){
		int min = (3 * individualTarget) - (2 * (3 - 1));
		
		if ( min < individualTarget){
			return individualTarget;
		}
		
		return min;
	}
	
	private static int miniTotal(int noOfGoogler, int individualTarget){
		int min = (3 * individualTarget) - (3 - 1);
		if ( min < individualTarget){
			return individualTarget;
		}
		return min;
	}
	
	private static void writeStringToFile(String outputString) {
		try {
			// Create file
			FileWriter fstream = new FileWriter("/Users/Bryan/Documents/CodeJam/ProblemB/output.txt");
			BufferedWriter out = new BufferedWriter(fstream);
			out.write(outputString);
			// Close the output stream
			out.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}

}
