import java.util.*;
import java.math.*;
import java.io.*;

public class Main
	{
	public static void main(String args[]) throws IOException
		{
		PrintWriter out=new PrintWriter(new File("output.txt"));
		BufferedReader in=new BufferedReader(new FileReader(new File("input.txt")));
		int T=Integer.parseInt(in.readLine());
		for(int t=0;t<T;t++)
			{
			String S[]=in.readLine().split(" ");
			char Name[]=S[0].toCharArray();
			int n=Integer.parseInt(S[1]);
			
			int Len=Name.length;
			int DP[]=new int[Len];		//number of consonants ending at index i (inclusive)
			//System.out.println("Len = "+Len);
			if(isConsonant(Name[0]))
				DP[0]=1;
			for(int i=1;i<Len;i++)
				{
				if(isConsonant(Name[i]))
					DP[i]=1+DP[i-1];
				}
			//System.out.println(Arrays.toString(DP));
			
			int SAT[]=new int[Len];		//number of times DP[j]>=n for j<=i
			if(DP[0]>=n)
				SAT[0]=1;
			for(int i=1;i<Len;i++)
				{
				if(DP[i]>=n)
					SAT[i]=1+SAT[i-1];
				else
					SAT[i]=SAT[i-1];
				}
			//System.out.println(Arrays.toString(SAT));
			
			long ans=0;
			for(int i=0;i<Len;i++)
				{
				int lo=i+n-1;
				if(lo>=Len)
					continue;
				int hi=Len-1;
				
				int dec=0;
				if(i+n-2>=0)
					dec=SAT[i+n-2];
				
				while(hi-lo>=10)
					{
					int mid=(hi+lo)/2;
					if(SAT[mid]-dec>0)
						hi=mid+1;
					else
						lo=mid-1;
					}
				while(lo<=hi)
					{
					if(SAT[lo]-dec>0)
						{
						//System.out.println("for i= "+i+" ans= "+lo);
						ans+=(Len-lo);
						break;
						}
					lo++;
					}
				}
			out.println("Case #"+(t+1)+": "+ans);
			}
		out.close();
		}

	private static boolean isConsonant(char c)
		{
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
			return false;
		return true;
		}
	
	}

//must declare new classes here