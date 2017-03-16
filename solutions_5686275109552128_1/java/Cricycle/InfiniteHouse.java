import java.util.*;

public class InfiniteHouse
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int testNum = 1; testNum <= t; ++testNum)
		{
			int d = in.nextInt();
			int[] inputs = new int[d];
			for (int i = 0; i < d; ++i)
				inputs[i] = in.nextInt();
			
			Arrays.sort(inputs);
			
			int min = 5000;
			for (int i = 1; i <= inputs[d-1]; ++i)
			{
				min = Math.min(min, eval(inputs, i));
			}
			
			System.out.printf("Case #%d: %d\n", testNum, min);
		}
	}
	
	public static int eval(int[] inputs, int target)
	{
		int total = target;
		for (int i = 0; i < inputs.length; ++i)
		{
			total += (inputs[i] / target) + (inputs[i] % target == 0 ? -1 : 0);
		}
		return total;
	}
}