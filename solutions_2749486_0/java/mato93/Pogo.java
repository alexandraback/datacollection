package Round_1C;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Pogo {

	public static int sign(int x)
	{
		if (x<0) return -1;
		return 1;
	}
	
	public static String solve(int x,int y)
	{
		String out = "";
		
		for(int i=1; i<=2*Math.abs(x); i++)
		{
			if(x>0)
			{
				if(i % 2 == 1) out += "W";
				else out += "E";
			}else
			{
				if(i % 2 == 1) out += "E";
				else out += "W";
			}
		}
		
		for(int i=1; i<=2*Math.abs(y); i++)
		{
			if(y>0)
			{
				if(i % 2 == 1) out += "S";
				else out += "N";
			}else
			{
				if(i % 2 == 1) out += "N";
				else out += "S";
			}
		}
		return out;
		
	}
	
	public static void main(String[] args) 
	{
		try{
			String readFrom = "1C/B-small-attempt0.in";
			Scanner sc = new Scanner(new File(readFrom));
				//sc.useDelimiter("\n");
			FileWriter out = new FileWriter(new File("1C/B-small-attempt0.out"));
			
			
			String answer;
			int x,y;
			int testCases = sc.nextInt();
				//System.out.println(testCases);
			
			for(int k=1; k<=testCases; k++)
			{
				x = sc.nextInt();
				y = sc.nextInt();
				answer = solve(x,y);
				
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
