

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


/**
 * 
 * Add a digit: have all 9s, increment gives one 1, then 0s
 * Reach all 9s from 10000: increment 99 times, swap, increment 998 times
 * Reach abdef from 10000: increment ba times, swap, increment (def-1) times
 *     (special case ba = 01: increment def times)
 * If tail half is zeroes, solve n-1, increment
 * abd00 from 10000: inc ba times (100ba), swap (ab001), inc (d00-1) times
 * 
 * 
 * @author ralf
 *
 */
public class A_CounterCulture {
	
	static long[] EXP10 = { 1, 
		10L, 
		100L, 
		1000L, 
		10000L, 
		100000L, 
		1000000L,
		10000000L,
		100000000L,
		1000000000L,
		10000000000L,
		100000000000L,
		1000000000000L,
		10000000000000L,
		100000000000000L,
		1000000000000000L,
		10000000000000000L,
		100000000000000000L,
		1000000000000000000L
	};
    
	long n;
    
    public A_CounterCulture(Scanner input) {
        n = input.nextLong();
    }
    
    public long solve() {
        return reach(n);
    }
    
    // from n-digits number 10...0
    private long reach9(int nDigits) {
    	if (nDigits == 1) {
    		return 8;
    	}
    	int lowerDigits = nDigits / 2;
    	int upperDigits = nDigits - lowerDigits;
    	long result = EXP10[upperDigits] - 1 + 1 + EXP10[lowerDigits] - 2;
		return result;
    }
    
    private long reach(long target) {
    	String digits = String.valueOf(target);
    	int nDigits = digits.length();
    	if (nDigits == 1) {
    		return target;
    	}
    	int upperDigits = nDigits / 2;
    	long lowerNum = Long.parseLong(digits.substring(upperDigits));
    	if (lowerNum == 0L) {
    		return reach(target-1) + 1;
    	}
    	long upperNumRev = Long.parseLong(reverse(digits.substring(0, upperDigits)));
    	long result = 1;
    	for (int i=1; i<nDigits; i++) {
    		result += reach9(i);
    		result ++;
    	}
    	if (upperNumRev == 1) {
    		result += lowerNum;
    	} else {
    		result += upperNumRev + lowerNum;
    	}
    	return result;
    }

    private String reverse(String in) {
    	StringBuilder result = new StringBuilder();
    	for (int i=in.length()-1; i>= 0; i--) {
    		result.append(in.charAt(i));
    	}
    	return result.toString();
    }
    
    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("data/A.in"));
        PrintWriter writer = new PrintWriter("data/A.out");
        int nTests = scanner.nextInt();
        for (int i=1; i<=nTests; i++) {
            A_CounterCulture task = new A_CounterCulture(scanner);
            StringBuilder builder = new StringBuilder();
            long result = task.solve();
            builder.append("Case #" + i + ": ").append(result);
            
            writer.println(builder);
            System.out.println(builder);
        }
        scanner.close();
        writer.close();
        long finish = System.currentTimeMillis();
        System.out.println("Time=" + (finish - start) + "ms");
    }
    
}
