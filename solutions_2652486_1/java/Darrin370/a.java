/*
ID: darrin31
LANG: JAVA
TASK: a
*/
import java.io.*;
import java.util.*;

class a{
	
	public void run() throws IOException
	{
		
		BufferedReader f = new BufferedReader(new FileReader(new File("a.txt")));
  		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sol.out")));
  		StringTokenizer st;
		int zz = Integer.parseInt(f.readLine().trim());
		for(int z = 0;z<zz;z++)
		{
			out.println("Case #1:");
			st = new StringTokenizer(f.readLine());
			int r = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			ArrayList<String> combos = new ArrayList<String>();
			permu(n,m,combos,"",2);
		loop:
			for(int i = 0;i<r;i++)
			{
				st = new StringTokenizer(f.readLine());
				long[] ints = new long[n];
				for(int j = 0;j<n;j++)
				{
					ints[j] = Long.parseLong(st.nextToken());
				}
				Collections.shuffle(combos);
				for(String str:combos)
				{
					if(check(sum(str),ints))
					{
						out.println(str);
						continue loop;
					}						
				}
			}
		}
  		out.close();	
	}
	
	public long sum(String s)
	{
		long sm = 1;
		for(char ch:s.toCharArray())
		{
			sm*=ch-48;
		}
		return sm;
	}
	
	public boolean check(long l,long[] ints)
	{
		for(long i:ints)
		{
			if(l%i!=0)
				return false;
		}
		return true;
	}
	
	public void permu(int n,int m,ArrayList<String> list,String curr,int c)
	{
		if(curr.length()==n)
			list.add(curr);
		else
		{
			for(int i = c;i<m+1;i++)
			{
				permu(n,m,list,curr+i,i);
			}
		}
	}
	
	public long ring(long r, long amount)
	{
		long n = 0;
		long current = 0;
		while(amount>=current)
		{
			n++;
			current = (long)Math.pow(r+(n*2-1),2)-((long)(Math.pow(r+(n*2-2),2)-current));	
		}
		return n-1;
	}
	
  	public static void main (String [] args) throws IOException 
  	{
  		new a().run();
  		System.exit(0);		
  	}	
}
