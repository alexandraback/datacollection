import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
public class c2 
{
	public static int n, m;
	public static long[] q1, q2;
	public static long[] t1, t2;
	public static HashMap<ArrayList<Long>, Long> memo;
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		for(int t = 0; t<T; t++)
		{
			System.out.printf("Case #%d: ", (t+1));
			n = input.nextInt();
			m = input.nextInt();
			q1 = new long[n];
			q2 = new long[m];
			t1 = new long[n];
			t2 = new long[m];
			for(int i = 0; i<n; i++)
			{
				q1[i] = input.nextLong();
				t1[i] = input.nextLong();
			}
			for(int i = 0; i<m; i++)
			{
				q2[i] = input.nextLong();
				t2[i] = input.nextLong();
			}
			long best = 0;
			for(int i = 0; i<=m; i++)
				for(int j = i+1; j<=m+1; j++)
					for(int k = j+1; k<=m+2; k++)
					{
						int index = 0;
						long[] types = new long[n+m];
						long[] data2 = new long[n+m];
						long[] data = new long[n+m];
						for(int pos = 0; pos<n+m; pos++)
						{
							if(pos == i)
							{
								types[pos] = 1;
								data[pos] = q1[0];
								data2[pos] = t1[0];
								continue;
							}
							if(pos == j && q1.length >1)
							{
								types[pos]=1;
								data[pos] = q1[1];
								data2[pos] = t1[1];
								continue;
							}
							if(pos == k && q1.length > 2)
							{
								types[pos] = 1;
								data[pos] = q1[2];
								data2[pos] = t1[2];
								continue;
							}
							//System.out.println(pos);
							types[pos] = 2;
							data[pos] = q2[index];
							data2[pos] = t2[index];
							index++;
						}

						long total = 0;
						long qu1 = 0, ty1 = 0, qu2 = 0, ty2 = 0;
						for(int pos = 0; pos < n+m; pos++)
						{
							//System.out.println(qu1 + " " + ty1 + " " + qu2 + " " + ty2);
							long num = data[pos];
							long ty = types[pos];
							if(ty == 1)
							{
								qu1 = data[pos];
								ty1 = data2[pos];
							}
							else
							{
								qu2 = data[pos];
								ty2 = data2[pos];
							}
							if(ty1 == ty2)
							{
								long plus = Math.min(qu1, qu2);
								qu1 -= plus;
								qu2 -= plus;
								total += plus;
							}
						}
						best = Math.max(best, total);
					}
			System.out.println(best);
			
		}
	}
}
