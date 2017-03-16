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
			int e = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			int energy = e;
			int[] ints = new int[n];
			st = new StringTokenizer(f.readLine());
			for(int i = 0;i<n;i++)
			{
				ints[i] = Integer.parseInt(st.nextToken());
			}
			int gain = 0;
			for(int i = 0;i<ints.length;i++)
			{
				int next = getNext(ints,i);
				if(next==-1)
				{
					gain+=energy*ints[i];
					System.out.print(energy+" ");
					energy = Math.min(r,e);
				}else{
					int dif = next-i;
					int q = e - Math.min(dif*r,e);
					int amount = Math.max(energy-q,0);
					gain+=ints[i]*amount;
					System.out.print(amount+" ");
					energy-=amount;
					energy=Math.min(energy+r,e);
					System.out.print("#"+q+" "+amount+" "+dif+"#");	
				}	
			}
			System.out.println();
			out.println("Case #"+(z+1)+": "+gain);
		}
  		out.close();	
	}
	
	public int getNext(int[] ints, int spot)
	{
		int m = ints[spot];
		for(int i = spot+1;i<ints.length;i++)
		{
			if(ints[i]>m)
				return i;
		}
		return -1;
	}
	
  	public static void main (String [] args) throws IOException 
  	{
  		new a().run();
  		System.exit(0);		
  	}	
}
