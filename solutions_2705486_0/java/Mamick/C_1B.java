import java.io.*;
import java.util.*;
 
public class C_1B {
	static String [] dictionary=new String[521196];
	static int [][] min;
	static String text;
	static int returnCool;
	public static int distance(int start, String s2, int cool)
	{
		int cooldown=cool;
		int count=0;
		for(int i=0;i<s2.length();i++)
		{
			if(start+i>=text.length())
				return -1;
			if(s2.charAt(i)!=text.charAt(start+i))
			{
				if(cooldown<=0)
				{
					cooldown=5;
					count++;
				}
				else
					return -1;
			}
			if(cooldown>0)
				cooldown--;
		}
		returnCool=cooldown;
		return count;
	}
	public static boolean isValid(int i, int length, int t)
	{
		return (i+length<=text.length())&&(i+length==text.length()||min[i+length][t]!=-1);
	}
	public static void main(String[] args) {
		try 
		{
			Scanner s1 = new Scanner(new File("garbled_email_dictionary.txt"));
			for(int i=0;i<dictionary.length;i++)
				dictionary[i]=s1.next();
			s1.close();
			Scanner s = new Scanner(new File("C-small-attempt1.in"));
			
			FileOutputStream out = new FileOutputStream(new File("lawn2.txt"));
			PrintStream p = new PrintStream(out);
			
			int num=s.nextInt();
			for(int n=1;n<=num;n++)
			{
				text=s.next();
				min=new int [text.length()][5];
				for(int i=0;i<min.length;i++)
					for(int j=0;j<5;j++)
						min[i][j]=-1;
				for(int i=min.length-1;i>=0;i--)
				{
					for(int j=0;j<dictionary.length;j++)
					{
						int tmp2=dictionary[j].length();
						for(int t=0;t<5;t++)
						{
							int tmp=distance(i,dictionary[j],t);
							if(tmp!=-1)
								if(isValid(i,tmp2,returnCool))
									if(min[i][t]==-1||tmp+((i+tmp2==text.length())?0:min[i+tmp2][returnCool])<min[i][t])
										min[i][t]=tmp+((i+tmp2==text.length())?0:min[i+tmp2][returnCool]);
						}
					}
				}
				p.println("Case #"+n+": "+min[0][0]);
			}
			
			p.close();
		}
		catch(IOException e)
		{
			System.out.println("There was a problem:" + e);
		
		}
    }
}
