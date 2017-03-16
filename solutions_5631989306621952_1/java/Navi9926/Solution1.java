package googlecodejam;

import java.util.Scanner;

public class Solution1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		for(int i=0;i<n;i++)
		{
			String s = in.next();
			 finalWord(i+1,s);
		}
		
	}
	public static void finalWord(int j,String s)
	{
		String a = ""+s.charAt(0);
		for(int i=1;i<s.length();i++)
		{
			if((int)a.charAt(0)>(int)s.charAt(i))
			{
				a=a+s.charAt(i);
			}
			else
				a=s.charAt(i)+a;
		}
		System.out.println("Case #"+j+": "+a);
	}
}