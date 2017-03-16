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
			st = new StringTokenizer(f.readLine());
			long r = Long.parseLong(st.nextToken());
			long l = Long.parseLong(st.nextToken());
			out.println("Case #"+(z+1)+": "+ring(r,l));
		}
  		out.close();	
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
