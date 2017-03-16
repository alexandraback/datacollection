import java.text.DecimalFormat;
import java.io.*;
import java.util.Scanner;
import java.util.*;
import java.math.*;
class Solution{
	public static void main(String args[]) throws IOException{
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i=0;i<cases;i++){
			double initial = 2;
			double c = in.nextDouble();
			double f = in.nextDouble();
			double x = in.nextDouble();
			double lowest = (x/initial);
		//	System.out.println("Cases "+i+" : "+lowest);
			double timeTaken = 0;
			int count=0;
			while(true){
			timeTaken = timeTaken + (c/initial);
			initial = initial+f;
			if(timeTaken+(x/initial) < lowest) lowest = timeTaken + (x/initial);
			else{System.out.println("Case #"+(i+1)+": "+roundTwoDecimals(lowest));break;}
			count++;
			}
		}
	}
	public static String roundTwoDecimals(double d) {
	    DecimalFormat twoDForm = new DecimalFormat("#.0000000");
	    twoDForm.setMinimumFractionDigits(7);
	    return twoDForm.format(d);
	}
}
