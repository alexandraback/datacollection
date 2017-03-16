import java.io.*;
import java.util.*;

public class ProblemB
{
	public static void main(String[] args) throws Exception
	{
		final String base = "B-large";
		BufferedReader reader = new BufferedReader(new FileReader(base+".in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter(base+".out"));
		reader.readLine();
		int place = 0;
		while (reader.ready())
		{
			String[] strs = reader.readLine().split(" ");
			int[] totals = new int[strs.length-3];
			int surprise = Integer.parseInt(strs[1]);
			int min = Integer.parseInt(strs[2]);
			for (int i=3;i<strs.length;i++)
				totals[i-3]=Integer.parseInt(strs[i]);
			int num = solve(surprise,min,totals);
			writer.write("Case #" + (++place) + ": " + num+'\n');
		}
		writer.close();
		reader.close();
	}

	public static int solve(int surprise, int min, int[] totals)
	{
		int number = 0;
		outer:
		for (int i=0;i<totals.length;i++)
		{
			int total = totals[i];
			boolean sur = false;
			for (int a=0;a<=10;a++)
			{
				for (int b=a;b<=a+2 && b<=10;b++)
				{
					int c = total - a - b;
					if (c<=10 && c>=min && a+2>=c && c>=b)
					{
						if (b==a+2||c==a+2)
							sur=true;
						else
						{
							number++;
							continue outer;
						}
					}
				}
			}
			if (sur && surprise>0)
			{
				number++;
				surprise--;
			}
		}
		return number;
	}

	public static int brute(int surprise, int min, int[] totals)
	{
		int number = 0;
		outer:
		for (int total : totals)
		{
			boolean sur = false;
			for (int a=1;a<=10;a++)
			{
				for (int b=1;b<=10;b++)
				{
					for (int c=1;c<=10;c++)
					{
						if (a+b+c!=total)
							continue;
						int maxDiff = Math.max(Math.abs(a-b), Math.max(Math.abs(a-c), Math.abs(b-c)));
						int max = Math.max(a, Math.max(b,c));
						if (max>=min)
						{
							if (maxDiff<2)
							{
								number++;
								continue outer;
							}
							else if (maxDiff==2)
							{
								sur=true;
							}
						}
					}
				}
			}
			if (sur && surprise>0)
			{
				number++;
				surprise--;
			}
		}
		return number;
	}
}
