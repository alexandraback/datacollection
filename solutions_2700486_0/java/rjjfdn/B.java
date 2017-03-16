import java.util.*;
import java.io.*;

public class B {
        
    public static void main(String[] args) throws Exception {
    	Scanner s = new Scanner(new FileReader("B-small-attempt1.in"));
    	Scanner s2 = new Scanner(new FileReader("hi.txt"));
    	PrintWriter printer = new PrintWriter(new FileWriter("bsmall2.out"));
    	HashMap<String, Double> map = new HashMap<String, Double>();
    	while(s2.hasNext()) {
    		int a = s2.nextInt();
    		int b = s2.nextInt();
    		int c = s2.nextInt();
    		double d = s2.nextDouble();
    		map.put(a + " " + b + " " + c, d);
    	}
    	int n = s.nextInt();
    	for(int i=0; i<n; i++) {
    		int a = Math.abs(s.nextInt());
    		int b = Math.abs(s.nextInt());
    		int c = Math.abs(s.nextInt());
    		if(!map.containsKey(a + " " + b + " " + c))
    			printer.println("Case #" + (i+1) + ": " + (double)(0));
    		else
    			printer.println("Case #" + (i+1) + ": " + map.get(a + " " + b + " " + c));
    	}
    	printer.close();
    }
}
