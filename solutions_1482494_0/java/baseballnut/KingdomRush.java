package gcj2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class KingdomRush 
{
	public String solve(int[] firstStar, int[] secondStar, int caseNr)
	{
		StringBuffer sb = new StringBuffer("");
		sb.append("Case #");
		sb.append(caseNr);
		sb.append(": ");
		int score = count(firstStar, secondStar);
		if (score == -1) sb.append("Too Bad");
		else sb.append(score);
		//sb.append();
		return sb.toString();
	}

	public int count(int[] firstStar, int[] secondStar)
	{
		int steps = 0;
		int stars = 0;
		int size = firstStar.length;
		boolean madeStep = true;
		boolean[] stepOne = new boolean[size];
		boolean[] stepTwo = new boolean[size];
		while (madeStep)
		{
			madeStep = false;
			//try to do two steps
			for (int i = 0; i < size; i++)
			{
				if (!stepOne[i] && !stepTwo[i] && secondStar[i] <= stars && !madeStep)
				{
					madeStep = true;
					stepTwo[i] = true;
					stepOne[i] = true;
					stars += 2;
//					System.out.println("Twostep: " + i);
				}
			}
			//if fails do one step to complete
			if (!madeStep)
			{
				for (int i = 0; i < size; i++)
				{
					if (stepOne[i] && !stepTwo[i] && secondStar[i] <= stars && !madeStep)
					{
						madeStep = true;
						stepTwo[i] = true;
						stars += 1;
//						System.out.println("Second: " + i);
					}
				}
			}
			//if fails do one step to start
			if (!madeStep)
			{
				int maxSecond = -1;
				int maxIndex = -1;
				for (int i = 0; i < size; i++)
				{
					if (!stepOne[i] && firstStar[i] <= stars && !madeStep)
					{
						if (secondStar[i] > maxSecond)
						{
							maxSecond = secondStar[i];
							maxIndex = i;
						}
//						madeStep = true;
//						stepOne[i] = true;
//						stars += 1;
//						System.out.println("First: " + i);
					}
				}
				if (maxIndex != -1)
				{
					madeStep = true;
					stepOne[maxIndex] = true;
					stars += 1;
				}
			}
			steps++;
		}
		steps--;
		if (stars < size*2) return -1;
		return steps;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		KingdomRush test = new KingdomRush();
		String fileName = "in4.txt";
		String outName = "out4.txt";
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(fileName));
			String line = br.readLine();
			BufferedWriter bw = new BufferedWriter(new FileWriter(outName));
			int tests = new Integer(line).intValue();
			for (int i = 0; i < tests; i++)
			{
				line = br.readLine();
				int caseNr = i + 1;
				int lineNr = new Integer(line).intValue();
				int[] firstStar = new int[lineNr];
				int[] secondStar = new int[lineNr];
				for (int j = 0; j < lineNr; j++)
				{
					line = br.readLine();
					String[] parts = line.split(" ");
					firstStar[j] = new Integer(parts[0]).intValue();
					secondStar[j] = new Integer(parts[1]).intValue();
				}
				String line2 = test.solve(firstStar, secondStar, caseNr);
				System.out.println(line2);
				bw.write(line2+"\n");
			}
			bw.flush();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}		
	}
}
