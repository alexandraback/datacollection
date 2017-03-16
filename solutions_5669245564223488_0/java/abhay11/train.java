import java.io.*;
import java.util.*;

public class train
{
	static boolean[] allowed, used;
	static String[] train;
	static int N, sols;
	
	public static void main(String[] args) throws IOException
	{
		Scanner in=new Scanner(new BufferedInputStream(System.in)).useDelimiter("[\\s/]+");
		
		int nR=in.nextInt();
		allowed=new boolean[26];
		for (int run=1; run<=nR; run++)
		{
			N=in.nextInt();
			train=new String[N];
			used=new boolean[N];
			for (int i=0; i<N; i++)
			{
				train[i]=in.next();
				used[i]=false;
			}
			
			for (int i=0; i<26; i++)
				allowed[i]=true;
			
			sols=0;
			System.out.print("Case #"+run+": ");
			System.out.println(recurse(0, -1)%1000000007);
		}
	}
	
	static int recurse(int lvl, int prev)
	{
		if (lvl>=N)
			return 1;
		
		int total=0;
		for (int i=0; i<N; i++)
		{
			if (used[i]) continue;
			
			int len=train[i].length();
			for (int j=0; j<len; j++)
			{
				if (prev>=0 && train[i].charAt(j)-'a'!=prev)
					allowed[prev]=false;
				if (!allowed[train[i].charAt(j)-'a'])
					return 0;
			}
			
			boolean chk=false;
			for (int j=len-1; j>=0; j--)
			{
				if (!chk && train[i].charAt(j)!=train[i].charAt(len-1))
					chk=true;
				
				if (chk)
					allowed[train[i].charAt(j)-'a']=false;
			}
			
			used[i]=true;
			
			//for (int j=0; j<lvl; j++) System.out.print("\t");
			//System.out.println(i);
			
			total+=recurse(lvl+1, train[i].charAt(len-1)-'a');
			
			used[i]=false;
			if (prev>=0)
				allowed[prev]=true;
			
			for (int j=0; j<len; j++)
				allowed[train[i].charAt(j)-'a']=true;
		}
		
		return total;
	}
}