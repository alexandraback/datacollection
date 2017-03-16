import java.io.*;
import java.util.*;

public class Pancake {
	public static void main(String[]args)
	{
		try
		{
			Scanner sc = new Scanner(new FileReader("B-large.in"));
			FileWriter fw = new FileWriter(new File("Output.txt"));
			PrintWriter pw = new PrintWriter(fw);
			
			int t = sc.nextInt();
			
			for(int r = 1; r <= t; r++)
			{
				String s = sc.next();
				int count = 0;
				while(s.indexOf('-') != -1)
				{
					s = s.substring(0, s.lastIndexOf('-')+1);
					if(s.charAt(0)== '+')
					{
						int at = plus(s);
						s = mirrorReverse(s.substring(0, at))+s.substring(at);
					}
					else
					{
						s = mirrorReverse(s);
					}
					count++;
				}
				pw.println("Case #" + r + ": " + count);		
			}
			pw.flush();
		}
		catch(IOException ioe)
		{
			System.out.print(ioe);
		}

	}
	public static int plus(String s)
	{
		int num = -1;
		int count = 0;
		int max = 0;
		for(int i = 0; i < s.length(); i++)
		{
			if(s.charAt(i)=='+')
			{
				count++;
			}
			else
			{
				if(count >= max)
				{
					max = count;
					num = i;
					
				}
				count = 0;
			}
		}
		return num;
	}
	public static String mirrorReverse(String s)
	{
		String rs = "";
		for(int i = s.length()-1; i >= 0; i--)
		{
			rs += (s.charAt(i)=='+'? '-':'+');
		}
		return rs;
	}
	
}
