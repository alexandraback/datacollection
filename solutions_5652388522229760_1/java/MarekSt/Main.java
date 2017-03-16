import java.util.*;
import java.io.*;
import java.lang.*;

/* *************************************** */

class BleatrixCounting{
	private
		int startNumber;
		boolean digits[]=new boolean[10];
		int digitsCount=0;
		
	public BleatrixCounting(int n){
		startNumber=n;
	}
	
	private void countDigits(long n){
		String s=String.valueOf(n);
		for(int i=s.length()-1; i>=0;i--){
			int d=s.charAt(i)-'0';
			if (!digits[d]){
				digitsCount++;
				digits[d]=true;				
			}
		}
		
	}
	
	public String lastNumber(){
		if (startNumber==0) return "INSOMNIA";
		long n=0;
		do{
			n+=startNumber;
			countDigits(n);
		}while (digitsCount<10);
				
		return String.valueOf(n);
	}
	
}

public class Main {
		
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    for (int i = 1; i <= t; ++i) {
	      int n = in.nextInt();
	      BleatrixCounting bc=new BleatrixCounting(n);
	      System.out.println("Case #" + i + ": "+bc.lastNumber());
	      
	    }
	}
}
