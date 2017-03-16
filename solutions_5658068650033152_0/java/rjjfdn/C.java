import java.util.*;
import java.io.*;

public class C {

    public static void main(String[] args) throws Exception {
    	Scanner s = new Scanner(new FileReader("c.in"));
    	PrintWriter p = new PrintWriter(new FileWriter("c.out"));
    	int t = s.nextInt();
    	for(int i=0; i<t; i++) {
    		int x = s.nextInt();
    		int y = s.nextInt();
    		int k = s.nextInt();
    		int n = Math.min(x, y);
    		int m = Math.max(x, y);
    		if(n < 3 || k < 5) {
    			p.println("Case #" + (i+1) + ": " + k);
    			continue;
    		}
    		if(n == 3) {
    			switch(m) {
    				case 3:
    					p.println("Case #" + (i+1) + ": " + (k-1));
    					break;
    				case 4:
    					if(k < 8)
    						p.println("Case #" + (i+1) + ": " + (k-1));
    					else
    						p.println("Case #" + (i+1) + ": " + (k-2));
    					break;
    				case 5:
    					if(k < 8)
    						p.println("Case #" + (i+1) + ": " + (k-1));
    					else if(k < 11)
    						p.println("Case #" + (i+1) + ": " + (k-2));
    					else
    						p.println("Case #" + (i+1) + ": " + (k-3));
    					break;
    				case 6:
    					if(k < 8)
    						p.println("Case #" + (i+1) + ": " + (k-1));
    					else if(k < 11)
    						p.println("Case #" + (i+1) + ": " + (k-2));
    					else if(k < 14)
    						p.println("Case #" + (i+1) + ": " + (k-3));
    					else
    						p.println("Case #" + (i+1) + ": " + (k-4));
    					break;
    			}
    		}
    		else if(n == 4) {
    			switch(m) {
    				case 4:
    					if(k < 8)
    						p.println("Case #" + (i+1) + ": " + (k-1));
    					else if(k < 10)
    						p.println("Case #" + (i+1) + ": " + (k-2));
    					else if(k < 12)
    						p.println("Case #" + (i+1) + ": " + (k-3));
    					else
    						p.println("Case #" + (i+1) + ": " + (k-4));
    					break;
    				case 5:
    					if(k < 8)
    						p.println("Case #" + (i+1) + ": " + (k-1));
    					else if(k < 10)
    						p.println("Case #" + (i+1) + ": " + (k-2));
    					else if(k < 12)
    						p.println("Case #" + (i+1) + ": " + (k-3));
    					else if(k < 14)
    						p.println("Case #" + (i+1) + ": " + (k-4));
    					else if(k < 16)
    						p.println("Case #" + (i+1) + ": " + (k-5));
    					else
    						p.println("Case #" + (i+1) + ": " + (k-6));
    					break;
    			}
    		}
    	}
    	p.close();
    }
}
