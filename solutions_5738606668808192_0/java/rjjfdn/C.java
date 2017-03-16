import java.util.*;
import java.io.*;

public class C {

    public static void main(String[] args) throws Exception {
    	PrintWriter p = new PrintWriter(new FileWriter("c.out"));
    	int n = 16;
    	int q = 50;
    	HashSet<String> set = new HashSet<String>();
    	int answer = 0;
    	int[] base = {2,3,4,5,6,7,8,9,10};
    	int[] rem = {2,3,5,7,11,13,17,19,23,29,31};
    	p.println("Case #1:");
    	while(true) {
    		String str = "";
    		do {
    			str = randomize(n);
    		} while(!set.add(str));
    		int[] gather = new int[base.length];
    		int count = 0;
    		for(int i=0; i<base.length; i++) {
    			for(int j=0; j<rem.length; j++)
    				if(f(str, base[i], rem[j])) {
    					gather[i] = rem[j];
    					count++;
    					break;
    				}
    		}
    		if(count == base.length) {
				p.print(str + " " + gather[0]);
				for(int i=1; i<base.length; i++)
					p.print(" " + gather[i]);
				p.println();
				answer++;
			}
    		if(answer == q) break;
    	}
    	p.close();
    }
    
    public static boolean f(String str, int base, int rem) {
    	int ans = 0;
    	for(int i=0; i<str.length(); i++) {
    		ans = ans*base;
    		ans = ans%rem;
    		ans = ans+(int)(str.charAt(i)-'0');
    		ans = ans%rem;
    	}
    	if(ans == 0) return true;
    	return false;
    }
    
    public static String randomize(int n) {
    	n -= 2;
    	String str = "1";
    	for(int i=0; i<n; i++) {
    		int a = (int)(Math.random()*2);
    		str += a;
    	}
    	str += "1";
    	return str;
    }
}
