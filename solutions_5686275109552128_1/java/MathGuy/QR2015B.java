import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class QR2015B
{
	static int[][] numSteps = new int[1001][1001];
	static
	{
		for (int from = 1; from <= 1000; from++)
		{
			for (int to = 1; to < from; to++)
			{
				numSteps[from][to] = from;
				for (int amt = to; amt < from; amt++)
				{
					numSteps[from][to] = Math.min(numSteps[from][to],1+numSteps[from-amt][to]+numSteps[amt][to]);
				}
			}
		}
	}
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; ++t)
		{
			int D = Integer.parseInt(in.readLine());
			StringTokenizer st = new StringTokenizer(in.readLine());
			int[] arr = new int[D];
			for (int i = 0; i < D; ++i) arr[i] = Integer.parseInt(st.nextToken());
			Arrays.sort(arr);
			int max = arr[arr.length-1], ret = max;
			for (int end = 1; end <= max; ++end)
			{
				int curr = end;
				for (int i = 0; i < arr.length; ++i) curr += numSteps[arr[i]][end];
				if (ret > curr) ret = curr;
			}
			System.out.printf("Case #%d: %d\n",t+1,ret);
		}
	}
}
