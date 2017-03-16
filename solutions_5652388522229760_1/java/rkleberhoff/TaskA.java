

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


/**
 * 
 * @author ralf
 *
 */
public class TaskA {
    
	int startNumber;
    
    public TaskA(Scanner input) {
        startNumber = input.nextInt();
    }
    
    public TaskA(int startNumber) {
		super();
		this.startNumber = startNumber;
	}

	public String solve() {
		int found = 0;
        for (int f=1; f<100; f++) {
        	String num = String.valueOf(startNumber * f);
        	for (int i=0; i<num.length(); i++) {
        		int digit = num.charAt(i) - '0';
        		found = found | (1 << digit);
        	}
        	if (found == 0x3ff) {
        		return num;
        	}
        }
        return "INSOMNIA";
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("data/A.in"));
        PrintWriter writer = new PrintWriter("data/A.out");
        int nTests = scanner.nextInt();
        for (int i=1; i<=nTests; i++) {
            TaskA task = new TaskA(scanner);
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
    
//	public static void main(String[] args) {
//		for (int i=0; i<=1000000; i++) {
//			TaskA task = new TaskA(i);
//			System.out.println(task.solve());
//		}
//	}
}
