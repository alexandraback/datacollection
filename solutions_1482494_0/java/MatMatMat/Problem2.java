import java.io.*;
import java.util.ArrayList;

public class Problem2
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		reader.readLine();
		int place = 0;
		while (reader.ready())
		{
			int cases = Integer.parseInt(reader.readLine());
			ArrayList<Level> levels = new ArrayList<Level>();
			for (int i=0;i<cases;i++)
			{
				String line = reader.readLine();
				//System.out.println(line);
				String[] arr = line.split(" ");
				levels.add(new Level(Integer.parseInt(arr[0]), Integer.parseInt(arr[1])));
			}
			int solvedInt = solve(levels);
			String solved = solvedInt == -1 ? "Too Bad" : String.valueOf(solvedInt);
			System.out.println("Case #" + (++place) + ": " + solved);
		}
		reader.close();
	}
	public static int solve(ArrayList<Level> levels)
	{
		int count = 0;
		int stars = 0;
		while (!levels.isEmpty())
		{
			count++;
			int max = 0;
			int maxIndex=-1;
			for (int i=0;i<levels.size();i++)
			{
				Level level = levels.get(i);
				int points = level.getPoints(stars);
				if (points>max || (points==1 && max==1 && (level.solved || (level.req2>levels.get(maxIndex).req2 && !levels.get(maxIndex).solved))))
				{
					max=points;
					maxIndex=i;
				}
				if (max==2)
					break;
			}
			if (max==0)
				return -1;
			stars+=max;
			if (max==2 || (max==1 && levels.get(maxIndex).solved))
				levels.remove(maxIndex);
			else
				levels.get(maxIndex).solved=true;
		}
		return count;
	}

	private static class Level
	{
		public int req1;
		public int req2;
		public boolean solved;

		public Level(int req1, int req2)
		{
			this.req1=req1;
			this.req2=req2;
			solved=false;
		}

		public int getPoints(int stars)
		{
			if (stars>=req2 && solved)
				return 1;
			else if (stars>=req2)
				return 2;
			else if (stars>=req1 && !solved)
				return 1;
			else
				return 0;
		}
	}
}
