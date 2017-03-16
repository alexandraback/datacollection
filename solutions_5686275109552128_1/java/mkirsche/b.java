import java.util.*;
public class b {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		int n = input.nextInt();
		int[] data = new int[n];
		for(int i = 0; i<n; i++) data[i] = input.nextInt();
		int res = 1000;
		for(int iter = 1; iter <= 1000; iter++)
		{
			int cur = 0;
			for(int i = 0; i<n; i++)
			{
				int x = data[i];
				while(x > iter)
				{
					x -= iter;
					cur++;
				}
			}
			res = Math.min(res, cur+iter);
		}
		System.out.println("Case #" + (t+1)+": "+res);
	}
}
}
