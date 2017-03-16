import java.util.PriorityQueue;
import java.util.Scanner;


public class B {
	
	static class Pair implements Comparable<Pair>
	{
		int index, d;

		public Pair(int index, int d) {
			super();
			this.index = index;
			this.d = d;
		}

		@Override
		public int compareTo(Pair o) {
			return o.d - d;
		}
		
	}

	public static void main(String[] args) {
		
		
		Scanner s = new Scanner(System.in);
		
		int numCases = s.nextInt();
		
		for(int numC = 0; numC < numCases; ++numC)
		{
			int n = s.nextInt();
			int[] d = new int[n];
			
			PriorityQueue<Pair> p = new PriorityQueue<Pair>();
			
			// TODO: try...
			int maxValue = 0;
			
			for(int i = 0; i < n; ++i)
			{
				d[i] = s.nextInt();
				p.add(new Pair(i, d[i]));
				if(d[i] > maxValue)
				{
					maxValue = d[i];
				}
			}
			
			int bestMinimum = 100000000;
			for(int maxAfter = 1; maxAfter <= maxValue; ++maxAfter)
			{
				int[] min = new int[maxValue+1];
				for(int i = 0; i <= maxAfter; ++i)
				{
					min[i] = 0;
				}
				for(int i = maxAfter+1; i <= maxValue; ++i)
				{
					int bestRes = 1000000;
					for(int first = 1; first <= i/2; ++first)
					{
						int second = i - first;
						int res = min[first] + min[second] + 1;
						if(res < bestRes)
						{
							bestRes = res;
						}
					}
					min[i] = bestRes;
				}
				
				int numMinutes = maxAfter;
				for(int i = 0; i < n; ++i)
				{
					int curr = min[d[i]];
					numMinutes += curr;
				}
				
				if(numMinutes < bestMinimum)
				{
					bestMinimum = numMinutes;
				}
				
			}
			
			
			System.out.print("Case #");
			System.out.print(numC+1);
			System.out.print(": ");
			System.out.println(bestMinimum);
			
		}

	}

}
