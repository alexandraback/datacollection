import java.util.*;
import java.io.*;
import java.math.*;

public class A {
        
    public static void main(String[] args) throws Exception {
    	Scanner s = new Scanner(new FileReader("a.in"));
    	PrintWriter p = new PrintWriter(new FileWriter("a.out"));
    	int n = s.nextInt();
    	for(int i=0; i<n; i++) {
    		String[] split = s.next().split("/");
    		BigInteger a = new BigInteger(split[0]);
    		BigInteger b = new BigInteger(split[1]);
    		BigInteger gcd = a.gcd(b);
    		a = a.divide(gcd);
    		b = b.divide(gcd);
    		if(check(b)) {
    			p.println("Case #" + (i+1) + ": impossible");
    			continue;
    		}
    		BigInteger c = new BigInteger("2");
    		int count = 0;
    		while(true) {
    			count++;
    			if(c.multiply(a).compareTo(b) >= 0)
    				break;
    			c = c.multiply(new BigInteger("2"));
    		}
    		p.println("Case #" + (i+1) + ": " + count);
    	}
    	p.close();
    }
    
    public static boolean check(BigInteger b) { 
    	while(!b.equals(BigInteger.ONE)) {
    		if(b.mod(new BigInteger("2")).equals(BigInteger.ONE))
    			return true;
    		b = b.divide(new BigInteger("2"));
    	}
    	return false;
    }
}
