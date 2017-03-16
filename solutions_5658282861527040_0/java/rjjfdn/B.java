import java.util.*;
import java.io.*;

public class B {
        
    public static void main(String[] args) throws Exception {
    	Scanner s = new Scanner(new FileReader("b.in"));
    	PrintWriter p = new PrintWriter(new FileWriter("b.out"));
    	int t = s.nextInt();
    	for(int i=0; i<t; i++) {
    		int a = s.nextInt();
    		int b = s.nextInt();
    		int K = s.nextInt();
    		int count = 0;
    		for(int j=0; j<a; j++)
    			for(int k=0; k<b; k++)
    				if((j & k) < K)
    					count++;
    		p.println("Case #" + (i+1) + ": " + count);
    	}
    	p.close();
    }
}
