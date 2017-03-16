import java.util.*;
import java.io.*;
public class QualProbC {
	
	public static void main(String[] args) throws Exception
	{
		String file = "C-large.in";

		BufferedReader br = new BufferedReader(new FileReader(file));
		PrintWriter writer = new PrintWriter("outCLarge.txt", "UTF-8");
		String line;

		int T = Integer.parseInt(br.readLine());
		for(int test=0;test<T;test++)
		{
			String[] lines = br.readLine().split(" ");
			int L = Integer.parseInt(lines[0]);
			long X = Long.parseLong(lines[1]);
			String str = br.readLine();
			
			StringBuilder sb = new StringBuilder();
			int modX = (int)(X%4);
			if(X>12) X=12+modX;
			for(int i = 0;i<X;i++)
			{
				sb.append(str);
			}
			
			boolean res = canIJK(sb.toString());
			writer.println("Case #"+(test+1)+": " + (res?"YES":"NO"));
		}
		writer.close();
	}
	
	
	private static boolean canIJK(String str)
	{
		
		String[] leftEvals = new String[str.length()];
		leftEvals[0]=""+str.charAt(0);
		for(int pos = 1; pos<str.length(); pos++)
		{
			leftEvals[pos] = mult(leftEvals[pos-1],str.charAt(pos));
		}
		
		if(!leftEvals[str.length()-1].equals("-1"))
		{
			return false;
		}
		
		String[] rightEvals = new String[str.length()];
		rightEvals[rightEvals.length-1]=""+str.charAt(str.length()-1);
		for(int pos = str.length()-2; pos>=0; pos--)
		{
			rightEvals[pos] = mult(str.charAt(pos),rightEvals[pos+1]);
		}
		
		
		
		for(int left = 0; left<str.length(); left++)
		{
			if("i".equals(leftEvals[left]))
			{
				for(int right = left+2; right<str.length(); right++)
				{
					if("k".equals(rightEvals[right]))
					{
						if("j".equals(mult(leftEvals[right-1],leftEvals[left]))) //really divide here
						{
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;
	}
	
	//note mult==div
	

	private static String eval(String str)
	{
		String current = ""+str.charAt(0);
		for(int spot = 1; spot<str.length(); spot++)
		{
			current = mult(current,str.charAt(spot));
		}
		return current;
	}
	
	private static String mult(String ls, String rs)
	{
		boolean neg = false;
		char right=rs.charAt(0);
		if(right=='-')
		{
			neg = true;
			right = rs.charAt(1);
		}
		char left=ls.charAt(0);
		if(left=='-')
		{
			neg = !neg;
			left = ls.charAt(1);
		}
		return mult((neg?"-":"")+left,right);
	}
	
	private static String mult(char left, String rs)
	{
		boolean neg = false;
		char right=rs.charAt(0);
		if(right=='-')
		{
			neg = true;
			right = rs.charAt(1);
		}
		return mult((neg?"-":"")+left,right);
	}
	private static String mult(String ls, char right)
	{
		boolean neg = false;
		char left;
		if(ls.charAt(0)=='-')
		{
			neg = true;
			left = ls.charAt(1);
		}
		else
		{
			left = ls.charAt(0);
		}
		if(left=='1')
		{
			return (neg?"-":"")+right;
		}
		else if(right == '1')
		{
			return (neg?"-":"")+left;
		}
		else if(left==right)
		{
			return (!neg?"-":"") +"1";
		}
		else if(left=='i')
		{
			if(right=='j') return (neg?"-":"")+"k";
			if(right=='k') return (!neg?"-":"")+"j";
		}
		else if(left=='j')
		{
			if(right=='i') return (!neg?"-":"")+"k";
			if(right=='k') return (neg?"-":"")+"i";
		}
		else if(left=='k')
		{
			if(right=='i') return (neg?"-":"")+"j";
			if(right=='j') return (!neg?"-":"")+"i";
		}
		throw new RuntimeException();
	}		
}