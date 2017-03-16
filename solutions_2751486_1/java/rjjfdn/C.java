import java.util.*;
import java.io.*;
import java.math.*;

public class C {

    public static void main(String[] args) throws Exception {
    	BufferedReader s = new BufferedReader(new FileReader("A-large.in"));
    	//BufferedReader s = new BufferedReader(new InputStreamReader(System.in));
    	PrintWriter printer = new PrintWriter(new FileWriter("alarge.out"));
    	
    	
    	int n = Integer.parseInt(s.readLine());
    	HashSet<Character> set = new HashSet<Character>();
    	set.add('a');
    	set.add('e');
    	set.add('i');
    	set.add('o');
    	set.add('u');
    	for(int i=0; i<n; i++) {
    		String[] split = s.readLine().split(" ");
    		String str = split[0];
    		int m = Integer.parseInt(split[1]);
    		BigInteger count = BigInteger.ZERO;
    		int curl = 0;
    		int curx = 0, cury = str.length();
    		for(int j=0; j<str.length(); j++) {
    			if(!set.contains(str.charAt(j)))
    				curl++;
    			else curl = 0;
    			//System.out.println(curl);
    			if(curl >= m) {
    				count = count.add((new BigInteger(""+(j-curx-m+2))).multiply(new BigInteger(""+(cury-j))));
    				curx = j-m+2;
    				//System.out.println(count);
    			}
    		}
    		printer.println("Case #" + (i+1) + ": " + count);
    	}
    	
    	printer.close();
    }
}
