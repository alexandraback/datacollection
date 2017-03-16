

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


/**
 * 
 * @author ralf
 *
 */
public class TaskB {
    
	String stack;
    
    public TaskB(Scanner input) {
        stack = input.next();
    }
    
    public String solve() {
    	String data = stack + "+";
    	int nBreaks = 0;
    	char current = data.charAt(0);
    	for (int i=0; i<data.length(); i++) {
    		char ch = data.charAt(i);
    		if (ch != current) {
    			nBreaks++;
    			current = ch;
    		}
    	}
        
        return String.valueOf(nBreaks);
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("data/B.in"));
        PrintWriter writer = new PrintWriter("data/B.out");
        int nTests = scanner.nextInt();
        for (int i=1; i<=nTests; i++) {
            TaskB task = new TaskB(scanner);
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
