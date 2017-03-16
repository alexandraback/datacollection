package Codejam16;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class q12 
{
	static ArrayList<String> ar;
	static String st;
	public static void main(String args[])
	{
		Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		int t1=t;
		StringBuilder pans=new StringBuilder();
		s.nextLine();
		while(t-->0)
		{
			st=s.next();
			st=sorted(st);
			int c=9;
//			System.out.println(st);
			StringBuilder ans=new StringBuilder();
//			System.out.println(subse("OTZ"));
			while(!st.isEmpty() && c>=0)
				{
//				System.out.println(ans+" "+c+" "+st);
				if(check(c))
				ans.append(c);
				else
					c--;
//				try {
//					Thread.sleep(500);
//				} catch (InterruptedException e) {
//					// TODO Auto-generated catch block
//					e.printStackTrace();
//				}
				}
//			System.out.println(c+" "+st);
			pans.append("Case #"+(t1-t)+": "+ans.reverse().toString()+" \n");
		}
		System.out.println(pans);
	}
	
	public static void init()
	{
		
	}
	
	public static boolean check(int n)
	{
	//	System.out.println("in check"+ (sorted(get(n)))+" "+subse((sorted(get(n)))));
		if(subse((sorted(get(n)))))
		{
	//		System.out.println("true"+" "+st+" "+n);
			String g=get(n);
			for(int i=0;i<g.length();i++)
				{
				String cha=g.charAt(i)+"";
			//	System.out.println(st+" "+st.indexOf(cha)+" "+cha);
		//		String tmp=st.substring(0,st.indexOf(cha))+st.substring(st.indexOf(cha)+1);
				st=st.replaceFirst(cha, "");
		//		System.out.println(st);
				//st=tmp;
				}
			
			return true;
		}
		return false;
		
	}
	
	public static String get(int n)
	{
		switch(n){
		case 0:
			  return "ZERO";

		case 1:
			  return "ONE";

		case 2:
			  return "TWO";
			  

		case 3:
			  return "THREE";
			  

		case 4:
			  return "FOUR";
			  

		case 5:
			  return "FIVE";
			  

		case 6:
			  return "SIX";
			  

		case 7:
			  return "SEVEN";
			  

		case 8:
			  return "EIGHT";
			  
	    default:
	    	return "NINE";
		}
	}
	
	public static String sorted(String st)
	{
		int a[]=new int[st.length()];
		for(int i=0;i<a.length;i++)
			a[i]=st.charAt(i)-'A';
		
		Arrays.sort(a);
		StringBuilder ans=new StringBuilder();
		for(int i=0;i<a.length;i++)
			ans.append((char)(a[i]+'A'));
		
		return ans.toString();
		
	}
	
	public static boolean subse( String b)
	{
		int j=0;
		for (int i=0;i<st.length();i++)
			if(st.charAt(i)==b.charAt(j))
				{
				j++;
		//		System.out.println(j+" in subse"+" "+i);
				if(j==b.length())
					return true;
				}
		return false;
	}
}
