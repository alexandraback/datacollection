import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class LessMoney {
	public static int leastFalseValue(boolean[] a)
	{
		for(int i = 0; i < a.length; i++)
		{
			if(!a[i])
				return i;
		}
		return -1;
	}
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("lessmoney.out");
			for(int i = 1; i <= t; i++)
			{
				StringTokenizer st = new StringTokenizer(f.readLine());
				int c = Integer.parseInt(st.nextToken());
				int d = Integer.parseInt(st.nextToken());
				int v = Integer.parseInt(st.nextToken());
				boolean[] canBeObtained = new boolean[v+1];
				ArrayList<Integer> denominations = new ArrayList<Integer>();
				canBeObtained[0] = true;
				st = new StringTokenizer(f.readLine());
				for(int j = 0; j < d; j++)
				{
					int coin = Integer.parseInt(st.nextToken());
					//canBeObtained[coin] = true;
					denominations.add(coin);
				}
				for(int j = 0; j < d; j++)
				{
					for(int k = v-1; k >= 0; k--)
					{
						if(canBeObtained[k] && k + denominations.get(j) <= v)
							canBeObtained[k + denominations.get(j)] = true;
					}
				}
				int count = 0;
				int leastFalse = leastFalseValue(canBeObtained);
				while(leastFalse != -1)
				{
					count++;
					//System.out.println(leastFalse);
					for(int j = v-1; j >= 0; j--)
					{
						if(canBeObtained[j] && leastFalse + j <= v)
							canBeObtained[leastFalse + j] = true;
					}
					leastFalse = leastFalseValue(canBeObtained);
				}
				System.out.println("Case #" + i + ": " + count);
				fout.write("Case #" + i + ": " + count + "\n");
			}
			f.close();
			fout.close();
		}
		catch(IOException e)
		{
			System.out.println(e);
		}

	}

}
