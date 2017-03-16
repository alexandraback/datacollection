import java.util.Scanner;

class Type
{
	public long id;
	public long count;
	
	public Type(long a, long b)
	{
		count = a;
		id = b;
	}
}

public class C {

	public static void main(String[] args) {
		new C();
	}
	
	Type[] boxes;
	Type[] toys;
	
	public C()
	{
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		
		for(int t = 1; t <= T; ++t)
		{
			int N = sc.nextInt();
			int M = sc.nextInt();
			
			boxes = new Type[N];
			toys = new Type[M];
			
			for(int i = 0; i < N; ++i)
			{
				long count = sc.nextLong();
				long id = sc.nextLong();
				
				boxes[i] = new Type(count, id);
			}
			
			for(int i = 0; i < M; ++i)
			{
				long count = sc.nextLong();
				long id = sc.nextLong();
				
				toys[i] = new Type(count, id);
			}
			
			long ans = 0;
			for(int i = 0; i < M; ++i)
			{
				long current = maxMatch(0, i);
				
				if(current > ans)
					ans = current;
			}
			
			System.out.printf("Case #%d: %d\n", t, ans);
		}
		
	}

	private long maxMatch(int boxIndex, int toyIndex) {
		
		long ans = 0;
		
		if(boxIndex == boxes.length || toyIndex == toys.length)
			return 0;
		
		/* Check if they match. */
		if(boxes[boxIndex].id == toys[toyIndex].id)
		{
			/* Consume the minimum. */
			if(boxes[boxIndex].count < toys[toyIndex].count)
			{
				long saved = boxes[boxIndex].count;
				
				toys[toyIndex].count -= saved;
				ans = saved + maxMatch(boxIndex + 1, toyIndex); 
				toys[toyIndex].count += saved;
			}
			else if(boxes[boxIndex].count > toys[toyIndex].count)
			{
				long saved = toys[toyIndex].count;
				boxes[boxIndex].count -= saved;
				ans = saved + maxMatch(boxIndex, toyIndex + 1); 
				boxes[boxIndex].count += saved;
			}
			else
			{
				ans = boxes[boxIndex].count + maxMatch(boxIndex + 1, toyIndex + 1);
			}
		}
		else
		{
			long ans1 = maxMatch(boxIndex + 1, toyIndex);
			long ans2 = maxMatch(boxIndex, toyIndex + 1);
			
			if(ans1 < ans2)
				return ans2;
			else
				return ans1;
			
		}
		
		return ans;
	}
}
