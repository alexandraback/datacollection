import java.util.*;
public class a 
{
	public static int sum;
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int C = input.nextInt();
		for(int c = 0; c<C; c++)
		{
			int n = input.nextInt();
			double[] data = new double[n];
			sum = 0;
			for(int i = 0; i<n; i++)
			{
				data[i] = (double)(input.nextInt());
				sum += data[i];
			}
			System.out.printf("Case #%d: ",c+1);
			for(int p = 0; p<n; p++)
			{
				double lo = 0;
				double hi = 1;
				for(int i = 0; i<100000; i++)
				{
					double mid = (lo+hi)/2;
					if(isValid(data, p, mid))
						lo = mid;
					else hi = mid;
				}
				if(p == n-1)
					System.out.printf("%.6f\n", 100*lo);
				else
					System.out.printf("%.6f ", 100*lo);
			}
		}
	}
	public static boolean isValid(double[] data, int at, double amt)
	{
		double go = data[at] + amt*sum;
		
		//data[at] += amt*sum;
		double total = 0;
		for(int i = 0; i<data.length; i++)
		{
			total += Math.max(0,  go-data[i]);
		}
		//System.out.println(amt + " " + go + " " + total);
		//System.out.println(total);
		return total < sum;
	}
}
