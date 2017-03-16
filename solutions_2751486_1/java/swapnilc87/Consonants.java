import java.util.Scanner;


public class Consonants {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		
		String consonants = "bcdfghjklmnpqrstvwxyz";
		int n;
		Scanner scanner = new Scanner(System.in);
		int noOfTestCases = scanner.nextInt();
		for (int k = 0; k < noOfTestCases; k++) {
			String input="";
			long count=0;
			input = scanner.next();
			n = scanner.nextInt();
			
			int windowStart=0;
			int maxMatched = 0;
			for(int j=0;j<input.length();j++) {
				Character c = input.charAt(j);
				if(isConsonent(c)) {
					maxMatched+=1;
				}else {
					maxMatched=0;
				}
				
				if(maxMatched==n) {
					count+= getNoOfSubStrings(j,n,windowStart,input.length());
					windowStart = j-n+2;
					maxMatched = maxMatched -1;
					
				}
			}
			
			System.out.print("\nCase #"+(k+1)+": "+count);
		}
	

	}

	private static long getNoOfSubStrings(int j, int n, int windowStart,
			int length) {
		long possibleEndingChars = length-j;
		long possiblestartingChars = (j-windowStart+1)-n+1;
		return possiblestartingChars*possibleEndingChars;
	}

	public static boolean isConsonent(Character s) {
		
		if("aeiou".indexOf(s)>=0) {
			return false;
		}else {
			return true;
		}
	}
}
