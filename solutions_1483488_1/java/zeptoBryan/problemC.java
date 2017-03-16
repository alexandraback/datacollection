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
public class problemC {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String filePath = "/Users/Bryan/Documents/CodeJam/ProblemC/C-large.in";
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
				
				resultString.append("Case #" + counter + ": ");
				String[] numberList = strLine.split(" ");
				int result = 0;
				int min = Integer.parseInt(numberList[0]);
				int max = Integer.parseInt(numberList[1]);
				for ( int a = min; a <= max; a++){
					result = result + noOfPairs(Integer.toString(a),min, max);
//					System.out.println("final result = " + result);
				}
				System.out.println("result = " + result/2);
				
				resultString.append(result/2);
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
	
	private static int noOfPairs(String num,int min, int max){
		int noOfPairs = 1;
		String oldString = num;

		String newString = "";
		String tempString = oldString;
		ArrayList<String> addedList = new ArrayList<String>();
		for ( int counter = 0; counter < oldString.length(); counter++){
			newString= tempString.substring(tempString.length()-1)+tempString.substring(0,tempString.length()-1);
			tempString=newString;
//			System.out.println(newString);
			
			if( !newString.startsWith("0") && Integer.parseInt(newString) <= max
					&&  Integer.parseInt(newString) >= min
					&&  !newString.equalsIgnoreCase(num)
					&& !addedList.contains(newString)){
				addedList.add(newString);
				noOfPairs++;
			}
		}
		if ( noOfPairs == 1 ){
			return 0;
		}
		return noOfPairs - 1;
//		return nCr(noOfPairs,2);
	}
	
	private static void writeStringToFile(String outputString) {
		try {
			// Create file
			FileWriter fstream = new FileWriter("/Users/Bryan/Documents/CodeJam/ProblemC/output.txt");
			BufferedWriter out = new BufferedWriter(fstream);
			out.write(outputString);
			// Close the output stream
			out.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}

}
