import java.io.*;
import java.util.*;

public class jam2 {

	/**
	 * @param args
	 */
	static int chuli(String in)
	{
		String[] ss = in.split(" ");
		int n = Integer.parseInt(ss[0]);
		int s = Integer.parseInt(ss[1]);
		int p = Integer.parseInt(ss[2]);

		ArrayList<Integer> ar = new ArrayList<Integer>();
		ArrayList<Integer> sy = new ArrayList<Integer>();
		ArrayList<Integer> sn = new ArrayList<Integer>();
		
		for(int i=0;i<n;i++)
			ar.add(Integer.parseInt(ss[3+i]));
		
		for(int i=0;i<n;i++)
		{
			int t = ar.get(i);
			if(t==0)
			{
				sy.add(-1);
				sn.add(0);
				
			}
			else
			{
			if(t==1)
			{
				sy.add(-1);
				sn.add(1);
				continue;
			}
			else{
			int tn = t/3;
			if(t%3==0)
			{
				sy.add(tn+1);
				sn.add(tn);
			}
			if(t%3==1)
			{
				sy.add(tn+1);
				sn.add(tn+1);
			}
			if(t%3==2)
			{
				sy.add(tn+2);
				sn.add(tn+1);
			}}
			}
		}
		
		
		int[][] map = new int[n+1][s+1];
		for(int i=0;i<=s;i++)
			map[0][i]=0;
		
		for(int ni = 1;ni <= n; ni++)
		{
			//System.out.println(ar.get(ni-1));
			map[ni][0]=map[ni-1][0];
			if(sn.get(ni-1)>=p)
			{
				map[ni][0]+=1;
			}
			//System.out.println(map[ni][0]);
			//System.out.println("---");
		}
		
		for(int ni = 1;ni<=n;ni++)
		{
			for(int si=1;si<=s;si++)
			{
				if(ar.get(ni-1)<2)
				{
					map[ni][si]=map[ni-1][si]+(sn.get(ni-1)>=p?1:0);
				}
				else
				{
				int s1 = map[ni-1][si]+(sn.get(ni-1)>=p?1:0);
				int s2 = map[ni-1][si-1]+(sy.get(ni-1)>=p?1:0);
				map[ni][si]=s1>s2?s1:s2;
				}
			}
		}
		/*
		System.out.println("###");
		for(int ni = 0;ni<=n;ni++)
		{
			for(int si=0;si<=s;si++)
			{
				System.out.print(map[ni][si]);
				System.out.print(" ");
			}
			System.out.println();
		}
		System.out.println("###");
		*/
		return map[n][s];
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			/*
			System.out.println(chuli("3 1 5 15 13 11"));
			
			System.out.println(chuli("3 0 8 23 22 21"));
			
			System.out.println(chuli("2 1 1 8 0"));
			
			System.out.println(chuli("6 2 8 29 20 8 18 18 21"));
			
			*/
			File fin1 = new File("d:\\B-small-attempt0.in");
	    	FileInputStream fs1 = new FileInputStream(fin1);
	    	BufferedReader br1 = new BufferedReader(new InputStreamReader(fs1));
	    	
	    	File fout6 = new File("d:\\cjamout1");
	    	FileOutputStream fos6 = new FileOutputStream(fout6);
	    	BufferedWriter wr6 = new BufferedWriter(new OutputStreamWriter(fos6));
	       
	    	String line = br1.readLine();
	    	int n = 1;
	    	line = br1.readLine();
	    	while(line!=null)
	    	{
	    	   if(!line.trim().equals(""))
	    	   {
	    		   wr6.write("Case #"+String.valueOf(n++)+": "+String.valueOf(chuli(line)));
	    	       wr6.newLine();
	    	   }
	    	   line = br1.readLine();
	    	  
			}
	    	br1.close();
	    	fs1.close();
	    	
	    	wr6.close();
	    	fos6.close();
	    	
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

}
