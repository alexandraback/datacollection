import java.util.*;
import java.io.*;
import java.lang.*;

class Fractal{
	private 
		int k;
		int c;
		int s;
		
	public Fractal(int k_, int c_, int s_){
		k=k_;
		c=c_;
		s=s_;
	}
	
	public String getSolution(){
		if (c*s<k) return " IMPOSSIBLE";
		
		int origSeqPos=0;
		String result="";
		while (origSeqPos<k){
			long artPos=1;
			for(int i=1;i<=c;i++)
			{
				origSeqPos++;
				artPos=(artPos-1)*k + (origSeqPos>k?1:origSeqPos);
			}
			result=result+" "+artPos;
		}
		return result; // + " // "+k+" "+c;
	}
}

/* *************************************** */

public class Main {
		
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    for (int i = 1; i <= t; ++i) {
	    	int k=in.nextInt();
	    	int c=in.nextInt();
	    	int s=in.nextInt();
	    	Fractal f=new Fractal(k, c, s);
	    	System.out.println("Case #" + i + ":"+f.getSolution());	      
	    }
	}
}
