
import java.io.*;
import java.util.*;

public class b {

	public static void main(String[] args) throws IOException
	{
		Scanner qwe = new Scanner(new File("b.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("b.out"));
		int t = qwe.nextInt();
		for(int i=1; i <= t; i++)
		{
			int n = qwe.nextInt();
			ArrayList<level> ls=  new ArrayList<level>();
			//ArrayList<level2> ls2=  new ArrayList<level2>();
			for(int j = 0; j < n; j++)
			{
				int a = qwe.nextInt();
				int b = qwe.nextInt();
				level l = new level(j,a,b);
			//	level2 l2 = new level2(j,a,b);
				ls.add(l);
			}
			Collections.sort(ls);
			int front =0;
			//int back = ls.size()-1;
			int stars = 0;
			boolean possible = true;
			boolean[] usedone = new boolean[n];
			boolean[] usedtwo = new boolean[n];
			int count = 0;
			while(stars != n*2)
			{
				if(ls.get(front).two <= stars)
				{
					if(usedone[front])
						stars++;
					else
						stars += 2;
					usedtwo[front] = true;
					usedone[front] = true;
					front++;
					count++;
				}
				else{
				boolean didsomething = false;
				for(int back = ls.size()-1; back >= 0; back --)
				{
					if(ls.get(back).one <= stars && !usedone[back])
					{
						didsomething = true;
						stars++;
						usedone[back] = true;
						count++;
						break;
					}
				}
				
				if(!didsomething)
				{
					possible = false;
					break;
				}
				}
			}
			if(possible)
				out.write("Case #" + i + ": " + count + "\n");
			else
				out.write("Case #" + i + ": Too Bad\n");	
		}
	out.close();
	}
	

}

class level implements Comparable<level>{
	int index;
	int one;
	int two;
	//boolean oned = false;
	
	public level(int i, int o , int t)
	{
		index = i;
		one = o;
		two = t;
	}
	
	public int compareTo(level o)
	{
		if(two == o.two)
			return index - o.index;
		return two - o.two;
	}
	
	
}

class level2 implements Comparable<level2>{
	int index;
	int one;
	int two;
	
	public level2(int i, int o , int t)
	{
		index = i;
		one = o;
		two = t;
	}
	
	public int compareTo(level2 o)
	{
		if(one == o.one)
			return index - o.index;
		return one - o.one;
	}
	
	
}