import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.Hashtable;
import java.util.Arrays;

import com.sun.xml.internal.bind.v2.runtime.unmarshaller.IntArrayData;



public class Recycler {
	
	private static int transpose(int num, int numDigits) { 
		//System.out.println("Input number " + num);
		//System.out.println("Number digits to be transposed " + numDigits);
		String inputString = Integer.toString(num);
		String truncatedString1 = inputString.substring(0,inputString.length()-numDigits);
		//System.out.println("Truncated String1 " + truncatedString1);
		String truncatedString2 = inputString.substring(inputString.length()-numDigits);
		//System.out.println("Truncated String2 " + truncatedString2);
		//System.out.println("Output string " +  truncatedString2 + truncatedString1);
		return Integer.valueOf(truncatedString2 + truncatedString1);
		
	}

	public static void main(String[] args) throws IOException{
		
		/* transpose(3234,2);
		transpose(323423242,5);
		transpose(100,1); */
		
 		 if (args.length != 1) {
			System.out.println("Error: incorrect number of arguments.");
			System.out.println("Usage: Recycler <input-filename>");
		} else {
			BufferedReader inputStream = null;
			try {
				 inputStream = new BufferedReader(new FileReader(args[0]));
				 int totalCases = Integer.valueOf(inputStream.readLine()).intValue();
				 //System.out.println("Total number of cases is: "+totalCases);
				 for (int i=0;i<totalCases;i++) {
					System.out.print("Case #"+(i+1)+": ");
					String numbersLine = inputStream.readLine();
					//System.out.println("Numbers line is: "+numbersLine);
					String[] theNumbers = numbersLine.split(" ");
					int lower = Integer.valueOf(theNumbers[0]);
					int higher = Integer.valueOf(theNumbers[1]);
					//System.out.println("Lower number is " +  theNumbers[0]);
					//System.out.println("Higher number is " +  theNumbers[1]);
					int numDigits = Integer.toString(lower).length();
					int output=0;
					Set<String> done = new HashSet<String>();
					for (int l=1;l<numDigits;l++) {
						//each iteration transposes l digits
						for (int k=lower;k<=higher;k++) {
							//System.out.println("Number is " + k);
							//k is the number under consideration;
							
							int otherNumber = transpose(k,l);
							//System.out.println("Other number is " + otherNumber);
							if ((otherNumber>k) &&
								(otherNumber<=higher) &&
								Integer.toString(k).length() == Integer.toString(otherNumber).length() &&
								!done.contains(String.valueOf(new Integer(k)) + String.valueOf(new Integer(otherNumber)))
								) {
								//System.out.println(k+" "+ otherNumber + " Incrementing");
									output++;
									done.add(String.valueOf(new Integer(k)) + String.valueOf(new Integer(otherNumber)));
								}
						}

					}
					System.out.println(output);
				}
			} catch (IOException e) {
				System.out.println("Error in reading file");
			} finally {
				if (inputStream != null) {
					inputStream.close();
				}
			}
		}  
	} 
}