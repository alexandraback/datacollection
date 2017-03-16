

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


/**
 * 
 * @author ralf
 *
 */
public class TaskC {
    
	int nCoins;
	int nDigits;
	
	String newLine = System.getProperty("line.separator");
    
    public TaskC(Scanner input) {
        nDigits = input.nextInt();
        nCoins = input.nextInt();
    }
    
    public String solve() {
    	if (nDigits == 16) {
    		return solve16();
    	} else {
    		return solve32();
    	}
    }
    
    public String solve16() {
        String divisor = "100000001";
        StringBuilder divisors = new StringBuilder();
        for (int radix=2; radix<=10; radix++) {
        	divisors.append(" ").append(inRadix(divisor, radix));
        }
        
        StringBuilder result = new StringBuilder();
        for (int c=0; c<nCoins; c++) {
            result.append(newLine);
        	long binaryCoin = 0x8181 + 0x101 * 2 * c;
        	String coin = Long.toBinaryString(binaryCoin);
        	result.append(coin).append(divisors);
        }
        
        return result.toString();
    }
    
    public String solve32() {
        String divisor = "10000000000000001";
        StringBuilder divisors = new StringBuilder();
        for (int radix=2; radix<=10; radix++) {
        	divisors.append(" ").append(inRadix(divisor, radix));
        }
        
        StringBuilder result = new StringBuilder();
        for (int c=0; c<nCoins; c++) {
            result.append(newLine);
        	long binaryCoin = 0x80018001L + 0x10001 * 2 * c;
        	String coin = Long.toBinaryString(binaryCoin);
        	result.append(coin).append(divisors);
        }
        
        return result.toString();
    }
    
    BigInteger inRadix(String digits, int radix) {
    	return new BigInteger(digits, radix);
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("data/C.in"));
        PrintWriter writer = new PrintWriter("data/C.out");
        int nTests = scanner.nextInt();
        for (int i=1; i<=nTests; i++) {
            TaskC task = new TaskC(scanner);
            StringBuilder builder = new StringBuilder();
            String result = task.solve();
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
