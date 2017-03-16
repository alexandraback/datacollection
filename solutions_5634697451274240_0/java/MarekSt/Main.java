import java.util.*;
import java.io.*;
import java.lang.*;

/* *************************************** */

public class Main {
	
	public static int howManyFlips(int blocks, boolean top){ // top: true == '+'
		int flips=0;
		boolean bottom;
		while ((blocks>1) || (!top)){
			if ((blocks & 1)==1)
				bottom=top;
			else
				bottom=!top;

			//System.out.println("flips:"+flips+" blocks:"+blocks+" top:"+top+" bottom:"+bottom);
			
			if (bottom){
				blocks--;
				bottom=!bottom;
			} else {//!bottom
				if (top==bottom){
					flips++;
					top=!top;
					bottom=!bottom;
				} else {
					flips++;
					top=!top;					
					blocks--;
				}
			}
		}
		return flips;
	}
	
	public static int howManyFlips(String s){
		//System.out.println("howManyFlips(" + s+ ")");
		char c=s.charAt(0);
		int blocks=1;
		int len=s.length();
		for(int i=1;i<len;i++)
		{
			char temp=s.charAt(i);
			if (c!=temp){
				c=temp;
				blocks++;
			}
		}
		return howManyFlips(blocks, s.charAt(0)=='+');
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    for (int i = 1; i <= t; ++i) {
	      String s = in.next();
	      System.out.println("Case #" + i + ": "+howManyFlips(s));
	      
	    }
	}
}
