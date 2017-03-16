import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

import javax.naming.ldap.HasControls;


public class Algorithm 
{
	public static int solve(String name, int n)
	{
		int count = 0;
		
		for (int i=0;i<name.length();i++)
			for (int j=i+n;j<=name.length();j++)
				if (hasNconstants(name.substring(i,j),n))
					count++;
		
		return count;
	}
	
	public static boolean hasNconstants(String s, int n)
	{
		int c = 0;
		for (int i=0;i<s.length();i++)
		{
			if (isConstant(s.charAt(i)))
				c++;
			else c=0;
			
			if (c==n) return true;
		}
			
		return false;
	}
	
	private static boolean isConstant(char s)
	{
		if (s=='a') return false;
		if (s=='e') return false;
		if (s=='i') return false;
		if (s=='o') return false;
		if (s=='u') return false;
		return true;
	}
	
	
	public static void main(String[] args)
	{
		try 
		{
			File f = new File("D:\\Users\\m.schadd\\Desktop\\Google\\Names.txt");
					
			Scanner s = new Scanner(f);
			int testCases = Integer.parseInt(s.nextLine());
			
			//System.out.println("Found "+testCases+" testcases");
			PrintWriter printer = new PrintWriter("out.txt");
			
			for (int i=0;i<testCases;i++)
			{
				String l = s.nextLine();
				String[] tok = l.split(" ");
				String name = tok[0];
				int n = Integer.parseInt(tok[1]);
				
				
				int solution = solve(name, n);
				System.out.println("Case #"+(i+1)+": "+solution);
				printer.write("Case #"+(i+1)+": "+solution+"\n");
				
			}
			printer.close();
			
		} 
		catch (Exception e) 
		{
			e.printStackTrace();
		} 
	}


}
