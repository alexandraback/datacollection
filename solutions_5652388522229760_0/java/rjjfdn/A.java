import java.util.*;
import java.io.*;

public class A {

    public static void main(String[] args) throws Exception {
    	Scanner s = new Scanner(new FileReader("a.in"));
    	PrintWriter printer = new PrintWriter(new FileWriter("a.out"));
    	int t = s.nextInt();
    	for(int i=1; i<=t; i++) {
    		printer.print("Case #" + i + ": ");
    		System.out.print("Case #" + i + ": ");
    		int count = 0;
    		long n = s.nextLong();
    		if(n == 0) {
    			printer.println("INSOMNIA");
    			System.out.println("INSOMNIA");
    			continue;
    		}
    		boolean[] visited = new boolean[10];
    		long m = n;
    		while(true) {
    			long tmp = m;
    			do {
    				int idx = (int)(tmp%10);
    				if(!visited[idx]) {
    					count++;
    					visited[idx] = true;
    				}
    				tmp /= 10;
    			} while(tmp != 0);
    			if(count == 10) break;
    			m += n;
    		}
    		printer.println(m);
    		System.out.println(m);
    	}
    	printer.close();
    }
}
