import java.io.File;import java.io.FileOutputStream;import java.io.FileReader;
import java.io.IOException;import java.io.PrintStream;import java.io.PrintWriter;
import java.util.ArrayList;import java.util.Arrays;import java.util.Scanner;

public class Csmall {
    
	 public static void main(String[] arg)throws IOException{
    	Scanner in=new Scanner(new File("C.in"));
    	int total=in.nextInt();
    	for(int ind=1; ind<=total; ind++){
    		int A=in.nextInt(); int B=in.nextInt();
    		int res=0;
    		for(int i=A; i<=B; i++){
    			if(isP(i)&isSP(i))
    				res++;
    		}
    		System.out.println("Case #"+ind+": "+res);
    	}
    	
     }
	 public static boolean isP(int n){
		 String s=""+n;
		 for(int i=0; i<s.length()/2; i++)
			 if(s.charAt(i)!=s.charAt(s.length()-i-1))
				 return false;
		 return true;
	 }
	 public static boolean isSP(int n){
		  int m=(int)Math.sqrt(n);
		  if(m*m!=n) return false;
		  if(isP(m)) return true;
		  return false;
	 }
	 
}