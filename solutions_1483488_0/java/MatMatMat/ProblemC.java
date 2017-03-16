import java.io.*;
import java.util.HashSet;

public class ProblemC
{
	public static void main(String[] args) throws Exception
	{
		String base = "C-small-attempt0";
		BufferedReader reader = new BufferedReader(new FileReader(base+".in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter(base+".out"));
		int place = 0;
		reader.readLine();
		while (reader.ready())
		{
			String line = reader.readLine();
			String[] strs = line.split(" ");
			int a = Integer.parseInt(strs[0]);
			int b = Integer.parseInt(strs[1]);
			int num = solve(a,b);
			writer.write("Case #" + (++place) + ": " + num+'\n');
		}
		reader.close();
		writer.close();
	}

	public static int solve(int a, int b)
	{
		int number = 0;
		for (int i=a;i<=b;i++)
		{
			HashSet<Integer> set = new HashSet<Integer>();
			String str = i+"";
			for (int p=str.length()-1;p>=1;p--)
			{
				String test = str.substring(p) + str.substring(0,p);
				int j = Integer.parseInt(test);
				String test2 = j+"";
				if (i < j && j <= b && str.length()==test2.length() && !set.contains(j))
				{
					set.add(j);
					number++;
				}
			}
		}
		return number;
	}
}
