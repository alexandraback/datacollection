package dancing;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Dance
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int count = Integer.parseInt(br.readLine());
		
		for(int i = 0;i < count;i++)
		{
			String[] info = br.readLine().split(" ");
			int n = Integer.parseInt(info[0]);
			int s = Integer.parseInt(info[1]);
			int p = Integer.parseInt(info[2]);
			
			int[] scores = new int[n];
			for(int j = 0;j < n;j++)
				scores[j] = Integer.parseInt(info[3 + j]);
			
			int maxCount = 0;

			int minS = p + 2 * (p - 2);
			int minN = p + 2 * (p - 1);
			
			//System.out.println(minS + " " + minN);
			
			for(int score : scores)
			{
				if(score == 0 && p != 0)
					continue;
				
				if(score >= minN)
				{
					maxCount++;
					continue;
				}
				
				if(score >= minS && s > 0)
				{
					maxCount++;
					s--;
					continue;
				}
			}
			
			System.out.println("Case #" + (i + 1) + ": " + maxCount);
		}
	}
	
}
