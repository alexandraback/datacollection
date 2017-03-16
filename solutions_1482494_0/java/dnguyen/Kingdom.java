import java.io.*;
import java.util.*;

class Kingdom
{
	public static void main (String [] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-small-attempt2.out")));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int numCases = Integer.parseInt(st.nextToken());
		
		Comparator<Pair> compFirst = new CompareFirst();
		Comparator<Pair> compSecond = new CompareSecond();

		for (int caseIndex = 0; caseIndex < numCases; caseIndex++)
		{
			out.print("Case #" + (caseIndex+1) + ": ");
			
			PriorityQueue<Pair> queue1 = new PriorityQueue<Pair>(1000, compFirst) ;
			PriorityQueue<Pair> queue2 = new PriorityQueue<Pair>(1000, compSecond) ;
			
			st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			
			for (int i = 0; i < N; i++)
			{
				st = new StringTokenizer(in.readLine());
				Pair p = new Pair (Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
				
				queue1.offer(p);
				queue2.offer(p);
			}
			
			int curPoint = 0;
			int num = 0;
			boolean possible = true;
			
			while (!(queue1.size() == 0 && queue2.size() == 0))
			{
				Pair p = queue2.peek();
				
				//System.out.println(p);
				
				if (curPoint >= p.second)
				{
					//System.out.println(p);
					
					if (queue1.remove(p))
					{
						curPoint += 2;
					}
					else
					{
						curPoint += 1;
					}
					
					queue2.poll();
					num ++;
				}
				else
				{
					if (queue1.size() == 0)
					{
						possible = false;
						break;						
					}
					
					ArrayList<Pair> list = new ArrayList<Pair>();
					
					Pair p2 = queue1.peek();
					
					if (curPoint >= p2.first)
					{
						int curMax = -1;
						int maxIndex = -1;
						int index = 0;
						
						do
						{
							if (p2.second > curMax)
							{
								curMax = p2.second;
								maxIndex = index;
							}
							
							queue1.poll();
							list.add(p2);
							p2 = queue1.peek();
							index ++;
						}
						while (p2 != null && curPoint >= p2.first);
						
						//System.out.println(maxIndex);
						
						for (int j = 0; j < list.size(); j++)
						{
							if (j != maxIndex)
							{
								queue1.offer(list.get(j));
							}
							else
							{
								//System.out.println(list.get(j));
							}
						}
						
						curPoint += 1;
						num ++;
					}
					else
					{
						possible = false;
						break;
					}
				}
				
			}
			
			if (possible)
			{
				out.print(num);
			}
			else
			{
				out.print("Too Bad");
			}
			
			out.println();
		}
		
		out.close();
	}
}

class CompareFirst implements Comparator<Pair>
{
	public int compare(Pair x, Pair y)
	{
		if (x.first != y.first)
		{
			return x.first - y.first;
		}
		else
		{
			return x.second - y.second;
		}
	}
}

class CompareSecond implements Comparator<Pair>
{
	public int compare(Pair x, Pair y)
	{
		if (x.second != y.second)
		{
			return x.second - y.second;
		}
		else
		{
			return x.first - y.first;
		}
	}
}

class Pair
{
	public int first;
	public int second;
	
	public Pair(int first, int second)
	{
		this.first = first;
		this.second = second;
	}
	
	public boolean equals(Object o)
	{
		Pair op = (Pair) o;
		return (first == op.first) && (second == op.second);
	}
	
	public String toString()
	{
		String result = "";
		result += "Pair (" + first +", " + second + ")";
		return result;
	}
}