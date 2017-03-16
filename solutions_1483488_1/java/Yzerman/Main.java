import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("c:\\input.txt")));
		int cases = Integer.parseInt(reader.readLine());
		for(int i=0; i<cases; i++){
			String inputString = reader.readLine();		
			StringTokenizer st = new StringTokenizer(inputString);
			
			int numOfRecycledPairs = 0;
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			int numOfDigits = Integer.toString(A).length();
			
			HashSet<Integer> processedNumber = new HashSet<Integer>();
			//System.out.println(A + " " + B);
			for(int a=A; a<=B; a++) {

				if(processedNumber.contains(a) || isAllTheSameDigits(a))
					continue;

				
				processedNumber.add(a);
				int eligibleNumbers = 1;
				int numberToProcessed = a;
				//System.out.print("numberToProcessed:" + numberToProcessed +",");
				for(int j=0; j<numOfDigits-1; j++) {
					numberToProcessed = shift(numOfDigits, numberToProcessed);
					//System.out.print("numberToProcessed:" + numberToProcessed);
					if(isCandidate(A, B, processedNumber, numberToProcessed)) {
						processedNumber.add(numberToProcessed);
						++eligibleNumbers;
					}
				}
				//System.out.println("");
				
				numOfRecycledPairs += (eligibleNumbers*(eligibleNumbers-1)/2);
				
			}
			
			System.out.println("Case #"+(i+1)+": "+numOfRecycledPairs);
		}

	}
	
	public static boolean isAllTheSameDigits(int number) {
		String sNumber = Integer.toString(number);
		char digits[] = sNumber.toCharArray();
			
		char significatDigits = digits[0];
		for(int i=1; i<digits.length; i++) {
			if(digits[i]!= significatDigits )
				return false;
		}
		return true;
	}
	
	public static int shift(int numOfDigits, int number) {
		return (int)((number%10)*Math.pow(10, numOfDigits-1)) + number/10;
	}
	
	public static boolean isCandidate(int A, int B, HashSet<Integer> processedNumber, int number) {
		if(number >=A && number <=B && !processedNumber.contains(number))
			return true;
		else
			return false;
	}

}
