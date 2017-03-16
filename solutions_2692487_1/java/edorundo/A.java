import java.util.*;
import java.io.*;
public class A 
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new File("A-large.in"));
		
		PrintWriter out = new PrintWriter(new FileWriter("A.out"));
		
		int t = in.nextInt();
		
		for(int x = 0; x < t; x++)
		{
			int a = in.nextInt();
			
			int n = in.nextInt();
			
			ArrayList<Integer> m = new ArrayList<Integer>();
			for(int y = 0; y < n; y++)
			{
				m.add(in.nextInt());
			}
			
			Collections.sort(m);
			
			ArrayDeque<Integer> motes = new ArrayDeque<Integer>(m);
			
			a = absorb(motes, a);
			
			int best = motes.size();
			
			int inserts = 0;
			while(motes.size() > 0)
			{
				if(a == 1)
				{
					break;
				}
				
				a += a - 1;
				inserts++;
				a = absorb(motes, a);
				best = Math.min(best, inserts + motes.size());
			}
			
			out.println("Case #" + (x + 1) + ": " + best);
		}
		
		out.close();
	}
	
	public static int absorb(ArrayDeque<Integer> motes, int armin)
	{
		while(armin > motes.peek())
		{
			armin += motes.peek();
			motes.remove();
			
			if(motes.size() == 0)
			{
				break;
			}
		}
		
		return armin;
	}
}
