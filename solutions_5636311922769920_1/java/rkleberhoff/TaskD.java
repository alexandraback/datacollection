

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


/**
 * 
 * @author ralf
 *
 */
public class TaskD {
    
	long origLength;
	long complexity;
	long maxSamples;
    
    public TaskD(Scanner input) {
        origLength = input.nextLong();
        complexity = input.nextLong();
        maxSamples = input.nextLong();
    }
    
    public String solve() {
    	List<Long> samples = new ArrayList<Long>();
    	for (int d=0; d<origLength; d+=complexity) {
    		samples.add(genSample(d, complexity));
    	}
    	if (samples.size() > maxSamples) {
    		return "IMPOSSIBLE";
    	} else {
    		StringBuilder builder = new StringBuilder();
    		for (int i=0; i<samples.size(); i++) {
    			if (i > 0) {
    				builder.append(" ");
    			}
    			builder.append(1+samples.get(i));
    		}
    		return builder.toString();
    	}
    }
    
    long genSample(long startDigit, long nDigits) {
    	long result = 0L;
    	for (int i=0; i<nDigits; i++) {
    		long digit = startDigit + i;
    		if (digit >= origLength) {
    			digit = 0;
    		}
			result = result * origLength + digit;
    	}
    	return result;
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("data/D.in"));
        PrintWriter writer = new PrintWriter("data/D.out");
        int nTests = scanner.nextInt();
        for (int i=1; i<=nTests; i++) {
            TaskD task = new TaskD(scanner);
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
