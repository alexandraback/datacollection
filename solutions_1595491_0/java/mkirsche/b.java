import java.util.*;
public class b {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int t = input.nextInt();
	for(int T = 1; T <= t; T++)
	{
		System.out.print("Case #" + T + ": ");
		int n = input.nextInt();
		int s = input.nextInt();
		int p = input.nextInt();
		int[] data = new int[n];
		for(int i =0; i<n; i++)
			data[i] = input.nextInt();
		Arrays.sort(data);
		int count = 0;
		for(int at = n - 1; at >= 0; at--)
		{
			if(data[at] >= p + 2*Math.max(0,p -1))
				count++;
			else if(data[at] >= p + 2*Math.max(0,p -2) && s > 0)
			{
				count++;
				s--;
			}
		}
		System.out.println(count);
	}
}
}
