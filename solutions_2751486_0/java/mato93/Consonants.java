package Round_1C;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Consonants
{

	public static boolean isCons(char c)
	{
		if ("aeiou".indexOf(c) == -1) return true;
		return false;
	}
	
	public static boolean onlyCons(String s)
	{
		for(int i=0; i<s.length(); i++)
			if(!isCons(s.charAt(i))) return false;
		return true;
	}
	
	public static long solve(String name,int n)
	{
		int[][] a = new int[name.length()][name.length()];
		int beginIndex;
		
		if(n == 1)
		for(int i=0; i<name.length(); i++)
			if(isCons(name.charAt(i))) a[i][i]=1;
		
		for(int i=0; i<name.length(); i++)
		{
			for(int j=i+1; j<name.length(); j++)
			{
				if(a[i][j-1] == 1) a[i][j]=1;
				else
				{
					beginIndex = j+1-n;
					if(beginIndex>=i && onlyCons(name.substring(beginIndex, j+1))) 
						a[i][j]=1;
				}
				
			}
			
			/*
			System.out.print("  ");
			for(int k=0; k<name.length(); k++) 
				System.out.print(name.charAt(k)+" ");
			System.out.println();
			for(int k=0; k<name.length(); k++)
			{
				System.out.print(name.charAt(k)+" ");
				for(int j = 0; j<name.length(); j++)
					System.out.print(a[k][j]+" ");
				System.out.println();
			}
			System.out.println();*/
			
		}
			
		long sum = 0;
		for(int i=0; i<name.length(); i++)
			for(int j=0; j<name.length(); j++)
				sum += a[i][j];
			
		return sum;
	}
	
	
	/**
	 * nextLine()
	 * @param args
	 */
	public static void main(String[] args) 
	{
		try{
			String readFrom = "1C/A-small-attempt1.in";
			Scanner sc = new Scanner(new File(readFrom));
				//sc.useDelimiter("\n");
			FileWriter out = new FileWriter(new File("1C/A-small-attempt1.out"));
			
			
			long answer;
			String name;
			int n = 0;
			int testCases = sc.nextInt();
				//System.out.println(testCases);
			
			for(int k=1; k<=testCases; k++)
			{
				name = sc.next();
				n = sc.nextInt();
				
				answer = solve(name,n);
				
				System.out.println("Case #"+k+": "+answer);
				out.write("Case #"+k+": "+answer+"\n");
			}

			out.close();
		}catch(IOException e)
		{
			System.out.println("IO error");
		}

	}

}
