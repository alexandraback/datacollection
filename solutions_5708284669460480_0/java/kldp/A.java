package Codejam_1C;

import java.util.Arrays;
import java.util.Scanner;

public class A 
{
	static Scanner in;
	public static void main(String args[])
	{
		in=new Scanner(System.in);
		int T=in.nextInt();
		for(int t=1;t<=T;t++)
			System.out.println("Case #"+t+": "+solve());
	}
	public static double solve()
	{
		double ans=0;
		int k=in.nextInt();
		int l=in.nextInt();
		int s=in.nextInt();
		in.nextLine();
		char[]keys=in.nextLine().toCharArray();
		char[] ll=in.nextLine().toCharArray();
		int max=0;
		int answer[] = new int[s+1];
		char[] ss=new char[7];
		for(int i1=0;i1<k;i1++)
		{
			ss[0]=keys[i1];
			for(int i2=0;i2<k;i2++)
			{
				ss[1]=keys[i2];
				for(int i3=0;i3<k;i3++)
				{	
					ss[2]=keys[i3];
					for(int i4=0;i4<k;i4++)
					{		
						ss[3]=keys[i4];
						for(int i5=0;i5<k;i5++)
						{			
							ss[4]=keys[i5];
							for(int i6=0;i6<k;i6++)
							{	
								ss[5]=keys[i6];
								for(int i7=0;i7<k;i7++)
								{
									ss[6]=keys[i7];
									int count=countL(ll,ss,s);
									if(max<count)
										max=count;	
									answer[count]+=1;
									if(s<7)
										break;
								}
								if(s<6)
									break;
							}
							if(s<5)
								break;
						}
						if(s<4)
							break;
					}
					if(s<3)
						break;
				}
				if(s<2)
					break;
			}
		}
//		System.out.println(Arrays.toString(answer));
//		System.out.println(max);
		for(int i=max;i>=0;i--)
		{
//			System.out.println((long)answer[i]*(max-i)/Math.pow(k,s));
			ans+=(long)answer[i]*(max-i);
		}
		ans/=Math.pow(k,s);
		
		return ans;

	}
	static int countL(char[] l,char[] s,int lenS)
	{
		int ans=0;
		for(int i=0;i<lenS-l.length+1;i++)
		{
			int j;
			for(j=0;j<l.length && s[i+j]==l[j];j++);
			if(j==l.length)
				ans++;
		}
		return ans;
	}
}


