import java.io.BufferedReader;
import java.io.InputStreamReader;

public class B {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		int ntests = Integer.parseInt(reader.readLine());
		for (int test = 1; test <= ntests; test++) {
			int d = Integer.parseInt(reader.readLine());
			String[] pStr = reader.readLine().split(" ");

			int res = Integer.MAX_VALUE;
			for(int t = 1; t <= 1000;t++)
			{
				int totalSplits = 0;
				for(int i = 0; i < d; i++)
					totalSplits += minSplits(Integer.parseInt(pStr[i]), t);
				int totalTime = totalSplits + t;
				if(totalTime < res)
					res = totalTime;
			}
			System.out.println("Case #" + test + ": " + res);
		}
	}
	
	//min splits to eat p pancakes in time eatTime (excluding time to split)
	//p > 0, eatTime > 0 
	static int minSplits(int p, int eatTime)
	{
		if(p <= eatTime)
			return 0;
		int n = p / eatTime;
		if(p % eatTime != 0)
			n++;
		return n - 1;
	}
}


