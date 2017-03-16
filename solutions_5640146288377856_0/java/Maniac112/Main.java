package Q1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.*;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		try
		{
		FileReader f=new FileReader("temp.txt");
		BufferedReader b=new BufferedReader(f);
		
		int t=Integer.parseInt(b.readLine().trim());
		
		for(int i=0;i<t;i++)
		{
			String aa[]=b.readLine().split(" ");
			int n1=Integer.parseInt(aa[0]);
			int n2=Integer.parseInt(aa[1]);
			int n3=Integer.parseInt(aa[2]);
			
			int number=0;
			number=(n2/n3)*n1;
			int answer=number+(n3-1);
			
			int k=n2/n3;
			
			if(n3*k!=n2)
				answer++;
			
			System.out.println("Case #"+(i+1)+": "+(answer));
			
		}
		}
		catch(FileNotFoundException ex)
		{
			System.out.println("ERROR");
		}
	}
}


