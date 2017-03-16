/**
 * 
 */
package codejam2012.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 * @author Jaffar Ramay
 *
 */
public class RecycledNumbers {

	public static void solve() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File("/Users/jaffar_ramay/Workspaces/eclipseWorkspace/Revision/src/codejam2012/qualification/RecycledNumbers.in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("/Users/jaffar_ramay/Workspaces/eclipseWorkspace/Revision/src/codejam2012/qualification/RecycledNumbers.out")));
		String line = null;
		while((line=reader.readLine())!=null){
			int testCases = Integer.parseInt(line);
			for (int i = 1; i <= testCases; i++) {
				String[] testCase = reader.readLine().split(" ");
			     int numberA = Integer.parseInt(testCase[0]);
			     int numberB = Integer.parseInt(testCase[1]);
			     int result = getRecycledCount(numberA, numberB);
			     writer.write("Case #"+i+": "+result);
			     if(i<testCases)
			    	 writer.newLine();
			}
		}
		reader.close();
		writer.close();
	}
	public static int getRecycledCount(int numberA, int numberB) {
		int result=0;
		for (int i = numberA; i <= numberB; i++) {
			
			String number = i+"";
			
			for (int j = 0; j < number.length(); j++) {
				
				int firstNumber = Integer.parseInt(number);
				int index = (number.length()-(j+1));
				if(index>0 && index<number.length()){
					int secondNumber =  (Integer.parseInt(number.substring(index,number.length())+number.substring(0,index)));
					
					if(numberA<=firstNumber && firstNumber<secondNumber && secondNumber<=numberB && (firstNumber+"").length() == (secondNumber+"").length()){
						//System.out.println(firstNumber+" "+secondNumber+" ");
						result++;
					}	
				}
				
			}
			
		}
		return result;
	}
	
	public static void main(String[] args) throws IOException {
		//System.out.println("Result = "+getRecycledCount(1111,2222));
		solve();
	}
}
