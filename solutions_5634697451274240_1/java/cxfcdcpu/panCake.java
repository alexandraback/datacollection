import java.io.*;
import java.util.*;
public class panCake{
	
	public static void main(String[] arg){
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt();  
		for (int i = 1; i <= t; ++i) {
			String input=in.next();
			
			//System.out.println(input);
			
			String output="";
			int n=input.length();
			int pointer=input.indexOf("+");
			if(pointer==0)pointer=nextBack(input,pointer);
			else if(pointer==-1)pointer=n;
			
			//System.out.println("Point value is: "+pointer);
			
			int times=0;
			while(pointer<=n){
				if(pointer==n&&input.charAt(pointer-1)=='-'){
					flip(input,pointer);
					times++;
					pointer++;
				}else if(pointer==n&&input.charAt(pointer-1)=='+'){
					pointer++;
				}
				else {
					flip(input,pointer);
					times++;
					if(input.charAt(pointer)=='+')pointer=nextBack(input,pointer);
					else if(input.charAt(pointer)=='-')pointer=nextHead(input,pointer);
				}
			}
		
			System.out.println("Case #" + i + ": " + times);
		
		}
		
	}
	
	public static int nextHead(String input,int pointer)
	{
		if(pointer==input.length()-1)return input.length();
		else if( input.substring(pointer+1).indexOf("+")>=0)return input.substring(pointer+1).indexOf("+")+pointer+1;
		else return input.length();
	
	}
	
	public static int nextBack(String input,int pointer)
	{
		if(pointer==input.length()-1)return input.length();
		else if( input.substring(pointer+1).indexOf("-")>=0)return input.substring(pointer+1).indexOf("-")+pointer+1;
		else return input.length();
	
	}
	
	public static void flip(String input,int pointer){
		String s1=input.substring(0,pointer);
		String s2="";
		if(pointer!=input.length());
		s2=input.substring(pointer);
		 
			
		String buf="";
		for(int i=0;i<pointer;i++){
			buf+=s1.charAt(pointer-i-1);
		}
		input=buf+s2;
	}
	
}