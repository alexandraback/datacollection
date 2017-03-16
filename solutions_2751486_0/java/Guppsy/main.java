import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class main {

	static int c;
	static double t;
	static double r;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader( new FileReader("inp.in"));
		Scanner scr = new Scanner(br);
		
		BufferedWriter wr = new BufferedWriter(new FileWriter("output.txt"));
		
		c = scr.nextInt();
		
		System.out.println("Total Cases : " + c);
		
		for(int i=0;i<c;i++){
			int res=0;
			String str = scr.next();
			int n = scr.nextInt();
			int[] mark = new int[str.length()];
			
			for(int j=0;j<str.length();j++)
				mark[j]=1;
			
			for(int j=0;j<str.length();j++){			
				if(str.charAt(j)=='a'||str.charAt(j)=='e'||str.charAt(j)=='i'||str.charAt(j)=='o'||str.charAt(j)=='u')
					mark[j]=0;
				
			}
			
			int counter=0;
			int flag=0;
			int num=0;
			for(int j=0;j<str.length();j++){
				for(int k=j;k<str.length();k++){		
					
					if(mark[k]==1)
						counter++;
					else
						counter=0;
					
					if(counter==n)
						flag=1;
					
					if(flag==1){
						res++;
					}
				}
				
				counter=0;
				flag=0;
			}
			
			wr.write("Case #" + (i+1) + ": "+res);
			wr.write("\r\n");
		}
		wr.close();
	}	
}