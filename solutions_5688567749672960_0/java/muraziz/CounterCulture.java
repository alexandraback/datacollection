import java.util.Scanner;

public class CounterCulture {
	private static int maxDigits = 16;
    private static long[] start = new long[maxDigits];
    private static long[] end = new long[maxDigits];
    private static long[] count = new long[maxDigits];

    public static void main(String[] args) {
    	Scanner scan = new Scanner(System.in);
    	int T = scan.nextInt();
   		precomputeDigits();
    	for (int t=0; t<T; t++) {
    		long n = scan.nextLong();
    		long out;
    		if (n % 10 == 0) {
    			out = 1 + solve(n-1);
    		} else {
    			out = solve(n);
    		}
    		print(t+1, out);
    	}
    }

    private static void precomputeDigits() {
    	start[1] = 1;
    	end[1] = 9;
    	count[1] = 9;
    	for (int i=2; i<maxDigits; i++) {
    		char[] digits = new char[i];
    		digits[0] = '1';
    		int j=i-1;
    		for (int k=0; k<i/2; k++) {
    			digits[j] = '9';
    			j--;
    		}
    		for (int k=1; k<=j; k++) {
    			digits[k] = '0';
    		}
    		//System.out.println("<pre> i="+i+", digits="+(new String(digits)));
    		start[i] = Long.valueOf(new String(digits));
    		reverse(digits);
    		end[i] = Long.valueOf(new String(digits));
    		count[i] = 1 + start[i] - end[i-1] + count[i-1];
    		//System.out.println("i="+i+", start="+start[i]+", end="+end[i]+", count="+count[i]);
    	}
    }

    private static void reverse(char[] digits) {
    	int len = digits.length;
    	for (int i=0; i<len/2; i++) {
    		char temp = digits[i];
    		digits[i] = digits[len-i-1];
    		digits[len-i-1] = temp;
    	}
    }

    private static long reverse(long input) {
    	char[] chars = Long.toString(input).toCharArray();
    	reverse(chars);
    	return Long.valueOf(new String(chars));
    }

    private static void print(int caseNo, long n) {
    	System.out.println("Case #"+caseNo+": "+n);
    }

    private static long solve(long n) {
    	if (n <= 19) {
    		return n;
    	} else {
    		long totalCount = 0;
    		int digitCount = (int)Math.log10(n)+1;
    		//System.out.println("n="+n+", digitCount="+digitCount);
    		long maxNumberOfDigits = 1;
    		for (int i=0; i<digitCount-1; i++) {
    			maxNumberOfDigits *= 10;
    		}
    		totalCount = count[digitCount-1] + maxNumberOfDigits-end[digitCount-1];
    		//System.out.println("maxNumberOfDigits="+maxNumberOfDigits+", count[digitCount-1]="+count[digitCount-1]+", end[digitCount-1]="+end[digitCount-1]
    		//	+", totalCount="+totalCount);

    		return adjust(digitCount, n, maxNumberOfDigits, totalCount);	
    	}
    }

    private static long adjust(int digitCount, long n, long maxNumberOfDigits, long totalCount) {
    	String nToString = Long.toString(n);
    	long additional = reverse(Long.valueOf(nToString.substring(0, digitCount/2)));
    	maxNumberOfDigits += additional;
    	totalCount += additional;
    	long reversedMaxNumberOfDigits = reverse(maxNumberOfDigits);
    	//System.out.println("additional="+additional+", maxNumberOfDigits="+maxNumberOfDigits+", reversedMaxNumberOfDigits="+reversedMaxNumberOfDigits);
    	if (maxNumberOfDigits != reversedMaxNumberOfDigits) {
	    	totalCount += 1;
    	}
    	totalCount += n - reversedMaxNumberOfDigits;
    	return totalCount;
    }
}