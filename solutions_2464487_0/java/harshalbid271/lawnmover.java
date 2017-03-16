import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.util.Scanner;
import java.util.StringTokenizer;


public class lawnmover {

	public static void main(String[] args) throws IOException 
	{

		Scanner sc=new Scanner((new FileReader("a.txt")));
		int cases=sc.nextInt();
		
//		sc.nextLine();
		for(int counter=0;counter<cases;counter++)
		{
			long r=sc.nextLong();
			long t=sc.nextLong();
			
			long b=(2*r-1);
			
//			System.out.println(r+", "+t);
			long n=(long)((-b+Math.sqrt(b*b+8*t))/4.0);
			
			System.out.println("Case #"+(counter+1)+": "+n);
		}
	}

}
