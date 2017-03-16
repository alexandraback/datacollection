import java.io.File;import java.io.FileOutputStream;import java.io.FileReader;
import java.io.IOException;import java.io.PrintStream;import java.io.PrintWriter;
import java.util.ArrayList;import java.util.Arrays;import java.util.Scanner;

public class Clarge {
    
	 public static void main(String[] arg)throws IOException{
    	ArrayList<Long> target=new ArrayList<Long>();
    	for(long n=1; n<=9999999; n++){
    		if(isP(n)){
    			if(isP(n*n))
    				target.add(n*n);
    		}
    	}
		Scanner in=new Scanner(new File("C.in"));
    	int total=in.nextInt();
    	for(int ind=1; ind<=total; ind++){
    		int A=in.nextInt(); int B=in.nextInt();
    		int res=0;
    		for(long x:target){
    			if(x<=B & x>=A)
    				res++;
    		}
    		System.out.println("Case #"+ind+": "+res);
    	}
    	
     }
	 public static boolean isP(long n){
		 String s=""+n;
		 for(int i=0; i<s.length()/2; i++)
			 if(s.charAt(i)!=s.charAt(s.length()-i-1))
				 return false;
		 return true;
	 }
	 
}