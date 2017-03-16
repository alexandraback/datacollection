import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class R0_3 {
	
	private static final String LOWER_LIMIT = "1";
	//private static final String UPPER_LIMIT = "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	private static final String UPPER_LIMIT = "100000000000000";
	//private static final String UPPER_LIMIT = "10000000000";
	
	private static List<String> squareAndFairs = new ArrayList<String>();
	
	private static String lower = null;
	private static String upper = null;
	
	public static void main(String[] args) {
		
		try {
		
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			
			int T = Integer.parseInt(bf.readLine());
			
			int minDigits = (LOWER_LIMIT.length() + 1) / 2;
			int maxDigits = (UPPER_LIMIT.length() + 1) / 2;
			
			for (int j=minDigits; j<= maxDigits; j++) {
				calculateSquareAndFairs(j);
			}
			
			for (int i=0; i<T; i++) {
				
				String[] strTemp = bf.readLine().split(" ");
				
				lower = strTemp[0];
				upper = strTemp[1];
				
				int squareFairCount = 0;
				
				for (int j=0; j<squareAndFairs.size(); j++) {
					
					String sqr = squareAndFairs.get(j);
					if (	( sqr.length() > lower.length() ||  
							  (sqr.length() == lower.length() && sqr.compareTo(lower) >= 0)
							) && 
							( sqr.length() < upper.length() ||
							  (sqr.length() == upper.length() && sqr.compareTo(upper) <= 0)
							)
						) {
						squareFairCount++;
					}
					
				}
				
				
				System.out.println("Case #" + (i+1) + ": " + squareFairCount);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private static String square(String number) {
		
		String numSqr = "";
		int len = number.length();
		int carry = 0;
		int sum = 0;

		for (int i=2*len; i>=1; i--) {

			sum = 0;
			for (int j=len; j>=1; j--) {
				int mult = 0;
				for (int k=len; k>=j; k--) {
					if (i == (j+k)) {
						mult = Integer.parseInt(number.substring(j-1, j)) * Integer.parseInt(number.substring(k-1, k));
						if (j != k) mult = 2 * mult;
						break;
					}
				}
				sum += mult; 
			}
			
			sum += carry;
			
			numSqr = sum%10 + numSqr;
			carry = sum / 10;
			
		}
		
		if (numSqr.charAt(0) == '0') numSqr = numSqr.substring(1);
		
		return numSqr;
		
	}
	
	private static void calculateSquareAndFairs(int digits) {
		
		for (int i=1; i<=9; i++) {
			if (!hasSquareAndFairs(i + "", digits)) break; 
		}
		
	}
	
	private static boolean hasSquareAndFairs(String startWith, int digits) {
		
		boolean retVal = false;
		
		if (startWith.length() == ((digits + 1) / 2)) {
			String endWith = "";
			for (int i=1; i<=digits/2; i++)
				endWith = startWith.substring(i-1, i) + endWith;
			
			String number = startWith + endWith;
			String sqr = square(number);
			if (isPalindrome(sqr)) {
				retVal = true;
				if (	( sqr.length() > LOWER_LIMIT.length() ||  
						  (sqr.length() == LOWER_LIMIT.length() && sqr.compareTo(LOWER_LIMIT) >= 0)
						) && 
						( sqr.length() < UPPER_LIMIT.length() ||
						  (sqr.length() == UPPER_LIMIT.length() && sqr.compareTo(UPPER_LIMIT) <= 0)
						)
					) {
					squareAndFairs.add(sqr);
					//System.out.println(squareAndFairs.size() + ":" + number + ":" + sqr );
				}
			}
		} else {
			
			for (int i=0; i<=9; i++) {
				if (hasSquareAndFairs(startWith + i, digits))
					retVal = true;
				else break;
			}
			
			
		}

		return retVal;
	}
	
	private static boolean isPalindrome (String str) {
		
		for (int i=0; i<str.length()/2; i++) {
			if (str.charAt(i) != str.charAt(str.length() - i -1))
				return false;
		}
		
		return true;
		
		
	}
	
	
}
