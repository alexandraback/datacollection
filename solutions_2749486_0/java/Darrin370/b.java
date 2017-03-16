import java.io.*;
import java.util.*;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Double.*;
import java.math.*;
class b
{
  	public static void main (String [] args) throws IOException 
  	{	
  		BufferedReader f = new BufferedReader(new FileReader(new File("b.in")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		PrintWriter out = new PrintWriter(new FileWriter(new File("sol.out")));
		long zz = Integer.parseInt(st.nextToken());
		for(int z = 0;z<zz;z++)
		{
			System.out.println(z);
			st =  new StringTokenizer(f.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			HashMap<String,String> map = new HashMap<String,String>();
			d(map,x,y);
			String ans = map.get(x+" "+y).substring(1);
			out.printf("Case #%d: %s%n",z+1,ans);
		}
		
		out.close();
		System.exit(0);
  	}
  	
  	public static void d(HashMap<String,String> map,int goalX,int goalY)
  	{
  		Queue<String> que = new LinkedList<String>();
  		que.offer("0 0 . 1");
  		while(!que.isEmpty())
  		{
  			String[] strs = que.poll().split(" ");
  			int x = Integer.parseInt(strs[0]);
  			int y = Integer.parseInt(strs[1]);
  			String current = strs[2];
  			int curr = Integer.parseInt(strs[3]);
  			if(map.get(goalX+" "+goalY)!=null&&map.get(goalX+" "+goalY).length()<=current.length())
  				continue;
  			if(map.get(x+" "+y)!=null)
  			{
	  			String get = map.get(x+" "+y);
	  			if(get.length()<=current.length())
	  				continue;
	  			else
	  			{
	  				map.put(x+" "+y,current);
	  				que.offer((x+curr)+" "+y+" "+current+"E "+(curr+1));
	  				que.offer(x-curr+" "+y+" "+current+"W "+(curr+1));
	  				que.offer(x+" "+(y+curr)+" "+current+"N "+(curr+1));
	  				que.offer(x+" "+(y-curr)+" "+current+"S "+(curr+1));
	  			}
  			}
  			else
  			{
  				map.put(x+" "+y,current);
  				que.offer((x+curr)+" "+y+" "+current+"E "+(curr+1));
  				que.offer(x-curr+" "+y+" "+current+"W "+(curr+1));
  				que.offer(x+" "+(y+curr)+" "+current+"N "+(curr+1));
  				que.offer(x+" "+(y-curr)+" "+current+"S "+(curr+1));
  			}
  		}
  		
  		
  	}
}
