import java.io.*;
import java.util.*;

public class CodeJamB
{

	public static void main(String[] args) throws IOException
	{
		String fileName = "B-large";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				fileName + ".out")));

		// Keep track of time for efficiency
		long startTime = System.currentTimeMillis();

		// Generate all of the scores
		HashMap<Integer, ArrayList<Score>> map = new HashMap<Integer, ArrayList<Score>>();
		for (int x = 0; x <= 10; x++)
			for (int y = x; y <= x + 2 && y <= 10; y++)
				for (int z = y; z <= x + 2 && z <= 10; z++)
				{
					Score next = new Score(x, y, z);
					int total = next.total;
					ArrayList<Score> list = map.get(total);
					if (list == null)
					{
						list = new ArrayList<Score>();
						map.put(total, list);
					}
					list.add(next);
				}
		//System.out.println(map);
		//System.out.println(map.size());

		// Process each of the test cases
		int noOfCases = in.nextInt();

		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{

			int N = in.nextInt();
			int S = in.nextInt();
			int p = in.nextInt();
		//	System.out.println("S: "+ S);
		//	System.out.println("P: "+ p);

			int overPNormal = 0;
			int overPSurprised = 0;
			for (int next = 0; next < N; next++)
			{
				int total = in.nextInt();
				int maxNormal = 0;
				int maxSurprise = 0;
				for (Score score : map.get(total))
				{
					if (score.isSurprising)
					{
						if (score.z > maxSurprise)
							maxSurprise = score.z;
					}
					else
					{
						if (score.z > maxNormal)
							maxNormal = score.z;
					}
				}
				if (maxNormal >= p)
					overPNormal++;
				else if (maxSurprise >= p)
					overPSurprised++;

			//	System.out.println(maxNormal + " " + maxSurprise);

			}
			int overP = overPNormal + Math.min(overPSurprised, S);
			System.out.println("Case #" + caseNo + ": " + overP);
			out.println("Case #" + caseNo + ": " + overP);

		}

		System.out.println("Done");
		long stopTime = System.currentTimeMillis();
		System.out.println("Time: " + (stopTime - startTime) / 1000.0);

		// Close the files
		in.close();
		out.close();
	}
}

class Score
{
	int x, y, z;

	int total;

	boolean isSurprising;

	// Assume z is always the highest score and x is the lowest
	public Score(int x, int y, int z)
	{
		this.x = x;
		this.y = y;
		this.z = z;
		total = x + y + z;
		isSurprising = (z - x == 2);
	}

	public String toString()
	{
		return "(" + x + "," + y + "," + z + ")" + (isSurprising ? "S" : "");
	}
}
