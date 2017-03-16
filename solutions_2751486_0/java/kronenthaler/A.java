package r1c;


import java.io.*;
import java.util.*;
import java.math.*;

/**
 *
 * @author kronenthaler
 */
public class A {
	public static void main(String[] args) {
        try{
			boolean small = true;
			String file = small ? "a-small.in" : "a-large.in"; 
			String out = small ? "a-small.out" : "a-large.out";
			Scanner in = new Scanner(new FileInputStream(file));
			System.setOut(new PrintStream(new FileOutputStream(out)));
			
			int T = in.nextInt();
			for(int cases = 1; cases <= T; cases++){
				String w = in.next();
				int n = in.nextInt();
				w = w.replaceAll("[aeiou]", ".");
				System.out.printf("Case #%d: %d\n",cases, solve(w,n));
			}
		}catch(Exception e){
			e.printStackTrace();
		}
    }

	public static long solve(String w, int n){
		int m = n;
		long count = 0;
		while(m <= w.length()){
			for(int i=0;i<w.length()-m+1;i++){
				char p = w.charAt(i);
				int c = p!='.'?1:0;
				for(int j=i+1;j<i+m;j++){
					if((p!='.' && w.charAt(j)!= '.') || p=='.' && w.charAt(j)!= '.')
						c++;
					else if(p!='.' && w.charAt(j)=='.')
						c=0;
					
					if(c >= n){ 
						break;
					}
					
					p = w.charAt(j);
				}
				if(c >= n){ 
					count++;
				}
			}
			m++;
		}
		return count;
	}
	static class Token{
		String t;
		int p;
		Token(String _t, int _p){ t=_t; p=_p;}
	}
}