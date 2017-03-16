

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;


/**
 * 
 * @author ralf
 *
 */
public class TaskC {
    
	List<String[]> topics = new ArrayList<String[]>();
	Map<String, Integer> lCount = new HashMap<String, Integer>();
	Map<String, Integer> rCount = new HashMap<String, Integer>();
    
    public TaskC(Scanner input) {
        int n = input.nextInt();
        for (int i=0; i<n; i++) {
        	String l = input.next();
        	String r = input.next();
        	topics.add(new String[] {l, r});
        	Integer lc = lCount.get(l);
        	if (lc == null) {
        		lCount.put(l, 1);
        	} else {
        		lCount.put(l, lc+1);
        	}
        	Integer rc = rCount.get(r);
        	if (rc == null) {
        		rCount.put(r, 1);
        	} else {
        		rCount.put(r, rc+1);
        	}
        }
    }
    
    public String solve() {
    	List<String[]> result = new ArrayList<String[]>();
        for (String[] topic : topics) {
        	String l = topic[0];
			String r = topic[1];
			Integer lc = lCount.get(l);
			Integer rc = rCount.get(r);
			if (lc > 1 && rc > 1) {
        		result.add(topic);
        		lCount.put(l, lc-1);
        		rCount.put(r, rc-1);
        	}
        }
        return String.valueOf(result.size());
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
